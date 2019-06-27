/*
    Copyright (C) 2019 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Spawn a roadblock composition.

    Parameter(s):

    0: ARRAY - Position

    1: (Optional) NUMBER - Direction

    2: (Optional) STRING - Faction name.  If this is provided,
    a flag will be placed at the roadblock.

    Returns: true
*/
#include "..\..\macros.hpp"

params [
    ["_pos", [], [[]], [2,3]],
    ["_dir", 0,  [0]],
    ["_faction", "", [""]]
];

if (_pos isEqualTo []) exitWith {
     ERROR("pos parameter cannot be empty");
     false;
};

private _bunkerTower = "Land_BagBunker_Tower_F";

private _climate = [] call den_fnc_worldToClimate;
if (_climate == "Tropic" || _climate == "Wood") then {
    _bunkerTower = "Land_HBarrier_01_tower_green_F";
};

private _objs = [
	["Land_CncBarrier_F",[-4.10803,-0.330566,0],181.108,1,0,[],"","",true,false],
	["RoadBarrier_F",[-4.39307,-2.39038,-0.00399923],177.317,1,0.0159713,[],"","",true,false],
	["FlagPole_F",[-5.43176,0.761475,0],0,1,0,[],"","",true,false],
	["Land_CncBarrier_F",[-6.74866,-0.289551,0],181.326,1,0,[],"","",true,false],
	["Land_CncBarrier_F",[6.78259,-0.836426,0],181.409,1,0,[],"","",true,false],
	["RoadBarrier_F",[7.01086,-2.70459,-0.00399923],184.508,1,0.0168094,[],"","",true,false],
	["Land_CncBarrier_F",[9.42322,-0.873535,0],181.185,1,0,[],"","",true,false],
	[_bunkerTower,[8.56775,5.39307,0],2.53815,1,0,[],"","",true,false],
	["Land_CncBarrier_F",[11.7006,-0.0161133,0],138.856,1,0,[],"","",true,false],
	["Land_CncBarrier_F",[12.7103,2.24658,0],90.833,1,0,[],"","",true,false],
    ["O_HMG_01_high_F",[7.797,4.08789,2.78],186.362,1,0,[],"","",true,false]
];

[_pos, _dir - 180, _objs] call BIS_fnc_objectsMapper;

if (_faction != "") then {
    private _flagTexture = getText (missionConfigFile >> "CfgFactions" >> _faction >> "flagTexture");
    private _flagPole    = nearestObject [_pos, "FlagPole_F"];
    _flagPole setFlagTexture _flagTexture;
};

true;