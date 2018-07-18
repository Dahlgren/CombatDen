/*
    Author: Ottavio

    Description:

    Mission logic to run only on the server.

    Parameter(s):

    0: GROUP - player group

    1: STRING - Enemy faction to populate each bunker, must be either
    "CSAT", or "Guerrilla".  Defaults to "CSAT".

    2: ARRAY of STRINGS - A location name blacklist.

    Returns: STRING - AO location name, empty string on error.
*/
params ["_group", "_faction", "_blacklist"];

_group     = _this param [0, grpNull, [grpNull]];
_faction   = _this param [1, "CSAT", [""]];
_blacklist = _this param [2, [], [[]]];

private _minInsert = 500;
private _maxInsert = 550;
private _minExfil  = 200;
private _maxExfil  = 250;

// HACK: For some reason _group looses it's reference to the caller's
// _group parameter.  When passing it to den_fnc_hostage it's a garbage
// group.  Putting this assignment alias in place until I can figure
// out what is wrong.
//_rescueGroup = _group;

private _ao = [
    ["NameCity", "NameVillage", "NameLocal"],
    _blacklist
] call den_fnc_randAo;

private _aoName   = _ao select 0;
private _aoPos    = _ao select 1;
private _aoArea   = _ao select 2;
private _aoRadius = _aoArea select 0;

/*
 * insert
 */
private _insert = [
    _aoPos,
    _minInsert + _aoRadius,
    _maxInsert + _aoRadius,
    _group
] call den_fnc_randInsert;

if (_insert isEqualTo []) exitWith {
    "";
};

/*
 * exfil
 */
private _exfilPos = [
    _aoPos,
    _minExfil + _aoRadius,
    _maxExfil + _aoRadius
] call den_fnc_randExfil;

if (_exfilPos isEqualTo []) exitWith {
    "";
};

[
    _exfilPos,
    (_exfilPos getDir _aoPos) - 180, // helicopter direction
    "den_hostageFound"
] call den_fnc_exfilTrigger;

/*
 * patrol
 */
[_aoPos, _aoRadius * 0.5,  _faction] call den_fnc_patrol;
[_aoPos, _aoRadius * 0.75, _faction] call den_fnc_motorPatrol;

/*
 * hostage
 */
private _hostagePos = [
    _aoPos,           // center pos
    0,                // min dist
    _aoRadius * 0.25, // max dist
    10,               // object dist
    0,                // water mode
    0.1,              // max gradient
    0,                // shore mode
    [],               // backlist
    [[0,0,0]]         // default
] call BIS_fnc_findSafePos;

if (_hostagePos isEqualTo [0,0,0]) exitWith {
    ["could not find safe hostage position"] call BIS_fnc_error;
    "";
};

"CamoNet_OPFOR_open_F" createVehicle _hostagePos;

[_hostagePos, _group, "B_Heli_Transport_01_camo_F"] call den_fnc_hostage;

createMarker ["hostageMarker", _hostagePos];
"hostageMarker" setMarkerType "mil_dot";
"hostageMarker" setMarkerColor "colorBLUFOR";
"hostageMarker" setMarkerText "hostage";

/*
 * guards
 */
private _guardGroup = [
    _hostagePos,
    30,          // radius
    _faction
] call den_fnc_randFireTeam;

if (!isNull _guardGroup) then {
    createGuardedPoint [east, _hostagePos, -1, objNull];
    [_guardGroup, _hostagePos, 0, "GUARD", "SAFE", "YELLOW"] call CBA_fnc_addWaypoint;
};

/*
 * reinforcements
 */
 [
    _aoPos,
    _aoArea,
    _aoRadius,
    _aoRadius + 50,
    _faction
] call den_fnc_reinforceTrigger;

_aoName;