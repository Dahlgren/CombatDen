/*
    Copyright (C) 2020 Dahlgren

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
*/

class SFP : Faction
{
    addOn       = "SFP";
    ammoBox     = "sfp_ammocrate_556";
    cargoBox    = "sfp_ammobox_container";
    era         = ERA_MODERN;
    flagTexture = "\sfp_config\data\flag_sweden_co.paa";
    name        = "Swedish Forces";
    patches[]   = {
        "SwedishForcesPack"
    };
    side = SIDE_BLUFOR;

    class Arsenal : Arsenal
    {
        class Base : Base
        {
            grenades[] += {
                "SmokeShell",
                "SmokeShellBlue",
                "SmokeShellGreen",
                "SmokeShellOrange",
                "SmokeShellPurple",
                "SmokeShellRed",
                "SmokeShellYellow"
                "sfp_handgrenade_shgr07",
                "sfp_handgrenade_shgr2000",
                "sfp_handgrenade_shgr56"
            };
            mags[] = {
                "sfp_10Rnd_127x99_ag90",

                "sfp_17Rnd_9x19_Mag",

                "sfp_20Rnd_762x51_ak4",
                "sfp_20Rnd_762x51_ak4_ap",
                "sfp_20Rnd_762x51_ak4_irtracer",
                "sfp_20Rnd_762x51_ak4_tracer",

                "sfp_30Rnd_556x45_Stanag",
                "sfp_30Rnd_556x45_Stanag_irtracer",
                "sfp_30Rnd_556x45_Stanag_irtracer_plastic",
                "sfp_30Rnd_556x45_Stanag_plastic",
                "sfp_30Rnd_556x45_Stanag_tracer",
                "sfp_30Rnd_556x45_Stanag_tracer_plastic",

                "sfp_50Rnd_762x51_ksp58",
                "sfp_50Rnd_762x51_ksp58_ap",
                "sfp_50Rnd_762x51_ksp58_irTracer",

                "sfp_200Rnd_556x45_ksp90",
                "sfp_200Rnd_556x45_ksp90_irtracer"

                "sfp_9Rnd_762x51_psg90",
                "sfp_9Rnd_762x51_psg90_prick",
                "sfp_9Rnd_762x51_psg90_tracer"
            };
            weapons[] = {
                "sfp_ag90",
                "sfp_ak4c",
                "sfp_ak4d",
                "sfp_ak5c",
                "sfp_ak5c_alt",
                "sfp_ak5c_m203",
                "sfp_ak5dmk2",
                "sfp_ksp58B2",
                "sfp_ksp90b",
                "sfp_ksp90c",
                "sfp_p88",
                "sfp_psg90"
            };
            launchers[] = {
                "sfp_grg86",
                "sfp_pskott86",
                "sfp_rb57"
            };
            Nvg[] = {
                "NVGoggles"
            };
            sights[] = {
                "sfp_optic_3x_aimpoint",
                "sfp_optic_aimpoint",
                "sfp_optic_aimpoint_t1",
                "sfp_optic_aimpoint_twist",
                "sfp_optic_fcs13",
                "sfp_optic_gcgm",
                "sfp_optic_grg",
                "sfp_optic_kikarsikte09_4x",
                "sfp_optic_kikarsikte90b_10x"
            };
            attachments[] = {
                "sfp_dbal2",
                "sfp_tlr2"
            };
            backpacks[] = {
                "sfp_backpack_grg_loader",
                "sfp_backpack_lk35",
                "sfp_backpack_sjvv9",
                "sfp_backpack_stridssack08",
                "sfp_backpack_stridssack2000"
            };
            vests[] = {
                "sfp_kroppsskydd12", 
                "sfp_kroppsskydd12_at",
                "sfp_kroppsskydd12_crew",
                "sfp_kroppsskydd12_gl",
                "sfp_kroppsskydd12_holster",
                "sfp_kroppsskydd12_medic",
                "sfp_kroppsskydd12_mg",
                "sfp_kroppsskydd12_tl"
            };
        };
        class SemiArid : Base {};
        class Arid     : Base {};
        class Tropic   : Base {};
        class Wood     : Base {};
        class Winter   : Base {};
    };

    class Vehicle
    {
        class SemiArid
        {
            heloTransport      = "sfp_hkp9";
            heloTransportLarge = "sfp_hkp16_ffv";
            heloCargo          = "sfp_hkp4_2015";
            truckAssault       = "sfp_tgb16_ksp58";
            truckSupplyAmmo    = "sfp_tgb40_ammo";
            truckSupplyCargo   = "sfp_tgb20";
            truckSupplyFuel    = "sfp_tgb40_fuel";
        };
        class Arid   : SemiArid
        {
            truckAssault     = "sfp_tgb16_desert";
        };
        class Tropic : SemiArid {};
        class Wood   : SemiArid {};
        class Winter : SemiArid {};
    };


#define UK3CB_BAF_NVG  "UK3CB_BAF_HMNVS"

    class Group : Group
    {
        accLight = "acc_flashlight";

        class Couple : Couple {};
        class Single : Single {};
        class Squad  : Squad {};
        class Team   : Team {};
        class Triple : Triple {};

        class SemiArid
        {
            class TruckCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
            };
            class HeloPilot : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_helipilot";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_helipilot";
                };
            };
            class HeloCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_helipilot";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_helipilot";
                };
            };
            class Pilot : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_pilot";
                };
            };
             class Sentry : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
            };
            class FireTeam : Team
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_squadleader";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_automaticrifleman_ksp90";
                };
                class Unit2 : Unit2
                {
                    vehicle = "sfp_m90w_at_specialist_pskott86";
                };
                class Unit3 : Unit3
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
            };
            class AssaultSquad : Squad
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90w_squadleader";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_automaticrifleman_ksp90";
                };
                class Unit2 : Unit2
                {
                    vehicle = "sfp_m90w_automaticrifleman_ksp90";
                };
                class Unit3 : Unit3
                {
                    vehicle = "sfp_m90w_gr";
                };
                class Unit4 : Unit4
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
                class Unit5 : Unit5
                {
                    vehicle = "sfp_m90w_at_specialist_pskott86";
                };
                class Unit6 : Unit6
                {
                    vehicle = "sfp_m90w_at_specialist_pskott86";
                };
                class Unit7 : Unit7
                {
                    vehicle = "sfp_m90w_medic";
                };
            };
            class ReconSquad : Squad
            {
                nvg = UK3CB_BAF_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_SC_MTP_BPT_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_MGLMG_MTP_BPT_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_MGLMG_MTP_BPT_RM";
                };
                class Unit3 : Unit3
                {
                    vehicle = "UK3CB_BAF_Pointman_MTP_BPT_RM";
                };
                class Unit4 : Unit4
                {
                    vehicle = "UK3CB_BAF_Pointman_MTP_BPT_RM";
                };
                class Unit5 : Unit5
                {
                    vehicle = "UK3CB_BAF_Pointman_MTP_BPT_RM";
                };
                class Unit6 : Unit6
                {
                    vehicle = "UK3CB_BAF_Pointman_MTP_BPT_RM";
                };
                class Unit7 : Unit7
                {
                    vehicle = "UK3CB_BAF_Medic_MTP_BPT_RM";
                };
            };
            class ReconTeam : Team
            {
                nvg = UK3CB_BAF_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_SC_MTP_BPT_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_MGLMG_MTP_BPT_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_Pointman_MTP_BPT_RM";
                };
                class Unit3 : Unit3
                {
                    vehicle = "UK3CB_BAF_Pointman_MTP_BPT_RM";
                };
            };
            class MotorizedHmg : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_tgb16_rws";
                };
            };
            class MotorizedTeam : Triple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_tgb16";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
                class Unit2 : Unit2
                {
                    vehicle = "sfp_m90w_rifleman_ak5";
                };
            };
            class MotorizedAssault : AssaultSquad
            {
                type = "motorized";

                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8
                {
                    position[] = {-20,-20,0};
                    rank = "LIEUTENANT";
                    vehicle = "sfp_tgb16_rws";
                };
            };
        };
        class Arid : SemiArid
        {
           class TruckCrew : TruckCrew
            {
                class Unit0 : Unit0 {
                    vehicle = "sfp_m90d_rifleman_ak5";
                };
                class Unit1 : Unit1 {
                    vehicle = "sfp_m90d_rifleman_ak5";
                };
            };
            class HeloPilot : HeloPilot
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloCrew : HeloCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class Pilot : Pilot
            {
                class Unit0 : Unit0 {};
            };
            class Sentry : Sentry
            {
                class Unit0 : Unit0 {
                    vehicle = "sfp_m90d_rifleman_ak5";
                };
                class Unit1 : Unit1 {
                    vehicle = "sfp_m90d_rifleman_ak5";
                };
            };
            class FireTeam : Team
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90d_squadleader";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90d_automaticrifleman_ksp90";
                };
                class Unit2 : Unit2
                {
                    vehicle = "sfp_m90d_at_specialist_pskott86";
                };
                class Unit3 : Unit3
                {
                    vehicle = "sfp_m90d_rifleman_ak5";
                };
            };
            class AssaultSquad : Squad
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90d_squadleader";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90d_automaticrifleman_ksp90";
                };
                class Unit2 : Unit2
                {
                    vehicle = "sfp_m90d_automaticrifleman_ksp90";
                };
                class Unit3 : Unit3
                {
                    vehicle = "sfp_m90d_gr";
                };
                class Unit4 : Unit4
                {
                    vehicle = "sfp_m90d_rifleman_ak5";
                };
                class Unit5 : Unit5
                {
                    vehicle = "sfp_m90d_at_specialist_pskott86";
                };
                class Unit6 : Unit6
                {
                    vehicle = "sfp_m90d_at_specialist_pskott86";
                };
                class Unit7 : Unit7
                {
                    vehicle = "sfp_m90d_medic";
                };
            };
            class ReconSquad : ReconSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconTeam : ReconTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : MotorizedHmg
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_tgb16_desert";
                };
            };
            class MotorizedTeam : MotorizedTeam
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_tgb16_desert";
                };
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
            };
            class MotorizedAssault : MotorizedAssault
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8 : Unit8
                {
                    vehicle = "sfp_tgb16_desert";
                };
            };
        };
        class Tropic : SemiArid
        {
            class TruckCrew : TruckCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloPilot : HeloPilot
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloCrew  : HeloCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class Pilot : Pilot
            {
                class Unit0 : Unit0 {};
            };
            class Sentry : Sentry
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class FireTeam : FireTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class AssaultSquad : AssaultSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconSquad : ReconSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconTeam : ReconTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : MotorizedHmg
            {
                class Unit0 : Unit0 {};
            };
            class MotorizedTeam : MotorizedTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
            };
            class MotorizedAssault : MotorizedAssault
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8 : Unit8 {};
            };
        };
        class Wood : SemiArid
        {
            class TruckCrew : TruckCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloPilot : HeloPilot
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class HeloCrew  : HeloCrew
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class Pilot : Pilot
            {
                class Unit0 : Unit0 {};
            };
            class Sentry : Sentry
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
            };
            class FireTeam : FireTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class AssaultSquad : AssaultSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconSquad : ReconSquad
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
            };
            class ReconTeam : ReconTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
            };
            class MotorizedHmg : MotorizedHmg
            {
                class Unit0 : Unit0 {};
            };
            class MotorizedTeam : MotorizedTeam
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
            };
            class MotorizedAssault : MotorizedAssault
            {
                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8 : Unit8 {};
            };
        };
        class Winter
        {
            class TruckCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90s_rifleman_ak5";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90s_rifleman_ak5";
                };
            };
            class HeloPilot : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90s_pilot";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90s_pilot";
                };
            };
            class HeloCrew : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90s_pilot";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90s_pilot";
                };
            };
            class Pilot : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90s_pilot";
                };
            };
             class Sentry : Couple
            {
                class Unit0 : Unit0
                {
                    vehicle = "sfp_m90s_rifleman_ak5";
                };
                class Unit1 : Unit1
                {
                    vehicle = "sfp_m90s_rifleman_ak5";
                };
            };
            class FireTeam : Team
            {
                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_FT_Arctic_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_MGLMG_Arctic_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_LAT_ILAW_Arctic_RM";
                };
                class Unit3 : Unit3
                {
                    vehicle = "sfp_m90s_rifleman_ak5";
                };
            };
            class AssaultSquad : Squad
            {
                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_FT_Arctic_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_MGLMG_Arctic_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_MGLMG_Arctic_RM";
                };
                class Unit3 : Unit3
                {
                    vehicle = "UK3CB_BAF_Grenadier_Arctic_RM";
                };
                class Unit4 : Unit4
                {
                    vehicle = "sfp_m90s_rifleman_ak5";
                };
                class Unit5 : Unit5
                {
                    vehicle = "UK3CB_BAF_LAT_ILAW_Arctic_RM";
                };
                class Unit6 : Unit6
                {
                    vehicle = "UK3CB_BAF_LAT_ILAW_Arctic_RM";
                };
                class Unit7 : Unit7
                {
                    vehicle = "UK3CB_BAF_Medic_Arctic_RM";
                };
            };
            class ReconSquad : Squad
            {
                nvg = UK3CB_BAF_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_SC_Arctic_BPT_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_MGLMG_Arctic_BPT_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_MGLMG_Arctic_BPT_RM";
                };
                class Unit3 : Unit3
                {
                    vehicle = "UK3CB_BAF_Pointman_Arctic_BPT_RM";
                };
                class Unit4 : Unit4
                {
                    vehicle = "UK3CB_BAF_Pointman_Arctic_BPT_RM";
                };
                class Unit5 : Unit5
                {
                    vehicle = "UK3CB_BAF_Pointman_Arctic_BPT_RM";
                };
                class Unit6 : Unit6
                {
                    vehicle = "UK3CB_BAF_Pointman_Arctic_BPT_RM";
                };
                class Unit7 : Unit7
                {
                    vehicle = "UK3CB_BAF_Medic_Arctic_BPT_RM";
                };
            };
            class ReconTeam : Team
            {
                nvg = UK3CB_BAF_NVG;

                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_SC_Arctic_BPT_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_MGLMG_Arctic_BPT_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_Pointman_Arctic_BPT_RM";
                };
                class Unit3 : Unit3
                {
                    vehicle = "UK3CB_BAF_Pointman_Arctic_BPT_RM";
                };
            };
            class MotorizedHmg : Single
            {
                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_Jackal2_L2A1_W_MTP_RM";
                };
            };
            class MotorizedTeam : Triple
            {
                class Unit0 : Unit0
                {
                    vehicle = "UK3CB_BAF_Jackal2_L2A1_W_Arctic_RM";
                };
                class Unit1 : Unit1
                {
                    vehicle = "UK3CB_BAF_Rifleman_Arctic_RM";
                };
                class Unit2 : Unit2
                {
                    vehicle = "UK3CB_BAF_Rifleman_Arctic_RM";
                };
            };
            class MotorizedAssault : AssaultSquad
            {
                type = "motorized";

                class Unit0 : Unit0 {};
                class Unit1 : Unit1 {};
                class Unit2 : Unit2 {};
                class Unit3 : Unit3 {};
                class Unit4 : Unit4 {};
                class Unit5 : Unit5 {};
                class Unit6 : Unit6 {};
                class Unit7 : Unit7 {};
                class Unit8
                {
                    position[] = {-20,-20,0};
                    rank = "LIEUTENANT";
                    vehicle = "UK3CB_BAF_Jackal2_L2A1_W_MTP_RM";
                };
            };
        };
    };

#define SFP_AUTORIFLE_556_MAG_COUNT    3
#define SFP_AT_MAG_COUNT              11
#define SFP_GRENADIRE_MAG_COUNT       11
#define SFP_MARKSMAN_MAG_COUNT        10
#define SFP_MEDIC_MAG_COUNT           11
#define SFP_RIFLEMAN_MAG_COUNT        11

    class Loadout : Loadout
    {
        class Base : Base
        {
            aceBinoculars = "ACE_Vector";
            aceNvg        = "ACE_NVG_Wide";

            handgun    = "sfp_p88";
            binoculars = "Binocular";
            headgear   = "sfp_m90w_helmet";
            rifleSight = "sfp_optic_aimpoint";
            nvg        = "NVGoggles";
            rifleLight = "sfp_ak5c_aimpoint_dbal2";
            primaryMag = "sfp_30Rnd_556x45_Stanag_plastic";

            class Uniform : Uniform
            {
                type = "sfp_m90w_uniform";

                items[] += {
                    "sfp_17Rnd_9x19_Mag",
                    "sfp_17Rnd_9x19_Mag"
                };
            };
            class Vest : Vest
            {
                type = "sfp_kroppsskydd12";
            };
            class Backpack : Backpack
            {
                type = "sfp_backpack_stridssack2000";
            };
            class LinkedItems : LinkedItems {};
        };
        class RiflemanBase : Base
        {
            unit            = "sfp_m90w_rifleman_ak5";
            primaryMagCount = SFP_RIFLEMAN_MAG_COUNT;

            class Uniform : Uniform {};

            class Vest : Vest
            {
               items[] += {
                    "HandGrenade",
                    "HandGrenade",
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen"
                };
            };
            class Backpack : Backpack
            {
                items[] += {
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade"
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class GrenadierBase : RiflemanBase
        {
            unit              = "sfp_m90w_gr";
            primaryMagCount   = SFP_GRENADIER_MAG_COUNT;
            secondaryMag      = "UK3CB_BAF_1Rnd_HE_Grenade_Shell";
            secondaryMagCount = 10;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
                type = "sfp_kroppsskydd12_gl";

                items[] += {
                    "UK3CB_BAF_1Rnd_Smoke_Grenade_shell",
                };
            };
            class Backpack    : Backpack {};
            class LinkedItems : LinkedItems {};
        };
        class AutorifleBase : Base
        {
            unit            = "sfp_m90w_automaticrifleman_ksp90";
            rifleBipod      = "";
            primaryMag      = "sfp_200Rnd_556x45_ksp90";
            primaryMagCount = SFP_AUTORIFLE_556_MAG_COUNT;

            class Uniform  : Uniform {};
            class Vest     : Vest {
                type = "sfp_kroppsskydd12_mg";

                items[] += {
                   "HandGrenade",
                   "HandGrenade",
                   "UK3CB_BAF_SmokeShellGreen",
                   "UK3CB_BAF_SmokeShellGreen"
                };
            };
            class Backpack : Backpack
            {
                type = "sfp_backpack_stridssack2000_ksp90";
            };
            class LinkedItems : LinkedItems {};
        };
        class MarksmanBase : Base
        {
            unit            = "sfp_m90w_sniper";

            rifleSight      = "sfp_optic_kikarsikte90b_10x";
            rifleBipod      = "";
            primaryMagCount = SFP_MARKSMAN_MAG_COUNT;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
                type = "sfp_kroppsskydd12_holster";

                items[] += {
                    "HandGrenade",
                    "HandGrenade",
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen"
                };
            };
            class Backpack : MarksmanBackpack
            {
                type = "UK3CB_BAF_B_Bergen_MTP_Rifleman_L_A";
            };
            class LinkedItems : LinkedItems {};
        };
        class MedicBase : Base
        {
            unit            = "sfp_m90w_medic";
            primaryMagCount = SFP_MEDIC_MAG_COUNT;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
                type = "sfp_kroppsskydd12_medic";

                items[] += {
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen",
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade",
                    "HandGrenade"
                };
            };
            class Backpack : MedicBackpack
            {
                type = "sfp_backpack_sjvv9";
            };
            class LinkedItems : LinkedItems {};
        };
        class AtBase : RiflemanBase
        {
            primaryMagCount = SFP_AT_MAG_COUNT;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
                type = "sfp_kroppsskydd12_at";

                items[] += {
                   "HandGrenade",
                   "HandGrenade",
                   "HandGrenade"
               };
            };
            class LinkedItems : LinkedItems {};
        };
        class EodBase : Base
        {
            unit            = "sfp_m90w_explosive_specialist";
            primaryMagCount = SFP_RIFLEMAN_MAG_COUNT;

            class Uniform : Uniform {};
            class Vest    : Vest
            {
               items[] += {
                    "HandGrenade",
                    "HandGrenade",
                    "UK3CB_BAF_SmokeShellGreen",
                    "UK3CB_BAF_SmokeShellGreen"
                };
            };
            class Backpack : Backpack
            {
                type = "sfp_backpack_stridssack2000_explosives";

                aceEodItems[] += {
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "ACE_M14",
                    "ACE_M14",
                    "ACE_M14",
                    "ACE_M14",
                    "ACE_M14",
                    "ACE_M14"
                };
                noAceEdoItems[] += {
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag",
                    "DemoCharge_Remote_Mag"
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class EngineerBase : RiflemanBase
        {
            unit = "sfp_m90w_engineer";

            class Uniform  : Uniform {};
            class Vest     : Vest {};

            class Backpack : Backpack
            {
                type = "UK3CB_BAF_B_Bergen_MTP_Sapper_L_A";

                items[] += {
                    "ToolKit"
                };
            };
            class LinkedItems : LinkedItems {};
        };
        class SemiArid
        {
            class Rifleman
            {
                role = "Rifleman";

                class Ak5C : RiflemanBase
                {
                    type    = "Ak5C";
                    rifle   = "sfp_ak5c";

                    default = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Autorifleman
            {
                role = "Autorifleman";

                class Ksp90 : AutorifleBase
                {
                    type    = "Ksp90";
                    rifle   = "sfp_ksp90c";
                    default = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Grenadier
            {
                role = "Grenadier";

                class Ak5C : GrenadierBase
                {
                    type    = "Ak5C GL";
                    rifle   = "sfp_ak5c_m203";
                    default = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class SquadLeader : Grenadier
            {
                role = "Squad Leader";

                class Ak5C : Ak5C
                {
                    unit = "sfp_m90w_squadleader";

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Marksman
            {
                role = "Marksman";

                class Psg90 : MarksmanBase
                {
                    type       = "Psg90";
                    rifle      = "sfp_psg90";
                    primaryMag = "sfp_9Rnd_762x51_psg90";
                    default    = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Medic
            {
                role = "Medic";

                class Ak5C : MedicBase
                {
                    type  = "Ak5C";
                    rifle = "sfp_ak5c";
                    default = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class At
            {
                role = "Anti-Tank";

                class Pskott86 : AtBase
                {
                    type     = "Pskott86";
                    launcher = "sfp_pskott86";
                    default  = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Rb57 : AtBase
                {
                    type     = "Rb57";
                    launcher = "sfp_rb57";

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Grg86 : AtBase
                {
                    type     = "GRG86";
                    launcher = "sfp_grg86";

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Eod
            {
                role = "EOD";

                class Ak5C : EodBase
                {
                    type    = "Ak5C";
                    rifle   = "sfp_ak5c";
                    default = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Engineer
            {
                role = "Engineer";

                class Ak5C : EngineerBase
                {
                    type    = "Ak5C";
                    rifle   = "sfp_ak5c";
                    default = 1;

                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
        };
        class Arid : SemiArid
        {
            class Rifleman : Rifleman
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90d_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class SquadLeader : SquadLeader
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Autorifleman : Autorifleman
            {
                class Ksp90 : Ksp90
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Grenadier : Grenadier
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Marksman : Marksman
            {
                class Psg90 : Psg90
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Medic : Medic
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class At : At
            {
                class Pskott86 : Pskott86
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Rb57 : Rb57
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Grg86 : Grg86
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Eod : Eod
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Engineer : Engineer
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
        };
        class Tropic : SemiArid
        {
            headgear   = "sfp_m90w_booniehat";

            class Rifleman : Rifleman
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class SquadLeader : SquadLeader
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Autorifleman : Autorifleman
            {
                class Ksp90 : Ksp90
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Grenadier : Grenadier
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Marksman : Marksman
            {
                class Psg90 : Psg90
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Medic : Medic
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class At : At
            {
                class Pskott86 : Pskott86
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Rb57 : Rb57
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Grg86 : Grg86
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Eod : Eod
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Engineer : Engineer
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform_fs18";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
        };
        class Wood : SemiArid
        {
            class Rifleman : Rifleman
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class SquadLeader : SquadLeader
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Autorifleman : Autorifleman
            {
                class Ksp90 : Ksp90
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Grenadier : Grenadier
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Marksman : Marksman
            {
                class Psg90 : Psg90
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Medic : Medic
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class At : At
            {
                class Pskott86 : Pskott86
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Rb57 : Rb57
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Grg86 : Grg86
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Eod : Eod
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Engineer : Engineer
            {
                class Ak5C : Ak5C
                {
                    class Uniform     : Uniform {
                        type = "sfp_m90w_uniform";
                    };
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
        };
        class Winter : SemiArid
        {
            headgear   = "sfp_m90s_helmet";

            class Rifleman : Rifleman
            {
                class Ak5C : Ak5C
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class SquadLeader : SquadLeader
            {
                class Ak5C : Ak5C
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Autorifleman : Autorifleman
            {
                class Ksp90 : Ksp90
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Grenadier : Grenadier
            {
                class Ak5C : Ak5C
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Marksman : Marksman
            {
                class Psg90 : Psg90
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Medic : Medic
            {
                class Ak5C : Ak5C
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class At : At
            {
                class Pskott86 : Pskott86
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Rb57 : Rb57
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
                class Grg86 : Grg86
                {
                    class Uniform     : Uniform {};
                    class Vest        : Vest {};
                    class Backpack    : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
            class Eod : Eod
            {
                class Ak5C : Ak5C
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack
                    {
                        type = "UK3CB_BAF_B_Kitbag_Arctic";
                    };
                    class LinkedItems : LinkedItems {};
                };
            };
            class Engineer : Engineer
            {
                class Ak5C : Ak5C
                {
                    class Uniform : Uniform
                    {
                        type = "sfp_m90s_uniform";
                    };
                    class Vest : Vest {};
                    class Backpack : Backpack {};
                    class LinkedItems : LinkedItems {};
                };
            };
        };
    };
};
