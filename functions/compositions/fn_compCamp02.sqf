/*
    Copyright (C) 2019 D. Ottavio

    This program is free software: you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program.  If not, see
    <https://www.gnu.org/licenses/>.

    Description:

    Spawn a pow camp composition.

    Parameter(s):

    0: ARRAY - Position

    1: NUMBER - Direction

    2: STRING - faction

    Returns: true
*/
#include "..\..\macros.hpp"

params [
    ["_pos", [], [[]], [2,3]],
    ["_dir", 0,  [0]],
    ["_faction", "",   [""]]
];

if (_pos isEqualTo []) exitWith {
    ERROR("pos parameter cannot be empty");
    false;
};
if (_faction == "") exitWith {
    ERROR("faction parameter cannot be empty");
    false;
};

private _bagFenceRound = "Land_BagFence_Round_F";

private _climate = DEN_CLIMATE;
if (_climate == "Tropic" || _climate == "Wood") then {
    _bagFenceRound = "Land_BagFence_01_round_green_F";
};

private _objs = [
	["CamoNet_BLUFOR_open_F",[-0.736328,-0.354492,0],0,1,0,[],"net_1","",true,false],
	["Land_CampingTable_small_F",[0.363037,2.01782,0.00259924],0.00417018,1,0,[],"","",true,false],
	["Land_Map_blank_F",[0.236938,2.06641,0.813],359.998,1,0,[],"","",true,false],
	["BloodPool_01_Large_New_F",[-2.005,-1.48389,0],0,1,0,[],"","",true,false],
	["MedicalGarbage_01_FirstAidKit_F",[-2.94604,1.72314,0.813],0,1,0,[],"","",true,false],
	["Land_CampingTable_small_F",[-3.18835,1.52881,0.00260258],0.000636725,1,0,[],"","",true,false],
	["MedicalGarbage_01_Bandage_F",[-3.26074,1.33423,0.813],0,1,0,[],"","",true,false],
	["Land_Bandage_F",[-3.29333,1.60254,0.813],359.914,1,0,[],"","",true,false],
	["Land_Bandage_F",[-3.2688,1.7605,0.813],359.918,1,0,[],"","",true,false],
	["MedicalGarbage_01_Bandage_F",[-3.53369,1.27979,0.813],0,1,0,[],"","",true,false],
	["Land_Razorwire_F",[-1.79236,6.23291,-2.38419e-006],358.489,1,0,[],"","",true,false],
	["Land_Razorwire_F",[-2.38623,-6.27271,-2.38419e-006],1.26291,1,0,[],"","",true,false],
	[_bagFenceRound,[8.43384,2.3313,-0.00130129],297.741,1,0,[],"","",true,false],
	[_bagFenceRound,[7.80896,5.40479,-0.00130129],216.319,1,0,[],"","",true,false],
	[_bagFenceRound,[-9.34314,-1.26636,-0.00130129],117.225,1,0,[],"","",true,false],
	[_bagFenceRound,[-8.69055,-4.33398,-0.00130129],35.8032,1,0,[],"","",true,false]
];

private _era = DEN_ERA(_faction);

if (_era > ERA_WW2) then {
    _objs pushBack ["Land_FMradio_F",[0.695068,2.21753,0.813],0.0186814,1,0,[],"","",true,false];
    _objs pushBack ["Land_CampingChair_V2_F",[2.16345,1.68433,9.05991e-006],0.00596005,1,0,[],"","",true,false];
    _objs pushBack ["Land_CampingChair_V2_F",[2.87024,-1.69214,5.24521e-006],113.268,1,0,[],"","",true,false];
    _objs pushBack ["MedicalGarbage_01_Gloves_F",[-3.49146,1.64087,0.813],0,1,0,[],"","",true,false];
};

if (_era >= ERA_MODERN) then {
    _objs pushBack ["Land_PortableLongRangeRadio_F",[0.620361,1.86938,0.813],359.978,1,0,[],"","",true,false];
    _objs pushBack ["Land_PortableLongRangeRadio_F",[0.66748,2.09155,0.813],359.985,1,0,[],"","",true,false];
};

[_pos, _dir, _objs] call BIS_fnc_objectsMapper;

true;
