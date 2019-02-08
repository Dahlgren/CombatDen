/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike
*/

class CfgArsenal
{
    class Nato
    {
        class ArsenalBase
        {
            grenades[] = {
                "Chemlight_blue",
                "Chemlight_green",
                "Chemlight_red",
                "Chemlight_yellow",
                "SmokeShellBlue",
                "SmokeShellGreen",
                "SmokeShellOrange",
                "SmokeShellPurple",
                "SmokeShellRed",
                "SmokeShellYellow",
                "SmokeShell",
                "HandGrenade"
            };
            aceGrenades[] = {
                "ACE_M14",
                "ACE_M84",
                "ACE_HandFlare_Green",
                "ACE_HandFlare_White",
                "ACE_HandFlare_Yellow",
                "ACE_HandFlare_Red",
                "ACE_Chemlight_HiOrange",
                "ACE_Chemlight_HiRed",
                "ACE_Chemlight_HiWhite",
                "ACE_Chemlight_HiYellow",
                "ACE_Chemlight_IR",
                "ACE_Chemlight_Orange",
                "ACE_Chemlight_White"
            };
            explosives[] = {
                "DemoCharge_Remote_Mag",
                "SatchelCharge_Remote_Mag",
            };
            misc[] = {
                "ACE_fieldDressing",
                "ACE_elasticBandage",
                "ACE_SpraypaintBlack",
                "ACE_SpraypaintBlue",
                "ACE_SpraypaintGreen",
                "ACE_SpraypaintRed",
                "ACE_adenosine",
                "ACE_atropine",
                "ACE_bloodIV",
                "ACE_bloodIV_250",
                "ACE_bloodIV_500",
                "ACE_quikclot",
                "ACE_CableTie",
                "ACE_EarPlugs",
                "ACE_EntrenchingTool",
                "ACE_epinephrine",
                "ACE_HuntIR_monitor",
                "ACE_Flashlight_XL50",
                "ACE_Flashlight_MX991",
                "ACE_Flashlight_KSF1",
                "ACE_MapTools",
                "ACE_microDAGR",
                "ACE_DAGR",
                "ACE_morphine",
                "ACE_personalAidKit",
                "ACE_plasmaIV",
                "ACE_plasmaIV_250",
                "ACE_plasmaIV_500",
                "ACE_salineIV",
                "ACE_salineIV_250",
                "ACE_salineIV_500",
                "ACE_surgicalKit",
                "ACE_tourniquet",
                "ItemMap",
                "ItemRadio",
                "ItemCompass",
                "ItemWatch"
            };
            mags[] = {
                "30Rnd_65x39_caseless_mag",
                "ACE_30Rnd_65x39_caseless_mag_Tracer_Dim",
                "30Rnd_65x39_caseless_mag_Tracer",
                "100Rnd_65x39_caseless_mag",
                "ACE_100Rnd_65x39_caseless_mag_Tracer_Dim",
                "100Rnd_65x39_caseless_mag_Tracer",
                "30Rnd_65x39_caseless_mag",
                "ACE_30Rnd_65x39_caseless_mag_Tracer_Dim",
                "16Rnd_9x21_Mag",
                "30Rnd_9x21_Mag",
                "3Rnd_UGL_FlareGreen_F",
                "3Rnd_UGL_FlareCIR_F",
                "3Rnd_UGL_FlareRed_F",
                "3Rnd_UGL_FlareWhite_F",
                "3Rnd_UGL_FlareYellow_F",
                "3Rnd_SmokeBlue_Grenade_shell",
                "3Rnd_SmokeGreen_Grenade_shell",
                "3Rnd_SmokeOrange_Grenade_shell",
                "3Rnd_SmokePurple_Grenade_shell",
                "3Rnd_SmokeRed_Grenade_shell",
                "3Rnd_Smoke_Grenade_shell",
                "3Rnd_SmokeYellow_Grenade_shell",
                "3Rnd_HE_Grenade_shell",
                "1Rnd_HE_Grenade_shell",
                "UGL_FlareGreen_F",
                "UGL_FlareCIR_F",
                "UGL_FlareRed_F",
                "UGL_FlareWhite_F",
                "UGL_FlareYellow_F",
                "ACE_HuntIR_M203",
                "1Rnd_SmokeBlue_Grenade_shell",
                "1Rnd_SmokeGreen_Grenade_shell",
                "1Rnd_SmokeOrange_Grenade_shell",
                "1Rnd_SmokePurple_Grenade_shell",
                "1Rnd_SmokeRed_Grenade_shell",
                "1Rnd_Smoke_Grenade_shell",
                "1Rnd_SmokeYellow_Grenade_shell",
                "130Rnd_338_Mag",
                "20Rnd_762x51_Mag",
                "ACE_20Rnd_762x51_M118LR_Mag",
                "ACE_20Rnd_762x51_M993_AP_Mag",
                "ACE_20Rnd_762x51_Mk316_Mod_0_Mag",
                "ACE_20Rnd_762x51_Mk319_Mod_0_Mag",
                "ACE_20Rnd_762x51_Mag_SD",
                "ACE_20Rnd_762x51_Mag_Tracer_Dim",
                "ACE_20Rnd_762x51_Mag_Tracer",
                "150Rnd_762x54_Box",
                "150Rnd_762x54_Box_Tracer",
                "MRAWS_HE_F",
                "MRAWS_HEAT_F",
                "Titan_AA",
                "Titan_AP",
                "Titan_AT",
                "MRAWS_HE_F",
                "30Rnd_556x45_Stanag_green",
                "30Rnd_556x45_Stanag_red",
                "30Rnd_556x45_Stanag",
                "30Rnd_556x45_Stanag_Tracer_Green",
                "30Rnd_556x45_Stanag_Tracer_Red",
                "30Rnd_556x45_Stanag_Tracer_Yellow",
                "ACE_30Rnd_556x45_Stanag_M995_AP_mag",
                "ACE_30Rnd_556x45_Stanag_Mk262_mag",
                "ACE_30Rnd_556x45_Stanag_Mk318_mag",
                "ACE_30Rnd_556x45_Stanag_Tracer_Dim",
                "150Rnd_556x45_Drum_Mag_F",
                "150Rnd_556x45_Drum_Mag_Tracer_F"
            };
            weapons[] = {
                "LMG_Zafir_F",
                "hgun_P07_F",
                "srifle_EBR_F"
            };
            launchers[] = {
                "launch_NLAW_F",
            };
            nvg[] = {
                "ACE_NVG_Wide",
                "ACE_NVG_Gen4"
            };
            binoculars[] = {
                "Binocular",
                "ACE_Vector",
                "ACE_Yardage450",
            };
            sights[] = {
                "ACE_optic_Hamr_2D",
                "ACE_optic_SOS_2D",
                "optic_Holosight",
                "ACE_optic_LRPS_2D",
                "optic_Aco",
                "optic_Aco_smg",
                "optic_tws",
                "optic_tws_mg",
                "optic_NVS",
            };
            attachments[] = {
                "acc_flashlight",
                "ACE_acc_pointer_green",
                "ACE_acc_pointer_green_IR"
            };
            faceware[] = {
                "G_Bandanna_beast",
                "G_Bandanna_blk",
                "G_Bandanna_oli",
                "G_Combat",
                "G_Lowprofile",
                "G_Shades_Black",
                "G_Shades_Blue",
                "G_Shades_Green",
                "G_Shades_Red",
                "G_Tactical_Clear",
                "G_Tactical_Black"
            };
        };
        class SemiArid : ArsenalBase
        {
            aridSights[] = {
                "optic_AMS_snd",
                "optic_Holosight_F",
                "optic_ERCO_snd_F"
            };
            aridBipods[] = {
                "bipod_01_f_snd"
            };
            aridWeapons[] = {
                "arifle_MX_F",
                "arifle_MX_GL_F",
                "arifle_MX_SW_F",
                "arifle_MXC_F",
                "arifle_MXM_F",
                "srifle_DMR_03_tan_F",
                "arifle_SPAR_01_snd_F",
                "arifle_SPAR_02_snd_F",
                "arifle_SPAR_03_snd_F",
                "MMG_02_sand_F"
            };
            aridLaunchers[] = {
                "launch_B_Titan_F",
                "launch_B_Titan_short_F",
                "launch_MRAWS_sand_F"
            };
            aridVests[] = {
                "V_PlateCarrierGL_rgr",
                "V_PlateCarrier1_rgr",
                "V_PlateCarrier2_rgr",
                "V_PlateCarrierSpec_rgr"
            };
            aridBacpacks[] = {
                "B_AssaultPack_mcamo",
                "B_AssaultPack_rgr",
                "B_Bergen_mpt",
                "B_Kitbag_mcamo",
                "B_Kitbag_rgr"
            };
            aridHelmets[] = {
                "H_HelmetB"
            };
            aridUniforms[] = {
                "U_B_CombatUniform_mcam"
            };
            aridFaceware[] = {
                "G_Bandanna_tan",
                "G_Bandanna_khk"
            };
        };
        class Tropic : ArsenalBase
        {
            tropicSights[] = {
                "optic_AMS",
                "optic_Holosight_blk_F",
                "optic_ERCO_blk_F"
            };
            tropicBipods[] = {
                "bipod_01_F_blk"
            };
            tropicWeapons[] = {
                "arifle_MX_Black_F",
                "arifle_MX_GL_Black_F",
                "arifle_MX_SW_Black_F",
                "arifle_MXC_Black_F",
                "arifle_MXM_Black_F",
                "srifle_DMR_03_F",
                "arifle_SPAR_01_blk_F",
                "arifle_SPAR_02_blk_F",
                "arifle_SPAR_03_blk_F",
                "MMG_02_black_F"
            };
            tropicLaunchers[] = {
                "launch_B_Titan_tna_F",
                "launch_B_Titan_short_tna_F",
                "launch_MRAWS_green_F"
            };
            tropicVests[] = {
                "V_PlateCarrierGL_tna_F",
                "V_PlateCarrier1_tna_F",
                "V_PlateCarrier2_tna_F",
                "V_PlateCarrierSpec_tna_F"
            };
            tropicBackpacks[] = {
                "B_AssaultPack_tna_F",
                "B_Bergen_tna_F",
                "B_Kitbag_rgr"
            };
        };
        class Arid : SemiArid {};
        class Wood : SemiArid {};
    };
    class RhsUsmc : Nato
    {
        class ArsenalBase : ArsenalBase
        {
            grenades[] = {
                "Chemlight_blue",
                "Chemlight_green",
                "Chemlight_red",
                "Chemlight_yellow",
                "rhs_mag_an_m8hc",
                "rhs_mag_m18_green",
                "rhs_mag_m18_purple",
                "rhs_mag_m18_red",
                "rhs_mag_m18_yellow",
                "rhs_mag_m67",
                "rhs_mag_m69",
                "rhs_mag_mk3a2"
            };
            mags[] = {
                "rhs_mag_100Rnd_556x45_M855_cmag",
                "rhs_mag_100Rnd_556x45_M855_cmag_mixed",
                "rhs_mag_100Rnd_556x45_M855A1_cmag",
                "rhs_mag_100Rnd_556x45_M855A1_cmag_mixed",
                "rhs_mag_100Rnd_556x45_Mk262_cmag",
                "rhs_mag_100Rnd_556x45_Mk318_cmag",
                "rhsusf_100Rnd_762x51_m61_ap",
                "rhsusf_100Rnd_762x51_m62_tracer",
                "rhsusf_100Rnd_762x51",
                "rhsusf_100Rnd_762x51_m80a1epr",
                "rhsusf_100Rnd_762x51_m82_blank",
                "rhsusf_100Rnd_556x45_M200_soft_pouch",
                "rhsusf_100Rnd_556x45_M855_soft_pouch",
                "rhsusf_100Rnd_556x45_M855_mixed_soft_pouch",
                "rhsusf_100Rnd_556x45_soft_pouch",
                "rhsusf_100Rnd_556x45_mixed_soft_pouch",
                "rhsusf_10Rnd_762x51_m118_special_Mag",
                "rhsusf_10Rnd_762x51_m62_Mag",
                "rhsusf_10Rnd_762x51_m993_Mag",
                "rhsusf_mag_10Rnd_STD_50BMG_M33",
                "rhsusf_mag_10Rnd_STD_50BMG_mk211",
                "rhsusf_mag_15Rnd_9x19_FMJ",
                "rhsusf_mag_15Rnd_9x19_JHP",
                "rhsusf_mag_17Rnd_9x19_FMJ",
                "rhsusf_mag_17Rnd_9x19_JHP",
                "rhsusf_200rnd_556x45_M855_box",
                "rhsusf_200rnd_556x45_M855_mixed_box",
                "rhsusf_200Rnd_556x45_box",
                "rhsusf_200rnd_556x45_mixed_box",
                "rhsusf_200Rnd_556x45_M855_soft_pouch",
                "rhsusf_200Rnd_556x45_M855_mixed_soft_pouch",
                "rhsusf_200Rnd_556x45_soft_pouch",
                "rhsusf_200Rnd_556x45_mixed_soft_pouch",
                "rhsusf_20Rnd_762x51_m118_special_Mag",
                "rhsusf_20Rnd_762x51_m62_Mag",
                "rhsusf_20Rnd_762x51_m993_Mag",
                "rhsusf_20Rnd_762x51_SR25_m118_special_Mag",
                "rhsusf_20Rnd_762x51_SR25_m62_Mag",
                "rhsusf_20Rnd_762x51_SR25_m993_Mag",
                "rhs_mag_30Rnd_556x45_M855_PMAG_Tan",
                "rhs_mag_30Rnd_556x45_M855_PMAG",
                "rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan",
                "rhs_mag_30Rnd_556x45_M855A1_PMAG",
                "rhs_mag_30Rnd_556x45_M855_PMAG_Tan_Tracer_Red",
                "rhs_mag_30Rnd_556x45_M855_PMAG_Tracer_Red",
                "rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red",
                "rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",
                "rhs_mag_30Rnd_556x45_Mk262_PMAG_Tan",
                "rhs_mag_30Rnd_556x45_Mk262_PMAG",
                "rhs_mag_30Rnd_556x45_Mk318_PMAG_Tan",
                "rhs_mag_30Rnd_556x45_Mk318_PMAG",
                "rhs_mag_30Rnd_556x45_M200_Stanag",
                "rhs_mag_30Rnd_556x45_M855_Stanag",
                "rhs_mag_30Rnd_556x45_M855A1_Stanag",
                "rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red",
                "rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red",
                "rhs_mag_30Rnd_556x45_Mk262_Stanag",
                "rhs_mag_30Rnd_556x45_Mk318_Stanag",
                "rhsusf_50Rnd_762x51_m82_blank",
                "rhsusf_50Rnd_762x51_m61_ap",
                "rhsusf_50Rnd_762x51_m62_tracer",
                "rhsusf_50Rnd_762x51",
                "rhsusf_50Rnd_762x51_m80a1epr",
                "rhsusf_5Rnd_00Buck",
                "rhsusf_5Rnd_300winmag_xm2010",
                "rhsusf_5Rnd_FRAG",
                "rhsusf_5Rnd_HE",
                "rhsusf_5Rnd_Slug",
                "rhsusf_5Rnd_762x51_AICS_m118_special_Mag",
                "rhsusf_5Rnd_762x51_AICS_m62_Mag",
                "rhsusf_5Rnd_762x51_AICS_m993_Mag",
                "rhsusf_5Rnd_762x51_m118_special_Mag",
                "rhsusf_5Rnd_762x51_m62_Mag",
                "rhsusf_5Rnd_762x51_m993_Mag",
                "rhsusf_mag_6Rnd_M397_HET",
                "rhsusf_mag_6Rnd_M433_HEDP",
                "rhsusf_mag_6Rnd_M441_HE",
                "rhsusf_mag_6Rnd_m4009",
                "rhsusf_mag_6Rnd_M576_Buckshot",
                "rhsusf_mag_6Rnd_M585_white",
                "rhsusf_mag_6Rnd_m661_green",
                "rhsusf_mag_6Rnd_m662_red",
                "rhsusf_mag_6Rnd_M714_white",
                "rhsusf_mag_6Rnd_M715_green",
                "rhsusf_mag_6Rnd_M716_yellow",
                "rhsusf_mag_6Rnd_M781_Practice",
                "rhsusf_mag_7x45acp_MHP",
                "rhsusf_8Rnd_00Buck",
                "rhsusf_8Rnd_FRAG",
                "rhsusf_8Rnd_HE",
                "rhsusf_8Rnd_Slug",
                "rhs_LaserMag",
                "rhs_LaserFCSMag",
                "rhs_mag_maaws_HE",
                "rhs_mag_maaws_SMOKE",
                "rhs_mag_maaws_HEDP",
                "rhs_mag_maaws_ILLUM",
                "rhs_mag_maaws_HEAT",
                "rhs_fim92_mag",
                "rhs_mag_m4009",
                "rhs_fgm148_magazine_AT",
                "rhs_mag_M397_HET",
                "rhs_mag_M433_HEDP",
                "rhs_mag_M441_HE",
                "rhs_mag_m576",
                "rhs_mag_M585_white",
                "rhs_mag_m661_green",
                "rhs_mag_m662_red",
                "rhs_mag_m713_Red",
                "rhs_mag_m714_White",
                "rhs_mag_m715_Green",
                "rhs_mag_m716_yellow",
                "rhs_m72a7_mag",
                "rhs_mag_M781_Practice",
                "rhs_mag_smaw_SR",
                "rhs_mag_smaw_HEDP",
                "rhs_mag_smaw_HEAA"
            };
            weapons[] = {
                "rhs_weap_hk416d10",
                "rhs_weap_hk416d10_m320",
                "rhs_weap_hk416d10_LMT",
                "rhs_weap_hk416d145",
                "rhs_weap_hk416d145_m320",
                "rhs_weap_m16a4",
                "rhs_weap_m16a4_carryhandle",
                "rhs_weap_m16a4_carryhandle_M203",
                "rhs_weap_m240B",
                "rhs_weap_m240G",
                "rhs_weap_m249",
                "rhs_weap_m249_pip_L",
                "rhs_weap_m249_pip_L_para",
                "rhs_weap_m249_pip_L_vfg",
                "rhs_weap_m249_pip_S",
                "rhs_weap_m249_pip_S_para",
                "rhs_weap_m249_pip_S_vfg",
                "rhs_weap_m249_pip",
                "rhs_weap_m27iar",
                "rhs_weap_m27iar_grip",
                "rhs_weap_m32",
                "rhs_weap_m4a1_carryhandle",
                "rhs_weap_m4a1_carryhandle_m203",
                "rhs_weap_m4a1_carryhandle_m203S",
                "rhs_weap_m4a1_carryhandle_mstock",
                "rhs_weap_m4a1_blockII_bk",
                "rhs_weap_m4a1_blockII_M203_bk",
                "rhs_weap_m4a1_blockII_KAC_bk",
                "rhs_weap_m4a1",
                "rhs_weap_m4a1_m203",
                "rhs_weap_m4a1_m203s",
                "rhs_weap_m4a1_m320",
                "rhs_weap_M590_8RD",
                "rhs_weap_M590_5RD",
                "rhs_weap_sr25",
                "rhs_weap_sr25_ec",
                "rhs_weap_mk18_bk",
                "rhs_weap_mk18_KAC_bk",
                "rhs_weap_mk18_m320",
                "rhsusf_weap_glock17g4",
                "rhsusf_weap_m1911a1",
                "rhs_weap_M320",
                "rhsusf_weap_m9"
            };
            launchers[] = {
                "rhs_weap_M136",
                "rhs_weap_M136_hedp",
                "rhs_weap_M136_hp",
                "rhs_weap_maaws",
                "rhs_weap_m72a7",
                "rhs_weap_smaw_green"
            };
            nvg[] = {
                "ACE_NVG_Wide",
                "ACE_NVG_Gen4",
                "rhsusf_ANPVS_14",
                "rhsusf_ANPVS_15"
            };
            binoculars[] = {
                "ACE_Vector",
                "ACE_Yardage450",
                "rhsusf_bino_lerca_1200_black",
                "rhsusf_bino_lerca_1200_tan",
                "rhsusf_bino_m24_ARD"
            };
            sights[] = {
                "rhsusf_acc_t1_high",
                "rhsusf_acc_t1_low",
                "rhsusf_acc_anpas13gv1",
                "rhsusf_acc_acog2_usmc",
                "rhsusf_acc_acog3_usmc",
                "rhsusf_acc_acog_usmc",
                "rhsusf_acc_anpvs27",
                "rhsusf_acc_eotech",
                "rhsusf_acc_g33_t1",
                "rhsusf_acc_g33_xps3",
                "rhsusf_acc_elcan",
                "rhsusf_acc_elcan_ard",
                "rhsusf_acc_acog",
                "rhsusf_acc_acog2",
                "rhsusf_acc_acog3",
                "rhsusf_acc_m2a1",
                "rhsusf_acc_eotech_552",
                "rhsusf_acc_compm4",
                "rhsusf_acc_mrds",
                "rhsusf_acc_mrds_c",
                "rhsusf_acc_rm05",
                "rhsusf_acc_rx01_nofilter",
                "rhsusf_acc_rx01",
                "rhsusf_acc_rx01_nofilter_tan",
                "rhsusf_acc_rx01_tan",
                "rhsusf_acc_su230",
                "rhsusf_acc_su230_c",
                "rhsusf_acc_su230_mrds",
                "rhsusf_acc_su230_mrds_c",
                "rhsusf_acc_su230a",
                "rhsusf_acc_su230a_c",
                "rhsusf_acc_su230a_mrds",
                "rhsusf_acc_su230a_mrds_c",
                "rhsusf_acc_acog_mdo",
                "rhsusf_acc_acog_rmr",
                "rhsusf_acc_eotech_xps3",
                "rhs_optic_maaws"
            };
            attachments[] = {
                "ACE_acc_pointer_green",
                "ACE_acc_pointer_green_IR",
                "rhsusf_acc_anpeq15side",
                "rhsusf_acc_anpeq15_top",
                "rhsusf_acc_anpeq15_wmx",
                "rhsusf_acc_anpeq15_wmx_light",
                "rhsusf_acc_anpeq15side_bk",
                "rhsusf_acc_anpeq15_bk_top",
                "rhsusf_acc_anpeq15",
                "rhsusf_acc_anpeq15_light",
                "rhsusf_acc_anpeq15_bk",
                "rhsusf_acc_anpeq15_bk_light",
                "rhsusf_acc_anpeq15a",
                "rhsusf_acc_anpeq16a",
                "rhsusf_acc_anpeq16a_light",
                "rhsusf_acc_anpeq16a_top",
                "rhsusf_acc_anpeq16a_light_top",
                "rhsusf_acc_m952v",
                "rhsusf_acc_wmx",
                "rhsusf_acc_wmx_bk"
            };
            faceware[] = {
                "G_Bandanna_beast",
                "G_Bandanna_blk",
                "G_Bandanna_oli",
                "G_Combat",
                "G_Lowprofile",
                "G_Shades_Black",
                "G_Shades_Blue",
                "G_Shades_Green",
                "G_Shades_Red",
                "G_Tactical_Clear",
                "G_Tactical_Black",
                "rhs_googles_black",
                "rhs_googles_clear",
                "rhs_googles_yellow",
                "rhs_googles_orange",
                "rhs_ess_black"
            };
        };
        class SemiArid : ArsenalBase {};
        class Arid     : ArsenalBase {};
        class Tropic   : ArsenalBase {};
        class Wood     : ArsenalBase {};
    };
    class Cup : Nato
    {
        class ArsenalBase : ArsenalBase
        {
            cupMags[] = {
                "CUP_20Rnd_556x45_Stanag",
                "CUP_20Rnd_556x45_Stanag_Tracer_Green",
                "CUP_20Rnd_556x45_Stanag_Tracer_Red",
                "CUP_20Rnd_556x45_Stanag_Tracer_Yellow",
                "CUP_30Rnd_556x45_Emag",
                "CUP_30Rnd_556x45_Emag_Tracer_Green",
                "CUP_30Rnd_556x45_Emag_Tracer_Red",
                "CUP_30Rnd_556x45_Emag_Tracer_Yellow",
                "CUP_30Rnd_556x45_PMAG_QP",
                "CUP_30Rnd_556x45_PMAG_QP_Tracer_Green",
                "CUP_30Rnd_556x45_PMAG_QP_Tracer_Red",
                "CUP_30Rnd_556x45_PMAG_QP_Tracer_Yellow",
                "CUP_30Rnd_556x45_Stanag",
                "CUP_30Rnd_556x45_Stanag_Tracer_Green",
                "CUP_30Rnd_556x45_Stanag_Tracer_Red",
                "CUP_30Rnd_556x45_Stanag_Tracer_Yellow",
                "CUP_30Rnd_556x45_Stanag_L85",
                "CUP_30Rnd_556x45_Stanag_L85_Tracer_Green",
                "CUP_30Rnd_556x45_Stanag_L85_Tracer_Red",
                "CUP_30Rnd_556x45_Stanag_L85_Tracer_Yellow",
                "CUP_30Rnd_556x45_Stanag_Mk16_black",
                "CUP_30Rnd_556x45_Stanag_Mk16_black_Tracer_Green",
                "CUP_30Rnd_556x45_Stanag_Mk16_black_Tracer_Red",
                "CUP_30Rnd_556x45_Stanag_Mk16_black_Tracer_Yellow",
                "CUP_60Rnd_556x45_SureFire",
                "CUP_100Rnd_556x45_BetaCMag_ar15",
                "CUP_100Rnd_TE1_Green_Tracer_556x45_BetaCMag_ar15",
                "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag_ar15",
                "CUP_100Rnd_TE1_Yellow_Tracer_556x45_BetaCMag_ar15",
                "CUP_1Rnd_HE_M203",
                "CUP_1Rnd_HEDP_M203",
                "CUP_FlareWhite_M203",
                "CUP_1Rnd_StarFlare_White_M203",
                "CUP_1Rnd_StarCluster_White_M203",
                "CUP_FlareGreen_M203",
                "CUP_1Rnd_StarCluster_Green_M203",
                "CUP_1Rnd_StarFlare_Green_M203",
                "CUP_FlareRed_M203",
                "CUP_1Rnd_StarCluster_Red_M203",
                "CUP_1Rnd_StarFlare_Red_M203",
                "CUP_FlareYellow_M203",
                "CUP_1Rnd_SmokeRed_M203",
                "CUP_1Rnd_Smoke_M203",
                "CUP_1Rnd_SmokeGreen_M203",
                "CUP_1Rnd_SmokeYellow_M203",
                "CUP_20Rnd_762x51_DMR",
                "CUP_20Rnd_762x51_HK417",
                "CUP_20Rnd_TE1_Red_Tracer_762x51_HK417"
            };
            cupsWeapons[] = {
                "CUP_hgun_Glock17",
                "CUP_arifle_HK416_CQB_Black",
                "CUP_arifle_HK416_CQB_M203_Black",
                "CUP_arifle_HK416_Black",
                "CUP_arifle_HK416_AGL_Black",
                "CUP_arifle_HK416_M203_Black",
                "CUP_arifle_HK417_12",
                "CUP_arifle_HK417_12_M203",
                "CUP_arifle_HK417_20",
                "CUP_arifle_M16A2",
                "CUP_arifle_M16A2_GL",
                "CUP_arifle_M16A4_Base",
                "CUP_arifle_M16A4_Grip",
                "CUP_arifle_M16A4_GL",
                "CUP_lmg_m249_SQuantoon",
                "CUP_lmg_m249_pip1",
                "CUP_lmg_m249_pip3",
                "CUP_lmg_m249_pip4",
                "CUP_lmg_M249_E2",
                "CUP_lmg_m249_pip2",
                "CUP_lmg_m249_para_gl",
                "CUP_lmg_m249_para",
                "CUP_arifle_HK_M27",
                "CUP_glaunch_M32",
                "CUP_arifle_M4A1_black",
                "CUP_arifle_M4A1",
                "CUP_arifle_M4A1_BUIS_GL",
                "CUP_arifle_M4A3_black",
                "CUP_arifle_mk18_black",
                "CUP_arifle_mk18_m203_black",
                "CUP_arifle_Mk16_CQC_black",
                "CUP_arifle_Mk16_CQC_FG_black",
                "CUP_arifle_Mk16_CQC_SFG_black",
                "CUP_arifle_Mk16_CQC_EGLM_black",
                "CUP_arifle_Mk16_STD_FG_black",
                "CUP_arifle_Mk16_STD_SFG_black",
                "CUP_arifle_Mk16_STD_EGLM_black",
                "CUP_arifle_Mk16_STD_black",
                "CUP_arifle_Mk16_SV_black",
                "CUP_arifle_Mk17_CQC_Black",
                "CUP_arifle_Mk17_CQC_FG_black",
                "CUP_arifle_Mk17_CQC_SFG_black",
                "CUP_arifle_Mk17_CQC_EGLM_black",
                "CUP_arifle_Mk20_black",
                "CUP_arifle_Mk17_STD_FG_black",
                "CUP_arifle_Mk17_STD_SFG_black",
                "CUP_arifle_Mk17_STD_EGLM_black",
                "CUP_arifle_Mk17_STD_black",
                "CUP_srifle_M14",
                "CUP_srifle_M14_DMR",
                "CUP_arifle_L85A2",
                "CUP_arifle_L85A2_G",
                "CUP_arifle_L85A2_NG",
                "CUP_arifle_L85A2_GL",
                "CUP_arifle_L86A2",
                "CUP_srifle_L129A1",
                "CUP_srifle_L129A1_HG",
                "CUP_lmg_minimi",
                "CUP_lmg_minimi_railed",
                "CUP_lmg_minimipara"
            };
            cupLaunchers[] = {
                "CUP_launch_Javelin",
                "CUP_launch_M136",
                "CUP_launch_M72A6",
                "CUP_launch_M72A6_Special",
                "CUP_launch_MAAWS"
            };
            cupNvg[] = {
                "CUP_NVG_PVS14",
                "CUP_NVG_PVS15_black",
                "CUP_NVG_PVS7",
                "CUP_NVG_GPNVG_black"
            };
            cupSights[] = {
                "cup_optic_compm4",
                "cup_optic_an_pas_13c1",
                "cup_optic_elcan",
                "cup_optic_elcan_reflex",
                "cup_optic_elcanm145",
                "cup_optic_holoblack",
                "cup_optic_leupoldmk4_cq_t",
                "cup_optic_compm2_black",
                "cup_optic_mrad",
                "cup_optic_zddot",
                "cup_optic_susat",
                "cup_optic_rco",
                "cup_optic_acog2",
                "cup_optic_acog",
                "cup_optic_trijiconrx01_black",
                "cup_optic_leupoldmk4"
            };
            cupAttachments[] = {
                "cup_acc_anpeq_15",
                "cup_acc_anpeq_2"
            };
            cupFaceware[] = {
                "CUP_RUS_Balaclava_blk",
                "CUP_RUS_Balaclava_grn",
                "CUP_PMC_Facewrap_Black",
                "CUP_PMC_Facewrap_Ranger",
                "CUP_PMC_Facewrap_Tan",
                "CUP_PMC_Facewrap_Tropical"
            };
        };
        class SemiArid : ArsenalBase
        {
            cupSemiAridMags[] = {
                "CUP_30Rnd_556x45_Stanag_Mk16",
                "CUP_30Rnd_556x45_Stanag_Mk16_Tracer_Green",
                "CUP_30Rnd_556x45_Stanag_Mk16_Tracer_Red",
                "CUP_30Rnd_556x45_Stanag_Mk16_Tracer_Yellow"
            };
            cupSemiAridWeapons[] = {
                "CUP_arifle_HK416_CQB_Desert",
                "CUP_arifle_HK416_Desert",
                "CUP_arifle_HK416_M203_Desert",
                "CUP_arifle_M4A1_desert_carryhandle",
                "CUP_arifle_M4A1_desert",
                "CUP_arifle_M4A1_BUIS_desert_GL",
                "CUP_arifle_M4A3_desert",
                "CUP_arifle_Mk16_CQC",
                "CUP_arifle_Mk16_CQC_FG",
                "CUP_arifle_Mk16_CQC_SFG",
                "CUP_arifle_Mk16_CQC_EGLM",
                "CUP_arifle_Mk16_STD",
                "CUP_arifle_Mk16_STD_FG",
                "CUP_arifle_Mk16_STD_SFG",
                "CUP_arifle_Mk16_STD_EGLM",
                "CUP_arifle_Mk16_SV",
                "CUP_arifle_Mk17_CQC",
                "CUP_arifle_Mk17_CQC_FG",
                "CUP_arifle_Mk17_CQC_SFG",
                "CUP_arifle_Mk17_CQC_EGLM",
                "CUP_arifle_Mk17_STD",
                "CUP_arifle_Mk17_STD_FG",
                "CUP_arifle_Mk17_STD_SFG",
                "CUP_arifle_Mk17_STD_EGLM",
                "CUP_arifle_G36A",
                "CUP_arifle_G36C",
                "CUP_arifle_AG36",
                "CUP_arifle_G36K"
            };
        };
        class Arid   : SemiArid {};
        class Tropic : ArsenalBase
        {
            cupTropicMags[] = {
                "CUP_30Rnd_556x45_Stanag_Mk16_woodland",
                "CUP_30Rnd_556x45_Stanag_Mk16_woodland_Tracer_Green",
                "CUP_30Rnd_556x45_Stanag_Mk16_woodland_Tracer_Red",
                "CUP_30Rnd_556x45_Stanag_Mk16_woodland_Tracer_Yellow",
                "CUP_20Rnd_762x51_B_SCAR_wdl"
            };
            cupTropicWeapons[] = {
                "CUP_arifle_HK416_CQB_Wood",
                "CUP_arifle_HK416_CQB_M203_Wood",
                "CUP_arifle_HK416_Wood",
                "CUP_arifle_HK416_AGL_Wood",
                "CUP_arifle_HK416_M203_Wood",
                "CUP_arifle_M4A1_camo_carryhandle",
                "CUP_arifle_M4A1_camo",
                "CUP_arifle_M4A1_BUIS_camo_GL",
                "CUP_arifle_M4A3_camo",
                "CUP_arifle_Mk16_CQC_woodland",
                "CUP_arifle_Mk16_CQC_FG_woodland",
                "CUP_arifle_Mk16_CQC_SFG_woodland",
                "CUP_arifle_Mk16_CQC_EGLM_woodland",
                "CUP_arifle_Mk16_STD_FG_woodland",
                "CUP_arifle_Mk16_STD_SFG_woodland",
                "CUP_arifle_Mk16_STD_EGLM_woodland",
                "CUP_arifle_Mk16_STD_woodland",
                "CUP_arifle_Mk16_SV_woodland",
                "CUP_arifle_Mk17_CQC_woodland",
                "CUP_arifle_Mk17_CQC_FG_woodland",
                "CUP_arifle_Mk17_CQC_EGLM_woodland",
                "CUP_arifle_Mk17_STD_FG_woodland",
                "CUP_arifle_Mk17_STD_SFG_woodland",
                "CUP_arifle_Mk17_STD_woodland",
                "CUP_arifle_Mk17_STD_EGLM_woodland"
            };
        };
        class Wood : Tropic {};
    };
    class CupUsmc : Cup
    {
        mags[]    = {};
        weapons[] = {};
        sights[]  = {};

        class ArsenalBase : ArsenalBase {};
        class SemiArid    : ArsenalBase {};
        class Arid        : ArsenalBase {};
        class Tropic      : ArsenalBase {};
        class Wood        : ArsenalBase {};
    };
    class CupBaf : Cup
    {
        mags[]    = {};
        weapons[] = {};
        sights[]  = {};

        class ArsenalBase : ArsenalBase {};
        class SemiArid    : ArsenalBase {};
        class Arid        : ArsenalBase {};
        class Tropic      : ArsenalBase {};
        class Wood        : ArsenalBase {};
    };
    class CupBundeswehr : Cup
    {
        mags[]    = {};
        weapons[] = {};
        sights[]  = {};

        class ArsenalBase : ArsenalBase {};
        class SemiArid    : ArsenalBase {};
        class Arid        : ArsenalBase {};
        class Tropic      : ArsenalBase {};
        class Wood        : ArsenalBase {};
    };
};
