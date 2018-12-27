/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Create a civilian presence.

    Parameter(s):

    0: ARRAY - Position

    1: NUMBER - Radius

    2: NUMBER - Density, should be between 0..1.

    Returns: STRING - zone location name, empty string on error.
*/
params [
    ["_pos",     [],   [[]], [2,3]],
    ["_radius",  0,    [0]],
    ["_density", 0.10, [0]]
];

private _buildingList = nearestObjects [_pos, ["House"], _radius];

if (_buildingList isEqualTo []) exitWith {};

_buildingList call BIS_fnc_arrayShuffle;

private _cfgClimate = [] call den_fnc_worldToClimate;

private _metaverse = "Arma2035";
if (isClass (configfile >> "CfgPatches" >> "lop_main")) then {
    _metaverse = "RHS_OPFOR";
};

private _genericName =
    getText (missionConfigFile >> "CfgFactions" >> _metaverse >> "Civilian" >> _cfgClimate >> "genericName");

if (isNil "_genericName") exitWith {
    ["invalid config parameters"] call BIS_fnc_error;
    false;
};

private _max = ceil ((count _buildingList) * _density);

private _cfgList = "(getText (_x >> ""genericNames"")) == _genericName" configClasses (configfile >> "CfgVehicles");
private _civList = [];

/*
 * Create the civ units in building with random animation.
 */
{
    if (_max == 0) exitWith{};

    private _building    = _x;
    private _civPos      = [0,0];
    private _buildingPos = _building buildingPos -1;

    if ((count _buildingPos) > 1) then {
        _civPos = _buildingPos select 1;
    } else {
        _civPos = [_building, 5, 10, 1, 0, 0.1, 0, [], [[0,0],[0,0]]] call BIS_fnc_findSafePos;
    };

    if !(_civPos isEqualTo [0,0]) then {
        private _type  = configName(selectRandom _cfgList);
        private _group = [_civPos, civilian, [_type]] call BIS_fnc_spawnGroup;
        {
            private _civ = _x;

            _civ addEventHandler ["killed", {
                params ["_unit", "_killer", "_instigator", "_useEffects"];
                _killer = _this select 1;
                if (isPlayer _killer) then {
                    ["den_civDead"] call den_fnc_publicBool;
                };
            }];

            _civList pushBack _civ;

            private _animation = selectRandom [
                "Acts_CivilHiding_1",
                "Acts_CivilHiding_2",
                "Acts_CivilInjuredArms_1",
                "Acts_CivilInjuredChest_1",
                "Acts_CivilInjuredGeneral_1",
                "Acts_CivilInjuredHead_1",
                "Acts_CivilInjuredLegs_1",
                "Acts_CivilShocked_1",
                "Acts_CivilShocked_2"
            ];

            _civ switchMove _animation;
        } forEach units _group;

        _max = _max - 1;
    };
} forEach _buildingList;

true;
