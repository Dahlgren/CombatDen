/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Mission logic to run only on the server.

    Parameter(s):

    0: GROUP - player group

    1: OBJECT - Transport helicopter to take players to the zone.

    2: STRING - Enemy faction to populate each bunker, must be either
    "CSAT", or "Guerrilla".  Defaults to "CSAT".

    3: ARRAY of STRINGS - A location name blacklist.

    Returns: STRING - zone location name, empty string on error.
*/
params ["_playerGroup", "_helo", "_faction"];

_playerGroup = _this param [0, grpNull, [grpNull]];
_helo        = _this param [1, objNull, [objNull]];
_faction     = _this param [2, "CSAT", [""]];

if (isNull _playerGroup) exitWith {
    ["group parameter must not be null"] call BIS_fnc_error;
    "";
};

if (isNull _helo) exitWith {
    ["helo parameter is  empty"] call BIS_fnc_error;
    false;
};

private _zoneRadius  = 500;
private _minLz       = _zoneRadius + 400;
private _maxLz       = _zoneRadius + 450;
private _maxConvoy   = _zoneRadius * 0.5;
private _minAssault1 = _zoneRadius * 0.75;
private _maxAssault1 = _zoneRadius * 0.8;
private _minAssault2 = _zoneRadius + 50;
private _maxAssault2 = _zoneRadius + 100;

private _safePosParams = [
    [_minLz,       _maxLz,       15, 0.1, 0], // insert safe position
    [_minAssault1, _maxAssault1,  5   -1, 1], // assault1 safe position
    [_minAssault2, _maxAssault2, 10, 0.1, 0]  // assault1 safe position
];

private _zone = [
    ["NameCity", "NameVillage", "NameLocal"],
    _zoneRadius,
    _safePosParams
] call den_fnc_zone;

if (_zone isEqualTo []) exitWith {
    "";
};

private _zoneName        = _zone select 0;
private _zoneArea        = _zone select 1;
private _zonePos         = _zoneArea select 0;
private _zoneRadius      = _zoneArea select 1;
private _zoneSafePosList = _zone select 2;
private _lzPos           = _zoneSafePosList select 0;
private _convoyRoads     = _zonePos nearRoads (_maxConvoy);
if (_convoyRoads isEqualTo []) exitWith {
    ["failed to find road for convoy"] call BIS_fnc_error;
    "";
};
private _convoyDir  = 0;
private _convoyRoad = (selectRandom _convoyRoads);
private _convoyConnList = roadsConnectedTo _convoyRoad;
if !(_convoyConnList isEqualTo []) then {
    private _convoyConnRoad = _convoyConnList select 0;
    _convoyDir  = _convoyRoad getDir _convoyConnRoad;
};
private _convoyPos  = getPos _convoyRoad;
private _assaultPos1 = _zoneSafePosList select 1;
private _assaultPos2 = _zoneSafePosList select 2;

[_lzPos, _playerGroup, _helo, _zoneArea] call den_fnc_insert;

/*
 * convoy
 */
private _convoyVehicles = ["B_Truck_01_ammo_F", "B_Truck_01_box_F", "B_Truck_01_fuel_F"];
private _i = 0;
{
    private _vpos = _convoyPos getPos [_i * 15, _convoyDir];
    private _v = _x createVehicle _vpos;
    _v setDir _convoyDir;
    _v setDamage 0.80;

    private _gpos = _vpos getPos [5, _convoyDir + 90];
    private _g = [_gpos, "NATO", "TruckCrew"] call den_fnc_spawnGroup;
    if (!isNull _g) then {
        private _wp = [_g, _vpos, 0, "SCRIPTED", "SAFE", "YELLOW", "FULL", "WEDGE"] call CBA_fnc_addWaypoint;
        _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf";
    };

    _i = _i + 1;
} forEach _convoyVehicles;

createMarker ["convoyMarker", _convoyPos];
"convoyMarker" setMarkerType "mil_objective";
"convoyMarker" setMarkerColor "colorBLUFOR";
"convoyMarker" setMarkerText "convoy";
"convoyMarker" setMarkerSize [0.75, 0.75];

createGuardedPoint [opfor, _convoyPos, -1, objNull];

/*
 * assault waves
 */
[_assaultPos1, _assaultPos2, _zoneArea, _convoyPos, _faction] spawn {
    private _assaultPos1 = _this select 0;
    private _assaultPos2 = _this select 1;
    private _zoneArea    = _this select 2;
    private _convoyPos   = _this select 3;
    private _faction     = _this select 4;

    // wait for player insert before staring wave attacks
    while {true} do {
        if (!isNil "den_insert") exitWith {
            sleep (random [10, 15, 20]);
        };
        sleep 1;
    };

    [
        _zoneArea,
        [[_assaultPos1, "MotorizedAssault"], [_assaultPos2, "AssaultSquad"]],
        _faction,
        {den_spawnDone = true}
    ] call den_fnc_wave;

    // wait for the zone to clear before mission complete
    private _enemyCount = -1;
    while {true} do {
        if (!isNil "den_spawnDone") then {
            _enemyCount = {((side _x) == opfor) && ((getPos _x) inArea _zoneArea) && (!fleeing _x)} count allUnits;
        };
        if (_enemyCount == 0) exitWith {};
        sleep 1;
    };

    ["den_convoyDefended"] call den_fnc_publicBool;
};

_zoneName;
