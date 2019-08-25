/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Occupy buildings with enemy units.

    Parameter(s):

    0: ARRAY - center position

    1: NUMBER - radius

    2: STRING - Enemy faction. See CfgFactions.

    3: NUMBER - Max number of 2 unit groups.

    4: BOOL - If true a single random unit will contain intel on
    remaining unit poisitions.

    Returns: unit array
*/
#include "..\..\macros.hpp"

params [
    ["_pos",     [],     [[]], [2,3]],
    ["_radius",  0,      [0]],
    ["_faction", "CSAT", [""]],
    ["_max",     5,      [0]],
    ["_intel",   true,   [true]],
    ["_flee",    true,   [true]]
];

if (_pos isEqualTo []) exitWith {
    ERROR("position parameter is empty");
    [];
};

private _buildingList = nearestObjects [_pos, ["House"], _radius];

if (_buildingList isEqualTo []) exitWith {
    false;
};

_buildingList call BIS_fnc_arrayShuffle;

private _units     = [];
private _positions = [];

{
    if (_max == 0) exitWith{};

    private _pos = _x buildingPos 0;
    if !(_pos isEqualTo [0,0,0]) then {
        private _group = [_pos, _faction, "Sentry"] call den_fnc_spawnGroup;

        private _wp = [_group, _x, 0, "SCRIPTED", "AWARE", "YELLOW", "FULL", "WEDGE"] call CBA_fnc_addWaypoint;
        _wp setWaypointScript "\x\cba\addons\ai\fnc_waypointGarrison.sqf";

        {
            _units pushBack _x;
        } forEach units _group;

        _positions pushBack _pos;

        _max = _max - 1;
    };
} forEach _buildingList;

if (_intel && (count _positions) > 1) then {
    [_units, _positions, _faction] call den_fnc_intelPositions;
};

if (_flee && (count _units) > 0) then {
    /*
     * Monitor the number of alive units that belong to these units.
     * If the number is low enough, force these units to flee.
     */
    private _side = [_faction] call den_fnc_factionSide;

    [_units, _side, _pos] spawn {
        params ["_units", "_side", "_pos"];

        private _active = true;
        private _fleePos = [_pos, 1500] call BIS_fnc_findSafePos;
        while { _active } do {
            private _unitCount = { (_side == (side _x)) && alive _x } count allUnits;
            if (_unitCount <= 3 || !(isNil "den_forceFlee")) then {
                {
                    {
                        deleteWaypoint _x;
                    } forEach (waypoints _x);

                    _x doMove _fleePos;
                } forEach _units;

                _active = false;
            };
            sleep 5;
        };
    };
};

_units;
