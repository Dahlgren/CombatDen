/*
    Author: Ottavio

    Description:

    Create one or more bunkers in a random location.  For each
    bunker created, a 4 man enemy unit is spawned and given a
    garrison waypoint at the bunker.

    Parameter(s):

    0: ARRAY - Center position to create bunkers

    1: NUMBER - A radius from the center position

    2: (Optional) STRING - Enemy faction to populate each bunker, must be either
    "CSAT", or "Guerrilla".  Defaults to "CSAT".

    3: (Optional) NUMBER - Number of bunkers to generate.  This is not a guarantee,
    as there may not be enough suitable locations for the number of
    bunkers requested.  Default is 1.

    4: (Optional) STRING - Bunker type.  Default is "Land_BagBunker_Large_F".

    5: (Optional) BOOL - When true, markers are created for each bunker on the map.
    Default is false.

    Returns: ARRAY - List of position for each bunker.
*/
params ["_pos", "_radius", "_faction", "_count", "_type", "_markers"];

_pos     = _this param [0, [], [[]], [2,3]];
_radius  = _this param [1, 0, [0]];
_faction = _this param [2, "CSAT", [""]];
_count   = _this param [3, 1, [0]];
_type    = _this param [4, "Land_BagBunker_Large_F", [""]];
_markers = _this param [5, false, [false]];
_min     = 0;
_objDist = 10;
_maxGrad = 0.1;
_posList = [];

_unitCfg = configNull;
switch (_faction) do {
    case "CSAT": {
        _unitCfg = configfile >> "CfgGroups" >> "East" >> "OPF_F" >> "Infantry" >> "OIA_InfTeam";
    };
    case "Guerrilla": {
        _unitCfg = configfile >> "CfgGroups" >> "East" >> "OPF_G_F" >> "Infantry" >> "O_G_InfTeam_Light";
    };
};
if (isNull _unitCfg) exitWith {
    ["faction param is invalid"] call BIS_fnc_error;
    false;
};

_blacklist = [];
for [{_x = 1}, {_x <= _count}, {_x = _x + 1}] do {
    _bunkerPos = [
        _pos,       // center pos
        _min,       // min distance
        _radius,    // max distance
        _objDist,   // obj distance
        0,          // water mode
        _maxGrad,   // max gradient
        0,          // shore mode
        _blacklist,
        [[0,0,0]]   // default pos
    ] call BIS_fnc_findSafePos;

    if (_bunkerPos isEqualTo [0,0,0]) exitWith {};

    _bunkerPos = [_bunkerPos select 0, _bunkerPos select 1, 0];
    _posList pushBack _bunkerPos;

    _area = [_bunkerPos, [100, 100, true]];
    _blacklist pushBack _area;

    _bunker = _type createVehicle _bunkerPos;
    _bunker setDir (_bunkerPos getDir _pos);

    _group = [_bunkerPos, opfor, _unitCfg] call BIS_fnc_spawnGroup;
    _wp = [_group, _bunkerPos, 0, "SCRIPTED", "SAFE", "YELLOW", "FULL", "WEDGE"] call CBA_fnc_addWaypoint;
    _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf";

    if (_markers) then {
        _marker = createMarker [format["bunkerMarker-%1", _x], _bunkerPos];
        _marker setMarkerType  "mil_triangle";
        _marker setMarkerColor "colorOPFOR";
        _marker setMarkerText  format["bunker-%1", _x];
    };
};

_posList;