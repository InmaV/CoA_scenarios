#include <math.h>
#include <stdio.h>
/*
   There are a total of 197 entries in the algebraic variable array.
   There are a total of 112 entries in each of the rate and state variable arrays.
   There are a total of 182 entries in the constant variable array.
 */
/*
 * VOI is t in component environment (second).
 * ALGEBRAIC[30] is L in component LA (dimensionless).
 * ALGEBRAIC[66] is Ls in component LA (Unitl).
 * CONSTANTS[0] is Lsref in component Parameters (Unitl).
 * STATES[0] is Lsc in component LA (Unitl).
 * CONSTANTS[1] is Lscini in component Parameters (Unitl).
 * ALGEBRAIC[78] is Lsnorm in component LA (dimensionless).
 * ALGEBRAIC[37] is ta in component LA (second).
 * CONSTANTS[170] is tact in component LA (second).
 * CONSTANTS[175] is td in component LA (second).
 * CONSTANTS[174] is trise in component LA (second).
 * CONSTANTS[2] is p_tact_a in component Parameters (second).
 * CONSTANTS[3] is p_trise_a in component Parameters (dimensionless).
 * CONSTANTS[4] is p_td_a in component Parameters (dimensionless).
 * STATES[1] is C in component LA (dimensionless).
 * CONSTANTS[5] is C0 in component Parameters (dimensionless).
 * STATES[2] is Vcav in component LA (UnitV).
 * CONSTANTS[6] is Vla0 in component Parameters (UnitV).
 * CONSTANTS[7] is Vwall_la in component Parameters (UnitV).
 * ALGEBRAIC[74] is sfpas in component LA (UnitP).
 * ALGEBRAIC[38] is sfact in component LA (UnitP).
 * ALGEBRAIC[43] is sfrest in component LA (UnitP).
 * ALGEBRAIC[79] is sf in component LA (UnitP).
 * CONSTANTS[8] is spas_a in component Parameters (UnitP).
 * CONSTANTS[9] is sact_a in component Parameters (UnitP).
 * CONSTANTS[10] is vmax_a in component Parameters (Unitv).
 * CONSTANTS[11] is delay_la in component Parameters (second).
 * ALGEBRAIC[0] is Time in component LA (second).
 * ALGEBRAIC[46] is Time2 in component LA (second).
 * ALGEBRAIC[18] is xrise in component LA (dimensionless).
 * ALGEBRAIC[42] is fRise in component LA (dimensionless).
 * ALGEBRAIC[50] is fDecay in component LA (dimensionless).
 * CONSTANTS[12] is Crest in component Parameters (dimensionless).
 * ALGEBRAIC[68] is xPos in component LA (dimensionless).
 * ALGEBRAIC[70] is xSarc in component LA (dimensionless).
 * ALGEBRAIC[72] is y in component LA (dimensionless).
 * ALGEBRAIC[76] is NoBuckle in component LA (dimensionless).
 * ALGEBRAIC[47] is Vm in component LA (UnitV).
 * ALGEBRAIC[51] is Cm in component LA (Unitc).
 * ALGEBRAIC[57] is Am in component LA (UnitA).
 * ALGEBRAIC[54] is Amtotal in component LA (UnitA).
 * CONSTANTS[13] is Amdead_la in component Parameters (UnitA).
 * CONSTANTS[14] is Amref_la in component Parameters (UnitA).
 * ALGEBRAIC[60] is z in component LA (dimensionless).
 * ALGEBRAIC[63] is Ef in component LA (dimensionless).
 * CONSTANTS[15] is kS_a in component Parameters (dimensionless).
 * ALGEBRAIC[80] is Tension in component LA (UnitT).
 * ALGEBRAIC[81] is Pi in component LA (UnitP).
 * ALGEBRAIC[168] is Pi in component LV (UnitP).
 * ALGEBRAIC[170] is Qo in component Bif_LUNG1in_FO2in_LAout (UnitQ).
 * STATES[3] is Qo in component LA (UnitQ).
 * CONSTANTS[16] is Q0foo in component Parameters (UnitQ).
 * CONSTANTS[17] is T in component Parameters (second).
 * CONSTANTS[18] is Kmivo in component Parameters (UnitKxi).
 * CONSTANTS[19] is Kmivc_p in component Parameters (UnitKxi).
 * CONSTANTS[20] is Kmivc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[84] is Linductance in component LA (UnitL).
 * CONSTANTS[21] is L_min_mi in component Parameters (UnitL).
 * CONSTANTS[22] is L_param in component Parameters (UnitLparam).
 * STATES[4] is xi in component LA (dimensionless).
 * ALGEBRAIC[82] is Aeff in component LA (UnitA).
 * CONSTANTS[23] is Ami in component Parameters (UnitA).
 * ALGEBRAIC[85] is B in component LA (UnitB).
 * ALGEBRAIC[173] is val_xi in component LA (ode_s).
 * CONSTANTS[24] is B_param in component Parameters (UnitBparam).
 * ALGEBRAIC[88] is L in component RA (dimensionless).
 * ALGEBRAIC[101] is Ls in component RA (Unitl).
 * STATES[5] is Lsc in component RA (Unitl).
 * ALGEBRAIC[107] is Lsnorm in component RA (dimensionless).
 * ALGEBRAIC[89] is ta in component RA (second).
 * CONSTANTS[171] is tact in component RA (second).
 * CONSTANTS[177] is td in component RA (second).
 * CONSTANTS[176] is trise in component RA (second).
 * STATES[6] is C in component RA (dimensionless).
 * STATES[7] is Vcav in component RA (UnitV).
 * CONSTANTS[25] is Vra0 in component Parameters (UnitV).
 * CONSTANTS[26] is Vwall_ra in component Parameters (UnitV).
 * ALGEBRAIC[105] is sfpas in component RA (UnitP).
 * ALGEBRAIC[90] is sfact in component RA (UnitP).
 * ALGEBRAIC[92] is sfrest in component RA (UnitP).
 * ALGEBRAIC[108] is sf in component RA (UnitP).
 * CONSTANTS[27] is delay_ra in component Parameters (second).
 * ALGEBRAIC[86] is Time in component RA (second).
 * ALGEBRAIC[93] is Time2 in component RA (second).
 * ALGEBRAIC[87] is xrise in component RA (dimensionless).
 * ALGEBRAIC[91] is fRise in component RA (dimensionless).
 * ALGEBRAIC[95] is fDecay in component RA (dimensionless).
 * ALGEBRAIC[102] is xPos in component RA (dimensionless).
 * ALGEBRAIC[103] is xSarc in component RA (dimensionless).
 * ALGEBRAIC[104] is y in component RA (dimensionless).
 * ALGEBRAIC[106] is NoBuckle in component RA (dimensionless).
 * ALGEBRAIC[94] is Vm in component RA (UnitV).
 * ALGEBRAIC[96] is Cm in component RA (Unitc).
 * ALGEBRAIC[98] is Am in component RA (UnitA).
 * ALGEBRAIC[97] is Amtotal in component RA (UnitA).
 * CONSTANTS[28] is Amdead_ra in component Parameters (UnitA).
 * CONSTANTS[29] is Amref_ra in component Parameters (UnitA).
 * ALGEBRAIC[99] is z in component RA (dimensionless).
 * ALGEBRAIC[100] is Ef in component RA (dimensionless).
 * ALGEBRAIC[109] is Tension in component RA (UnitT).
 * ALGEBRAIC[110] is Pi in component RA (UnitP).
 * ALGEBRAIC[176] is Pi in component RV (UnitP).
 * ALGEBRAIC[188] is Qo in component Bif_SVC1in_IVC2in_DV3in_Coronary4in_RAout (UnitQ).
 * STATES[8] is Qo in component RA (UnitQ).
 * CONSTANTS[30] is Ktrvo in component Parameters (UnitKxi).
 * CONSTANTS[31] is Ktrvc_p in component Parameters (UnitKxi).
 * CONSTANTS[32] is Ktrvc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[115] is Linductance in component RA (UnitL).
 * CONSTANTS[33] is L_min_tr in component Parameters (UnitL).
 * STATES[9] is xi in component RA (dimensionless).
 * ALGEBRAIC[111] is Aeff in component RA (UnitA).
 * CONSTANTS[34] is Atr in component Parameters (UnitA).
 * ALGEBRAIC[119] is B in component RA (UnitB).
 * ALGEBRAIC[192] is val_xi in component RA (ode_s).
 * ALGEBRAIC[132] is L in component RV (dimensionless).
 * ALGEBRAIC[157] is Ls in component RV (Unitl).
 * STATES[10] is Lsc in component RV (Unitl).
 * ALGEBRAIC[169] is Lsnorm in component RV (dimensionless).
 * ALGEBRAIC[135] is ta in component RV (second).
 * CONSTANTS[172] is tact in component RV (second).
 * CONSTANTS[179] is td in component RV (second).
 * CONSTANTS[178] is trise in component RV (second).
 * CONSTANTS[35] is p_tact_v in component Parameters (second).
 * CONSTANTS[36] is p_trise_v in component Parameters (dimensionless).
 * CONSTANTS[37] is p_td_v in component Parameters (dimensionless).
 * STATES[11] is C in component RV (dimensionless).
 * STATES[12] is Vcav in component RV (UnitV).
 * CONSTANTS[38] is Vrv0 in component Parameters (UnitV).
 * CONSTANTS[39] is Vwall_rv in component Parameters (UnitV).
 * ALGEBRAIC[165] is sfpas in component RV (UnitP).
 * ALGEBRAIC[136] is sfact in component RV (UnitP).
 * ALGEBRAIC[140] is sfrest in component RV (UnitP).
 * ALGEBRAIC[171] is sf in component RV (UnitP).
 * CONSTANTS[40] is spas_v in component Parameters (UnitP).
 * CONSTANTS[41] is sact_v in component Parameters (UnitP).
 * CONSTANTS[42] is vmax_v in component Parameters (Unitv).
 * CONSTANTS[43] is delay_rv in component Parameters (second).
 * ALGEBRAIC[124] is Time in component RV (second).
 * ALGEBRAIC[142] is Time2 in component RV (second).
 * ALGEBRAIC[129] is xrise in component RV (dimensionless).
 * ALGEBRAIC[139] is fRise in component RV (dimensionless).
 * ALGEBRAIC[146] is fDecay in component RV (dimensionless).
 * ALGEBRAIC[159] is xPos in component RV (dimensionless).
 * ALGEBRAIC[161] is xSarc in component RV (dimensionless).
 * ALGEBRAIC[163] is y in component RV (dimensionless).
 * ALGEBRAIC[167] is NoBuckle in component RV (dimensionless).
 * ALGEBRAIC[143] is Vm in component RV (UnitV).
 * ALGEBRAIC[147] is Cm in component RV (Unitc).
 * ALGEBRAIC[151] is Am in component RV (UnitA).
 * ALGEBRAIC[149] is Amtotal in component RV (UnitA).
 * CONSTANTS[44] is Amdead_rv in component Parameters (UnitA).
 * CONSTANTS[45] is Amref_rv in component Parameters (UnitA).
 * ALGEBRAIC[153] is z in component RV (dimensionless).
 * ALGEBRAIC[155] is Ef in component RV (dimensionless).
 * CONSTANTS[46] is kS_v in component Parameters (dimensionless).
 * ALGEBRAIC[174] is Tension in component RV (UnitT).
 * STATES[13] is Pi in component PA_RCL (UnitP).
 * STATES[14] is Qo in component RV (UnitQ).
 * CONSTANTS[47] is Kpvvo in component Parameters (UnitKxi).
 * CONSTANTS[48] is Kpvvc_p in component Parameters (UnitKxi).
 * CONSTANTS[49] is Kpvvc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[183] is Linductance in component RV (UnitL).
 * CONSTANTS[50] is L_min_pv in component Parameters (UnitL).
 * STATES[15] is xi in component RV (dimensionless).
 * ALGEBRAIC[179] is Aeff in component RV (UnitA).
 * CONSTANTS[51] is Apv in component Parameters (UnitA).
 * ALGEBRAIC[186] is B in component RV (UnitB).
 * ALGEBRAIC[180] is val_xi in component RV (ode_s).
 * ALGEBRAIC[120] is L in component LV (dimensionless).
 * ALGEBRAIC[150] is Ls in component LV (Unitl).
 * STATES[16] is Lsc in component LV (Unitl).
 * ALGEBRAIC[162] is Lsnorm in component LV (dimensionless).
 * ALGEBRAIC[125] is ta in component LV (second).
 * CONSTANTS[173] is tact in component LV (second).
 * CONSTANTS[181] is td in component LV (second).
 * CONSTANTS[180] is trise in component LV (second).
 * STATES[17] is C in component LV (dimensionless).
 * STATES[18] is Vcav in component LV (UnitV).
 * CONSTANTS[52] is Vlv0 in component Parameters (UnitV).
 * CONSTANTS[53] is Vwall_lv in component Parameters (UnitV).
 * ALGEBRAIC[158] is sfpas in component LV (UnitP).
 * ALGEBRAIC[126] is sfact in component LV (UnitP).
 * ALGEBRAIC[131] is sfrest in component LV (UnitP).
 * ALGEBRAIC[164] is sf in component LV (UnitP).
 * CONSTANTS[54] is delay_lv in component Parameters (second).
 * ALGEBRAIC[112] is Time in component LV (second).
 * ALGEBRAIC[133] is Time2 in component LV (second).
 * ALGEBRAIC[116] is xrise in component LV (dimensionless).
 * ALGEBRAIC[130] is fRise in component LV (dimensionless).
 * ALGEBRAIC[137] is fDecay in component LV (dimensionless).
 * ALGEBRAIC[152] is xPos in component LV (dimensionless).
 * ALGEBRAIC[154] is xSarc in component LV (dimensionless).
 * ALGEBRAIC[156] is y in component LV (dimensionless).
 * ALGEBRAIC[160] is NoBuckle in component LV (dimensionless).
 * ALGEBRAIC[134] is Vm in component LV (UnitV).
 * ALGEBRAIC[138] is Cm in component LV (Unitc).
 * ALGEBRAIC[144] is Am in component LV (UnitA).
 * ALGEBRAIC[141] is Amtotal in component LV (UnitA).
 * CONSTANTS[55] is Amdead_lv in component Parameters (UnitA).
 * CONSTANTS[56] is Amref_lv in component Parameters (UnitA).
 * ALGEBRAIC[145] is z in component LV (dimensionless).
 * ALGEBRAIC[148] is Ef in component LV (dimensionless).
 * ALGEBRAIC[166] is Tension in component LV (UnitT).
 * ALGEBRAIC[187] is Pi in component Bif_LVin_AA1out_Coronary2out (UnitP).
 * STATES[19] is Qo in component LV (UnitQ).
 * CONSTANTS[57] is Kaovo in component Parameters (UnitKxi).
 * CONSTANTS[58] is Kaovc_p in component Parameters (UnitKxi).
 * CONSTANTS[59] is Kaovc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[175] is Linductance in component LV (UnitL).
 * CONSTANTS[60] is L_min_ao in component Parameters (UnitL).
 * STATES[20] is xi in component LV (dimensionless).
 * ALGEBRAIC[172] is Aeff in component LV (UnitA).
 * CONSTANTS[61] is Aao in component Parameters (UnitA).
 * ALGEBRAIC[177] is B in component LV (UnitB).
 * ALGEBRAIC[189] is val_xi in component LV (ode_s).
 * STATES[21] is Pi in component AA_RCL (UnitP).
 * ALGEBRAIC[19] is Pi in component Bif_AAin_AAA1out_BrachT2out (UnitP).
 * STATES[22] is Qo in component AA_RCL (UnitQ).
 * ALGEBRAIC[184] is Qo1 in component Bif_LVin_AA1out_Coronary2out (UnitQ).
 * STATES[23] is V in component AA_RCL (UnitV).
 * CONSTANTS[62] is Raa in component Parameters (UnitR).
 * CONSTANTS[63] is Caa in component Parameters (UnitC).
 * CONSTANTS[64] is Laa in component Parameters (UnitL).
 * CONSTANTS[65] is P0foo in component Parameters (UnitP).
 * STATES[24] is Pi in component AAA_RCL (UnitP).
 * ALGEBRAIC[20] is Pi in component Bif_AAAin_DAA1out_CCaroAL2out (UnitP).
 * STATES[25] is Qo in component AAA_RCL (UnitQ).
 * ALGEBRAIC[1] is Qo1 in component Bif_AAin_AAA1out_BrachT2out (UnitQ).
 * STATES[26] is V in component AAA_RCL (UnitV).
 * CONSTANTS[66] is RaAoA in component Parameters (UnitR).
 * CONSTANTS[67] is CaAoA in component Parameters (UnitC).
 * CONSTANTS[68] is LaAoA in component Parameters (UnitL).
 * STATES[27] is Pi in component DAA_RCL (UnitP).
 * ALGEBRAIC[21] is Pi in component Bif_DAAin_AI1out_SubAL2out (UnitP).
 * STATES[28] is Qo in component DAA_RCL (UnitQ).
 * ALGEBRAIC[2] is Qo1 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ).
 * STATES[29] is V in component DAA_RCL (UnitV).
 * CONSTANTS[69] is RdAoA in component Parameters (UnitR).
 * CONSTANTS[70] is CdAoA in component Parameters (UnitC).
 * CONSTANTS[71] is LdAoA in component Parameters (UnitL).
 * ALGEBRAIC[31] is Pi in component Bif_PAin_LUNG1out_DA2out (UnitP).
 * STATES[30] is Qo in component PA_RCL (UnitQ).
 * STATES[31] is V in component PA_RCL (UnitV).
 * CONSTANTS[72] is Rpa in component Parameters (UnitR).
 * CONSTANTS[73] is Cpa in component Parameters (UnitC).
 * CONSTANTS[74] is Lpa in component Parameters (UnitL).
 * STATES[32] is Pi in component LUNG_RCL (UnitP).
 * ALGEBRAIC[83] is Pi1 in component Bif_LUNG1in_FO2in_LAout (UnitP).
 * STATES[33] is Qo in component LUNG_RCL (UnitQ).
 * ALGEBRAIC[3] is Qo in component LUNG_RC (UnitQ).
 * STATES[34] is V in component LUNG_RCL (UnitV).
 * CONSTANTS[75] is Rla in component Parameters (UnitR).
 * CONSTANTS[76] is Clung in component Parameters (UnitC).
 * CONSTANTS[77] is Lfoo in component Parameters (UnitL).
 * STATES[35] is Pi in component SVC_RCL (UnitP).
 * ALGEBRAIC[113] is Pi1 in component Bif_SVC1in_IVC2in_DV3in_Coronary4in_RAout (UnitP).
 * STATES[36] is Qo in component SVC_RCL (UnitQ).
 * ALGEBRAIC[77] is Qo in component Bif_BR1in_UB2in_SVCout (UnitQ).
 * STATES[37] is V in component SVC_RCL (UnitV).
 * CONSTANTS[78] is Rsvc in component Parameters (UnitR).
 * CONSTANTS[79] is Csvc in component Parameters (UnitC).
 * STATES[38] is Pi in component AO2_RCL (UnitP).
 * ALGEBRAIC[22] is Pi in component Bif_AOin_LEG1out_UA2out (UnitP).
 * STATES[39] is Qo in component AO2_RCL (UnitQ).
 * ALGEBRAIC[32] is Qo1 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * STATES[40] is V in component AO2_RCL (UnitV).
 * CONSTANTS[80] is Rdaao in component Parameters (UnitR).
 * CONSTANTS[81] is Cao2 in component Parameters (UnitC).
 * STATES[41] is Pi in component UV_RCL (UnitP).
 * ALGEBRAIC[196] is Pi in component Bif_UVin_DV1out_HE2out (UnitP).
 * STATES[42] is Qo in component UV_RCL (UnitQ).
 * ALGEBRAIC[33] is Qo in component PLAC_RC (UnitQ).
 * STATES[43] is V in component UV_RCL (UnitV).
 * CONSTANTS[82] is Ruv in component Parameters (UnitR).
 * CONSTANTS[83] is Cuv in component Parameters (UnitC).
 * STATES[44] is Pi in component IVC_RCL (UnitP).
 * ALGEBRAIC[121] is Pi in component Bif_IVCin_FO1out_RA2out (UnitP).
 * STATES[45] is Qo in component IVC_RCL (UnitQ).
 * ALGEBRAIC[64] is Qo in component Bif_KID1in_HE2in_LEG3in_IVCout (UnitQ).
 * STATES[46] is V in component IVC_RCL (UnitV).
 * CONSTANTS[84] is Rivc in component Parameters (UnitR).
 * CONSTANTS[85] is Civc in component Parameters (UnitC).
 * STATES[47] is Pi in component BrachT_RCL (UnitP).
 * ALGEBRAIC[24] is Pi in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitP).
 * STATES[48] is Qo in component BrachT_RCL (UnitQ).
 * STATES[49] is Qo2 in component Bif_AAin_AAA1out_BrachT2out (UnitQ).
 * STATES[50] is V in component BrachT_RCL (UnitV).
 * CONSTANTS[86] is Rbct in component Parameters (UnitR).
 * CONSTANTS[87] is Cbct in component Parameters (UnitC).
 * CONSTANTS[88] is Lbct in component Parameters (UnitL).
 * STATES[51] is Pi in component SubAR_RCL (UnitP).
 * ALGEBRAIC[5] is Pi in component UBR_R (UnitP).
 * STATES[52] is Qo in component SubAR_RCL (UnitQ).
 * ALGEBRAIC[6] is Qo1 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ).
 * STATES[53] is V in component SubAR_RCL (UnitV).
 * CONSTANTS[89] is R_R_SC in component Parameters (UnitR).
 * CONSTANTS[90] is C_R_SC in component Parameters (UnitC).
 * CONSTANTS[91] is L_R_SC in component Parameters (UnitL).
 * STATES[54] is Pi in component ICaroAR_RCL (UnitP).
 * ALGEBRAIC[7] is Pi in component BRR_R (UnitP).
 * STATES[55] is Qo in component ICaroAR_RCL (UnitQ).
 * ALGEBRAIC[8] is Qo in component CCaroAR_RC (UnitQ).
 * STATES[56] is V in component ICaroAR_RCL (UnitV).
 * CONSTANTS[92] is R_R_ICA in component Parameters (UnitR).
 * CONSTANTS[93] is C_R_ICA in component Parameters (UnitC).
 * CONSTANTS[94] is L_R_ICA in component Parameters (UnitL).
 * STATES[57] is Pi in component ICaroAL_RCL (UnitP).
 * ALGEBRAIC[9] is Pi in component BRL_R (UnitP).
 * STATES[58] is Qo in component ICaroAL_RCL (UnitQ).
 * ALGEBRAIC[10] is Qo in component CCaroAL_RC (UnitQ).
 * STATES[59] is V in component ICaroAL_RCL (UnitV).
 * CONSTANTS[95] is R_L_ICA in component Parameters (UnitR).
 * CONSTANTS[96] is C_L_ICA in component Parameters (UnitC).
 * CONSTANTS[97] is L_L_ICA in component Parameters (UnitL).
 * STATES[60] is Pi in component SubAL_RCL (UnitP).
 * ALGEBRAIC[11] is Pi in component UBL_R (UnitP).
 * STATES[61] is Qo in component SubAL_RCL (UnitQ).
 * STATES[62] is Qo2 in component Bif_DAAin_AI1out_SubAL2out (UnitQ).
 * STATES[63] is V in component SubAL_RCL (UnitV).
 * CONSTANTS[98] is R_L_SC in component Parameters (UnitR).
 * CONSTANTS[99] is C_L_SC in component Parameters (UnitC).
 * CONSTANTS[100] is L_L_SC in component Parameters (UnitL).
 * STATES[64] is Pi in component AI_RCL (UnitP).
 * ALGEBRAIC[12] is Pi2 in component Bif_DA1in_AI2in_AOout (UnitP).
 * STATES[65] is Qo in component AI_RCL (UnitQ).
 * ALGEBRAIC[13] is Qo1 in component Bif_DAAin_AI1out_SubAL2out (UnitQ).
 * STATES[66] is V in component AI_RCL (UnitV).
 * CONSTANTS[101] is Risthm in component Parameters (UnitR).
 * CONSTANTS[102] is Cisthm in component Parameters (UnitC).
 * CONSTANTS[103] is Listhm in component Parameters (UnitL).
 * CONSTANTS[104] is Bisthm in component Parameters (UnitK).
 * CONSTANTS[105] is BdAoA in component Parameters (UnitK).
 * STATES[67] is Pi in component LUNG_RC (UnitP).
 * ALGEBRAIC[25] is Qo1 in component Bif_PAin_LUNG1out_DA2out (UnitQ).
 * STATES[68] is V in component LUNG_RC (UnitV).
 * CONSTANTS[106] is Rlung in component Parameters (UnitR).
 * CONSTANTS[107] is Cfoo in component Parameters (UnitC).
 * STATES[69] is Pi in component AO1_RC (UnitP).
 * ALGEBRAIC[14] is Pi in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitP).
 * ALGEBRAIC[34] is Qo in component Bif_DA1in_AI2in_AOout (UnitQ).
 * ALGEBRAIC[26] is Qo in component AO1_RC (UnitQ).
 * STATES[70] is V in component AO1_RC (UnitV).
 * CONSTANTS[108] is Rdtao in component Parameters (UnitR).
 * CONSTANTS[109] is Cao1 in component Parameters (UnitC).
 * STATES[71] is Pi in component KID_RC (UnitP).
 * ALGEBRAIC[44] is Pi1 in component Bif_KID1in_HE2in_LEG3in_IVCout (UnitP).
 * STATES[72] is Qo4 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * ALGEBRAIC[48] is Qo in component KID_RC (UnitQ).
 * STATES[73] is V in component KID_RC (UnitV).
 * CONSTANTS[110] is Rrev in component Parameters (UnitR).
 * CONSTANTS[111] is Ckid in component Parameters (UnitC).
 * STATES[74] is Pi in component INTE_RC (UnitP).
 * ALGEBRAIC[27] is Pi2 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP).
 * STATES[75] is Qo2 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * ALGEBRAIC[35] is Qo in component INTE_RC (UnitQ).
 * STATES[76] is V in component INTE_RC (UnitV).
 * CONSTANTS[112] is Rporv in component Parameters (UnitR).
 * CONSTANTS[113] is Cinte in component Parameters (UnitC).
 * STATES[77] is Pi in component LEG_RC (UnitP).
 * ALGEBRAIC[58] is Pi3 in component Bif_KID1in_HE2in_LEG3in_IVCout (UnitP).
 * ALGEBRAIC[15] is Qo1 in component Bif_AOin_LEG1out_UA2out (UnitQ).
 * ALGEBRAIC[61] is Qo in component LEG_RC (UnitQ).
 * STATES[78] is V in component LEG_RC (UnitV).
 * CONSTANTS[114] is Rfv in component Parameters (UnitR).
 * CONSTANTS[115] is Cleg in component Parameters (UnitC).
 * STATES[79] is Pi in component UA_RC (UnitP).
 * STATES[80] is Pi in component PLAC_RC_prox (UnitP).
 * STATES[81] is Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ).
 * ALGEBRAIC[4] is Qo in component UA_RC (UnitQ).
 * STATES[82] is V in component UA_RC (UnitV).
 * CONSTANTS[116] is Rua in component Parameters (UnitR).
 * CONSTANTS[117] is Cua in component Parameters (UnitC).
 * STATES[83] is Pi in component PLAC_RC (UnitP).
 * ALGEBRAIC[23] is Qo in component PLAC_RC_prox (UnitQ).
 * STATES[84] is V in component PLAC_RC_prox (UnitV).
 * CONSTANTS[118] is Rplac_prox in component Parameters (UnitR).
 * STATES[85] is V in component PLAC_RC (UnitV).
 * CONSTANTS[119] is Rplac in component Parameters (UnitR).
 * CONSTANTS[120] is Cplac in component Parameters (UnitC).
 * STATES[86] is Pi in component HE_RC (UnitP).
 * ALGEBRAIC[52] is Pi2 in component Bif_KID1in_HE2in_LEG3in_IVCout (UnitP).
 * ALGEBRAIC[39] is Qo in component Bif_UV1in_INTE2in_AO3in_HEout (UnitQ).
 * ALGEBRAIC[55] is Qo in component HE_RC (UnitQ).
 * STATES[87] is V in component HE_RC (UnitV).
 * CONSTANTS[121] is Rhv in component Parameters (UnitR).
 * CONSTANTS[122] is Che in component Parameters (UnitC).
 * STATES[88] is Pi in component UBR_RC (UnitP).
 * ALGEBRAIC[67] is Pi1 in component Bif_UBR1in_UBL2in_UBout (UnitP).
 * ALGEBRAIC[16] is Qo in component UBR_R (UnitQ).
 * ALGEBRAIC[69] is Qo in component UBR_RC (UnitQ).
 * STATES[89] is V in component UBR_RC (UnitV).
 * CONSTANTS[123] is R_R_ub in component Parameters (UnitR).
 * CONSTANTS[124] is C_R_ub in component Parameters (UnitC).
 * STATES[90] is Pi in component CCaroAR_RC (UnitP).
 * STATES[91] is Qo2 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ).
 * STATES[92] is V in component CCaroAR_RC (UnitV).
 * CONSTANTS[125] is R_R_CCA in component Parameters (UnitR).
 * CONSTANTS[126] is C_R_CCA in component Parameters (UnitC).
 * STATES[93] is Pi in component BRR_RC (UnitP).
 * ALGEBRAIC[49] is Pi1 in component Bif_BRR1in_BRL2in_BRout (UnitP).
 * ALGEBRAIC[28] is Qo in component BRR_R (UnitQ).
 * ALGEBRAIC[53] is Qo in component BRR_RC (UnitQ).
 * STATES[94] is V in component BRR_RC (UnitV).
 * CONSTANTS[127] is R_R_br in component Parameters (UnitR).
 * CONSTANTS[128] is C_R_br in component Parameters (UnitC).
 * STATES[95] is Pi in component CCaroAL_RC (UnitP).
 * STATES[96] is Qo2 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ).
 * STATES[97] is V in component CCaroAL_RC (UnitV).
 * CONSTANTS[129] is R_L_CCA in component Parameters (UnitR).
 * CONSTANTS[130] is C_L_CCA in component Parameters (UnitC).
 * STATES[98] is Pi in component BRL_RC (UnitP).
 * ALGEBRAIC[56] is Pi2 in component Bif_BRR1in_BRL2in_BRout (UnitP).
 * ALGEBRAIC[36] is Qo in component BRL_R (UnitQ).
 * ALGEBRAIC[59] is Qo in component BRL_RC (UnitQ).
 * STATES[99] is V in component BRL_RC (UnitV).
 * CONSTANTS[131] is R_L_br in component Parameters (UnitR).
 * CONSTANTS[132] is C_L_br in component Parameters (UnitC).
 * STATES[100] is Pi in component UBL_RC (UnitP).
 * ALGEBRAIC[71] is Pi2 in component Bif_UBR1in_UBL2in_UBout (UnitP).
 * ALGEBRAIC[40] is Qo in component UBL_R (UnitQ).
 * ALGEBRAIC[73] is Qo in component UBL_RC (UnitQ).
 * STATES[101] is V in component UBL_RC (UnitV).
 * CONSTANTS[133] is R_L_ub in component Parameters (UnitR).
 * CONSTANTS[134] is C_L_ub in component Parameters (UnitC).
 * CONSTANTS[135] is R_R_ub_p in component Parameters (UnitR).
 * CONSTANTS[136] is R_R_br_p in component Parameters (UnitR).
 * CONSTANTS[137] is R_L_br_p in component Parameters (UnitR).
 * CONSTANTS[138] is R_L_ub_p in component Parameters (UnitR).
 * ALGEBRAIC[194] is Pi in component Coronary_R (UnitP).
 * ALGEBRAIC[191] is Pi4 in component Bif_SVC1in_IVC2in_DV3in_Coronary4in_RAout (UnitP).
 * STATES[102] is Qo2 in component Bif_LVin_AA1out_Coronary2out (UnitQ).
 * ALGEBRAIC[178] is Qo in component Coronary_R (UnitQ).
 * ALGEBRAIC[181] is R in component Coronary_R (UnitR).
 * CONSTANTS[139] is R0_Coronary in component Parameters (UnitR).
 * CONSTANTS[140] is k_Coronary in component Parameters (dimensionless).
 * CONSTANTS[141] is n_Coronary in component Parameters (dimensionless).
 * CONSTANTS[142] is Ps_Coronary in component Parameters (UnitP).
 * CONSTANTS[143] is Rfoo in component Parameters (UnitR).
 * CONSTANTS[144] is L_R_CCA in component Parameters (UnitL).
 * CONSTANTS[145] is L_L_CCA in component Parameters (UnitL).
 * CONSTANTS[146] is Rfa in component Parameters (UnitR).
 * CONSTANTS[147] is L_R_CCO in component Parameters (UnitL).
 * ALGEBRAIC[41] is Pi1 in component Bif_DA1in_AI2in_AOout (UnitP).
 * STATES[103] is Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ).
 * CONSTANTS[148] is Rda in component Parameters (UnitR).
 * CONSTANTS[149] is Bda in component Parameters (UnitK).
 * CONSTANTS[150] is Bmpa in component Parameters (UnitK).
 * CONSTANTS[151] is Lda in component Parameters (UnitL).
 * ALGEBRAIC[195] is Pi in component Bif_DVin_FO1out_RA2out (UnitP).
 * ALGEBRAIC[190] is Pi1 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP).
 * ALGEBRAIC[182] is Qo1 in component Bif_UVin_DV1out_HE2out (UnitQ).
 * STATES[104] is Qo2 in component Bif_UVin_DV1out_HE2out (UnitQ).
 * CONSTANTS[152] is Rha in component Parameters (UnitR).
 * ALGEBRAIC[117] is Pi2 in component Bif_DV1in_IVC2in_FOout (UnitP).
 * ALGEBRAIC[127] is Pi2 in component Bif_SVC1in_IVC2in_DV3in_Coronary4in_RAout (UnitP).
 * ALGEBRAIC[114] is Qo1 in component Bif_IVCin_FO1out_RA2out (UnitQ).
 * STATES[105] is Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ).
 * CONSTANTS[153] is Rivc_la in component Parameters (UnitR).
 * CONSTANTS[154] is Rivc_ra in component Parameters (UnitR).
 * STATES[106] is Pi1 in component Bif_DV1in_IVC2in_FOout (UnitP).
 * ALGEBRAIC[193] is Pi3 in component Bif_SVC1in_IVC2in_DV3in_Coronary4in_RAout (UnitP).
 * STATES[107] is Qo1 in component Bif_DVin_FO1out_RA2out (UnitQ).
 * ALGEBRAIC[185] is Qo2 in component Bif_DVin_FO1out_RA2out (UnitQ).
 * ALGEBRAIC[17] is v1 in component Bif_DVin_FO1out_RA2out (UnitVel).
 * CONSTANTS[155] is Rdv_fo in component Parameters (UnitR).
 * CONSTANTS[156] is Kdv_fo in component Parameters (UnitK).
 * CONSTANTS[157] is Adv in component Parameters (UnitA).
 * CONSTANTS[158] is Rdv_ra in component Parameters (UnitR).
 * CONSTANTS[159] is Kdv_ra in component Parameters (UnitK).
 * CONSTANTS[160] is Ldv in component Parameters (UnitL).
 * ALGEBRAIC[29] is Pi3 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP).
 * STATES[108] is Qo3 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * CONSTANTS[161] is Rmea in component Parameters (UnitR).
 * CONSTANTS[162] is Relg in component Parameters (UnitR).
 * CONSTANTS[163] is Rrea in component Parameters (UnitR).
 * ALGEBRAIC[45] is Pi1 in component Bif_BR1in_UB2in_SVCout (UnitP).
 * ALGEBRAIC[62] is Qo in component Bif_BRR1in_BRL2in_BRout (UnitQ).
 * ALGEBRAIC[65] is Pi2 in component Bif_BR1in_UB2in_SVCout (UnitP).
 * ALGEBRAIC[75] is Qo in component Bif_UBR1in_UBL2in_UBout (UnitQ).
 * ALGEBRAIC[118] is Pi2 in component Bif_LUNG1in_FO2in_LAout (UnitP).
 * STATES[109] is Qo in component Bif_DV1in_IVC2in_FOout (UnitQ).
 * STATES[110] is V in component Bif_DV1in_IVC2in_FOout (UnitV).
 * CONSTANTS[164] is Kfo in component Parameters (UnitKfo).
 * CONSTANTS[165] is Kfovo in component Parameters (UnitKxi).
 * CONSTANTS[166] is Kfovc_p in component Parameters (UnitKxi).
 * CONSTANTS[167] is Kfovc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[128] is Linductance in component Bif_DV1in_IVC2in_FOout (UnitL).
 * CONSTANTS[168] is L_min_fo in component Parameters (UnitL).
 * STATES[111] is xi in component Bif_DV1in_IVC2in_FOout (dimensionless).
 * ALGEBRAIC[122] is val_xi in component Bif_DV1in_IVC2in_FOout (ode_s).
 * ALGEBRAIC[123] is Aeff in component Bif_DV1in_IVC2in_FOout (UnitA).
 * CONSTANTS[169] is Afo in component Parameters (UnitA).
 * RATES[1] is d/dt C in component LA (dimensionless).
 * RATES[0] is d/dt Lsc in component LA (Unitl).
 * RATES[2] is d/dt Vcav in component LA (UnitV).
 * RATES[3] is d/dt Qo in component LA (UnitQ).
 * RATES[4] is d/dt xi in component LA (dimensionless).
 * RATES[6] is d/dt C in component RA (dimensionless).
 * RATES[5] is d/dt Lsc in component RA (Unitl).
 * RATES[7] is d/dt Vcav in component RA (UnitV).
 * RATES[8] is d/dt Qo in component RA (UnitQ).
 * RATES[9] is d/dt xi in component RA (dimensionless).
 * RATES[11] is d/dt C in component RV (dimensionless).
 * RATES[10] is d/dt Lsc in component RV (Unitl).
 * RATES[12] is d/dt Vcav in component RV (UnitV).
 * RATES[14] is d/dt Qo in component RV (UnitQ).
 * RATES[15] is d/dt xi in component RV (dimensionless).
 * RATES[17] is d/dt C in component LV (dimensionless).
 * RATES[16] is d/dt Lsc in component LV (Unitl).
 * RATES[18] is d/dt Vcav in component LV (UnitV).
 * RATES[19] is d/dt Qo in component LV (UnitQ).
 * RATES[20] is d/dt xi in component LV (dimensionless).
 * RATES[21] is d/dt Pi in component AA_RCL (UnitP).
 * RATES[22] is d/dt Qo in component AA_RCL (UnitQ).
 * RATES[23] is d/dt V in component AA_RCL (UnitV).
 * RATES[24] is d/dt Pi in component AAA_RCL (UnitP).
 * RATES[25] is d/dt Qo in component AAA_RCL (UnitQ).
 * RATES[26] is d/dt V in component AAA_RCL (UnitV).
 * RATES[27] is d/dt Pi in component DAA_RCL (UnitP).
 * RATES[28] is d/dt Qo in component DAA_RCL (UnitQ).
 * RATES[29] is d/dt V in component DAA_RCL (UnitV).
 * RATES[13] is d/dt Pi in component PA_RCL (UnitP).
 * RATES[30] is d/dt Qo in component PA_RCL (UnitQ).
 * RATES[31] is d/dt V in component PA_RCL (UnitV).
 * RATES[32] is d/dt Pi in component LUNG_RCL (UnitP).
 * RATES[33] is d/dt Qo in component LUNG_RCL (UnitQ).
 * RATES[34] is d/dt V in component LUNG_RCL (UnitV).
 * RATES[35] is d/dt Pi in component SVC_RCL (UnitP).
 * RATES[36] is d/dt Qo in component SVC_RCL (UnitQ).
 * RATES[37] is d/dt V in component SVC_RCL (UnitV).
 * RATES[38] is d/dt Pi in component AO2_RCL (UnitP).
 * RATES[39] is d/dt Qo in component AO2_RCL (UnitQ).
 * RATES[40] is d/dt V in component AO2_RCL (UnitV).
 * RATES[41] is d/dt Pi in component UV_RCL (UnitP).
 * RATES[42] is d/dt Qo in component UV_RCL (UnitQ).
 * RATES[43] is d/dt V in component UV_RCL (UnitV).
 * RATES[44] is d/dt Pi in component IVC_RCL (UnitP).
 * RATES[45] is d/dt Qo in component IVC_RCL (UnitQ).
 * RATES[46] is d/dt V in component IVC_RCL (UnitV).
 * RATES[47] is d/dt Pi in component BrachT_RCL (UnitP).
 * RATES[48] is d/dt Qo in component BrachT_RCL (UnitQ).
 * RATES[50] is d/dt V in component BrachT_RCL (UnitV).
 * RATES[51] is d/dt Pi in component SubAR_RCL (UnitP).
 * RATES[52] is d/dt Qo in component SubAR_RCL (UnitQ).
 * RATES[53] is d/dt V in component SubAR_RCL (UnitV).
 * RATES[54] is d/dt Pi in component ICaroAR_RCL (UnitP).
 * RATES[55] is d/dt Qo in component ICaroAR_RCL (UnitQ).
 * RATES[56] is d/dt V in component ICaroAR_RCL (UnitV).
 * RATES[57] is d/dt Pi in component ICaroAL_RCL (UnitP).
 * RATES[58] is d/dt Qo in component ICaroAL_RCL (UnitQ).
 * RATES[59] is d/dt V in component ICaroAL_RCL (UnitV).
 * RATES[60] is d/dt Pi in component SubAL_RCL (UnitP).
 * RATES[61] is d/dt Qo in component SubAL_RCL (UnitQ).
 * RATES[63] is d/dt V in component SubAL_RCL (UnitV).
 * RATES[64] is d/dt Pi in component AI_RCL (UnitP).
 * RATES[65] is d/dt Qo in component AI_RCL (UnitQ).
 * RATES[66] is d/dt V in component AI_RCL (UnitV).
 * RATES[67] is d/dt Pi in component LUNG_RC (UnitP).
 * RATES[68] is d/dt V in component LUNG_RC (UnitV).
 * RATES[69] is d/dt Pi in component AO1_RC (UnitP).
 * RATES[70] is d/dt V in component AO1_RC (UnitV).
 * RATES[71] is d/dt Pi in component KID_RC (UnitP).
 * RATES[73] is d/dt V in component KID_RC (UnitV).
 * RATES[74] is d/dt Pi in component INTE_RC (UnitP).
 * RATES[76] is d/dt V in component INTE_RC (UnitV).
 * RATES[77] is d/dt Pi in component LEG_RC (UnitP).
 * RATES[78] is d/dt V in component LEG_RC (UnitV).
 * RATES[79] is d/dt Pi in component UA_RC (UnitP).
 * RATES[82] is d/dt V in component UA_RC (UnitV).
 * RATES[80] is d/dt Pi in component PLAC_RC_prox (UnitP).
 * RATES[84] is d/dt V in component PLAC_RC_prox (UnitV).
 * RATES[83] is d/dt Pi in component PLAC_RC (UnitP).
 * RATES[85] is d/dt V in component PLAC_RC (UnitV).
 * RATES[86] is d/dt Pi in component HE_RC (UnitP).
 * RATES[87] is d/dt V in component HE_RC (UnitV).
 * RATES[88] is d/dt Pi in component UBR_RC (UnitP).
 * RATES[89] is d/dt V in component UBR_RC (UnitV).
 * RATES[90] is d/dt Pi in component CCaroAR_RC (UnitP).
 * RATES[92] is d/dt V in component CCaroAR_RC (UnitV).
 * RATES[93] is d/dt Pi in component BRR_RC (UnitP).
 * RATES[94] is d/dt V in component BRR_RC (UnitV).
 * RATES[95] is d/dt Pi in component CCaroAL_RC (UnitP).
 * RATES[97] is d/dt V in component CCaroAL_RC (UnitV).
 * RATES[98] is d/dt Pi in component BRL_RC (UnitP).
 * RATES[99] is d/dt V in component BRL_RC (UnitV).
 * RATES[100] is d/dt Pi in component UBL_RC (UnitP).
 * RATES[101] is d/dt V in component UBL_RC (UnitV).
 * RATES[91] is d/dt Qo2 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ).
 * RATES[49] is d/dt Qo2 in component Bif_AAin_AAA1out_BrachT2out (UnitQ).
 * RATES[96] is d/dt Qo2 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ).
 * RATES[62] is d/dt Qo2 in component Bif_DAAin_AI1out_SubAL2out (UnitQ).
 * RATES[81] is d/dt Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ).
 * RATES[102] is d/dt Qo2 in component Bif_LVin_AA1out_Coronary2out (UnitQ).
 * RATES[103] is d/dt Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ).
 * RATES[104] is d/dt Qo2 in component Bif_UVin_DV1out_HE2out (UnitQ).
 * RATES[105] is d/dt Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ).
 * RATES[107] is d/dt Qo1 in component Bif_DVin_FO1out_RA2out (UnitQ).
 * RATES[75] is d/dt Qo2 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * RATES[108] is d/dt Qo3 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * RATES[72] is d/dt Qo4 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * RATES[110] is d/dt V in component Bif_DV1in_IVC2in_FOout (UnitV).
 * RATES[106] is d/dt Pi1 in component Bif_DV1in_IVC2in_FOout (UnitP).
 * RATES[109] is d/dt Qo in component Bif_DV1in_IVC2in_FOout (UnitQ).
 * RATES[111] is d/dt xi in component Bif_DV1in_IVC2in_FOout (dimensionless).
 */
void
initConsts(double* CONSTANTS, double* RATES, double *STATES)
{
CONSTANTS[0] = 2.;
STATES[0] = 2.;
CONSTANTS[1] = 2.;
CONSTANTS[2] = 0.10;
CONSTANTS[3] = 0.18;
CONSTANTS[4] = 0.16;
STATES[1] = 0.0;
CONSTANTS[5] = 0.0;
STATES[2] = 26.74;
CONSTANTS[6] = 26.74;
CONSTANTS[7] = 1.7573;
CONSTANTS[8] = 82.6136;
CONSTANTS[9] = 127.428;
CONSTANTS[10] = 10.5;
CONSTANTS[11] = 0.325;
CONSTANTS[12] = 0.02;
CONSTANTS[13] = 4.5983;
CONSTANTS[14] = 10.113716337394823;
CONSTANTS[15] = 2.25;
STATES[3] = 0.;
CONSTANTS[16] = 0.;
CONSTANTS[17] = 0.43;
CONSTANTS[18] = 74.41915686963517;
CONSTANTS[19] = 99.21934;
CONSTANTS[20] = 186.04789;
CONSTANTS[21] = 0.0011665;
CONSTANTS[22] = 0.00034289;
STATES[4] = 1.0;
CONSTANTS[23] = 0.553;
CONSTANTS[24] = 3.975e-4;
STATES[5] = 2.;
STATES[6] = 0.0;
STATES[7] = 26.74;
CONSTANTS[25] = 26.74;
CONSTANTS[26] = 1.7573;
CONSTANTS[27] = 0.325;
CONSTANTS[28] = 4.5983;
CONSTANTS[29] = 10.113716337394823;
STATES[8] = 0.;
CONSTANTS[30] = 74.41915686963517;
CONSTANTS[31] = 99.21934;
CONSTANTS[32] = 186.04789;
CONSTANTS[33] = 0.0011665;
STATES[9] = 1.0;
CONSTANTS[34] = 0.596;
STATES[10] = 2.;
CONSTANTS[35] = 0.28;
CONSTANTS[36] = 0.14;
CONSTANTS[37] = 0.08;
STATES[11] = 0.0;
STATES[12] = 26.74;
CONSTANTS[38] = 26.74;
CONSTANTS[39] = 8.9973;
CONSTANTS[40] = 18.4;
CONSTANTS[41] = 246;
CONSTANTS[42] = 7.;
CONSTANTS[43] = 0.375;
CONSTANTS[44] = 4.5983;
CONSTANTS[45] = 22.7025;
CONSTANTS[46] = 3.;
STATES[13] = 0.;
STATES[14] = 0.;
CONSTANTS[47] = 186.04789;
CONSTANTS[48] = 49.61897;
CONSTANTS[49] = 186.04789;
CONSTANTS[50] = 0.002333078603077328;
STATES[15] = 1.0;
CONSTANTS[51] = 0.493;
STATES[16] = 2.;
STATES[17] = 0.0;
STATES[18] = 26.74;
CONSTANTS[52] = 26.74;
CONSTANTS[53] = 8.9973;
CONSTANTS[54] = 0.375;
CONSTANTS[55] = 4.5983;
CONSTANTS[56] = 22.7025;
STATES[19] = 0.;
CONSTANTS[57] = 186.04789;
CONSTANTS[58] = 29.76766;
CONSTANTS[59] = 186.04789;
CONSTANTS[60] = 0.0011665;
STATES[20] = 1.0;
CONSTANTS[61] = 0.410;
STATES[21] = 0.;
STATES[22] = 0.;
STATES[23] = 0;
CONSTANTS[62] = 0.00733;
CONSTANTS[63] = 0.0708;
CONSTANTS[64] = 0.0000521;
CONSTANTS[65] = 0.;
STATES[24] = 0.;
STATES[25] = 0.;
STATES[26] = 0;
CONSTANTS[66] = 0.0059;
CONSTANTS[67] = 0.00209;
CONSTANTS[68] = 0.0000209;
STATES[27] = 0.;
STATES[28] = 0.;
STATES[29] = 0;
CONSTANTS[69] = 0.00832;
CONSTANTS[70] = 0.00176;
CONSTANTS[71] = 0.000028;
STATES[30] = 0.;
STATES[31] = 0;
CONSTANTS[72] = 0.00448;
CONSTANTS[73] = 0.08455;
CONSTANTS[74] = 0.00243;
STATES[32] = 0.;
STATES[33] = 0.;
STATES[34] = 0;
CONSTANTS[75] = 2.2691;
CONSTANTS[76] = 0.33821;
CONSTANTS[77] = 0.00001;
STATES[35] = 0.;
STATES[36] = 0.;
STATES[37] = 0;
CONSTANTS[78] = 0.2276;
CONSTANTS[79] = 0.8455;
STATES[38] = 0.;
STATES[39] = 0.;
STATES[40] = 0;
CONSTANTS[80] = 0.06807;
CONSTANTS[81] = 0.04228;
STATES[41] = 0.;
STATES[42] = 0.;
STATES[43] = 0;
CONSTANTS[82] = 0.2803;
CONSTANTS[83] = 0.25366;
STATES[44] = 0.;
STATES[45] = 0.;
STATES[46] = 0;
CONSTANTS[84] = 0.00171;
CONSTANTS[85] = 0.50732;
STATES[47] = 0.;
STATES[48] = 0.;
STATES[49] = 0.;
STATES[50] = 0;
CONSTANTS[86] = 0.02529;
CONSTANTS[87] = 0.001907;
CONSTANTS[88] = 0.0000411;
STATES[51] = 0.;
STATES[52] = 0.;
STATES[53] = 0;
CONSTANTS[89] = 0.16147;
CONSTANTS[90] = 0.000844;
CONSTANTS[91] = 0.000125;
STATES[54] = 0.;
STATES[55] = 0.;
STATES[56] = 0;
CONSTANTS[92] = 0.6324;
CONSTANTS[93] = 0.001015;
CONSTANTS[94] = 0.000469;
STATES[57] = 0.;
STATES[58] = 0.;
STATES[59] = 0;
CONSTANTS[95] = 0.6324;
CONSTANTS[96] = 0.001015;
CONSTANTS[97] = 0.000469;
STATES[60] = 0.;
STATES[61] = 0.;
STATES[62] = 0.;
STATES[63] = 0;
CONSTANTS[98] = 0.16147;
CONSTANTS[99] = 0.000844;
CONSTANTS[100] = 0.000125;
STATES[64] = 0.;
STATES[65] = 0.;
STATES[66] = 0;
CONSTANTS[101] = 0.00782;
CONSTANTS[102] = 0.001504;
CONSTANTS[103] = 0.0000104;
CONSTANTS[104] = 0.00743;
CONSTANTS[105] = 0.00576;
STATES[67] = 0.;
STATES[68] = 0;
CONSTANTS[106] = 9.7;
CONSTANTS[107] = 0.0005;
STATES[69] = 0.;
STATES[70] = 0;
CONSTANTS[108] = 0.04887;
CONSTANTS[109] = 0.07;
STATES[71] = 0.;
STATES[72] = 0.;
STATES[73] = 0;
CONSTANTS[110] = 15.88;
CONSTANTS[111] = 0.01691;
STATES[74] = 0.;
STATES[75] = 0.;
STATES[76] = 0;
CONSTANTS[112] = 7.94122;
CONSTANTS[113] = 0.21138;
STATES[77] = 0.;
STATES[78] = 0;
CONSTANTS[114] = 0.68074;
CONSTANTS[115] = 3.38212;
STATES[79] = 0.;
STATES[80] = 0.;
STATES[81] = 0.;
STATES[82] = 0;
CONSTANTS[116] = 1.5274;
CONSTANTS[117] = 0.013686;
STATES[83] = 0.;
STATES[84] = 0;
CONSTANTS[118] = 2;
STATES[85] = 0;
CONSTANTS[119] = 2.67;
CONSTANTS[120] = 1.2683;
STATES[86] = 0.;
STATES[87] = 0;
CONSTANTS[121] = 0.16005;
CONSTANTS[122] = 2.53659;
STATES[88] = 0.;
STATES[89] = 0;
CONSTANTS[123] = 48;
CONSTANTS[124] = 0.22998;
STATES[90] = 0.;
STATES[91] = 0.;
STATES[92] = 0;
CONSTANTS[125] = 0.259;
CONSTANTS[126] = 0.00262;
STATES[93] = 0.;
STATES[94] = 0;
CONSTANTS[127] = 15.5;
CONSTANTS[128] = 0.01573;
STATES[95] = 0.;
STATES[96] = 0.;
STATES[97] = 0;
CONSTANTS[129] = 0.3706;
CONSTANTS[130] = 0.00374;
STATES[98] = 0.;
STATES[99] = 0;
CONSTANTS[131] = 15.5;
CONSTANTS[132] = 0.01573;
STATES[100] = 0.;
STATES[101] = 0;
CONSTANTS[133] = 48;
CONSTANTS[134] = 0.07187;
CONSTANTS[135] = 18;
CONSTANTS[136] = 1;
CONSTANTS[137] = 1;
CONSTANTS[138] = 18;
STATES[102] = 0.;
CONSTANTS[139] = 48;
CONSTANTS[140] = 10;
CONSTANTS[141] = 1;
CONSTANTS[142] = 25;
CONSTANTS[143] = 0.00001;
CONSTANTS[144] = 0.0003003;
CONSTANTS[145] = 0.0003575;
CONSTANTS[146] = 10.5;
CONSTANTS[147] = 0.0003003;
STATES[103] = 0.;
CONSTANTS[148] = 0.02766;
CONSTANTS[149] = 0.01346;
CONSTANTS[150] = 0.001537;
CONSTANTS[151] = 0.0000894;
STATES[104] = 0.;
CONSTANTS[152] = 0.25;
STATES[105] = 0.;
CONSTANTS[153] = 0.20923;
CONSTANTS[154] = 0.38857;
STATES[106] = 0.;
STATES[107] = 0.;
CONSTANTS[155] = 1.5522;
CONSTANTS[156] = 0.306;
CONSTANTS[157] = 0.0157;
CONSTANTS[158] = 29.492;
CONSTANTS[159] = 5.81;
CONSTANTS[160] = 0.00005;
STATES[108] = 0.;
CONSTANTS[161] = 38.572;
CONSTANTS[162] = 91.8888;
CONSTANTS[163] = 19.853;
STATES[109] = 0.;
STATES[110] = 0;
CONSTANTS[164] = 0.19018;
CONSTANTS[165] = 180;
CONSTANTS[166] = 1000;
CONSTANTS[167] = 1000;
CONSTANTS[168] = 0.0011665;
STATES[111] = 1.0;
CONSTANTS[169] = 0.471;
CONSTANTS[170] = CONSTANTS[2];
CONSTANTS[171] = CONSTANTS[2];
CONSTANTS[172] = CONSTANTS[35];
CONSTANTS[173] = CONSTANTS[35];
CONSTANTS[174] =  CONSTANTS[3]*CONSTANTS[170];
CONSTANTS[175] =  CONSTANTS[4]*CONSTANTS[170];
CONSTANTS[176] =  CONSTANTS[3]*CONSTANTS[171];
CONSTANTS[177] =  CONSTANTS[4]*CONSTANTS[171];
CONSTANTS[178] =  CONSTANTS[36]*CONSTANTS[172];
CONSTANTS[179] =  CONSTANTS[37]*CONSTANTS[172];
CONSTANTS[180] =  CONSTANTS[36]*CONSTANTS[173];
CONSTANTS[181] =  CONSTANTS[37]*CONSTANTS[173];
}
void
computeRates(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC)
{
RATES[12] = STATES[8] - STATES[14];
RATES[18] = STATES[3] - STATES[19];
RATES[13] = (STATES[14] - STATES[30])/CONSTANTS[73];
RATES[31] = STATES[14] - STATES[30];
RATES[47] = (STATES[49] - STATES[48])/CONSTANTS[87];
RATES[50] = STATES[49] - STATES[48];
RATES[60] = (STATES[62] - STATES[61])/CONSTANTS[99];
RATES[63] = STATES[62] - STATES[61];
ALGEBRAIC[1] = STATES[22] - STATES[49];
RATES[24] = (ALGEBRAIC[1] - STATES[25])/CONSTANTS[67];
RATES[26] = ALGEBRAIC[1] - STATES[25];
ALGEBRAIC[2] = STATES[25] - STATES[96];
RATES[27] = (ALGEBRAIC[2] - STATES[28])/CONSTANTS[70];
RATES[29] = ALGEBRAIC[2] - STATES[28];
ALGEBRAIC[3] = (STATES[67] - STATES[32])/CONSTANTS[106];
RATES[32] = (ALGEBRAIC[3] - STATES[33])/CONSTANTS[76];
RATES[34] = ALGEBRAIC[3] - STATES[33];
ALGEBRAIC[6] = STATES[48] - STATES[91];
RATES[51] = (ALGEBRAIC[6] - STATES[52])/CONSTANTS[90];
ALGEBRAIC[5] = STATES[88]+ CONSTANTS[135]*STATES[52];
RATES[52] = ((STATES[51] - ALGEBRAIC[5]) -  CONSTANTS[89]*STATES[52])/CONSTANTS[91];
RATES[53] = ALGEBRAIC[6] - STATES[52];
ALGEBRAIC[8] = (STATES[90] - STATES[54])/CONSTANTS[125];
RATES[54] = (ALGEBRAIC[8] - STATES[55])/CONSTANTS[93];
ALGEBRAIC[7] = STATES[93]+ CONSTANTS[136]*STATES[55];
RATES[55] = ((STATES[54] - ALGEBRAIC[7]) -  CONSTANTS[92]*STATES[55])/CONSTANTS[94];
RATES[56] = ALGEBRAIC[8] - STATES[55];
ALGEBRAIC[10] = (STATES[95] - STATES[57])/CONSTANTS[129];
RATES[57] = (ALGEBRAIC[10] - STATES[58])/CONSTANTS[96];
ALGEBRAIC[9] = STATES[98]+ CONSTANTS[137]*STATES[58];
RATES[58] = ((STATES[57] - ALGEBRAIC[9]) -  CONSTANTS[95]*STATES[58])/CONSTANTS[97];
RATES[59] = ALGEBRAIC[10] - STATES[58];
ALGEBRAIC[11] = STATES[100]+ CONSTANTS[138]*STATES[61];
RATES[61] = ((STATES[60] - ALGEBRAIC[11]) -  CONSTANTS[98]*STATES[61])/CONSTANTS[100];
ALGEBRAIC[13] = STATES[28] - STATES[62];
RATES[64] = (ALGEBRAIC[13] - STATES[65])/CONSTANTS[102];
ALGEBRAIC[12] = STATES[69];
RATES[65] = (((STATES[64] - ALGEBRAIC[12]) -  CONSTANTS[101]*STATES[65]) -  (CONSTANTS[104] - CONSTANTS[105])*STATES[65]*fabs(STATES[65]))/CONSTANTS[103];
RATES[66] = ALGEBRAIC[13] - STATES[65];
ALGEBRAIC[4] = (STATES[79] - STATES[80])/CONSTANTS[116];
RATES[79] = (STATES[81] - ALGEBRAIC[4])/CONSTANTS[117];
RATES[82] = STATES[81] - ALGEBRAIC[4];
RATES[90] = (STATES[91] - ALGEBRAIC[8])/CONSTANTS[126];
RATES[92] = STATES[91] - ALGEBRAIC[8];
RATES[95] = (STATES[96] - ALGEBRAIC[10])/CONSTANTS[130];
RATES[97] = STATES[96] - ALGEBRAIC[10];
ALGEBRAIC[14] = STATES[38];
RATES[75] = ((ALGEBRAIC[14] - STATES[74]) -  CONSTANTS[161]*STATES[75])/CONSTANTS[77];
RATES[72] = ((ALGEBRAIC[14] - STATES[71]) -  CONSTANTS[163]*STATES[72])/CONSTANTS[77];
ALGEBRAIC[19] = STATES[24]+ CONSTANTS[143]*ALGEBRAIC[1];
RATES[22] = ((STATES[21] - ALGEBRAIC[19]) -  CONSTANTS[62]*STATES[22])/CONSTANTS[64];
ALGEBRAIC[20] = STATES[27]+ CONSTANTS[143]*ALGEBRAIC[2];
RATES[25] = ((STATES[24] - ALGEBRAIC[20]) -  CONSTANTS[66]*STATES[25])/CONSTANTS[68];
ALGEBRAIC[21] = STATES[64]+ CONSTANTS[143]*ALGEBRAIC[13];
RATES[28] = ((STATES[27] - ALGEBRAIC[21]) -  CONSTANTS[69]*STATES[28])/CONSTANTS[71];
ALGEBRAIC[15] = STATES[39] - STATES[81];
ALGEBRAIC[22] = STATES[77]+ CONSTANTS[146]*ALGEBRAIC[15];
RATES[39] = ((STATES[38] - ALGEBRAIC[22]) -  CONSTANTS[80]*STATES[39])/CONSTANTS[77];
ALGEBRAIC[24] = STATES[51]+ CONSTANTS[143]*ALGEBRAIC[6];
RATES[48] = ((STATES[47] - ALGEBRAIC[24]) -  CONSTANTS[86]*STATES[48])/CONSTANTS[88];
ALGEBRAIC[25] = STATES[30] - STATES[103];
RATES[67] = (ALGEBRAIC[25] - ALGEBRAIC[3])/CONSTANTS[107];
RATES[68] = ALGEBRAIC[25] - ALGEBRAIC[3];
ALGEBRAIC[23] = (STATES[80] - STATES[83])/CONSTANTS[118];
RATES[80] = (ALGEBRAIC[4] - ALGEBRAIC[23])/CONSTANTS[107];
RATES[84] = ALGEBRAIC[4] - ALGEBRAIC[23];
RATES[91] = ((ALGEBRAIC[24] - STATES[90]) -  CONSTANTS[143]*STATES[91])/CONSTANTS[144];
RATES[49] = ((ALGEBRAIC[19] - STATES[47]) -  CONSTANTS[143]*STATES[49])/CONSTANTS[77];
RATES[96] = ((ALGEBRAIC[20] - STATES[95]) -  CONSTANTS[143]*STATES[96])/CONSTANTS[145];
RATES[62] = ((ALGEBRAIC[21] - STATES[60]) -  CONSTANTS[143]*STATES[62])/CONSTANTS[77];
RATES[81] = ((ALGEBRAIC[22] - STATES[79]) -  CONSTANTS[143]*STATES[81])/CONSTANTS[77];
ALGEBRAIC[29] = STATES[86];
RATES[108] = ((ALGEBRAIC[14] - ALGEBRAIC[29]) -  CONSTANTS[162]*STATES[108])/CONSTANTS[77];
ALGEBRAIC[31] = STATES[67]+ CONSTANTS[143]*ALGEBRAIC[25];
RATES[30] = ((STATES[13] - ALGEBRAIC[31]) -  CONSTANTS[72]*STATES[30])/CONSTANTS[74];
ALGEBRAIC[26] = (STATES[69] - ALGEBRAIC[14])/CONSTANTS[108];
ALGEBRAIC[32] = ((ALGEBRAIC[26] - STATES[75]) - STATES[108]) - STATES[72];
RATES[38] = (ALGEBRAIC[32] - STATES[39])/CONSTANTS[81];
RATES[40] = ALGEBRAIC[32] - STATES[39];
ALGEBRAIC[33] = (STATES[83] - STATES[41])/CONSTANTS[119];
RATES[41] = (ALGEBRAIC[33] - STATES[42])/CONSTANTS[83];
RATES[43] = ALGEBRAIC[33] - STATES[42];
ALGEBRAIC[34] = STATES[103]+STATES[65];
RATES[69] = (ALGEBRAIC[34] - ALGEBRAIC[26])/CONSTANTS[109];
RATES[70] = ALGEBRAIC[34] - ALGEBRAIC[26];
ALGEBRAIC[27] = STATES[86];
ALGEBRAIC[35] = (STATES[74] - ALGEBRAIC[27])/CONSTANTS[112];
RATES[74] = (STATES[75] - ALGEBRAIC[35])/CONSTANTS[113];
RATES[76] = STATES[75] - ALGEBRAIC[35];
RATES[83] = (ALGEBRAIC[23] - ALGEBRAIC[33])/CONSTANTS[120];
RATES[85] = ALGEBRAIC[23] - ALGEBRAIC[33];
ALGEBRAIC[41] = STATES[69];
RATES[103] = (((ALGEBRAIC[31] - ALGEBRAIC[41]) -  CONSTANTS[148]*STATES[103]) -  (CONSTANTS[149] - CONSTANTS[150])*STATES[103]*fabs(STATES[103]))/CONSTANTS[151];
ALGEBRAIC[44] = STATES[44];
ALGEBRAIC[48] = (STATES[71] - ALGEBRAIC[44])/CONSTANTS[110];
RATES[71] = (STATES[72] - ALGEBRAIC[48])/CONSTANTS[111];
RATES[73] = STATES[72] - ALGEBRAIC[48];
ALGEBRAIC[30] = fmax((STATES[0] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[0] = ((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17]))/CONSTANTS[174];
ALGEBRAIC[18] = fmin(8.00000, fmax(ALGEBRAIC[0], 0.00000));
ALGEBRAIC[42] = (  tanh( 4.00000*pow(ALGEBRAIC[30], 2.00000))*pow(ALGEBRAIC[18], 3.00000)*exp(- ALGEBRAIC[18])*pow(8.00000 - ALGEBRAIC[18], 2.00000)*0.0200000)/CONSTANTS[174];
ALGEBRAIC[37] =  CONSTANTS[170]*(0.650000+ 0.700000*ALGEBRAIC[30]);
ALGEBRAIC[46] = (((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17])) - ALGEBRAIC[37])/CONSTANTS[175];
ALGEBRAIC[50] = (0.500000+ 0.500000* sin( (ALGEBRAIC[46]/fabs(ALGEBRAIC[46]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[46]))))/CONSTANTS[175];
RATES[1] = ALGEBRAIC[42] -  STATES[1]*ALGEBRAIC[50];
ALGEBRAIC[28] = STATES[55];
ALGEBRAIC[45] = STATES[35];
ALGEBRAIC[49] = ALGEBRAIC[45];
ALGEBRAIC[53] = (STATES[93] - ALGEBRAIC[49])/CONSTANTS[127];
RATES[93] = (ALGEBRAIC[28] - ALGEBRAIC[53])/CONSTANTS[128];
RATES[94] = ALGEBRAIC[28] - ALGEBRAIC[53];
ALGEBRAIC[39] = STATES[104]+ALGEBRAIC[35]+STATES[108];
ALGEBRAIC[52] = STATES[44];
ALGEBRAIC[55] = (STATES[86] - ALGEBRAIC[52])/CONSTANTS[121];
RATES[86] = (ALGEBRAIC[39] - ALGEBRAIC[55])/CONSTANTS[122];
RATES[87] = ALGEBRAIC[39] - ALGEBRAIC[55];
ALGEBRAIC[36] = STATES[58];
ALGEBRAIC[56] = ALGEBRAIC[45];
ALGEBRAIC[59] = (STATES[98] - ALGEBRAIC[56])/CONSTANTS[131];
RATES[98] = (ALGEBRAIC[36] - ALGEBRAIC[59])/CONSTANTS[132];
RATES[99] = ALGEBRAIC[36] - ALGEBRAIC[59];
ALGEBRAIC[58] = STATES[44];
ALGEBRAIC[61] = (STATES[77] - ALGEBRAIC[58])/CONSTANTS[114];
RATES[77] = (ALGEBRAIC[15] - ALGEBRAIC[61])/CONSTANTS[115];
RATES[78] = ALGEBRAIC[15] - ALGEBRAIC[61];
ALGEBRAIC[64] = ALGEBRAIC[48]+ALGEBRAIC[55]+ALGEBRAIC[61];
RATES[44] = (ALGEBRAIC[64] - STATES[45])/CONSTANTS[85];
RATES[46] = ALGEBRAIC[64] - STATES[45];
ALGEBRAIC[16] = STATES[52];
ALGEBRAIC[65] = STATES[35];
ALGEBRAIC[67] = ALGEBRAIC[65];
ALGEBRAIC[69] = (STATES[88] - ALGEBRAIC[67])/CONSTANTS[123];
RATES[88] = (ALGEBRAIC[16] - ALGEBRAIC[69])/CONSTANTS[124];
RATES[89] = ALGEBRAIC[16] - ALGEBRAIC[69];
ALGEBRAIC[40] = STATES[61];
ALGEBRAIC[71] = ALGEBRAIC[65];
ALGEBRAIC[73] = (STATES[100] - ALGEBRAIC[71])/CONSTANTS[133];
RATES[100] = (ALGEBRAIC[40] - ALGEBRAIC[73])/CONSTANTS[134];
RATES[101] = ALGEBRAIC[40] - ALGEBRAIC[73];
ALGEBRAIC[62] = ALGEBRAIC[53]+ALGEBRAIC[59];
ALGEBRAIC[75] = ALGEBRAIC[69]+ALGEBRAIC[73];
ALGEBRAIC[77] = ALGEBRAIC[62]+ALGEBRAIC[75];
RATES[35] = (ALGEBRAIC[77] - STATES[36])/CONSTANTS[79];
RATES[37] = ALGEBRAIC[77] - STATES[36];
ALGEBRAIC[47] = STATES[2]+ 0.500000*CONSTANTS[7];
ALGEBRAIC[51] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[47]), 1.00000/3.00000);
ALGEBRAIC[54] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[51], 2.00000);
ALGEBRAIC[57] = ALGEBRAIC[54] - CONSTANTS[13];
ALGEBRAIC[60] = ( 1.50000*CONSTANTS[7]*ALGEBRAIC[51])/ALGEBRAIC[57];
ALGEBRAIC[63] = ( 0.500000*log(ALGEBRAIC[57]/CONSTANTS[14]) - pow(ALGEBRAIC[60], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[60], 4.00000);
ALGEBRAIC[66] =  exp(ALGEBRAIC[63])*CONSTANTS[0];
ALGEBRAIC[78] = fmax((ALGEBRAIC[66] - STATES[0])/0.0400000, - 0.0200000);
ALGEBRAIC[68] = fmax( CONSTANTS[15]*log(ALGEBRAIC[66]/1.80000), 0.00000);
ALGEBRAIC[70] = log(ALGEBRAIC[66]/CONSTANTS[0])+0.100000;
ALGEBRAIC[72] =  0.120000*(cosh( 5.00000*ALGEBRAIC[68]) - 1.00000)+ALGEBRAIC[70];
ALGEBRAIC[74] =  CONSTANTS[8]*ALGEBRAIC[72];
ALGEBRAIC[76] =  tanh( 10.0000*STATES[1]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[74], 2.00000)));
RATES[0] = ( fmax(ALGEBRAIC[78] - 1.00000,  ALGEBRAIC[76]*(ALGEBRAIC[78] - 1.00000))*CONSTANTS[10]*0.850000)/CONSTANTS[17];
ALGEBRAIC[38] =  CONSTANTS[9]*STATES[1]*ALGEBRAIC[30];
ALGEBRAIC[43] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[30];
ALGEBRAIC[79] = (fmax( 0.200000*ALGEBRAIC[74], ALGEBRAIC[74])+ (ALGEBRAIC[38]+ALGEBRAIC[43])*ALGEBRAIC[78]) - ALGEBRAIC[43];
ALGEBRAIC[80] =  (( ALGEBRAIC[79]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[60], 2.00000)))/ALGEBRAIC[57])*CONSTANTS[7];
ALGEBRAIC[81] =  2.00000*ALGEBRAIC[80]*ALGEBRAIC[51];
ALGEBRAIC[83] = ALGEBRAIC[81];
RATES[33] = ((STATES[32] - ALGEBRAIC[83]) -  CONSTANTS[75]*STATES[33])/CONSTANTS[77];
ALGEBRAIC[88] = fmax((STATES[5] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[86] = ((VOI - CONSTANTS[27]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[27])/CONSTANTS[17]))/CONSTANTS[176];
ALGEBRAIC[87] = fmin(8.00000, fmax(ALGEBRAIC[86], 0.00000));
ALGEBRAIC[91] = (  tanh( 4.00000*pow(ALGEBRAIC[88], 2.00000))*pow(ALGEBRAIC[87], 3.00000)*exp(- ALGEBRAIC[87])*pow(8.00000 - ALGEBRAIC[87], 2.00000)*0.0200000)/CONSTANTS[176];
ALGEBRAIC[89] =  CONSTANTS[171]*(0.650000+ 0.700000*ALGEBRAIC[88]);
ALGEBRAIC[93] = (((VOI - CONSTANTS[27]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[27])/CONSTANTS[17])) - ALGEBRAIC[89])/CONSTANTS[177];
ALGEBRAIC[95] = (0.500000+ 0.500000* sin( (ALGEBRAIC[93]/fabs(ALGEBRAIC[93]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[93]))))/CONSTANTS[177];
RATES[6] = ALGEBRAIC[91] -  STATES[6]*ALGEBRAIC[95];
ALGEBRAIC[94] = STATES[7]+ 0.500000*CONSTANTS[26];
ALGEBRAIC[96] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[94]), 1.00000/3.00000);
ALGEBRAIC[97] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[96], 2.00000);
ALGEBRAIC[98] = ALGEBRAIC[97] - CONSTANTS[28];
ALGEBRAIC[99] = ( 1.50000*CONSTANTS[26]*ALGEBRAIC[96])/ALGEBRAIC[98];
ALGEBRAIC[100] = ( 0.500000*log(ALGEBRAIC[98]/CONSTANTS[29]) - pow(ALGEBRAIC[99], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[99], 4.00000);
ALGEBRAIC[101] =  exp(ALGEBRAIC[100])*CONSTANTS[0];
ALGEBRAIC[107] = fmax((ALGEBRAIC[101] - STATES[5])/0.0400000, - 0.0200000);
ALGEBRAIC[102] = fmax( CONSTANTS[15]*log(ALGEBRAIC[101]/1.80000), 0.00000);
ALGEBRAIC[103] = log(ALGEBRAIC[101]/CONSTANTS[0])+0.100000;
ALGEBRAIC[104] =  0.120000*(cosh( 5.00000*ALGEBRAIC[102]) - 1.00000)+ALGEBRAIC[103];
ALGEBRAIC[105] =  CONSTANTS[8]*ALGEBRAIC[104];
ALGEBRAIC[106] =  tanh( 10.0000*STATES[6]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[105], 2.00000)));
RATES[5] = ( fmax(ALGEBRAIC[107] - 1.00000,  ALGEBRAIC[106]*(ALGEBRAIC[107] - 1.00000))*CONSTANTS[10]*0.850000)/CONSTANTS[17];
ALGEBRAIC[90] =  CONSTANTS[9]*STATES[6]*ALGEBRAIC[88];
ALGEBRAIC[92] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[88];
ALGEBRAIC[108] = (fmax( 0.200000*ALGEBRAIC[105], ALGEBRAIC[105])+ (ALGEBRAIC[90]+ALGEBRAIC[92])*ALGEBRAIC[107]) - ALGEBRAIC[92];
ALGEBRAIC[109] =  (( ALGEBRAIC[108]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[99], 2.00000)))/ALGEBRAIC[98])*CONSTANTS[26];
ALGEBRAIC[110] =  2.00000*ALGEBRAIC[109]*ALGEBRAIC[96];
ALGEBRAIC[113] = ALGEBRAIC[110];
RATES[36] = ((STATES[35] - ALGEBRAIC[113]) -  CONSTANTS[78]*STATES[36])/CONSTANTS[77];
ALGEBRAIC[114] = STATES[45] - STATES[105];
RATES[110] = (STATES[107]+ALGEBRAIC[114]) - STATES[109];
RATES[106] = ((STATES[107]+ALGEBRAIC[114]) - STATES[109])/CONSTANTS[107];
ALGEBRAIC[117] = STATES[106];
ALGEBRAIC[121] = ALGEBRAIC[117]+ CONSTANTS[153]*ALGEBRAIC[114];
RATES[45] = ((STATES[44] - ALGEBRAIC[121]) -  CONSTANTS[84]*STATES[45])/CONSTANTS[77];
ALGEBRAIC[118] = ALGEBRAIC[81];
ALGEBRAIC[122] = (STATES[107]+ALGEBRAIC[114]>=STATES[109] ?  STATES[111]*CONSTANTS[166]*(STATES[106] - ALGEBRAIC[118]) :  STATES[111]*CONSTANTS[167]*(STATES[106] - ALGEBRAIC[118]));
RATES[111] = (STATES[106]>=ALGEBRAIC[118] ?  (1.00000 - STATES[111])*CONSTANTS[165]*(STATES[106] - ALGEBRAIC[118]) : ALGEBRAIC[122]);
ALGEBRAIC[127] = ALGEBRAIC[110];
RATES[105] = ((ALGEBRAIC[121] - ALGEBRAIC[127]) -  CONSTANTS[154]*STATES[105])/CONSTANTS[77];
ALGEBRAIC[123] =  CONSTANTS[169]*STATES[111]+0.000100000;
ALGEBRAIC[128] = CONSTANTS[22]/ALGEBRAIC[123]+CONSTANTS[168];
RATES[109] = (STATES[109]>=0.00000 ? ((STATES[106] - ALGEBRAIC[118]) -  (CONSTANTS[164]/ALGEBRAIC[123])*pow(fabs(STATES[109]), 0.625000))/ALGEBRAIC[128] : ((STATES[106] - ALGEBRAIC[118])+ (CONSTANTS[164]/ALGEBRAIC[123])*pow(fabs(STATES[109]), 0.625000))/ALGEBRAIC[128]);
ALGEBRAIC[120] = fmax((STATES[16] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[112] = ((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17]))/CONSTANTS[180];
ALGEBRAIC[116] = fmin(8.00000, fmax(ALGEBRAIC[112], 0.00000));
ALGEBRAIC[130] = (  tanh( 4.00000*pow(ALGEBRAIC[120], 2.00000))*pow(ALGEBRAIC[116], 3.00000)*exp(- ALGEBRAIC[116])*pow(8.00000 - ALGEBRAIC[116], 2.00000)*0.0200000)/CONSTANTS[180];
ALGEBRAIC[125] =  CONSTANTS[173]*(0.650000+ 0.700000*ALGEBRAIC[120]);
ALGEBRAIC[133] = (((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17])) - ALGEBRAIC[125])/CONSTANTS[181];
ALGEBRAIC[137] = (0.500000+ 0.500000* sin( (ALGEBRAIC[133]/fabs(ALGEBRAIC[133]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[133]))))/CONSTANTS[181];
RATES[17] = ALGEBRAIC[130] -  STATES[17]*ALGEBRAIC[137];
ALGEBRAIC[132] = fmax((STATES[10] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[124] = ((VOI - CONSTANTS[43]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[43])/CONSTANTS[17]))/CONSTANTS[178];
ALGEBRAIC[129] = fmin(8.00000, fmax(ALGEBRAIC[124], 0.00000));
ALGEBRAIC[139] = (  tanh( 4.00000*pow(ALGEBRAIC[132], 2.00000))*pow(ALGEBRAIC[129], 3.00000)*exp(- ALGEBRAIC[129])*pow(8.00000 - ALGEBRAIC[129], 2.00000)*0.0200000)/CONSTANTS[178];
ALGEBRAIC[135] =  CONSTANTS[172]*(0.650000+ 0.700000*ALGEBRAIC[132]);
ALGEBRAIC[142] = (((VOI - CONSTANTS[43]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[43])/CONSTANTS[17])) - ALGEBRAIC[135])/CONSTANTS[179];
ALGEBRAIC[146] = (0.500000+ 0.500000* sin( (ALGEBRAIC[142]/fabs(ALGEBRAIC[142]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[142]))))/CONSTANTS[179];
RATES[11] = ALGEBRAIC[139] -  STATES[11]*ALGEBRAIC[146];
ALGEBRAIC[134] = STATES[18]+ 0.500000*CONSTANTS[53];
ALGEBRAIC[138] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[134]), 1.00000/3.00000);
ALGEBRAIC[141] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[138], 2.00000);
ALGEBRAIC[144] = ALGEBRAIC[141] - CONSTANTS[55];
ALGEBRAIC[145] = ( 1.50000*CONSTANTS[53]*ALGEBRAIC[138])/ALGEBRAIC[144];
ALGEBRAIC[148] = ( 0.500000*log(ALGEBRAIC[144]/CONSTANTS[56]) - pow(ALGEBRAIC[145], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[145], 4.00000);
ALGEBRAIC[150] =  exp(ALGEBRAIC[148])*CONSTANTS[0];
ALGEBRAIC[162] = fmax((ALGEBRAIC[150] - STATES[16])/0.0400000, - 0.0200000);
ALGEBRAIC[152] = fmax( CONSTANTS[46]*log(ALGEBRAIC[150]/1.80000), 0.00000);
ALGEBRAIC[154] = log(ALGEBRAIC[150]/CONSTANTS[0])+0.100000;
ALGEBRAIC[156] =  0.120000*(cosh( 5.00000*ALGEBRAIC[152]) - 1.00000)+ALGEBRAIC[154];
ALGEBRAIC[158] =  CONSTANTS[40]*ALGEBRAIC[156];
ALGEBRAIC[160] =  tanh( 10.0000*STATES[17]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[158], 2.00000)));
RATES[16] = ( fmax(ALGEBRAIC[162] - 1.00000,  ALGEBRAIC[160]*(ALGEBRAIC[162] - 1.00000))*CONSTANTS[42]*0.850000)/CONSTANTS[17];
ALGEBRAIC[126] =  CONSTANTS[41]*STATES[17]*ALGEBRAIC[120];
ALGEBRAIC[131] =  CONSTANTS[41]*CONSTANTS[12]*ALGEBRAIC[120];
ALGEBRAIC[164] = (fmax( 0.200000*ALGEBRAIC[158], ALGEBRAIC[158])+ (ALGEBRAIC[126]+ALGEBRAIC[131])*ALGEBRAIC[162]) - ALGEBRAIC[131];
ALGEBRAIC[166] =  (( ALGEBRAIC[164]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[145], 2.00000)))/ALGEBRAIC[144])*CONSTANTS[53];
ALGEBRAIC[168] =  2.00000*ALGEBRAIC[166]*ALGEBRAIC[138];
ALGEBRAIC[82] =  CONSTANTS[23]*STATES[4]+0.000100000;
ALGEBRAIC[84] = CONSTANTS[22]/ALGEBRAIC[82]+CONSTANTS[21];
ALGEBRAIC[85] = CONSTANTS[24]/pow(ALGEBRAIC[82], 2.00000);
RATES[3] = ((ALGEBRAIC[81] - ALGEBRAIC[168]) -  ALGEBRAIC[85]*STATES[3]*fabs(STATES[3]))/ALGEBRAIC[84];
ALGEBRAIC[143] = STATES[12]+ 0.500000*CONSTANTS[39];
ALGEBRAIC[147] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[143]), 1.00000/3.00000);
ALGEBRAIC[149] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[147], 2.00000);
ALGEBRAIC[151] = ALGEBRAIC[149] - CONSTANTS[44];
ALGEBRAIC[153] = ( 1.50000*CONSTANTS[39]*ALGEBRAIC[147])/ALGEBRAIC[151];
ALGEBRAIC[155] = ( 0.500000*log(ALGEBRAIC[151]/CONSTANTS[45]) - pow(ALGEBRAIC[153], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[153], 4.00000);
ALGEBRAIC[157] =  exp(ALGEBRAIC[155])*CONSTANTS[0];
ALGEBRAIC[169] = fmax((ALGEBRAIC[157] - STATES[10])/0.0400000, - 0.0200000);
ALGEBRAIC[159] = fmax( CONSTANTS[46]*log(ALGEBRAIC[157]/1.80000), 0.00000);
ALGEBRAIC[161] = log(ALGEBRAIC[157]/CONSTANTS[0])+0.100000;
ALGEBRAIC[163] =  0.120000*(cosh( 5.00000*ALGEBRAIC[159]) - 1.00000)+ALGEBRAIC[161];
ALGEBRAIC[165] =  CONSTANTS[40]*ALGEBRAIC[163];
ALGEBRAIC[167] =  tanh( 10.0000*STATES[11]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[165], 2.00000)));
RATES[10] = ( fmax(ALGEBRAIC[169] - 1.00000,  ALGEBRAIC[167]*(ALGEBRAIC[169] - 1.00000))*CONSTANTS[42]*0.850000)/CONSTANTS[17];
ALGEBRAIC[170] = STATES[33]+STATES[109];
RATES[2] = ALGEBRAIC[170] - STATES[3];
ALGEBRAIC[173] = (ALGEBRAIC[170]>=STATES[3] ?  STATES[4]*CONSTANTS[19]*(ALGEBRAIC[81] - ALGEBRAIC[168]) :  STATES[4]*CONSTANTS[20]*(ALGEBRAIC[81] - ALGEBRAIC[168]));
RATES[4] = (ALGEBRAIC[81]>=ALGEBRAIC[168] ?  (1.00000 - STATES[4])*CONSTANTS[18]*(ALGEBRAIC[81] - ALGEBRAIC[168]) : ALGEBRAIC[173]);
ALGEBRAIC[136] =  CONSTANTS[41]*STATES[11]*ALGEBRAIC[132];
ALGEBRAIC[140] =  CONSTANTS[41]*CONSTANTS[12]*ALGEBRAIC[132];
ALGEBRAIC[171] = (fmax( 0.200000*ALGEBRAIC[165], ALGEBRAIC[165])+ (ALGEBRAIC[136]+ALGEBRAIC[140])*ALGEBRAIC[169]) - ALGEBRAIC[140];
ALGEBRAIC[174] =  (( ALGEBRAIC[171]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[153], 2.00000)))/ALGEBRAIC[151])*CONSTANTS[39];
ALGEBRAIC[176] =  2.00000*ALGEBRAIC[174]*ALGEBRAIC[147];
ALGEBRAIC[111] =  CONSTANTS[34]*STATES[9]+0.000100000;
ALGEBRAIC[115] = CONSTANTS[22]/ALGEBRAIC[111]+CONSTANTS[33];
ALGEBRAIC[119] = CONSTANTS[24]/pow(ALGEBRAIC[111], 2.00000);
RATES[8] = ((ALGEBRAIC[110] - ALGEBRAIC[176]) -  ALGEBRAIC[119]*STATES[8]*fabs(STATES[8]))/ALGEBRAIC[115];
ALGEBRAIC[180] = (STATES[8]>=STATES[14] ?  STATES[15]*CONSTANTS[48]*(ALGEBRAIC[176] - STATES[13]) :  STATES[15]*CONSTANTS[49]*(ALGEBRAIC[176] - STATES[13]));
RATES[15] = (ALGEBRAIC[176]>=STATES[13] ?  (1.00000 - STATES[15])*CONSTANTS[47]*(ALGEBRAIC[176] - STATES[13]) : ALGEBRAIC[180]);
ALGEBRAIC[184] = STATES[19] - STATES[102];
RATES[21] = (ALGEBRAIC[184] - STATES[22])/CONSTANTS[63];
RATES[23] = ALGEBRAIC[184] - STATES[22];
ALGEBRAIC[179] =  CONSTANTS[51]*STATES[15]+0.000100000;
ALGEBRAIC[183] = CONSTANTS[22]/ALGEBRAIC[179]+CONSTANTS[50];
ALGEBRAIC[186] = CONSTANTS[24]/pow(ALGEBRAIC[179], 2.00000);
RATES[14] = ((ALGEBRAIC[176] - STATES[13]) -  ALGEBRAIC[186]*STATES[14]*fabs(STATES[14]))/ALGEBRAIC[183];
ALGEBRAIC[187] = STATES[21]+ CONSTANTS[143]*ALGEBRAIC[184];
ALGEBRAIC[172] =  CONSTANTS[61]*STATES[20]+0.000100000;
ALGEBRAIC[175] = CONSTANTS[22]/ALGEBRAIC[172]+CONSTANTS[60];
ALGEBRAIC[177] = CONSTANTS[24]/pow(ALGEBRAIC[172], 2.00000);
RATES[19] = ((ALGEBRAIC[168] - ALGEBRAIC[187]) -  ALGEBRAIC[177]*STATES[19]*fabs(STATES[19]))/ALGEBRAIC[175];
ALGEBRAIC[178] = STATES[102];
ALGEBRAIC[182] = STATES[42] - STATES[104];
ALGEBRAIC[185] = ALGEBRAIC[182] - STATES[107];
ALGEBRAIC[188] = STATES[36]+STATES[105]+ALGEBRAIC[185]+ALGEBRAIC[178];
RATES[7] = ALGEBRAIC[188] - STATES[8];
ALGEBRAIC[189] = (STATES[3]>=STATES[19] ?  STATES[20]*CONSTANTS[58]*(ALGEBRAIC[168] - ALGEBRAIC[187]) :  STATES[20]*CONSTANTS[59]*(ALGEBRAIC[168] - ALGEBRAIC[187]));
RATES[20] = (ALGEBRAIC[168]>=ALGEBRAIC[187] ?  (1.00000 - STATES[20])*CONSTANTS[57]*(ALGEBRAIC[168] - ALGEBRAIC[187]) : ALGEBRAIC[189]);
ALGEBRAIC[192] = (ALGEBRAIC[188]>=STATES[8] ?  STATES[9]*CONSTANTS[31]*(ALGEBRAIC[110] - ALGEBRAIC[176]) :  STATES[9]*CONSTANTS[32]*(ALGEBRAIC[110] - ALGEBRAIC[176]));
RATES[9] = (ALGEBRAIC[110]>=ALGEBRAIC[176] ?  (1.00000 - STATES[9])*CONSTANTS[30]*(ALGEBRAIC[110] - ALGEBRAIC[176]) : ALGEBRAIC[192]);
ALGEBRAIC[191] = ALGEBRAIC[110];
ALGEBRAIC[181] = CONSTANTS[139]+ (CONSTANTS[140]/(1.00000+exp( - 1.00000*(ALGEBRAIC[168] - CONSTANTS[142]))))*pow(ALGEBRAIC[168] - CONSTANTS[142], CONSTANTS[141]);
ALGEBRAIC[194] = ALGEBRAIC[191]+ ALGEBRAIC[181]*STATES[102];
RATES[102] = ((ALGEBRAIC[187] - ALGEBRAIC[194]) -  CONSTANTS[143]*STATES[102])/CONSTANTS[147];
ALGEBRAIC[193] = ALGEBRAIC[110];
ALGEBRAIC[195] = ALGEBRAIC[193]+ CONSTANTS[158]*ALGEBRAIC[185]+ CONSTANTS[159]*ALGEBRAIC[185]*fabs(ALGEBRAIC[185]);
RATES[107] = (((ALGEBRAIC[195] - STATES[106]) -  CONSTANTS[155]*STATES[107]) -  CONSTANTS[156]*STATES[107]*fabs(STATES[107]))/CONSTANTS[160];
ALGEBRAIC[196] = ALGEBRAIC[195];
RATES[42] = ((STATES[41] - ALGEBRAIC[196]) -  CONSTANTS[82]*STATES[42])/CONSTANTS[77];
ALGEBRAIC[190] = STATES[86];
RATES[104] = ((ALGEBRAIC[196] - ALGEBRAIC[190]) -  CONSTANTS[152]*STATES[104])/CONSTANTS[77];
}
void
computeVariables(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC)
{
ALGEBRAIC[1] = STATES[22] - STATES[49];
ALGEBRAIC[2] = STATES[25] - STATES[96];
ALGEBRAIC[3] = (STATES[67] - STATES[32])/CONSTANTS[106];
ALGEBRAIC[6] = STATES[48] - STATES[91];
ALGEBRAIC[5] = STATES[88]+ CONSTANTS[135]*STATES[52];
ALGEBRAIC[8] = (STATES[90] - STATES[54])/CONSTANTS[125];
ALGEBRAIC[7] = STATES[93]+ CONSTANTS[136]*STATES[55];
ALGEBRAIC[10] = (STATES[95] - STATES[57])/CONSTANTS[129];
ALGEBRAIC[9] = STATES[98]+ CONSTANTS[137]*STATES[58];
ALGEBRAIC[11] = STATES[100]+ CONSTANTS[138]*STATES[61];
ALGEBRAIC[13] = STATES[28] - STATES[62];
ALGEBRAIC[12] = STATES[69];
ALGEBRAIC[4] = (STATES[79] - STATES[80])/CONSTANTS[116];
ALGEBRAIC[14] = STATES[38];
ALGEBRAIC[19] = STATES[24]+ CONSTANTS[143]*ALGEBRAIC[1];
ALGEBRAIC[20] = STATES[27]+ CONSTANTS[143]*ALGEBRAIC[2];
ALGEBRAIC[21] = STATES[64]+ CONSTANTS[143]*ALGEBRAIC[13];
ALGEBRAIC[15] = STATES[39] - STATES[81];
ALGEBRAIC[22] = STATES[77]+ CONSTANTS[146]*ALGEBRAIC[15];
ALGEBRAIC[24] = STATES[51]+ CONSTANTS[143]*ALGEBRAIC[6];
ALGEBRAIC[25] = STATES[30] - STATES[103];
ALGEBRAIC[23] = (STATES[80] - STATES[83])/CONSTANTS[118];
ALGEBRAIC[29] = STATES[86];
ALGEBRAIC[31] = STATES[67]+ CONSTANTS[143]*ALGEBRAIC[25];
ALGEBRAIC[26] = (STATES[69] - ALGEBRAIC[14])/CONSTANTS[108];
ALGEBRAIC[32] = ((ALGEBRAIC[26] - STATES[75]) - STATES[108]) - STATES[72];
ALGEBRAIC[33] = (STATES[83] - STATES[41])/CONSTANTS[119];
ALGEBRAIC[34] = STATES[103]+STATES[65];
ALGEBRAIC[27] = STATES[86];
ALGEBRAIC[35] = (STATES[74] - ALGEBRAIC[27])/CONSTANTS[112];
ALGEBRAIC[41] = STATES[69];
ALGEBRAIC[44] = STATES[44];
ALGEBRAIC[48] = (STATES[71] - ALGEBRAIC[44])/CONSTANTS[110];
ALGEBRAIC[30] = fmax((STATES[0] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[0] = ((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17]))/CONSTANTS[174];
ALGEBRAIC[18] = fmin(8.00000, fmax(ALGEBRAIC[0], 0.00000));
ALGEBRAIC[42] = (  tanh( 4.00000*pow(ALGEBRAIC[30], 2.00000))*pow(ALGEBRAIC[18], 3.00000)*exp(- ALGEBRAIC[18])*pow(8.00000 - ALGEBRAIC[18], 2.00000)*0.0200000)/CONSTANTS[174];
ALGEBRAIC[37] =  CONSTANTS[170]*(0.650000+ 0.700000*ALGEBRAIC[30]);
ALGEBRAIC[46] = (((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17])) - ALGEBRAIC[37])/CONSTANTS[175];
ALGEBRAIC[50] = (0.500000+ 0.500000* sin( (ALGEBRAIC[46]/fabs(ALGEBRAIC[46]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[46]))))/CONSTANTS[175];
ALGEBRAIC[28] = STATES[55];
ALGEBRAIC[45] = STATES[35];
ALGEBRAIC[49] = ALGEBRAIC[45];
ALGEBRAIC[53] = (STATES[93] - ALGEBRAIC[49])/CONSTANTS[127];
ALGEBRAIC[39] = STATES[104]+ALGEBRAIC[35]+STATES[108];
ALGEBRAIC[52] = STATES[44];
ALGEBRAIC[55] = (STATES[86] - ALGEBRAIC[52])/CONSTANTS[121];
ALGEBRAIC[36] = STATES[58];
ALGEBRAIC[56] = ALGEBRAIC[45];
ALGEBRAIC[59] = (STATES[98] - ALGEBRAIC[56])/CONSTANTS[131];
ALGEBRAIC[58] = STATES[44];
ALGEBRAIC[61] = (STATES[77] - ALGEBRAIC[58])/CONSTANTS[114];
ALGEBRAIC[64] = ALGEBRAIC[48]+ALGEBRAIC[55]+ALGEBRAIC[61];
ALGEBRAIC[16] = STATES[52];
ALGEBRAIC[65] = STATES[35];
ALGEBRAIC[67] = ALGEBRAIC[65];
ALGEBRAIC[69] = (STATES[88] - ALGEBRAIC[67])/CONSTANTS[123];
ALGEBRAIC[40] = STATES[61];
ALGEBRAIC[71] = ALGEBRAIC[65];
ALGEBRAIC[73] = (STATES[100] - ALGEBRAIC[71])/CONSTANTS[133];
ALGEBRAIC[62] = ALGEBRAIC[53]+ALGEBRAIC[59];
ALGEBRAIC[75] = ALGEBRAIC[69]+ALGEBRAIC[73];
ALGEBRAIC[77] = ALGEBRAIC[62]+ALGEBRAIC[75];
ALGEBRAIC[47] = STATES[2]+ 0.500000*CONSTANTS[7];
ALGEBRAIC[51] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[47]), 1.00000/3.00000);
ALGEBRAIC[54] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[51], 2.00000);
ALGEBRAIC[57] = ALGEBRAIC[54] - CONSTANTS[13];
ALGEBRAIC[60] = ( 1.50000*CONSTANTS[7]*ALGEBRAIC[51])/ALGEBRAIC[57];
ALGEBRAIC[63] = ( 0.500000*log(ALGEBRAIC[57]/CONSTANTS[14]) - pow(ALGEBRAIC[60], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[60], 4.00000);
ALGEBRAIC[66] =  exp(ALGEBRAIC[63])*CONSTANTS[0];
ALGEBRAIC[78] = fmax((ALGEBRAIC[66] - STATES[0])/0.0400000, - 0.0200000);
ALGEBRAIC[68] = fmax( CONSTANTS[15]*log(ALGEBRAIC[66]/1.80000), 0.00000);
ALGEBRAIC[70] = log(ALGEBRAIC[66]/CONSTANTS[0])+0.100000;
ALGEBRAIC[72] =  0.120000*(cosh( 5.00000*ALGEBRAIC[68]) - 1.00000)+ALGEBRAIC[70];
ALGEBRAIC[74] =  CONSTANTS[8]*ALGEBRAIC[72];
ALGEBRAIC[76] =  tanh( 10.0000*STATES[1]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[74], 2.00000)));
ALGEBRAIC[38] =  CONSTANTS[9]*STATES[1]*ALGEBRAIC[30];
ALGEBRAIC[43] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[30];
ALGEBRAIC[79] = (fmax( 0.200000*ALGEBRAIC[74], ALGEBRAIC[74])+ (ALGEBRAIC[38]+ALGEBRAIC[43])*ALGEBRAIC[78]) - ALGEBRAIC[43];
ALGEBRAIC[80] =  (( ALGEBRAIC[79]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[60], 2.00000)))/ALGEBRAIC[57])*CONSTANTS[7];
ALGEBRAIC[81] =  2.00000*ALGEBRAIC[80]*ALGEBRAIC[51];
ALGEBRAIC[83] = ALGEBRAIC[81];
ALGEBRAIC[88] = fmax((STATES[5] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[86] = ((VOI - CONSTANTS[27]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[27])/CONSTANTS[17]))/CONSTANTS[176];
ALGEBRAIC[87] = fmin(8.00000, fmax(ALGEBRAIC[86], 0.00000));
ALGEBRAIC[91] = (  tanh( 4.00000*pow(ALGEBRAIC[88], 2.00000))*pow(ALGEBRAIC[87], 3.00000)*exp(- ALGEBRAIC[87])*pow(8.00000 - ALGEBRAIC[87], 2.00000)*0.0200000)/CONSTANTS[176];
ALGEBRAIC[89] =  CONSTANTS[171]*(0.650000+ 0.700000*ALGEBRAIC[88]);
ALGEBRAIC[93] = (((VOI - CONSTANTS[27]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[27])/CONSTANTS[17])) - ALGEBRAIC[89])/CONSTANTS[177];
ALGEBRAIC[95] = (0.500000+ 0.500000* sin( (ALGEBRAIC[93]/fabs(ALGEBRAIC[93]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[93]))))/CONSTANTS[177];
ALGEBRAIC[94] = STATES[7]+ 0.500000*CONSTANTS[26];
ALGEBRAIC[96] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[94]), 1.00000/3.00000);
ALGEBRAIC[97] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[96], 2.00000);
ALGEBRAIC[98] = ALGEBRAIC[97] - CONSTANTS[28];
ALGEBRAIC[99] = ( 1.50000*CONSTANTS[26]*ALGEBRAIC[96])/ALGEBRAIC[98];
ALGEBRAIC[100] = ( 0.500000*log(ALGEBRAIC[98]/CONSTANTS[29]) - pow(ALGEBRAIC[99], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[99], 4.00000);
ALGEBRAIC[101] =  exp(ALGEBRAIC[100])*CONSTANTS[0];
ALGEBRAIC[107] = fmax((ALGEBRAIC[101] - STATES[5])/0.0400000, - 0.0200000);
ALGEBRAIC[102] = fmax( CONSTANTS[15]*log(ALGEBRAIC[101]/1.80000), 0.00000);
ALGEBRAIC[103] = log(ALGEBRAIC[101]/CONSTANTS[0])+0.100000;
ALGEBRAIC[104] =  0.120000*(cosh( 5.00000*ALGEBRAIC[102]) - 1.00000)+ALGEBRAIC[103];
ALGEBRAIC[105] =  CONSTANTS[8]*ALGEBRAIC[104];
ALGEBRAIC[106] =  tanh( 10.0000*STATES[6]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[105], 2.00000)));
ALGEBRAIC[90] =  CONSTANTS[9]*STATES[6]*ALGEBRAIC[88];
ALGEBRAIC[92] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[88];
ALGEBRAIC[108] = (fmax( 0.200000*ALGEBRAIC[105], ALGEBRAIC[105])+ (ALGEBRAIC[90]+ALGEBRAIC[92])*ALGEBRAIC[107]) - ALGEBRAIC[92];
ALGEBRAIC[109] =  (( ALGEBRAIC[108]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[99], 2.00000)))/ALGEBRAIC[98])*CONSTANTS[26];
ALGEBRAIC[110] =  2.00000*ALGEBRAIC[109]*ALGEBRAIC[96];
ALGEBRAIC[113] = ALGEBRAIC[110];
ALGEBRAIC[114] = STATES[45] - STATES[105];
ALGEBRAIC[117] = STATES[106];
ALGEBRAIC[121] = ALGEBRAIC[117]+ CONSTANTS[153]*ALGEBRAIC[114];
ALGEBRAIC[118] = ALGEBRAIC[81];
ALGEBRAIC[122] = (STATES[107]+ALGEBRAIC[114]>=STATES[109] ?  STATES[111]*CONSTANTS[166]*(STATES[106] - ALGEBRAIC[118]) :  STATES[111]*CONSTANTS[167]*(STATES[106] - ALGEBRAIC[118]));
ALGEBRAIC[127] = ALGEBRAIC[110];
ALGEBRAIC[123] =  CONSTANTS[169]*STATES[111]+0.000100000;
ALGEBRAIC[128] = CONSTANTS[22]/ALGEBRAIC[123]+CONSTANTS[168];
ALGEBRAIC[120] = fmax((STATES[16] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[112] = ((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17]))/CONSTANTS[180];
ALGEBRAIC[116] = fmin(8.00000, fmax(ALGEBRAIC[112], 0.00000));
ALGEBRAIC[130] = (  tanh( 4.00000*pow(ALGEBRAIC[120], 2.00000))*pow(ALGEBRAIC[116], 3.00000)*exp(- ALGEBRAIC[116])*pow(8.00000 - ALGEBRAIC[116], 2.00000)*0.0200000)/CONSTANTS[180];
ALGEBRAIC[125] =  CONSTANTS[173]*(0.650000+ 0.700000*ALGEBRAIC[120]);
ALGEBRAIC[133] = (((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17])) - ALGEBRAIC[125])/CONSTANTS[181];
ALGEBRAIC[137] = (0.500000+ 0.500000* sin( (ALGEBRAIC[133]/fabs(ALGEBRAIC[133]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[133]))))/CONSTANTS[181];
ALGEBRAIC[132] = fmax((STATES[10] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[124] = ((VOI - CONSTANTS[43]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[43])/CONSTANTS[17]))/CONSTANTS[178];
ALGEBRAIC[129] = fmin(8.00000, fmax(ALGEBRAIC[124], 0.00000));
ALGEBRAIC[139] = (  tanh( 4.00000*pow(ALGEBRAIC[132], 2.00000))*pow(ALGEBRAIC[129], 3.00000)*exp(- ALGEBRAIC[129])*pow(8.00000 - ALGEBRAIC[129], 2.00000)*0.0200000)/CONSTANTS[178];
ALGEBRAIC[135] =  CONSTANTS[172]*(0.650000+ 0.700000*ALGEBRAIC[132]);
ALGEBRAIC[142] = (((VOI - CONSTANTS[43]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[43])/CONSTANTS[17])) - ALGEBRAIC[135])/CONSTANTS[179];
ALGEBRAIC[146] = (0.500000+ 0.500000* sin( (ALGEBRAIC[142]/fabs(ALGEBRAIC[142]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[142]))))/CONSTANTS[179];
ALGEBRAIC[134] = STATES[18]+ 0.500000*CONSTANTS[53];
ALGEBRAIC[138] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[134]), 1.00000/3.00000);
ALGEBRAIC[141] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[138], 2.00000);
ALGEBRAIC[144] = ALGEBRAIC[141] - CONSTANTS[55];
ALGEBRAIC[145] = ( 1.50000*CONSTANTS[53]*ALGEBRAIC[138])/ALGEBRAIC[144];
ALGEBRAIC[148] = ( 0.500000*log(ALGEBRAIC[144]/CONSTANTS[56]) - pow(ALGEBRAIC[145], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[145], 4.00000);
ALGEBRAIC[150] =  exp(ALGEBRAIC[148])*CONSTANTS[0];
ALGEBRAIC[162] = fmax((ALGEBRAIC[150] - STATES[16])/0.0400000, - 0.0200000);
ALGEBRAIC[152] = fmax( CONSTANTS[46]*log(ALGEBRAIC[150]/1.80000), 0.00000);
ALGEBRAIC[154] = log(ALGEBRAIC[150]/CONSTANTS[0])+0.100000;
ALGEBRAIC[156] =  0.120000*(cosh( 5.00000*ALGEBRAIC[152]) - 1.00000)+ALGEBRAIC[154];
ALGEBRAIC[158] =  CONSTANTS[40]*ALGEBRAIC[156];
ALGEBRAIC[160] =  tanh( 10.0000*STATES[17]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[158], 2.00000)));
ALGEBRAIC[126] =  CONSTANTS[41]*STATES[17]*ALGEBRAIC[120];
ALGEBRAIC[131] =  CONSTANTS[41]*CONSTANTS[12]*ALGEBRAIC[120];
ALGEBRAIC[164] = (fmax( 0.200000*ALGEBRAIC[158], ALGEBRAIC[158])+ (ALGEBRAIC[126]+ALGEBRAIC[131])*ALGEBRAIC[162]) - ALGEBRAIC[131];
ALGEBRAIC[166] =  (( ALGEBRAIC[164]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[145], 2.00000)))/ALGEBRAIC[144])*CONSTANTS[53];
ALGEBRAIC[168] =  2.00000*ALGEBRAIC[166]*ALGEBRAIC[138];
ALGEBRAIC[82] =  CONSTANTS[23]*STATES[4]+0.000100000;
ALGEBRAIC[84] = CONSTANTS[22]/ALGEBRAIC[82]+CONSTANTS[21];
ALGEBRAIC[85] = CONSTANTS[24]/pow(ALGEBRAIC[82], 2.00000);
ALGEBRAIC[143] = STATES[12]+ 0.500000*CONSTANTS[39];
ALGEBRAIC[147] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[143]), 1.00000/3.00000);
ALGEBRAIC[149] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[147], 2.00000);
ALGEBRAIC[151] = ALGEBRAIC[149] - CONSTANTS[44];
ALGEBRAIC[153] = ( 1.50000*CONSTANTS[39]*ALGEBRAIC[147])/ALGEBRAIC[151];
ALGEBRAIC[155] = ( 0.500000*log(ALGEBRAIC[151]/CONSTANTS[45]) - pow(ALGEBRAIC[153], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[153], 4.00000);
ALGEBRAIC[157] =  exp(ALGEBRAIC[155])*CONSTANTS[0];
ALGEBRAIC[169] = fmax((ALGEBRAIC[157] - STATES[10])/0.0400000, - 0.0200000);
ALGEBRAIC[159] = fmax( CONSTANTS[46]*log(ALGEBRAIC[157]/1.80000), 0.00000);
ALGEBRAIC[161] = log(ALGEBRAIC[157]/CONSTANTS[0])+0.100000;
ALGEBRAIC[163] =  0.120000*(cosh( 5.00000*ALGEBRAIC[159]) - 1.00000)+ALGEBRAIC[161];
ALGEBRAIC[165] =  CONSTANTS[40]*ALGEBRAIC[163];
ALGEBRAIC[167] =  tanh( 10.0000*STATES[11]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[165], 2.00000)));
ALGEBRAIC[170] = STATES[33]+STATES[109];
ALGEBRAIC[173] = (ALGEBRAIC[170]>=STATES[3] ?  STATES[4]*CONSTANTS[19]*(ALGEBRAIC[81] - ALGEBRAIC[168]) :  STATES[4]*CONSTANTS[20]*(ALGEBRAIC[81] - ALGEBRAIC[168]));
ALGEBRAIC[136] =  CONSTANTS[41]*STATES[11]*ALGEBRAIC[132];
ALGEBRAIC[140] =  CONSTANTS[41]*CONSTANTS[12]*ALGEBRAIC[132];
ALGEBRAIC[171] = (fmax( 0.200000*ALGEBRAIC[165], ALGEBRAIC[165])+ (ALGEBRAIC[136]+ALGEBRAIC[140])*ALGEBRAIC[169]) - ALGEBRAIC[140];
ALGEBRAIC[174] =  (( ALGEBRAIC[171]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[153], 2.00000)))/ALGEBRAIC[151])*CONSTANTS[39];
ALGEBRAIC[176] =  2.00000*ALGEBRAIC[174]*ALGEBRAIC[147];
ALGEBRAIC[111] =  CONSTANTS[34]*STATES[9]+0.000100000;
ALGEBRAIC[115] = CONSTANTS[22]/ALGEBRAIC[111]+CONSTANTS[33];
ALGEBRAIC[119] = CONSTANTS[24]/pow(ALGEBRAIC[111], 2.00000);
ALGEBRAIC[180] = (STATES[8]>=STATES[14] ?  STATES[15]*CONSTANTS[48]*(ALGEBRAIC[176] - STATES[13]) :  STATES[15]*CONSTANTS[49]*(ALGEBRAIC[176] - STATES[13]));
ALGEBRAIC[184] = STATES[19] - STATES[102];
ALGEBRAIC[179] =  CONSTANTS[51]*STATES[15]+0.000100000;
ALGEBRAIC[183] = CONSTANTS[22]/ALGEBRAIC[179]+CONSTANTS[50];
ALGEBRAIC[186] = CONSTANTS[24]/pow(ALGEBRAIC[179], 2.00000);
ALGEBRAIC[187] = STATES[21]+ CONSTANTS[143]*ALGEBRAIC[184];
ALGEBRAIC[172] =  CONSTANTS[61]*STATES[20]+0.000100000;
ALGEBRAIC[175] = CONSTANTS[22]/ALGEBRAIC[172]+CONSTANTS[60];
ALGEBRAIC[177] = CONSTANTS[24]/pow(ALGEBRAIC[172], 2.00000);
ALGEBRAIC[178] = STATES[102];
ALGEBRAIC[182] = STATES[42] - STATES[104];
ALGEBRAIC[185] = ALGEBRAIC[182] - STATES[107];
ALGEBRAIC[188] = STATES[36]+STATES[105]+ALGEBRAIC[185]+ALGEBRAIC[178];
ALGEBRAIC[189] = (STATES[3]>=STATES[19] ?  STATES[20]*CONSTANTS[58]*(ALGEBRAIC[168] - ALGEBRAIC[187]) :  STATES[20]*CONSTANTS[59]*(ALGEBRAIC[168] - ALGEBRAIC[187]));
ALGEBRAIC[192] = (ALGEBRAIC[188]>=STATES[8] ?  STATES[9]*CONSTANTS[31]*(ALGEBRAIC[110] - ALGEBRAIC[176]) :  STATES[9]*CONSTANTS[32]*(ALGEBRAIC[110] - ALGEBRAIC[176]));
ALGEBRAIC[191] = ALGEBRAIC[110];
ALGEBRAIC[181] = CONSTANTS[139]+ (CONSTANTS[140]/(1.00000+exp( - 1.00000*(ALGEBRAIC[168] - CONSTANTS[142]))))*pow(ALGEBRAIC[168] - CONSTANTS[142], CONSTANTS[141]);
ALGEBRAIC[194] = ALGEBRAIC[191]+ ALGEBRAIC[181]*STATES[102];
ALGEBRAIC[193] = ALGEBRAIC[110];
ALGEBRAIC[195] = ALGEBRAIC[193]+ CONSTANTS[158]*ALGEBRAIC[185]+ CONSTANTS[159]*ALGEBRAIC[185]*fabs(ALGEBRAIC[185]);
ALGEBRAIC[196] = ALGEBRAIC[195];
ALGEBRAIC[190] = STATES[86];
ALGEBRAIC[17] = STATES[107]/( 0.700000*CONSTANTS[157]);
}
