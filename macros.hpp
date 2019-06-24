/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike
*/
#define PREFIX    DEN
#define COMPONENT mission

#include "\x\cba\addons\main\script_macros_common.hpp"

// true if a addon/mod is loaded
#define DEN_HAS_ADDON(addon) (isClass (configfile >> "CfgPatches" >> addon))

// true if a faction has a transport helicopter
#define DEN_FACTION_HAS_TRANSPORT_HELO(faction)\
((getText (missionConfigFile >> "CfgFactions" >> faction >> "Vehicle" >> (call den_fnc_worldToClimate) >> "heloTransport")) != "")
