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

    1: STRING - Enemy faction to populate each bunker, must be either
    "CSAT", or "Guerrilla".  Defaults to "CSAT".

    Returns: STRING - AO location name, empty string on error.
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
    ["helo parameter must not be null"] call BIS_fnc_error;
    "";
};

private _aoRadius       = 500;
private _minLz          = _aoRadius + 500;
private _maxLz          = _aoRadius + 550;
private _maxBunker      = _aoRadius * 0.8;
private _maxInfPatrol   = _aoRadius * 0.75;
private _maxMotorPatrol = _aoRadius * 0.75;
private _minReinforce   = _aoRadius + 300;
private _maxReinforce   = _aoRadius + 325;

private _safePosParams = [
    [_minLz,        _maxLz,          15, 0.1], // lz safe position
    [0,             _maxBunker,      10, 0.1], // bunker 1 safe position
    [0,             _maxBunker,      10, 0.1], // bunker 2 safe position
    [0,             _maxBunker,      10, 0.1], // bunker 3 safe position
    [0,             _maxInfPatrol,    5,  -1], // inf patrol safe position
    [0,             _maxMotorPatrol, 10, 0.1], // inf patrol safe position
    [_minReinforce, _maxReinforce,    5,  -1]  // reinforce safe position
];

private _ao = [
    ["NameCity", "NameVillage", "NameLocal"],
    _aoRadius,
    _safePosParams,
    true
] call den_fnc_randAo;

private _aoName        = _ao select 0;
private _aoArea        = _ao select 1;
private _aoPos         = _aoArea select 0;
private _aoRadius      = _aoArea select 1;
private _aoSafePosList = _ao select 2;
private _lzPos         = _aoSafePosList select 0;
private _bunkerPosList = [
    _aoSafePosList select 1,
    _aoSafePosList select 2,
    _aoSafePosList select 3
];
private _infPatrolPos   = _aoSafePosList select 4;
private _motorPatrolPos = _aoSafePosList select 5;
private _reinforcePos   = _aoSafePosList select 6;

private _aoActivation = "missionNamespace setVariable [""den_aoClear"", TRUE, TRUE];";
private _aoTrigger = createTrigger ["EmptyDetector", _aoPos, false];
_aoTrigger setTriggerArea          [_aoRadius, _aoRadius, 0, false];
_aoTrigger setTriggerActivation    ["EAST", "NOT PRESENT", false];
_aoTrigger setTriggerStatements    ["this", _aoActivation, ""];

[_lzPos, _playerGroup, _helo, _aoArea] call den_fnc_insert;

private _i = 1;
{
    [_x, "bunker01"] call den_fnc_composition;

    private _group = [_x, _faction, "FireTeam"] call den_fnc_spawnGroup;

    private _wp = [_group, _x, 0, "SCRIPTED", "SAFE", "YELLOW", "FULL", "WEDGE"] call CBA_fnc_addWaypoint;
    _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf";

    private _marker = createMarker [format["bunkerMarker-%1", _i], _x];
    _marker setMarkerType  "loc_Bunker";
    _marker setMarkerColor "colorOPFOR";
    _marker setMarkerText  format["%1", _i];
    _marker setMarkerSize  [2,2];

    _i = _i + 1;
} forEach _bunkerPosList;

private _guardPos = selectRandom _bunkerPosList;
createGuardedPoint [east, _guardPos, -1, objNull];

/*
 * patrol
 */
private _motorGroup = [_motorPatrolPos, _faction, "MotorizedHmg"] call den_fnc_spawnGroup;

[_motorGroup, _motorPatrolPos, 0, "GUARD", "SAFE", "YELLOW"] call CBA_fnc_addWaypoint;

private _infGroup = [_infPatrolPos, _faction, "FireTeam"] call den_fnc_spawnGroup;

[_infGroup, _lzPos, "den_insertUnload"] call den_fnc_attack;

/*
 * reinforcements
 */
[_aoArea, [[_reinforcePos, "AssaultSquad"]], _faction] call den_fnc_wave;

/*
 * enemy unit markers
 */
private _infMarkerPos   = _aoPos getPos [100, (_aoPos getDir _lzPos)];
private _motorMarkerPos = _aoPos getPos [150, (_aoPos getDir _lzPos)];

["infMarker",   _infMarkerPos,   _faction, "FireTeam"] call den_fnc_groupMarker;
["motorMarker", _motorMarkerPos, _faction, "MotorizedHmg"] call den_fnc_groupMarker;

_aoName;
