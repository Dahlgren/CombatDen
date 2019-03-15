/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Mission logic to run only on the server.

    0: GROUP - player group

    1: OBJECT - Transport helicopter to take players to the zone.

    2: STRING - BLUFOR faction. See CfgFactions.

    3: STRING - OPFOR faction. See CfgFactions.

    4: NUMBER - difficulty. See CfgParams.

    Returns: STRING - zone location name, empty string on error.
*/
#include "..\..\macros.hpp"

params [
    ["_playerGroup",   grpNull, [grpNull]],
    ["_helo",          objNull, [objNull]],
    ["_bluforFaction", "",      [""]],
    ["_opforFaciton",  "",      [""]],
    ["_difficulty",    0,       [0]]
];

if (isNull _playerGroup) exitWith {
    ERROR("group parameter must not be null");
    "";
};

if (isNull _helo) exitWith {
    ERROR("helo parameter cannot be empty");
    "";
};

if (_bluforFaction == "") exitWith {
    ERROR("blufor faction cannot be empty");
    "";
};

if (_opforFaction == "") exitWith {
    ERROR("opfor faction cannot be empty");
    "";
};
/*
 * max radius for AO objects
 */
private _zoneRadius   = 400;
private _minLz        = _zoneRadius + 500;
private _maxLz        = _zoneRadius + 550;
private _maxBunker    = _zoneRadius * 0.8;
private _maxReact     = _zoneRadius * 0.5;  // reaction force
private _maxPatrol    = _zoneRadius * 0.75; // patrol force
private _minReinforce = _zoneRadius + 300;  // reinforcements
private _maxReinforce = _zoneRadius + 325;

private _safePosParams = [
    [_minLz,        _maxLz,          15, 0.1], // lz safe position
    [0,             _maxBunker,      10, 0.1], // bunker 1 safe position
    [0,             _maxBunker,      10, 0.1], // bunker 2 safe position
    [0,             _maxBunker,      10, 0.1], // bunker 3 safe position
    [0,             _maxReact,        5,  -1], // inf patrol safe position
    [0,             _maxPatrol,       5,  -1], // inf patrol safe position
    [_minReinforce, _maxReinforce,   15, 0.1]  // reinforce safe position
];

private _zone = [
    ["NameVillage", "NameLocal", "CityCenter"],
    _zoneRadius,
    _safePosParams,
    true
] call den_fnc_zone;

if (_zone isEqualTo []) exitWith {
    ERROR("zone failure");
    "";
};

private _zoneName        = _zone select 0;
private _zoneArea        = _zone select 1;
private _zonePos         = _zoneArea select 0;
private _zoneRadius      = _zoneArea select 1;
private _zoneSafePosList = _zone select 2;
private _lzPos         = _zoneSafePosList select 0;
private _bunkerPosList = [
    _zoneSafePosList select 1,
    _zoneSafePosList select 2,
    _zoneSafePosList select 3
];
private _reactPos     = _zoneSafePosList select 4;
private _patrolPos    = _zoneSafePosList select 5;
private _reinforcePos = _zoneSafePosList select 6;

private _zoneActivation = "[""den_zoneClear""] call den_fnc_publicBool;";
private _zoneTrigger = createTrigger ["EmptyDetector", _zonePos, false];
_zoneTrigger setTriggerArea          [_zoneRadius, _zoneRadius, 0, false];
_zoneTrigger setTriggerActivation    ["EAST", "NOT PRESENT", false];
_zoneTrigger setTriggerStatements    ["this", _zoneActivation, ""];

[_lzPos, _playerGroup, _helo, _zoneArea] call den_fnc_insert;

/*
 * enemy units
 */
private _guardPos = selectRandom _bunkerPosList;
createGuardedPoint [east, _guardPos, -1, objNull];

private _guardType     = "FireTeam";
private _reactType     = "FireTeam";
private _patrolType    = "Sentry";
private _reinforceArgs = [[_reinforcePos, "MotorizedTeam"]];

switch (_difficulty) do {
    case 1: {
        _reactType     = "AssaultSquad";
        _reinforceArgs = [[_reinforcePos, "MotorizedAssault"]];
    };
    case 2: {
        _guardType     = "AssaultSquad";
        _reactType     = "AssaultSquad";
        _reinforceArgs = [[_reinforcePos, "MotorizedAssault"]];
    };
};

private _i = 1;
{
    [_x, "bunker01"] call den_fnc_composition;

    private _group = [_x, _opforFaction, _guardType] call den_fnc_spawnGroup;

    private _wp = [_group, _x, 0, "SCRIPTED", "AWARE", "YELLOW", "FULL", "WEDGE"] call CBA_fnc_addWaypoint;
    _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf";

    private _marker = createMarker [format["bunkerMarker-%1", _i], _x];
    _marker setMarkerType  "loc_Bunker";
    _marker setMarkerColor "colorOPFOR";
    _marker setMarkerText  format["%1", _i];
    _marker setMarkerSize  [2,2];
    _i = _i + 1;
} forEach _bunkerPosList;

private _reactGroup = [_reactPos, _opforFaction, _reactType] call den_fnc_spawnGroup;
/*
 * Select either the current patrol pos, or the LZ by random.
 * Delay the waypoint until after the players have unloaded
 * from the transport.
 */
private _reactWpPos = selectRandom [_reactPos, _lzPos];
[_reactGroup, _reactWpPos] spawn {
    params ["_group", "_pos"];

    while {isNil "den_insertUnload"} do { sleep 1 };
    [_group, _pos, 0, "GUARD", "AWARE", "YELLOW"] call CBA_fnc_addWaypoint;
};

private _patrolGroup = [_patrolPos, _opforFaction, _patrolType] call den_fnc_spawnGroup;
[
    _patrolGroup,
    _zonePos,
    300,
    6,
    "MOVE",
    "SAFE",
    "YELLOW",
    "LIMITED",
    "STAG COLUMN"
] call CBA_fnc_taskPatrol;

[_zonePos, _zoneRadius * 0.5, _opforFaction, 4] call den_fnc_buildingOccupy;

[_zoneArea, _reinforceArgs, _opforFaction] call den_fnc_wave;

/*
 * enemy unit markers
 */
private _infMarkerPos = _zonePos getPos [100, (_zonePos getDir _lzPos)];

private _marker = createMarker ["opforInfMarker", _infMarkerPos];
_marker setMarkerType "o_inf";

_zoneName;
