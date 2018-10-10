/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike
*/

if (!isMultiplayer) exitWith {
    cutText ["","BLACK", .5];
    [] spawn den_fnc_initSinglePlayer;
};

waitUntil {!isNil "den_initServerDone"};

cutText ["","BLACK OUT"];
[] spawn {
    waitUntil {!visibleMap};
    cutText ["","BLACK IN", 5];
    if (isNil "den_ao" || den_ao == "") then {
        ["There was an error generating the AO. Please restart the mission.","Error",true,false] spawn BIS_fnc_guiMessage;
    };
};
if (isNil "den_ao" || den_ao == "") exitWith {
    player createDiaryRecord ["Diary", ["Error", "There was an error generating the AO.  Please restart the mission."]];
};

0 setOvercast den_overcast;

[den_mission, den_ao, den_falcon, den_faction] call den_fnc_initMissionLocal;

true;