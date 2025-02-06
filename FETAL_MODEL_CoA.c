/*
   There are a total of 181 entries in the algebraic variable array.
   There are a total of 73 entries in each of the rate and state variable arrays.
   There are a total of 163 entries in the constant variable array.
 */
/*
 * VOI is t in component environment (second).
 * ALGEBRAIC[27] is L in component LV (dimensionless).
 * ALGEBRAIC[65] is Ls in component LV (Unitl).
 * CONSTANTS[0] is Lsref in component Parameters (Unitl).
 * STATES[0] is Lsc in component LV (Unitl).
 * CONSTANTS[1] is Lscini in component Parameters (Unitl).
 * ALGEBRAIC[78] is Lsnorm in component LV (dimensionless).
 * ALGEBRAIC[34] is ta in component LV (second).
 * CONSTANTS[2] is p_tact_v in component Parameters (second).
 * CONSTANTS[153] is td in component LV (second).
 * CONSTANTS[152] is trise in component LV (second).
 * CONSTANTS[151] is p_tact in component LV (second).
 * CONSTANTS[3] is p_trise_v in component Parameters (dimensionless).
 * CONSTANTS[4] is p_td_v in component Parameters (dimensionless).
 * STATES[1] is C in component LV (dimensionless).
 * CONSTANTS[5] is C0 in component Parameters (dimensionless).
 * STATES[2] is Vcav in component LV (UnitV).
 * CONSTANTS[6] is Vlv0 in component Parameters (UnitV).
 * CONSTANTS[7] is Vwall_lv in component Parameters (UnitV).
 * ALGEBRAIC[74] is sfpas in component LV (UnitP).
 * ALGEBRAIC[35] is sfact in component LV (UnitP).
 * ALGEBRAIC[41] is sfrest in component LV (UnitP).
 * ALGEBRAIC[79] is sf in component LV (UnitP).
 * CONSTANTS[8] is spas_v in component Parameters (UnitP).
 * CONSTANTS[9] is sact_v in component Parameters (UnitP).
 * CONSTANTS[10] is vmax_v in component Parameters (Unitv).
 * CONSTANTS[11] is delay_lv in component Parameters (second).
 * ALGEBRAIC[0] is Time in component LV (second).
 * ALGEBRAIC[45] is Time2 in component LV (second).
 * ALGEBRAIC[17] is xrise in component LV (dimensionless).
 * ALGEBRAIC[40] is fRise in component LV (dimensionless).
 * ALGEBRAIC[49] is fDecay in component LV (dimensionless).
 * CONSTANTS[12] is Crest in component Parameters (dimensionless).
 * ALGEBRAIC[68] is xPos in component LV (dimensionless).
 * ALGEBRAIC[70] is xSarc in component LV (dimensionless).
 * ALGEBRAIC[72] is y in component LV (dimensionless).
 * ALGEBRAIC[76] is NoBuckle in component LV (dimensionless).
 * ALGEBRAIC[46] is Vm in component LV (UnitV).
 * ALGEBRAIC[50] is Cm in component LV (Unitc).
 * ALGEBRAIC[56] is Am in component LV (UnitA).
 * ALGEBRAIC[53] is Amtotal in component LV (UnitA).
 * CONSTANTS[13] is Amdead_lv in component Parameters (UnitA).
 * CONSTANTS[14] is Amref_lv in component Parameters (UnitA).
 * ALGEBRAIC[59] is z in component LV (dimensionless).
 * ALGEBRAIC[62] is Ef in component LV (dimensionless).
 * CONSTANTS[15] is kS_v in component Parameters (dimensionless).
 * ALGEBRAIC[80] is Tension in component LV (UnitT).
 * ALGEBRAIC[81] is Pi in component LV (UnitP).
 * STATES[3] is Pi in component AA_RCL (UnitP).
 * STATES[4] is Qo in component LA (UnitQ).
 * STATES[5] is Qo in component LV (UnitQ).
 * CONSTANTS[16] is Q0foo in component Parameters (UnitQ).
 * CONSTANTS[17] is T in component Parameters (second).
 * CONSTANTS[18] is Kaovo in component Parameters (UnitKxi).
 * CONSTANTS[19] is Kaovc_p in component Parameters (UnitKxi).
 * CONSTANTS[20] is Kaovc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[85] is Linductance in component LV (UnitL).
 * CONSTANTS[21] is L_min_ao in component Parameters (UnitL).
 * CONSTANTS[22] is L_param in component Parameters (UnitLparam).
 * STATES[6] is xi in component LV (dimensionless).
 * ALGEBRAIC[82] is Aeff in component LV (UnitA).
 * CONSTANTS[23] is Aao in component Parameters (UnitA).
 * ALGEBRAIC[87] is B in component LV (UnitB).
 * ALGEBRAIC[83] is val_xi in component LV (ode_s).
 * CONSTANTS[24] is B_param in component Parameters (UnitBparam).
 * ALGEBRAIC[88] is L in component LA (dimensionless).
 * ALGEBRAIC[101] is Ls in component LA (Unitl).
 * STATES[7] is Lsc in component LA (Unitl).
 * ALGEBRAIC[107] is Lsnorm in component LA (dimensionless).
 * ALGEBRAIC[89] is ta in component LA (second).
 * CONSTANTS[25] is p_tact_a in component Parameters (second).
 * CONSTANTS[156] is td in component LA (second).
 * CONSTANTS[155] is trise in component LA (second).
 * CONSTANTS[154] is p_tact in component LA (second).
 * CONSTANTS[26] is p_trise_a in component Parameters (dimensionless).
 * CONSTANTS[27] is p_td_a in component Parameters (dimensionless).
 * STATES[8] is C in component LA (dimensionless).
 * STATES[9] is Vcav in component LA (UnitV).
 * CONSTANTS[28] is Vla0 in component Parameters (UnitV).
 * CONSTANTS[29] is Vwall_la in component Parameters (UnitV).
 * ALGEBRAIC[105] is sfpas in component LA (UnitP).
 * ALGEBRAIC[90] is sfact in component LA (UnitP).
 * ALGEBRAIC[92] is sfrest in component LA (UnitP).
 * ALGEBRAIC[108] is sf in component LA (UnitP).
 * CONSTANTS[30] is spas_a in component Parameters (UnitP).
 * CONSTANTS[31] is sact_a in component Parameters (UnitP).
 * CONSTANTS[32] is vmax_a in component Parameters (Unitv).
 * CONSTANTS[33] is delay_la in component Parameters (second).
 * ALGEBRAIC[84] is Time in component LA (second).
 * ALGEBRAIC[93] is Time2 in component LA (second).
 * ALGEBRAIC[86] is xrise in component LA (dimensionless).
 * ALGEBRAIC[91] is fRise in component LA (dimensionless).
 * ALGEBRAIC[95] is fDecay in component LA (dimensionless).
 * ALGEBRAIC[102] is xPos in component LA (dimensionless).
 * ALGEBRAIC[103] is xSarc in component LA (dimensionless).
 * ALGEBRAIC[104] is y in component LA (dimensionless).
 * ALGEBRAIC[106] is NoBuckle in component LA (dimensionless).
 * ALGEBRAIC[94] is Vm in component LA (UnitV).
 * ALGEBRAIC[96] is Cm in component LA (Unitc).
 * ALGEBRAIC[98] is Am in component LA (UnitA).
 * ALGEBRAIC[97] is Amtotal in component LA (UnitA).
 * CONSTANTS[34] is Amdead_la in component Parameters (UnitA).
 * CONSTANTS[35] is Amref_la in component Parameters (UnitA).
 * ALGEBRAIC[99] is z in component LA (dimensionless).
 * ALGEBRAIC[100] is Ef in component LA (dimensionless).
 * CONSTANTS[36] is kS_a in component Parameters (dimensionless).
 * ALGEBRAIC[109] is Tension in component LA (UnitT).
 * ALGEBRAIC[110] is Pi in component LA (UnitP).
 * ALGEBRAIC[173] is Qo in component Bif_LUNG1in_FO2in_LAout (UnitQ).
 * CONSTANTS[37] is Kmivo in component Parameters (UnitKxi).
 * CONSTANTS[38] is Kmivc_p in component Parameters (UnitKxi).
 * CONSTANTS[39] is Kmivc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[114] is Linductance in component LA (UnitL).
 * CONSTANTS[40] is L_min_mi in component Parameters (UnitL).
 * STATES[10] is xi in component LA (dimensionless).
 * ALGEBRAIC[111] is Aeff in component LA (UnitA).
 * CONSTANTS[41] is Ami in component Parameters (UnitA).
 * ALGEBRAIC[116] is B in component LA (UnitB).
 * ALGEBRAIC[177] is val_xi in component LA (ode_s).
 * ALGEBRAIC[117] is L in component RV (dimensionless).
 * ALGEBRAIC[130] is Ls in component RV (Unitl).
 * STATES[11] is Lsc in component RV (Unitl).
 * ALGEBRAIC[136] is Lsnorm in component RV (dimensionless).
 * ALGEBRAIC[118] is ta in component RV (second).
 * CONSTANTS[157] is tact in component RV (second).
 * CONSTANTS[160] is td in component RV (second).
 * CONSTANTS[159] is trise in component RV (second).
 * STATES[12] is C in component RV (dimensionless).
 * STATES[13] is Vcav in component RV (UnitV).
 * CONSTANTS[42] is Vrv0 in component Parameters (UnitV).
 * CONSTANTS[43] is Vwall_rv in component Parameters (UnitV).
 * ALGEBRAIC[134] is sfpas in component RV (UnitP).
 * ALGEBRAIC[119] is sfact in component RV (UnitP).
 * ALGEBRAIC[121] is sfrest in component RV (UnitP).
 * ALGEBRAIC[137] is sf in component RV (UnitP).
 * CONSTANTS[44] is delay_rv in component Parameters (second).
 * ALGEBRAIC[112] is Time in component RV (second).
 * ALGEBRAIC[122] is Time2 in component RV (second).
 * ALGEBRAIC[115] is xrise in component RV (dimensionless).
 * ALGEBRAIC[120] is fRise in component RV (dimensionless).
 * ALGEBRAIC[124] is fDecay in component RV (dimensionless).
 * ALGEBRAIC[131] is xPos in component RV (dimensionless).
 * ALGEBRAIC[132] is xSarc in component RV (dimensionless).
 * ALGEBRAIC[133] is y in component RV (dimensionless).
 * ALGEBRAIC[135] is NoBuckle in component RV (dimensionless).
 * ALGEBRAIC[123] is Vm in component RV (UnitV).
 * ALGEBRAIC[125] is Cm in component RV (Unitc).
 * ALGEBRAIC[127] is Am in component RV (UnitA).
 * ALGEBRAIC[126] is Amtotal in component RV (UnitA).
 * CONSTANTS[45] is Amdead_rv in component Parameters (UnitA).
 * CONSTANTS[46] is Amref_rv in component Parameters (UnitA).
 * ALGEBRAIC[128] is z in component RV (dimensionless).
 * ALGEBRAIC[129] is Ef in component RV (dimensionless).
 * ALGEBRAIC[138] is Tension in component RV (UnitT).
 * ALGEBRAIC[139] is Pi in component RV (UnitP).
 * STATES[14] is Pi in component PA_RCL (UnitP).
 * STATES[15] is Qo in component RA (UnitQ).
 * STATES[16] is Qo in component RV (UnitQ).
 * CONSTANTS[47] is Kpvvo in component Parameters (UnitKxi).
 * CONSTANTS[48] is Kpvvc_p in component Parameters (UnitKxi).
 * CONSTANTS[49] is Kpvvc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[143] is Linductance in component RV (UnitL).
 * CONSTANTS[50] is L_min_pv in component Parameters (UnitL).
 * STATES[17] is xi in component RV (dimensionless).
 * ALGEBRAIC[140] is Aeff in component RV (UnitA).
 * CONSTANTS[51] is Apv in component Parameters (UnitA).
 * ALGEBRAIC[145] is B in component RV (UnitB).
 * ALGEBRAIC[141] is val_xi in component RV (ode_s).
 * ALGEBRAIC[146] is L in component RA (dimensionless).
 * ALGEBRAIC[159] is Ls in component RA (Unitl).
 * STATES[18] is Lsc in component RA (Unitl).
 * ALGEBRAIC[165] is Lsnorm in component RA (dimensionless).
 * ALGEBRAIC[147] is ta in component RA (second).
 * CONSTANTS[158] is tact in component RA (second).
 * CONSTANTS[162] is td in component RA (second).
 * CONSTANTS[161] is trise in component RA (second).
 * STATES[19] is C in component RA (dimensionless).
 * STATES[20] is Vcav in component RA (UnitV).
 * CONSTANTS[52] is Vra0 in component Parameters (UnitV).
 * CONSTANTS[53] is Vwall_ra in component Parameters (UnitV).
 * ALGEBRAIC[163] is sfpas in component RA (UnitP).
 * ALGEBRAIC[148] is sfact in component RA (UnitP).
 * ALGEBRAIC[150] is sfrest in component RA (UnitP).
 * ALGEBRAIC[166] is sf in component RA (UnitP).
 * CONSTANTS[54] is delay_ra in component Parameters (second).
 * ALGEBRAIC[142] is Time in component RA (second).
 * ALGEBRAIC[151] is Time2 in component RA (second).
 * ALGEBRAIC[144] is xrise in component RA (dimensionless).
 * ALGEBRAIC[149] is fRise in component RA (dimensionless).
 * ALGEBRAIC[153] is fDecay in component RA (dimensionless).
 * ALGEBRAIC[160] is xPos in component RA (dimensionless).
 * ALGEBRAIC[161] is xSarc in component RA (dimensionless).
 * ALGEBRAIC[162] is y in component RA (dimensionless).
 * ALGEBRAIC[164] is NoBuckle in component RA (dimensionless).
 * ALGEBRAIC[152] is Vm in component RA (UnitV).
 * ALGEBRAIC[154] is Cm in component RA (Unitc).
 * ALGEBRAIC[156] is Am in component RA (UnitA).
 * ALGEBRAIC[155] is Amtotal in component RA (UnitA).
 * CONSTANTS[55] is Amdead_ra in component Parameters (UnitA).
 * CONSTANTS[56] is Amref_ra in component Parameters (UnitA).
 * ALGEBRAIC[157] is z in component RA (dimensionless).
 * ALGEBRAIC[158] is Ef in component RA (dimensionless).
 * ALGEBRAIC[167] is Tension in component RA (UnitT).
 * ALGEBRAIC[168] is Pi in component RA (UnitP).
 * ALGEBRAIC[170] is Qo in component Bif_SVC1in_IVC2in_RAout (UnitQ).
 * CONSTANTS[57] is Ktrvo in component Parameters (UnitKxi).
 * CONSTANTS[58] is Ktrvc_p in component Parameters (UnitKxi).
 * CONSTANTS[59] is Ktrvc_n in component Parameters (UnitKxi).
 * ALGEBRAIC[174] is Linductance in component RA (UnitL).
 * CONSTANTS[60] is L_min_tr in component Parameters (UnitL).
 * STATES[21] is xi in component RA (dimensionless).
 * ALGEBRAIC[171] is Aeff in component RA (UnitA).
 * CONSTANTS[61] is Atr in component Parameters (UnitA).
 * ALGEBRAIC[178] is B in component RA (UnitB).
 * ALGEBRAIC[175] is val_xi in component RA (ode_s).
 * ALGEBRAIC[18] is Pi in component Bif_AAin_AAA1out_BrachT2out (UnitP).
 * STATES[22] is Qo in component AA_RCL (UnitQ).
 * CONSTANTS[62] is Raa in component Parameters (UnitR).
 * CONSTANTS[63] is Caa in component Parameters (UnitC).
 * CONSTANTS[64] is Laa in component Parameters (UnitL).
 * CONSTANTS[65] is P0foo in component Parameters (UnitP).
 * STATES[23] is Pi in component AAA_RCL (UnitP).
 * ALGEBRAIC[19] is Pi in component Bif_AAAin_DAA1out_CCaroAL2out (UnitP).
 * STATES[24] is Qo in component AAA_RCL (UnitQ).
 * ALGEBRAIC[1] is Qo1 in component Bif_AAin_AAA1out_BrachT2out (UnitQ).
 * CONSTANTS[66] is RaAoA in component Parameters (UnitR).
 * CONSTANTS[67] is CaAoA in component Parameters (UnitC).
 * CONSTANTS[68] is LaAoA in component Parameters (UnitL).
 * STATES[25] is Pi in component DAA_RCL (UnitP).
 * ALGEBRAIC[20] is Pi in component Bif_DAAin_AI1out_SubAL2out (UnitP).
 * STATES[26] is Qo in component DAA_RCL (UnitQ).
 * ALGEBRAIC[2] is Qo1 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ).
 * CONSTANTS[69] is RdAoA in component Parameters (UnitR).
 * CONSTANTS[70] is CdAoA in component Parameters (UnitC).
 * CONSTANTS[71] is LdAoA in component Parameters (UnitL).
 * STATES[27] is Pi in component AI_RCL (UnitP).
 * ALGEBRAIC[3] is Pi2 in component Bif_DA1in_AI2in_AOout (UnitP).
 * STATES[28] is Qo in component AI_RCL (UnitQ).
 * ALGEBRAIC[4] is Qo1 in component Bif_DAAin_AI1out_SubAL2out (UnitQ).
 * CONSTANTS[72] is Risthm in component Parameters (UnitR).
 * CONSTANTS[73] is Cisthm in component Parameters (UnitC).
 * CONSTANTS[74] is Listhm in component Parameters (UnitL).
 * CONSTANTS[75] is Bisthm in component Parameters (UnitK).
 * CONSTANTS[76] is BdAoA in component Parameters (UnitK).
 * ALGEBRAIC[21] is Pi in component Bif_PAin_LUNG1out_DA2out (UnitP).
 * STATES[29] is Qo in component PA_RCL (UnitQ).
 * CONSTANTS[77] is Rpa in component Parameters (UnitR).
 * CONSTANTS[78] is Cpa in component Parameters (UnitC).
 * CONSTANTS[79] is Lpa in component Parameters (UnitL).
 * STATES[30] is Pi in component LUNG_RCL (UnitP).
 * ALGEBRAIC[113] is Pi1 in component Bif_LUNG1in_FO2in_LAout (UnitP).
 * STATES[31] is Qo in component LUNG_RCL (UnitQ).
 * ALGEBRAIC[5] is Qo1 in component Bif_PAin_LUNG1out_DA2out (UnitQ).
 * CONSTANTS[80] is Rla in component Parameters (UnitR).
 * CONSTANTS[81] is Clung in component Parameters (UnitC).
 * CONSTANTS[82] is Lfoo in component Parameters (UnitL).
 * STATES[32] is Pi in component AO1_RC (UnitP).
 * ALGEBRAIC[22] is Pi in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitP).
 * ALGEBRAIC[6] is Qo in component Bif_DA1in_AI2in_AOout (UnitQ).
 * ALGEBRAIC[28] is Qo in component AO1_RC (UnitQ).
 * CONSTANTS[83] is Rdtao in component Parameters (UnitR).
 * CONSTANTS[84] is Cao1 in component Parameters (UnitC).
 * STATES[33] is Pi in component SVC_RCL (UnitP).
 * ALGEBRAIC[172] is Pi1 in component Bif_SVC1in_IVC2in_RAout (UnitP).
 * STATES[34] is Qo in component SVC_RCL (UnitQ).
 * ALGEBRAIC[77] is Qo in component Bif_BR1in_UB2in_SVCout (UnitQ).
 * CONSTANTS[85] is Rsvc in component Parameters (UnitR).
 * CONSTANTS[86] is Csvc in component Parameters (UnitC).
 * STATES[35] is Pi in component AO2_RCL (UnitP).
 * ALGEBRAIC[23] is Pi in component Bif_AOin_LEG1out_UA2out (UnitP).
 * STATES[36] is Qo in component AO2_RCL (UnitQ).
 * ALGEBRAIC[36] is Qo1 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * CONSTANTS[87] is Rdaao in component Parameters (UnitR).
 * CONSTANTS[88] is Cao2 in component Parameters (UnitC).
 * STATES[37] is Pi in component KID_RC (UnitP).
 * ALGEBRAIC[47] is Pi1 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP).
 * STATES[38] is Qo4 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * ALGEBRAIC[51] is Qo in component KID_RC (UnitQ).
 * CONSTANTS[89] is Rrev in component Parameters (UnitR).
 * CONSTANTS[90] is Ckid in component Parameters (UnitC).
 * STATES[39] is Pi in component INTE_RC (UnitP).
 * ALGEBRAIC[29] is Pi2 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP).
 * STATES[40] is Qo2 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * ALGEBRAIC[37] is Qo in component INTE_RC (UnitQ).
 * CONSTANTS[91] is Rporv in component Parameters (UnitR).
 * CONSTANTS[92] is Cinte in component Parameters (UnitC).
 * STATES[41] is Pi in component LEG_RC (UnitP).
 * ALGEBRAIC[60] is Pi4 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP).
 * ALGEBRAIC[7] is Qo1 in component Bif_AOin_LEG1out_UA2out (UnitQ).
 * ALGEBRAIC[63] is Qo in component LEG_RC (UnitQ).
 * CONSTANTS[93] is Rfv in component Parameters (UnitR).
 * CONSTANTS[94] is Cleg in component Parameters (UnitC).
 * STATES[42] is Pi in component PLAC_RC (UnitP).
 * STATES[43] is Pi in component UV_RCL (UnitP).
 * STATES[44] is Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ).
 * ALGEBRAIC[8] is Qo in component PLAC_RC (UnitQ).
 * CONSTANTS[95] is Rplac in component Parameters (UnitR).
 * CONSTANTS[96] is Cplac in component Parameters (UnitC).
 * ALGEBRAIC[43] is Pi in component Bif_UVin_DV1out_HE2out (UnitP).
 * STATES[45] is Qo in component UV_RCL (UnitQ).
 * CONSTANTS[97] is Rfoo in component Parameters (UnitR).
 * CONSTANTS[98] is Cuv in component Parameters (UnitC).
 * STATES[46] is Pi in component HE_RC (UnitP).
 * ALGEBRAIC[54] is Pi3 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP).
 * ALGEBRAIC[42] is Qo in component Bif_UV1in_INTE2in_AO3in_HEout (UnitQ).
 * ALGEBRAIC[57] is Qo in component HE_RC (UnitQ).
 * CONSTANTS[99] is Rhv in component Parameters (UnitR).
 * CONSTANTS[100] is Che in component Parameters (UnitC).
 * STATES[47] is Pi in component IVC_RCL (UnitP).
 * ALGEBRAIC[179] is Pi in component Bif_IVCin_FO1out_RA2out (UnitP).
 * STATES[48] is Qo in component IVC_RCL (UnitQ).
 * ALGEBRAIC[66] is Qo in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitQ).
 * CONSTANTS[101] is Civc in component Parameters (UnitC).
 * STATES[49] is Pi in component BrachT_RCL (UnitP).
 * ALGEBRAIC[25] is Pi in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitP).
 * STATES[50] is Qo in component BrachT_RCL (UnitQ).
 * STATES[51] is Qo2 in component Bif_AAin_AAA1out_BrachT2out (UnitQ).
 * CONSTANTS[102] is Rbct in component Parameters (UnitR).
 * CONSTANTS[103] is Cbct in component Parameters (UnitC).
 * CONSTANTS[104] is Lbct in component Parameters (UnitL).
 * STATES[52] is Pi in component SubAR_RCL (UnitP).
 * ALGEBRAIC[9] is Pi in component UBR_R (UnitP).
 * STATES[53] is Qo in component SubAR_RCL (UnitQ).
 * ALGEBRAIC[10] is Qo1 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ).
 * CONSTANTS[105] is R_R_SC in component Parameters (UnitR).
 * CONSTANTS[106] is C_R_SC in component Parameters (UnitC).
 * CONSTANTS[107] is L_R_SC in component Parameters (UnitL).
 * STATES[54] is Pi in component UBR_RC (UnitP).
 * ALGEBRAIC[11] is Qo in component UBR_R (UnitQ).
 * CONSTANTS[108] is R_R_ub_p in component Parameters (UnitR).
 * ALGEBRAIC[67] is Pi1 in component Bif_UBR1in_UBL2in_UBout (UnitP).
 * ALGEBRAIC[69] is Qo in component UBR_RC (UnitQ).
 * CONSTANTS[109] is R_R_ub in component Parameters (UnitR).
 * CONSTANTS[110] is C_R_ub in component Parameters (UnitC).
 * STATES[55] is Pi in component CCaroAR_RC (UnitP).
 * STATES[56] is Pi in component ICaroAR_RCL (UnitP).
 * STATES[57] is Qo2 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ).
 * ALGEBRAIC[12] is Qo in component CCaroAR_RC (UnitQ).
 * CONSTANTS[111] is R_R_CCA in component Parameters (UnitR).
 * CONSTANTS[112] is C_R_CCA in component Parameters (UnitC).
 * ALGEBRAIC[13] is Pi in component BRR_R (UnitP).
 * STATES[58] is Qo in component ICaroAR_RCL (UnitQ).
 * CONSTANTS[113] is R_R_ICA in component Parameters (UnitR).
 * CONSTANTS[114] is C_R_ICA in component Parameters (UnitC).
 * CONSTANTS[115] is L_R_ICA in component Parameters (UnitL).
 * STATES[59] is Pi in component BRR_RC (UnitP).
 * ALGEBRAIC[48] is Pi1 in component Bif_BRR1in_BRL2in_BRout (UnitP).
 * ALGEBRAIC[26] is Qo in component BRR_R (UnitQ).
 * ALGEBRAIC[52] is Qo in component BRR_RC (UnitQ).
 * CONSTANTS[116] is R_R_br in component Parameters (UnitR).
 * CONSTANTS[117] is C_R_br in component Parameters (UnitC).
 * CONSTANTS[118] is R_R_br_p in component Parameters (UnitR).
 * STATES[60] is Pi in component CCaroAL_RC (UnitP).
 * STATES[61] is Pi in component ICaroAL_RCL (UnitP).
 * STATES[62] is Qo2 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ).
 * ALGEBRAIC[14] is Qo in component CCaroAL_RC (UnitQ).
 * CONSTANTS[119] is R_L_CCA in component Parameters (UnitR).
 * CONSTANTS[120] is C_L_CCA in component Parameters (UnitC).
 * ALGEBRAIC[15] is Pi in component BRL_R (UnitP).
 * STATES[63] is Qo in component ICaroAL_RCL (UnitQ).
 * CONSTANTS[121] is R_L_ICA in component Parameters (UnitR).
 * CONSTANTS[122] is C_L_ICA in component Parameters (UnitC).
 * CONSTANTS[123] is L_L_ICA in component Parameters (UnitL).
 * STATES[64] is Pi in component BRL_RC (UnitP).
 * ALGEBRAIC[31] is Qo in component BRL_R (UnitQ).
 * CONSTANTS[124] is R_L_br_p in component Parameters (UnitR).
 * ALGEBRAIC[55] is Pi2 in component Bif_BRR1in_BRL2in_BRout (UnitP).
 * ALGEBRAIC[58] is Qo in component BRL_RC (UnitQ).
 * CONSTANTS[125] is R_L_br in component Parameters (UnitR).
 * CONSTANTS[126] is C_L_br in component Parameters (UnitC).
 * STATES[65] is Pi in component SubAL_RCL (UnitP).
 * ALGEBRAIC[16] is Pi in component UBL_R (UnitP).
 * STATES[66] is Qo in component SubAL_RCL (UnitQ).
 * STATES[67] is Qo2 in component Bif_DAAin_AI1out_SubAL2out (UnitQ).
 * CONSTANTS[127] is R_L_SC in component Parameters (UnitR).
 * CONSTANTS[128] is C_L_SC in component Parameters (UnitC).
 * CONSTANTS[129] is L_L_SC in component Parameters (UnitL).
 * STATES[68] is Pi in component UBL_RC (UnitP).
 * ALGEBRAIC[39] is Qo in component UBL_R (UnitQ).
 * CONSTANTS[130] is R_L_ub_p in component Parameters (UnitR).
 * ALGEBRAIC[71] is Pi2 in component Bif_UBR1in_UBL2in_UBout (UnitP).
 * ALGEBRAIC[73] is Qo in component UBL_RC (UnitQ).
 * CONSTANTS[131] is R_L_ub in component Parameters (UnitR).
 * CONSTANTS[132] is C_L_ub in component Parameters (UnitC).
 * CONSTANTS[133] is L_R_CCA in component Parameters (UnitL).
 * CONSTANTS[134] is L_L_CCA in component Parameters (UnitL).
 * ALGEBRAIC[44] is Pi1 in component Bif_BR1in_UB2in_SVCout (UnitP).
 * ALGEBRAIC[61] is Qo in component Bif_BRR1in_BRL2in_BRout (UnitQ).
 * ALGEBRAIC[64] is Pi2 in component Bif_BR1in_UB2in_SVCout (UnitP).
 * ALGEBRAIC[75] is Qo in component Bif_UBR1in_UBL2in_UBout (UnitQ).
 * ALGEBRAIC[32] is Pi1 in component Bif_DA1in_AI2in_AOout (UnitP).
 * STATES[69] is Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ).
 * CONSTANTS[135] is Rda in component Parameters (UnitR).
 * CONSTANTS[136] is Bda in component Parameters (UnitK).
 * CONSTANTS[137] is Bmpa in component Parameters (UnitK).
 * CONSTANTS[138] is Rlung in component Parameters (UnitR).
 * CONSTANTS[139] is Lda in component Parameters (UnitL).
 * ALGEBRAIC[33] is Pi3 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP).
 * STATES[70] is Qo3 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * CONSTANTS[140] is Rmea in component Parameters (UnitR).
 * CONSTANTS[141] is Relg in component Parameters (UnitR).
 * CONSTANTS[142] is Rrea in component Parameters (UnitR).
 * CONSTANTS[143] is Rfa in component Parameters (UnitR).
 * CONSTANTS[144] is Rua in component Parameters (UnitR).
 * ALGEBRAIC[38] is Pi2 in component Bif_KID1in_UV2in_HE3in_LEG4in_IVCout (UnitP).
 * ALGEBRAIC[30] is Pi1 in component Bif_UV1in_INTE2in_AO3in_HEout (UnitP).
 * ALGEBRAIC[24] is Qo1 in component Bif_UVin_DV1out_HE2out (UnitQ).
 * STATES[71] is Qo2 in component Bif_UVin_DV1out_HE2out (UnitQ).
 * CONSTANTS[145] is Rha in component Parameters (UnitR).
 * CONSTANTS[146] is Rdv in component Parameters (UnitR).
 * CONSTANTS[147] is Kdv in component Parameters (UnitK).
 * ALGEBRAIC[176] is Pi2 in component Bif_LUNG1in_FO2in_LAout (UnitP).
 * ALGEBRAIC[180] is Pi2 in component Bif_SVC1in_IVC2in_RAout (UnitP).
 * ALGEBRAIC[169] is Qo1 in component Bif_IVCin_FO1out_RA2out (UnitQ).
 * STATES[72] is Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ).
 * CONSTANTS[148] is Rivc in component Parameters (UnitR).
 * CONSTANTS[149] is Kfo in component Parameters (UnitKfo).
 * CONSTANTS[150] is Cfoo in component Parameters (UnitC).
 * RATES[1] is d/dt C in component LV (dimensionless).
 * RATES[0] is d/dt Lsc in component LV (Unitl).
 * RATES[2] is d/dt Vcav in component LV (UnitV).
 * RATES[5] is d/dt Qo in component LV (UnitQ).
 * RATES[6] is d/dt xi in component LV (dimensionless).
 * RATES[8] is d/dt C in component LA (dimensionless).
 * RATES[7] is d/dt Lsc in component LA (Unitl).
 * RATES[9] is d/dt Vcav in component LA (UnitV).
 * RATES[4] is d/dt Qo in component LA (UnitQ).
 * RATES[10] is d/dt xi in component LA (dimensionless).
 * RATES[12] is d/dt C in component RV (dimensionless).
 * RATES[11] is d/dt Lsc in component RV (Unitl).
 * RATES[13] is d/dt Vcav in component RV (UnitV).
 * RATES[16] is d/dt Qo in component RV (UnitQ).
 * RATES[17] is d/dt xi in component RV (dimensionless).
 * RATES[19] is d/dt C in component RA (dimensionless).
 * RATES[18] is d/dt Lsc in component RA (Unitl).
 * RATES[20] is d/dt Vcav in component RA (UnitV).
 * RATES[15] is d/dt Qo in component RA (UnitQ).
 * RATES[21] is d/dt xi in component RA (dimensionless).
 * RATES[3] is d/dt Pi in component AA_RCL (UnitP).
 * RATES[22] is d/dt Qo in component AA_RCL (UnitQ).
 * RATES[23] is d/dt Pi in component AAA_RCL (UnitP).
 * RATES[24] is d/dt Qo in component AAA_RCL (UnitQ).
 * RATES[25] is d/dt Pi in component DAA_RCL (UnitP).
 * RATES[26] is d/dt Qo in component DAA_RCL (UnitQ).
 * RATES[27] is d/dt Pi in component AI_RCL (UnitP).
 * RATES[28] is d/dt Qo in component AI_RCL (UnitQ).
 * RATES[14] is d/dt Pi in component PA_RCL (UnitP).
 * RATES[29] is d/dt Qo in component PA_RCL (UnitQ).
 * RATES[30] is d/dt Pi in component LUNG_RCL (UnitP).
 * RATES[31] is d/dt Qo in component LUNG_RCL (UnitQ).
 * RATES[32] is d/dt Pi in component AO1_RC (UnitP).
 * RATES[33] is d/dt Pi in component SVC_RCL (UnitP).
 * RATES[34] is d/dt Qo in component SVC_RCL (UnitQ).
 * RATES[35] is d/dt Pi in component AO2_RCL (UnitP).
 * RATES[36] is d/dt Qo in component AO2_RCL (UnitQ).
 * RATES[37] is d/dt Pi in component KID_RC (UnitP).
 * RATES[39] is d/dt Pi in component INTE_RC (UnitP).
 * RATES[41] is d/dt Pi in component LEG_RC (UnitP).
 * RATES[42] is d/dt Pi in component PLAC_RC (UnitP).
 * RATES[43] is d/dt Pi in component UV_RCL (UnitP).
 * RATES[45] is d/dt Qo in component UV_RCL (UnitQ).
 * RATES[46] is d/dt Pi in component HE_RC (UnitP).
 * RATES[47] is d/dt Pi in component IVC_RCL (UnitP).
 * RATES[48] is d/dt Qo in component IVC_RCL (UnitQ).
 * RATES[49] is d/dt Pi in component BrachT_RCL (UnitP).
 * RATES[50] is d/dt Qo in component BrachT_RCL (UnitQ).
 * RATES[52] is d/dt Pi in component SubAR_RCL (UnitP).
 * RATES[53] is d/dt Qo in component SubAR_RCL (UnitQ).
 * RATES[54] is d/dt Pi in component UBR_RC (UnitP).
 * RATES[55] is d/dt Pi in component CCaroAR_RC (UnitP).
 * RATES[56] is d/dt Pi in component ICaroAR_RCL (UnitP).
 * RATES[58] is d/dt Qo in component ICaroAR_RCL (UnitQ).
 * RATES[59] is d/dt Pi in component BRR_RC (UnitP).
 * RATES[60] is d/dt Pi in component CCaroAL_RC (UnitP).
 * RATES[61] is d/dt Pi in component ICaroAL_RCL (UnitP).
 * RATES[63] is d/dt Qo in component ICaroAL_RCL (UnitQ).
 * RATES[64] is d/dt Pi in component BRL_RC (UnitP).
 * RATES[65] is d/dt Pi in component SubAL_RCL (UnitP).
 * RATES[66] is d/dt Qo in component SubAL_RCL (UnitQ).
 * RATES[68] is d/dt Pi in component UBL_RC (UnitP).
 * RATES[57] is d/dt Qo2 in component Bif_BrachTin_SubAR1out_CCaroAR2out (UnitQ).
 * RATES[51] is d/dt Qo2 in component Bif_AAin_AAA1out_BrachT2out (UnitQ).
 * RATES[62] is d/dt Qo2 in component Bif_AAAin_DAA1out_CCaroAL2out (UnitQ).
 * RATES[67] is d/dt Qo2 in component Bif_DAAin_AI1out_SubAL2out (UnitQ).
 * RATES[69] is d/dt Qo2 in component Bif_PAin_LUNG1out_DA2out (UnitQ).
 * RATES[40] is d/dt Qo2 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * RATES[70] is d/dt Qo3 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * RATES[38] is d/dt Qo4 in component Bif_AOin_AO1out_INTE2out_HE3out_KID4out (UnitQ).
 * RATES[44] is d/dt Qo2 in component Bif_AOin_LEG1out_UA2out (UnitQ).
 * RATES[71] is d/dt Qo2 in component Bif_UVin_DV1out_HE2out (UnitQ).
 * RATES[72] is d/dt Qo2 in component Bif_IVCin_FO1out_RA2out (UnitQ).
 */
#include <math.h>
#include <stdio.h>
void
initConsts(double* CONSTANTS, double* RATES, double *STATES)
{
CONSTANTS[0] = 2.;
STATES[0] = 2.;
CONSTANTS[1] = 2.;
CONSTANTS[2] = 0.28;
CONSTANTS[3] = 0.14;
CONSTANTS[4] = 0.08;
STATES[1] = 0.0;
CONSTANTS[5] = 0.0;
CONSTANTS[6] = 17;
CONSTANTS[7] = 6.3955042632574255;
CONSTANTS[8] = 15;
CONSTANTS[9] = 280.;
CONSTANTS[10] = 7.;
CONSTANTS[11] = 0.375;
CONSTANTS[12] = 0.02;
CONSTANTS[13] = 3.65716;
CONSTANTS[14] = 18.066;
CONSTANTS[15] = 3.;
STATES[3] = 0.;
CONSTANTS[16] = 0.;
CONSTANTS[17] = 0.43;
CONSTANTS[18] = 186.04789;
CONSTANTS[19] = 29.76766;
CONSTANTS[20] = 186.04789;
CONSTANTS[21] = 0.0011665;
CONSTANTS[22] = 0.00034289;
STATES[6] = 1.0;
CONSTANTS[23] = 0.302;
CONSTANTS[24] = 3.975e-4;
STATES[7] = 2.;
CONSTANTS[25] = 0.10;
CONSTANTS[26] = 0.18;
CONSTANTS[27] = 0.16;
STATES[8] = 0.0;
CONSTANTS[28] = 17;
CONSTANTS[29] = 1.2540204437759659;
CONSTANTS[30] = 91;
CONSTANTS[31] = 196.;
CONSTANTS[32] = 10.5;
CONSTANTS[33] = 0.325;
CONSTANTS[34] = 3.65716;
CONSTANTS[35] = 8.045752729286914;
CONSTANTS[36] = 2.25;
CONSTANTS[37] = 74.41915686963517;
CONSTANTS[38] = 79.07035417398737;
CONSTANTS[39] = 79.07035417398737;
CONSTANTS[40] = 0.0011665;
STATES[10] = 1.0;
CONSTANTS[41] = 0.407;
STATES[11] = 2.;
STATES[12] = 0.0;
CONSTANTS[42] = 17;
CONSTANTS[43] = 6.3955042632574255;
CONSTANTS[44] = 0.375;
CONSTANTS[45] = 3.65716;
CONSTANTS[46] = 18.066;
STATES[14] = 0.;
CONSTANTS[47] = 186.04789;
CONSTANTS[48] = 49.61897;
CONSTANTS[49] = 186.04789;
CONSTANTS[50] = 0.0011665;
STATES[17] = 1.0;
CONSTANTS[51] = 0.363;
STATES[18] = 2.;
STATES[19] = 0.0;
CONSTANTS[52] = 17;
CONSTANTS[53] = 1.2540204437759659;
CONSTANTS[54] = 0.325;
CONSTANTS[55] = 3.65716;
CONSTANTS[56] = 8.045752729286914;
CONSTANTS[57] = 74.41915686963517;
CONSTANTS[58] = 99.21934;
CONSTANTS[59] = 186.04789;
CONSTANTS[60] = 0.0011665;
STATES[21] = 1.0;
CONSTANTS[61] = 0.439;
STATES[22] = 0.;
CONSTANTS[62] = 0.01028363914594297;
CONSTANTS[63] = 0.045;
CONSTANTS[64] = 5.83e-05;
CONSTANTS[65] = 0.;
STATES[23] = 0.;
STATES[24] = 0.;
CONSTANTS[66] = 0.00830126333005667;
CONSTANTS[67] = 0.0013289450460739467;
CONSTANTS[68] = 0.0000234;
STATES[25] = 0.;
STATES[26] = 0.;
CONSTANTS[69] = 0.011696950003148087;
CONSTANTS[70] = 0.0011195482130380158;
CONSTANTS[71] = 0.0000313554;
STATES[27] = 0.;
STATES[28] = 0.;
CONSTANTS[72] = 0.010987993251745447;
CONSTANTS[73] = 0.000956187060206298;
CONSTANTS[74] = 0.000011665;
CONSTANTS[75] = 0.01756;
CONSTANTS[76] = 0.012451;
STATES[29] = 0.;
CONSTANTS[77] = 0.006307296462416422;
CONSTANTS[78] = 0.05374960115453952;
CONSTANTS[79] = 0.002719541056715655;
STATES[30] = 0.;
STATES[31] = 0.;
CONSTANTS[80] = 3.189740661608074;
CONSTANTS[81] = 0.21499840461815808;
CONSTANTS[82] = 0.00001;
STATES[32] = 0.;
CONSTANTS[83] = 0.068699902722773;
CONSTANTS[84] = 0.08;
STATES[33] = 0.;
STATES[34] = 0.;
CONSTANTS[85] = 0.3189740661608074;
CONSTANTS[86] = 0.5374960115453952;
STATES[35] = 0.;
STATES[36] = 0.;
CONSTANTS[87] = 0.0956922198482422;
CONSTANTS[88] = 0.02687480057726976;
STATES[37] = 0.;
STATES[38] = 0.;
CONSTANTS[89] = 22.32818463125652;
CONSTANTS[90] = 0.010749920230907904;
STATES[39] = 0.;
STATES[40] = 0.;
CONSTANTS[91] = 11.16409231562826;
CONSTANTS[92] = 0.1343740028863488;
STATES[41] = 0.;
CONSTANTS[93] = 0.9569221984824222;
CONSTANTS[94] = 2.1499840461815807;
STATES[42] = 0.;
STATES[43] = 0.;
STATES[44] = 0.;
CONSTANTS[95] = 5.422559124733726;
CONSTANTS[96] = 0.8062440173180927;
STATES[45] = 0.;
CONSTANTS[97] = 0.00001;
CONSTANTS[98] = 0.16124880346361856;
STATES[46] = 0.;
CONSTANTS[99] = 0.25517925292864596;
CONSTANTS[100] = 1.6124880346361854;
STATES[47] = 0.;
STATES[48] = 0.;
CONSTANTS[101] = 0.3224976069272371;
STATES[49] = 0.;
STATES[50] = 0.;
STATES[51] = 0.;
CONSTANTS[102] = 0.035554987210575435;
CONSTANTS[103] = 0.0012120550623362601;
CONSTANTS[104] = 0.00004595;
STATES[52] = 0.;
STATES[53] = 0.;
CONSTANTS[105] = 0.22733452587929065;
CONSTANTS[106] = 0.0005365772743248872;
CONSTANTS[107] = 0.00013936645035482416;
STATES[54] = 0.;
CONSTANTS[108] = 7.5;
CONSTANTS[109] = 35;
CONSTANTS[110] = 0.1461989151403475;
STATES[55] = 0.;
STATES[56] = 0.;
STATES[57] = 0.;
CONSTANTS[111] = 0.3641088965225617;
CONSTANTS[112] = 0.001666237635790725;
STATES[58] = 0.;
CONSTANTS[113] = 0.8889807223901702;
CONSTANTS[114] = 0.0006449952138544742;
CONSTANTS[115] = 0.000525129331980645;
STATES[59] = 0.;
CONSTANTS[116] = 35;
CONSTANTS[117] = 0.01;
CONSTANTS[118] = 7.5;
STATES[60] = 0.;
STATES[61] = 0.;
STATES[62] = 0.;
CONSTANTS[119] = 0.5210354270914556;
CONSTANTS[120] = 0.0023832141382615236;
STATES[63] = 0.;
CONSTANTS[121] = 0.8889807223901702;
CONSTANTS[122] = 0.0006449952138544742;
CONSTANTS[123] = 0.000525129331980645;
STATES[64] = 0.;
CONSTANTS[124] = 7.5;
CONSTANTS[125] = 35;
CONSTANTS[126] = 0.01;
STATES[65] = 0.;
STATES[66] = 0.;
STATES[67] = 0.;
CONSTANTS[127] = 0.22733452587929065;
CONSTANTS[128] = 0.0005365772743248872;
CONSTANTS[129] = 0.00013936645035482416;
STATES[68] = 0.;
CONSTANTS[130] = 7.5;
CONSTANTS[131] = 35;
CONSTANTS[132] = 0.045687160981358596;
CONSTANTS[133] = 0.00033607997277328904;
CONSTANTS[134] = 0.00039494354592893;
STATES[69] = 0.;
CONSTANTS[135] = 0.03888377243196166;
CONSTANTS[136] = 0.02091;
CONSTANTS[137] = 0.00293;
CONSTANTS[138] = 21.530749465854502;
CONSTANTS[139] = 0.001;
STATES[70] = 0.;
CONSTANTS[140] = 54.22559124733726;
CONSTANTS[141] = 129.184496795127;
CONSTANTS[142] = 27.91023078907065;
CONSTANTS[143] = 5.58204615781413;
CONSTANTS[144] = 6.219994290135745;
STATES[71] = 0.;
CONSTANTS[145] = 0.7974351654020185;
CONSTANTS[146] = 2.0733314300452483;
CONSTANTS[147] = 0.39207728437276956;
STATES[72] = 0.;
CONSTANTS[148] = 0.19138443969648444;
CONSTANTS[149] = 0.5292918645216145;
CONSTANTS[150] = 0.0005;
CONSTANTS[151] = CONSTANTS[2];
CONSTANTS[152] =  CONSTANTS[3]*CONSTANTS[2];
CONSTANTS[153] =  CONSTANTS[4]*CONSTANTS[2];
CONSTANTS[154] = CONSTANTS[25];
CONSTANTS[155] =  CONSTANTS[26]*CONSTANTS[25];
CONSTANTS[156] =  CONSTANTS[27]*CONSTANTS[25];
CONSTANTS[157] = CONSTANTS[2];
CONSTANTS[158] = CONSTANTS[25];
CONSTANTS[159] =  CONSTANTS[3]*CONSTANTS[157];
CONSTANTS[160] =  CONSTANTS[4]*CONSTANTS[157];
CONSTANTS[161] =  CONSTANTS[26]*CONSTANTS[158];
CONSTANTS[162] =  CONSTANTS[27]*CONSTANTS[158];
STATES[2] = CONSTANTS[6];
STATES[4] = CONSTANTS[16];
STATES[5] = CONSTANTS[16];
STATES[9] = CONSTANTS[28];
STATES[13] = CONSTANTS[42];
STATES[15] = CONSTANTS[16];
STATES[16] = CONSTANTS[16];
STATES[20] = CONSTANTS[52];
}
void
computeRates(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC)
{
RATES[2] = STATES[4] - STATES[5];
RATES[13] = STATES[15] - STATES[16];
RATES[3] = (STATES[5] - STATES[22])/CONSTANTS[63];
RATES[14] = (STATES[16] - STATES[29])/CONSTANTS[78];
RATES[49] = (STATES[51] - STATES[50])/CONSTANTS[103];
RATES[65] = (STATES[67] - STATES[66])/CONSTANTS[128];
ALGEBRAIC[1] = STATES[22] - STATES[51];
RATES[23] = (ALGEBRAIC[1] - STATES[24])/CONSTANTS[67];
ALGEBRAIC[2] = STATES[24] - STATES[62];
RATES[25] = (ALGEBRAIC[2] - STATES[26])/CONSTANTS[70];
ALGEBRAIC[4] = STATES[26] - STATES[67];
RATES[27] = (ALGEBRAIC[4] - STATES[28])/CONSTANTS[73];
ALGEBRAIC[3] = STATES[32];
RATES[28] = (((STATES[27] - ALGEBRAIC[3]) -  CONSTANTS[72]*STATES[28]) -  (CONSTANTS[75] - CONSTANTS[76])*STATES[28]*fabs(STATES[28]))/CONSTANTS[74];
ALGEBRAIC[5] = STATES[29] - STATES[69];
RATES[30] = (ALGEBRAIC[5] - STATES[31])/CONSTANTS[81];
ALGEBRAIC[8] = (STATES[42] - STATES[43])/CONSTANTS[95];
RATES[42] = (STATES[44] - ALGEBRAIC[8])/CONSTANTS[96];
RATES[43] = (ALGEBRAIC[8] - STATES[45])/CONSTANTS[98];
ALGEBRAIC[10] = STATES[50] - STATES[57];
RATES[52] = (ALGEBRAIC[10] - STATES[53])/CONSTANTS[106];
ALGEBRAIC[9] = STATES[54]+ CONSTANTS[108]*STATES[53];
RATES[53] = ((STATES[52] - ALGEBRAIC[9]) -  CONSTANTS[105]*STATES[53])/CONSTANTS[107];
ALGEBRAIC[12] = (STATES[55] - STATES[56])/CONSTANTS[111];
RATES[55] = (STATES[57] - ALGEBRAIC[12])/CONSTANTS[112];
RATES[56] = (ALGEBRAIC[12] - STATES[58])/CONSTANTS[114];
ALGEBRAIC[13] = STATES[59]+ CONSTANTS[118]*STATES[58];
RATES[58] = ((STATES[56] - ALGEBRAIC[13]) -  CONSTANTS[113]*STATES[58])/CONSTANTS[115];
ALGEBRAIC[14] = (STATES[60] - STATES[61])/CONSTANTS[119];
RATES[60] = (STATES[62] - ALGEBRAIC[14])/CONSTANTS[120];
RATES[61] = (ALGEBRAIC[14] - STATES[63])/CONSTANTS[122];
ALGEBRAIC[15] = STATES[64]+ CONSTANTS[124]*STATES[63];
RATES[63] = ((STATES[61] - ALGEBRAIC[15]) -  CONSTANTS[121]*STATES[63])/CONSTANTS[123];
ALGEBRAIC[16] = STATES[68]+ CONSTANTS[130]*STATES[66];
RATES[66] = ((STATES[65] - ALGEBRAIC[16]) -  CONSTANTS[127]*STATES[66])/CONSTANTS[129];
ALGEBRAIC[18] = STATES[23]+ CONSTANTS[97]*ALGEBRAIC[1];
RATES[22] = ((STATES[3] - ALGEBRAIC[18]) -  CONSTANTS[62]*STATES[22])/CONSTANTS[64];
ALGEBRAIC[19] = STATES[25]+ CONSTANTS[97]*ALGEBRAIC[2];
RATES[24] = ((STATES[23] - ALGEBRAIC[19]) -  CONSTANTS[66]*STATES[24])/CONSTANTS[68];
ALGEBRAIC[20] = STATES[27]+ CONSTANTS[97]*ALGEBRAIC[4];
RATES[26] = ((STATES[25] - ALGEBRAIC[20]) -  CONSTANTS[69]*STATES[26])/CONSTANTS[71];
ALGEBRAIC[21] = STATES[30]+ CONSTANTS[138]*ALGEBRAIC[5];
RATES[29] = ((STATES[14] - ALGEBRAIC[21]) -  CONSTANTS[77]*STATES[29])/CONSTANTS[79];
ALGEBRAIC[7] = STATES[36] - STATES[44];
ALGEBRAIC[23] = STATES[41]+ CONSTANTS[143]*ALGEBRAIC[7];
RATES[36] = ((STATES[35] - ALGEBRAIC[23]) -  CONSTANTS[87]*STATES[36])/CONSTANTS[82];
ALGEBRAIC[25] = STATES[52]+ CONSTANTS[97]*ALGEBRAIC[10];
RATES[50] = ((STATES[49] - ALGEBRAIC[25]) -  CONSTANTS[102]*STATES[50])/CONSTANTS[104];
RATES[57] = ((ALGEBRAIC[25] - STATES[55]) -  CONSTANTS[97]*STATES[57])/CONSTANTS[133];
RATES[51] = ((ALGEBRAIC[18] - STATES[49]) -  CONSTANTS[97]*STATES[51])/CONSTANTS[82];
RATES[62] = ((ALGEBRAIC[19] - STATES[60]) -  CONSTANTS[97]*STATES[62])/CONSTANTS[134];
RATES[67] = ((ALGEBRAIC[20] - STATES[65]) -  CONSTANTS[97]*STATES[67])/CONSTANTS[82];
ALGEBRAIC[22] = STATES[35];
RATES[40] = ((ALGEBRAIC[22] - STATES[39]) -  CONSTANTS[140]*STATES[40])/CONSTANTS[82];
RATES[38] = ((ALGEBRAIC[22] - STATES[37]) -  CONSTANTS[142]*STATES[38])/CONSTANTS[82];
RATES[44] = ((ALGEBRAIC[23] - STATES[42]) -  CONSTANTS[144]*STATES[44])/CONSTANTS[82];
ALGEBRAIC[6] = STATES[69]+STATES[28];
ALGEBRAIC[28] = (STATES[32] - ALGEBRAIC[22])/CONSTANTS[83];
RATES[32] = (ALGEBRAIC[6] - ALGEBRAIC[28])/CONSTANTS[84];
ALGEBRAIC[32] = STATES[32];
RATES[69] = (((ALGEBRAIC[21] - ALGEBRAIC[32]) -  CONSTANTS[135]*STATES[69]) -  (CONSTANTS[136] - CONSTANTS[137])*STATES[69]*fabs(STATES[69]))/CONSTANTS[139];
ALGEBRAIC[33] = STATES[46];
RATES[70] = ((ALGEBRAIC[22] - ALGEBRAIC[33]) -  CONSTANTS[141]*STATES[70])/CONSTANTS[82];
ALGEBRAIC[36] = ((ALGEBRAIC[28] - STATES[40]) - STATES[70]) - STATES[38];
RATES[35] = (ALGEBRAIC[36] - STATES[36])/CONSTANTS[88];
ALGEBRAIC[29] = STATES[46];
ALGEBRAIC[37] = (STATES[39] - ALGEBRAIC[29])/CONSTANTS[91];
RATES[39] = (STATES[40] - ALGEBRAIC[37])/CONSTANTS[92];
ALGEBRAIC[38] = STATES[47];
ALGEBRAIC[24] = STATES[45] - STATES[71];
ALGEBRAIC[43] = ALGEBRAIC[38]+ CONSTANTS[146]*ALGEBRAIC[24]+ CONSTANTS[147]*ALGEBRAIC[24]*fabs(ALGEBRAIC[24]);
RATES[45] = ((STATES[43] - ALGEBRAIC[43]) -  CONSTANTS[97]*STATES[45])/CONSTANTS[82];
ALGEBRAIC[30] = STATES[46];
RATES[71] = ((ALGEBRAIC[43] - ALGEBRAIC[30]) -  CONSTANTS[145]*STATES[71])/CONSTANTS[82];
ALGEBRAIC[27] = fmax((STATES[0] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[0] = ((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17]))/CONSTANTS[152];
ALGEBRAIC[17] = fmin(8.00000, fmax(ALGEBRAIC[0], 0.00000));
ALGEBRAIC[40] = (  tanh( 4.00000*pow(ALGEBRAIC[27], 2.00000))*pow(ALGEBRAIC[17], 3.00000)*exp(- ALGEBRAIC[17])*pow(8.00000 - ALGEBRAIC[17], 2.00000)*0.0200000)/CONSTANTS[152];
ALGEBRAIC[34] =  CONSTANTS[2]*(0.650000+ 0.700000*ALGEBRAIC[27]);
ALGEBRAIC[45] = (((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17])) - ALGEBRAIC[34])/CONSTANTS[153];
ALGEBRAIC[49] = (0.500000+ 0.500000* sin( (ALGEBRAIC[45]/fabs(ALGEBRAIC[45]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[45]))))/CONSTANTS[153];
RATES[1] = ALGEBRAIC[40] -  STATES[1]*ALGEBRAIC[49];
ALGEBRAIC[47] = STATES[47];
ALGEBRAIC[51] = (STATES[37] - ALGEBRAIC[47])/CONSTANTS[89];
RATES[37] = (STATES[38] - ALGEBRAIC[51])/CONSTANTS[90];
ALGEBRAIC[26] = STATES[58];
ALGEBRAIC[44] = STATES[33];
ALGEBRAIC[48] = ALGEBRAIC[44];
ALGEBRAIC[52] = (STATES[59] - ALGEBRAIC[48])/CONSTANTS[116];
RATES[59] = (ALGEBRAIC[26] - ALGEBRAIC[52])/CONSTANTS[117];
ALGEBRAIC[42] = STATES[71]+ALGEBRAIC[37]+STATES[70];
ALGEBRAIC[54] = STATES[47];
ALGEBRAIC[57] = (STATES[46] - ALGEBRAIC[54])/CONSTANTS[99];
RATES[46] = (ALGEBRAIC[42] - ALGEBRAIC[57])/CONSTANTS[100];
ALGEBRAIC[31] = STATES[63];
ALGEBRAIC[55] = ALGEBRAIC[44];
ALGEBRAIC[58] = (STATES[64] - ALGEBRAIC[55])/CONSTANTS[125];
RATES[64] = (ALGEBRAIC[31] - ALGEBRAIC[58])/CONSTANTS[126];
ALGEBRAIC[60] = STATES[47];
ALGEBRAIC[63] = (STATES[41] - ALGEBRAIC[60])/CONSTANTS[93];
RATES[41] = (ALGEBRAIC[7] - ALGEBRAIC[63])/CONSTANTS[94];
ALGEBRAIC[66] = ALGEBRAIC[51]+ALGEBRAIC[24]+ALGEBRAIC[57]+ALGEBRAIC[63];
RATES[47] = (ALGEBRAIC[66] - STATES[48])/CONSTANTS[101];
ALGEBRAIC[11] = STATES[53];
ALGEBRAIC[64] = STATES[33];
ALGEBRAIC[67] = ALGEBRAIC[64];
ALGEBRAIC[69] = (STATES[54] - ALGEBRAIC[67])/CONSTANTS[109];
RATES[54] = (ALGEBRAIC[11] - ALGEBRAIC[69])/CONSTANTS[110];
ALGEBRAIC[39] = STATES[66];
ALGEBRAIC[71] = ALGEBRAIC[64];
ALGEBRAIC[73] = (STATES[68] - ALGEBRAIC[71])/CONSTANTS[131];
RATES[68] = (ALGEBRAIC[39] - ALGEBRAIC[73])/CONSTANTS[132];
ALGEBRAIC[61] = ALGEBRAIC[52]+ALGEBRAIC[58];
ALGEBRAIC[75] = ALGEBRAIC[69]+ALGEBRAIC[73];
ALGEBRAIC[77] = ALGEBRAIC[61]+ALGEBRAIC[75];
RATES[33] = (ALGEBRAIC[77] - STATES[34])/CONSTANTS[86];
ALGEBRAIC[46] = STATES[2]+ 0.500000*CONSTANTS[7];
ALGEBRAIC[50] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[46]), 1.00000/3.00000);
ALGEBRAIC[53] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[50], 2.00000);
ALGEBRAIC[56] = ALGEBRAIC[53] - CONSTANTS[13];
ALGEBRAIC[59] = ( 1.50000*CONSTANTS[7]*ALGEBRAIC[50])/ALGEBRAIC[56];
ALGEBRAIC[62] = ( 0.500000*log(ALGEBRAIC[56]/CONSTANTS[14]) - pow(ALGEBRAIC[59], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[59], 4.00000);
ALGEBRAIC[65] =  exp(ALGEBRAIC[62])*CONSTANTS[0];
ALGEBRAIC[78] = fmax((ALGEBRAIC[65] - STATES[0])/0.0400000, - 0.0200000);
ALGEBRAIC[68] = fmax( CONSTANTS[15]*log(ALGEBRAIC[65]/1.80000), 0.00000);
ALGEBRAIC[70] = log(ALGEBRAIC[65]/CONSTANTS[0])+0.100000;
ALGEBRAIC[72] =  0.120000*(cosh( 5.00000*ALGEBRAIC[68]) - 1.00000)+ALGEBRAIC[70];
ALGEBRAIC[74] =  CONSTANTS[8]*ALGEBRAIC[72];
ALGEBRAIC[76] =  tanh( 10.0000*STATES[1]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[74], 2.00000)));
RATES[0] = ( fmax(ALGEBRAIC[78] - 1.00000,  ALGEBRAIC[76]*(ALGEBRAIC[78] - 1.00000))*CONSTANTS[10]*0.850000)/CONSTANTS[17];
ALGEBRAIC[35] =  CONSTANTS[9]*STATES[1]*ALGEBRAIC[27];
ALGEBRAIC[41] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[27];
ALGEBRAIC[79] = (fmax( 0.200000*ALGEBRAIC[74], ALGEBRAIC[74])+ (ALGEBRAIC[35]+ALGEBRAIC[41])*ALGEBRAIC[78]) - ALGEBRAIC[41];
ALGEBRAIC[80] =  (( ALGEBRAIC[79]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[59], 2.00000)))/ALGEBRAIC[56])*CONSTANTS[7];
ALGEBRAIC[81] =  2.00000*ALGEBRAIC[80]*ALGEBRAIC[50];
ALGEBRAIC[83] = (STATES[4]>=STATES[5] ?  STATES[6]*CONSTANTS[19]*(ALGEBRAIC[81] - STATES[3]) :  STATES[6]*CONSTANTS[20]*(ALGEBRAIC[81] - STATES[3]));
RATES[6] = (ALGEBRAIC[81]>=STATES[3] ?  (1.00000 - STATES[6])*CONSTANTS[18]*(ALGEBRAIC[81] - STATES[3]) : ALGEBRAIC[83]);
ALGEBRAIC[82] =  CONSTANTS[23]*STATES[6]+0.000100000;
ALGEBRAIC[85] = CONSTANTS[22]/ALGEBRAIC[82]+CONSTANTS[21];
ALGEBRAIC[87] = CONSTANTS[24]/pow(ALGEBRAIC[82], 2.00000);
RATES[5] = ((ALGEBRAIC[81] - STATES[3]) -  ALGEBRAIC[87]*STATES[5]*fabs(STATES[5]))/ALGEBRAIC[85];
ALGEBRAIC[88] = fmax((STATES[7] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[84] = ((VOI - CONSTANTS[33]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[33])/CONSTANTS[17]))/CONSTANTS[155];
ALGEBRAIC[86] = fmin(8.00000, fmax(ALGEBRAIC[84], 0.00000));
ALGEBRAIC[91] = (  tanh( 4.00000*pow(ALGEBRAIC[88], 2.00000))*pow(ALGEBRAIC[86], 3.00000)*exp(- ALGEBRAIC[86])*pow(8.00000 - ALGEBRAIC[86], 2.00000)*0.0200000)/CONSTANTS[155];
ALGEBRAIC[89] =  CONSTANTS[25]*(0.650000+ 0.700000*ALGEBRAIC[88]);
ALGEBRAIC[93] = (((VOI - CONSTANTS[33]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[33])/CONSTANTS[17])) - ALGEBRAIC[89])/CONSTANTS[156];
ALGEBRAIC[95] = (0.500000+ 0.500000* sin( (ALGEBRAIC[93]/fabs(ALGEBRAIC[93]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[93]))))/CONSTANTS[156];
RATES[8] = ALGEBRAIC[91] -  STATES[8]*ALGEBRAIC[95];
ALGEBRAIC[94] = STATES[9]+ 0.500000*CONSTANTS[29];
ALGEBRAIC[96] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[94]), 1.00000/3.00000);
ALGEBRAIC[97] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[96], 2.00000);
ALGEBRAIC[98] = ALGEBRAIC[97] - CONSTANTS[34];
ALGEBRAIC[99] = ( 1.50000*CONSTANTS[29]*ALGEBRAIC[96])/ALGEBRAIC[98];
ALGEBRAIC[100] = ( 0.500000*log(ALGEBRAIC[98]/CONSTANTS[35]) - pow(ALGEBRAIC[99], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[99], 4.00000);
ALGEBRAIC[101] =  exp(ALGEBRAIC[100])*CONSTANTS[0];
ALGEBRAIC[107] = fmax((ALGEBRAIC[101] - STATES[7])/0.0400000, - 0.0200000);
ALGEBRAIC[102] = fmax( CONSTANTS[36]*log(ALGEBRAIC[101]/1.80000), 0.00000);
ALGEBRAIC[103] = log(ALGEBRAIC[101]/CONSTANTS[0])+0.100000;
ALGEBRAIC[104] =  0.120000*(cosh( 5.00000*ALGEBRAIC[102]) - 1.00000)+ALGEBRAIC[103];
ALGEBRAIC[105] =  CONSTANTS[30]*ALGEBRAIC[104];
ALGEBRAIC[106] =  tanh( 10.0000*STATES[8]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[105], 2.00000)));
RATES[7] = ( fmax(ALGEBRAIC[107] - 1.00000,  ALGEBRAIC[106]*(ALGEBRAIC[107] - 1.00000))*CONSTANTS[32]*0.850000)/CONSTANTS[17];
ALGEBRAIC[90] =  CONSTANTS[31]*STATES[8]*ALGEBRAIC[88];
ALGEBRAIC[92] =  CONSTANTS[31]*CONSTANTS[12]*ALGEBRAIC[88];
ALGEBRAIC[108] = (fmax( 0.200000*ALGEBRAIC[105], ALGEBRAIC[105])+ (ALGEBRAIC[90]+ALGEBRAIC[92])*ALGEBRAIC[107]) - ALGEBRAIC[92];
ALGEBRAIC[109] =  (( ALGEBRAIC[108]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[99], 2.00000)))/ALGEBRAIC[98])*CONSTANTS[29];
ALGEBRAIC[110] =  2.00000*ALGEBRAIC[109]*ALGEBRAIC[96];
ALGEBRAIC[113] = ALGEBRAIC[110];
RATES[31] = ((STATES[30] - ALGEBRAIC[113]) -  CONSTANTS[80]*STATES[31])/CONSTANTS[82];
ALGEBRAIC[111] =  CONSTANTS[41]*STATES[10]+0.000100000;
ALGEBRAIC[114] = CONSTANTS[22]/ALGEBRAIC[111]+CONSTANTS[40];
ALGEBRAIC[116] = CONSTANTS[24]/pow(ALGEBRAIC[111], 2.00000);
RATES[4] = ((ALGEBRAIC[110] - ALGEBRAIC[81]) -  ALGEBRAIC[116]*STATES[4]*fabs(STATES[4]))/ALGEBRAIC[114];
ALGEBRAIC[117] = fmax((STATES[11] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[112] = ((VOI - CONSTANTS[44]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[44])/CONSTANTS[17]))/CONSTANTS[159];
ALGEBRAIC[115] = fmin(8.00000, fmax(ALGEBRAIC[112], 0.00000));
ALGEBRAIC[120] = (  tanh( 4.00000*pow(ALGEBRAIC[117], 2.00000))*pow(ALGEBRAIC[115], 3.00000)*exp(- ALGEBRAIC[115])*pow(8.00000 - ALGEBRAIC[115], 2.00000)*0.0200000)/CONSTANTS[159];
ALGEBRAIC[118] =  CONSTANTS[157]*(0.650000+ 0.700000*ALGEBRAIC[117]);
ALGEBRAIC[122] = (((VOI - CONSTANTS[44]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[44])/CONSTANTS[17])) - ALGEBRAIC[118])/CONSTANTS[160];
ALGEBRAIC[124] = (0.500000+ 0.500000* sin( (ALGEBRAIC[122]/fabs(ALGEBRAIC[122]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[122]))))/CONSTANTS[160];
RATES[12] = ALGEBRAIC[120] -  STATES[12]*ALGEBRAIC[124];
ALGEBRAIC[123] = STATES[13]+ 0.500000*CONSTANTS[43];
ALGEBRAIC[125] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[123]), 1.00000/3.00000);
ALGEBRAIC[126] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[125], 2.00000);
ALGEBRAIC[127] = ALGEBRAIC[126] - CONSTANTS[45];
ALGEBRAIC[128] = ( 1.50000*CONSTANTS[43]*ALGEBRAIC[125])/ALGEBRAIC[127];
ALGEBRAIC[129] = ( 0.500000*log(ALGEBRAIC[127]/CONSTANTS[46]) - pow(ALGEBRAIC[128], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[128], 4.00000);
ALGEBRAIC[130] =  exp(ALGEBRAIC[129])*CONSTANTS[0];
ALGEBRAIC[136] = fmax((ALGEBRAIC[130] - STATES[11])/0.0400000, - 0.0200000);
ALGEBRAIC[131] = fmax( CONSTANTS[15]*log(ALGEBRAIC[130]/1.80000), 0.00000);
ALGEBRAIC[132] = log(ALGEBRAIC[130]/CONSTANTS[0])+0.100000;
ALGEBRAIC[133] =  0.120000*(cosh( 5.00000*ALGEBRAIC[131]) - 1.00000)+ALGEBRAIC[132];
ALGEBRAIC[134] =  CONSTANTS[8]*ALGEBRAIC[133];
ALGEBRAIC[135] =  tanh( 10.0000*STATES[12]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[134], 2.00000)));
RATES[11] = ( fmax(ALGEBRAIC[136] - 1.00000,  ALGEBRAIC[135]*(ALGEBRAIC[136] - 1.00000))*CONSTANTS[10]*0.850000)/CONSTANTS[17];
ALGEBRAIC[119] =  CONSTANTS[9]*STATES[12]*ALGEBRAIC[117];
ALGEBRAIC[121] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[117];
ALGEBRAIC[137] = (fmax( 0.200000*ALGEBRAIC[134], ALGEBRAIC[134])+ (ALGEBRAIC[119]+ALGEBRAIC[121])*ALGEBRAIC[136]) - ALGEBRAIC[121];
ALGEBRAIC[138] =  (( ALGEBRAIC[137]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[128], 2.00000)))/ALGEBRAIC[127])*CONSTANTS[43];
ALGEBRAIC[139] =  2.00000*ALGEBRAIC[138]*ALGEBRAIC[125];
ALGEBRAIC[141] = (STATES[15]>=STATES[16] ?  STATES[17]*CONSTANTS[48]*(ALGEBRAIC[139] - STATES[14]) :  STATES[17]*CONSTANTS[49]*(ALGEBRAIC[139] - STATES[14]));
RATES[17] = (ALGEBRAIC[139]>=STATES[14] ?  (1.00000 - STATES[17])*CONSTANTS[47]*(ALGEBRAIC[139] - STATES[14]) : ALGEBRAIC[141]);
ALGEBRAIC[140] =  CONSTANTS[51]*STATES[17]+0.000100000;
ALGEBRAIC[143] = CONSTANTS[22]/ALGEBRAIC[140]+CONSTANTS[50];
ALGEBRAIC[145] = CONSTANTS[24]/pow(ALGEBRAIC[140], 2.00000);
RATES[16] = ((ALGEBRAIC[139] - STATES[14]) -  ALGEBRAIC[145]*STATES[16]*fabs(STATES[16]))/ALGEBRAIC[143];
ALGEBRAIC[146] = fmax((STATES[18] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[142] = ((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17]))/CONSTANTS[161];
ALGEBRAIC[144] = fmin(8.00000, fmax(ALGEBRAIC[142], 0.00000));
ALGEBRAIC[149] = (  tanh( 4.00000*pow(ALGEBRAIC[146], 2.00000))*pow(ALGEBRAIC[144], 3.00000)*exp(- ALGEBRAIC[144])*pow(8.00000 - ALGEBRAIC[144], 2.00000)*0.0200000)/CONSTANTS[161];
ALGEBRAIC[147] =  CONSTANTS[158]*(0.650000+ 0.700000*ALGEBRAIC[146]);
ALGEBRAIC[151] = (((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17])) - ALGEBRAIC[147])/CONSTANTS[162];
ALGEBRAIC[153] = (0.500000+ 0.500000* sin( (ALGEBRAIC[151]/fabs(ALGEBRAIC[151]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[151]))))/CONSTANTS[162];
RATES[19] = ALGEBRAIC[149] -  STATES[19]*ALGEBRAIC[153];
ALGEBRAIC[152] = STATES[20]+ 0.500000*CONSTANTS[53];
ALGEBRAIC[154] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[152]), 1.00000/3.00000);
ALGEBRAIC[155] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[154], 2.00000);
ALGEBRAIC[156] = ALGEBRAIC[155] - CONSTANTS[55];
ALGEBRAIC[157] = ( 1.50000*CONSTANTS[53]*ALGEBRAIC[154])/ALGEBRAIC[156];
ALGEBRAIC[158] = ( 0.500000*log(ALGEBRAIC[156]/CONSTANTS[56]) - pow(ALGEBRAIC[157], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[157], 4.00000);
ALGEBRAIC[159] =  exp(ALGEBRAIC[158])*CONSTANTS[0];
ALGEBRAIC[165] = fmax((ALGEBRAIC[159] - STATES[18])/0.0400000, - 0.0200000);
ALGEBRAIC[160] = fmax( CONSTANTS[36]*log(ALGEBRAIC[159]/1.80000), 0.00000);
ALGEBRAIC[161] = log(ALGEBRAIC[159]/CONSTANTS[0])+0.100000;
ALGEBRAIC[162] =  0.120000*(cosh( 5.00000*ALGEBRAIC[160]) - 1.00000)+ALGEBRAIC[161];
ALGEBRAIC[163] =  CONSTANTS[30]*ALGEBRAIC[162];
ALGEBRAIC[164] =  tanh( 10.0000*STATES[19]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[163], 2.00000)));
RATES[18] = ( fmax(ALGEBRAIC[165] - 1.00000,  ALGEBRAIC[164]*(ALGEBRAIC[165] - 1.00000))*CONSTANTS[32]*0.850000)/CONSTANTS[17];
ALGEBRAIC[170] = STATES[34]+STATES[72];
RATES[20] = ALGEBRAIC[170] - STATES[15];
ALGEBRAIC[148] =  CONSTANTS[31]*STATES[19]*ALGEBRAIC[146];
ALGEBRAIC[150] =  CONSTANTS[31]*CONSTANTS[12]*ALGEBRAIC[146];
ALGEBRAIC[166] = (fmax( 0.200000*ALGEBRAIC[163], ALGEBRAIC[163])+ (ALGEBRAIC[148]+ALGEBRAIC[150])*ALGEBRAIC[165]) - ALGEBRAIC[150];
ALGEBRAIC[167] =  (( ALGEBRAIC[166]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[157], 2.00000)))/ALGEBRAIC[156])*CONSTANTS[53];
ALGEBRAIC[168] =  2.00000*ALGEBRAIC[167]*ALGEBRAIC[154];
ALGEBRAIC[172] = ALGEBRAIC[168];
RATES[34] = ((STATES[33] - ALGEBRAIC[172]) -  CONSTANTS[85]*STATES[34])/CONSTANTS[82];
ALGEBRAIC[169] = STATES[48] - STATES[72];
ALGEBRAIC[173] = STATES[31]+ALGEBRAIC[169];
RATES[9] = ALGEBRAIC[173] - STATES[4];
ALGEBRAIC[175] = (ALGEBRAIC[170]>=STATES[15] ?  STATES[21]*CONSTANTS[58]*(ALGEBRAIC[168] - ALGEBRAIC[139]) :  STATES[21]*CONSTANTS[59]*(ALGEBRAIC[168] - ALGEBRAIC[139]));
RATES[21] = (ALGEBRAIC[168]>=ALGEBRAIC[139] ?  (1.00000 - STATES[21])*CONSTANTS[57]*(ALGEBRAIC[168] - ALGEBRAIC[139]) : ALGEBRAIC[175]);
ALGEBRAIC[177] = (ALGEBRAIC[173]>=STATES[4] ?  STATES[10]*CONSTANTS[38]*(ALGEBRAIC[110] - ALGEBRAIC[81]) :  STATES[10]*CONSTANTS[39]*(ALGEBRAIC[110] - ALGEBRAIC[81]));
RATES[10] = (ALGEBRAIC[110]>=ALGEBRAIC[81] ?  (1.00000 - STATES[10])*CONSTANTS[37]*(ALGEBRAIC[110] - ALGEBRAIC[81]) : ALGEBRAIC[177]);
ALGEBRAIC[171] =  CONSTANTS[61]*STATES[21]+0.000100000;
ALGEBRAIC[174] = CONSTANTS[22]/ALGEBRAIC[171]+CONSTANTS[60];
ALGEBRAIC[178] = CONSTANTS[24]/pow(ALGEBRAIC[171], 2.00000);
RATES[15] = ((ALGEBRAIC[168] - ALGEBRAIC[139]) -  ALGEBRAIC[178]*STATES[15]*fabs(STATES[15]))/ALGEBRAIC[174];
ALGEBRAIC[176] = ALGEBRAIC[110];
ALGEBRAIC[179] = (ALGEBRAIC[169]>=0.00000 ? ALGEBRAIC[176]+ CONSTANTS[149]*pow(fabs(ALGEBRAIC[169]), 0.625000) : ALGEBRAIC[176] -  CONSTANTS[149]*pow(fabs(ALGEBRAIC[169]), 0.625000));
RATES[48] = ((STATES[47] - ALGEBRAIC[179]) -  CONSTANTS[97]*STATES[48])/CONSTANTS[82];
ALGEBRAIC[180] = ALGEBRAIC[168];
RATES[72] = ((ALGEBRAIC[179] - ALGEBRAIC[180]) -  CONSTANTS[148]*STATES[72])/CONSTANTS[82];
}
void
computeVariables(double VOI, double* CONSTANTS, double* RATES, double* STATES, double* ALGEBRAIC)
{
ALGEBRAIC[1] = STATES[22] - STATES[51];
ALGEBRAIC[2] = STATES[24] - STATES[62];
ALGEBRAIC[4] = STATES[26] - STATES[67];
ALGEBRAIC[3] = STATES[32];
ALGEBRAIC[5] = STATES[29] - STATES[69];
ALGEBRAIC[8] = (STATES[42] - STATES[43])/CONSTANTS[95];
ALGEBRAIC[10] = STATES[50] - STATES[57];
ALGEBRAIC[9] = STATES[54]+ CONSTANTS[108]*STATES[53];
ALGEBRAIC[12] = (STATES[55] - STATES[56])/CONSTANTS[111];
ALGEBRAIC[13] = STATES[59]+ CONSTANTS[118]*STATES[58];
ALGEBRAIC[14] = (STATES[60] - STATES[61])/CONSTANTS[119];
ALGEBRAIC[15] = STATES[64]+ CONSTANTS[124]*STATES[63];
ALGEBRAIC[16] = STATES[68]+ CONSTANTS[130]*STATES[66];
ALGEBRAIC[18] = STATES[23]+ CONSTANTS[97]*ALGEBRAIC[1];
ALGEBRAIC[19] = STATES[25]+ CONSTANTS[97]*ALGEBRAIC[2];
ALGEBRAIC[20] = STATES[27]+ CONSTANTS[97]*ALGEBRAIC[4];
ALGEBRAIC[21] = STATES[30]+ CONSTANTS[138]*ALGEBRAIC[5];
ALGEBRAIC[7] = STATES[36] - STATES[44];
ALGEBRAIC[23] = STATES[41]+ CONSTANTS[143]*ALGEBRAIC[7];
ALGEBRAIC[25] = STATES[52]+ CONSTANTS[97]*ALGEBRAIC[10];
ALGEBRAIC[22] = STATES[35];
ALGEBRAIC[6] = STATES[69]+STATES[28];
ALGEBRAIC[28] = (STATES[32] - ALGEBRAIC[22])/CONSTANTS[83];
ALGEBRAIC[32] = STATES[32];
ALGEBRAIC[33] = STATES[46];
ALGEBRAIC[36] = ((ALGEBRAIC[28] - STATES[40]) - STATES[70]) - STATES[38];
ALGEBRAIC[29] = STATES[46];
ALGEBRAIC[37] = (STATES[39] - ALGEBRAIC[29])/CONSTANTS[91];
ALGEBRAIC[38] = STATES[47];
ALGEBRAIC[24] = STATES[45] - STATES[71];
ALGEBRAIC[43] = ALGEBRAIC[38]+ CONSTANTS[146]*ALGEBRAIC[24]+ CONSTANTS[147]*ALGEBRAIC[24]*fabs(ALGEBRAIC[24]);
ALGEBRAIC[30] = STATES[46];
ALGEBRAIC[27] = fmax((STATES[0] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[0] = ((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17]))/CONSTANTS[152];
ALGEBRAIC[17] = fmin(8.00000, fmax(ALGEBRAIC[0], 0.00000));
ALGEBRAIC[40] = (  tanh( 4.00000*pow(ALGEBRAIC[27], 2.00000))*pow(ALGEBRAIC[17], 3.00000)*exp(- ALGEBRAIC[17])*pow(8.00000 - ALGEBRAIC[17], 2.00000)*0.0200000)/CONSTANTS[152];
ALGEBRAIC[34] =  CONSTANTS[2]*(0.650000+ 0.700000*ALGEBRAIC[27]);
ALGEBRAIC[45] = (((VOI - CONSTANTS[11]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[11])/CONSTANTS[17])) - ALGEBRAIC[34])/CONSTANTS[153];
ALGEBRAIC[49] = (0.500000+ 0.500000* sin( (ALGEBRAIC[45]/fabs(ALGEBRAIC[45]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[45]))))/CONSTANTS[153];
ALGEBRAIC[47] = STATES[47];
ALGEBRAIC[51] = (STATES[37] - ALGEBRAIC[47])/CONSTANTS[89];
ALGEBRAIC[26] = STATES[58];
ALGEBRAIC[44] = STATES[33];
ALGEBRAIC[48] = ALGEBRAIC[44];
ALGEBRAIC[52] = (STATES[59] - ALGEBRAIC[48])/CONSTANTS[116];
ALGEBRAIC[42] = STATES[71]+ALGEBRAIC[37]+STATES[70];
ALGEBRAIC[54] = STATES[47];
ALGEBRAIC[57] = (STATES[46] - ALGEBRAIC[54])/CONSTANTS[99];
ALGEBRAIC[31] = STATES[63];
ALGEBRAIC[55] = ALGEBRAIC[44];
ALGEBRAIC[58] = (STATES[64] - ALGEBRAIC[55])/CONSTANTS[125];
ALGEBRAIC[60] = STATES[47];
ALGEBRAIC[63] = (STATES[41] - ALGEBRAIC[60])/CONSTANTS[93];
ALGEBRAIC[66] = ALGEBRAIC[51]+ALGEBRAIC[24]+ALGEBRAIC[57]+ALGEBRAIC[63];
ALGEBRAIC[11] = STATES[53];
ALGEBRAIC[64] = STATES[33];
ALGEBRAIC[67] = ALGEBRAIC[64];
ALGEBRAIC[69] = (STATES[54] - ALGEBRAIC[67])/CONSTANTS[109];
ALGEBRAIC[39] = STATES[66];
ALGEBRAIC[71] = ALGEBRAIC[64];
ALGEBRAIC[73] = (STATES[68] - ALGEBRAIC[71])/CONSTANTS[131];
ALGEBRAIC[61] = ALGEBRAIC[52]+ALGEBRAIC[58];
ALGEBRAIC[75] = ALGEBRAIC[69]+ALGEBRAIC[73];
ALGEBRAIC[77] = ALGEBRAIC[61]+ALGEBRAIC[75];
ALGEBRAIC[46] = STATES[2]+ 0.500000*CONSTANTS[7];
ALGEBRAIC[50] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[46]), 1.00000/3.00000);
ALGEBRAIC[53] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[50], 2.00000);
ALGEBRAIC[56] = ALGEBRAIC[53] - CONSTANTS[13];
ALGEBRAIC[59] = ( 1.50000*CONSTANTS[7]*ALGEBRAIC[50])/ALGEBRAIC[56];
ALGEBRAIC[62] = ( 0.500000*log(ALGEBRAIC[56]/CONSTANTS[14]) - pow(ALGEBRAIC[59], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[59], 4.00000);
ALGEBRAIC[65] =  exp(ALGEBRAIC[62])*CONSTANTS[0];
ALGEBRAIC[78] = fmax((ALGEBRAIC[65] - STATES[0])/0.0400000, - 0.0200000);
ALGEBRAIC[68] = fmax( CONSTANTS[15]*log(ALGEBRAIC[65]/1.80000), 0.00000);
ALGEBRAIC[70] = log(ALGEBRAIC[65]/CONSTANTS[0])+0.100000;
ALGEBRAIC[72] =  0.120000*(cosh( 5.00000*ALGEBRAIC[68]) - 1.00000)+ALGEBRAIC[70];
ALGEBRAIC[74] =  CONSTANTS[8]*ALGEBRAIC[72];
ALGEBRAIC[76] =  tanh( 10.0000*STATES[1]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[74], 2.00000)));
ALGEBRAIC[35] =  CONSTANTS[9]*STATES[1]*ALGEBRAIC[27];
ALGEBRAIC[41] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[27];
ALGEBRAIC[79] = (fmax( 0.200000*ALGEBRAIC[74], ALGEBRAIC[74])+ (ALGEBRAIC[35]+ALGEBRAIC[41])*ALGEBRAIC[78]) - ALGEBRAIC[41];
ALGEBRAIC[80] =  (( ALGEBRAIC[79]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[59], 2.00000)))/ALGEBRAIC[56])*CONSTANTS[7];
ALGEBRAIC[81] =  2.00000*ALGEBRAIC[80]*ALGEBRAIC[50];
ALGEBRAIC[83] = (STATES[4]>=STATES[5] ?  STATES[6]*CONSTANTS[19]*(ALGEBRAIC[81] - STATES[3]) :  STATES[6]*CONSTANTS[20]*(ALGEBRAIC[81] - STATES[3]));
ALGEBRAIC[82] =  CONSTANTS[23]*STATES[6]+0.000100000;
ALGEBRAIC[85] = CONSTANTS[22]/ALGEBRAIC[82]+CONSTANTS[21];
ALGEBRAIC[87] = CONSTANTS[24]/pow(ALGEBRAIC[82], 2.00000);
ALGEBRAIC[88] = fmax((STATES[7] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[84] = ((VOI - CONSTANTS[33]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[33])/CONSTANTS[17]))/CONSTANTS[155];
ALGEBRAIC[86] = fmin(8.00000, fmax(ALGEBRAIC[84], 0.00000));
ALGEBRAIC[91] = (  tanh( 4.00000*pow(ALGEBRAIC[88], 2.00000))*pow(ALGEBRAIC[86], 3.00000)*exp(- ALGEBRAIC[86])*pow(8.00000 - ALGEBRAIC[86], 2.00000)*0.0200000)/CONSTANTS[155];
ALGEBRAIC[89] =  CONSTANTS[25]*(0.650000+ 0.700000*ALGEBRAIC[88]);
ALGEBRAIC[93] = (((VOI - CONSTANTS[33]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[33])/CONSTANTS[17])) - ALGEBRAIC[89])/CONSTANTS[156];
ALGEBRAIC[95] = (0.500000+ 0.500000* sin( (ALGEBRAIC[93]/fabs(ALGEBRAIC[93]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[93]))))/CONSTANTS[156];
ALGEBRAIC[94] = STATES[9]+ 0.500000*CONSTANTS[29];
ALGEBRAIC[96] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[94]), 1.00000/3.00000);
ALGEBRAIC[97] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[96], 2.00000);
ALGEBRAIC[98] = ALGEBRAIC[97] - CONSTANTS[34];
ALGEBRAIC[99] = ( 1.50000*CONSTANTS[29]*ALGEBRAIC[96])/ALGEBRAIC[98];
ALGEBRAIC[100] = ( 0.500000*log(ALGEBRAIC[98]/CONSTANTS[35]) - pow(ALGEBRAIC[99], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[99], 4.00000);
ALGEBRAIC[101] =  exp(ALGEBRAIC[100])*CONSTANTS[0];
ALGEBRAIC[107] = fmax((ALGEBRAIC[101] - STATES[7])/0.0400000, - 0.0200000);
ALGEBRAIC[102] = fmax( CONSTANTS[36]*log(ALGEBRAIC[101]/1.80000), 0.00000);
ALGEBRAIC[103] = log(ALGEBRAIC[101]/CONSTANTS[0])+0.100000;
ALGEBRAIC[104] =  0.120000*(cosh( 5.00000*ALGEBRAIC[102]) - 1.00000)+ALGEBRAIC[103];
ALGEBRAIC[105] =  CONSTANTS[30]*ALGEBRAIC[104];
ALGEBRAIC[106] =  tanh( 10.0000*STATES[8]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[105], 2.00000)));
ALGEBRAIC[90] =  CONSTANTS[31]*STATES[8]*ALGEBRAIC[88];
ALGEBRAIC[92] =  CONSTANTS[31]*CONSTANTS[12]*ALGEBRAIC[88];
ALGEBRAIC[108] = (fmax( 0.200000*ALGEBRAIC[105], ALGEBRAIC[105])+ (ALGEBRAIC[90]+ALGEBRAIC[92])*ALGEBRAIC[107]) - ALGEBRAIC[92];
ALGEBRAIC[109] =  (( ALGEBRAIC[108]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[99], 2.00000)))/ALGEBRAIC[98])*CONSTANTS[29];
ALGEBRAIC[110] =  2.00000*ALGEBRAIC[109]*ALGEBRAIC[96];
ALGEBRAIC[113] = ALGEBRAIC[110];
ALGEBRAIC[111] =  CONSTANTS[41]*STATES[10]+0.000100000;
ALGEBRAIC[114] = CONSTANTS[22]/ALGEBRAIC[111]+CONSTANTS[40];
ALGEBRAIC[116] = CONSTANTS[24]/pow(ALGEBRAIC[111], 2.00000);
ALGEBRAIC[117] = fmax((STATES[11] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[112] = ((VOI - CONSTANTS[44]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[44])/CONSTANTS[17]))/CONSTANTS[159];
ALGEBRAIC[115] = fmin(8.00000, fmax(ALGEBRAIC[112], 0.00000));
ALGEBRAIC[120] = (  tanh( 4.00000*pow(ALGEBRAIC[117], 2.00000))*pow(ALGEBRAIC[115], 3.00000)*exp(- ALGEBRAIC[115])*pow(8.00000 - ALGEBRAIC[115], 2.00000)*0.0200000)/CONSTANTS[159];
ALGEBRAIC[118] =  CONSTANTS[157]*(0.650000+ 0.700000*ALGEBRAIC[117]);
ALGEBRAIC[122] = (((VOI - CONSTANTS[44]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[44])/CONSTANTS[17])) - ALGEBRAIC[118])/CONSTANTS[160];
ALGEBRAIC[124] = (0.500000+ 0.500000* sin( (ALGEBRAIC[122]/fabs(ALGEBRAIC[122]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[122]))))/CONSTANTS[160];
ALGEBRAIC[123] = STATES[13]+ 0.500000*CONSTANTS[43];
ALGEBRAIC[125] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[123]), 1.00000/3.00000);
ALGEBRAIC[126] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[125], 2.00000);
ALGEBRAIC[127] = ALGEBRAIC[126] - CONSTANTS[45];
ALGEBRAIC[128] = ( 1.50000*CONSTANTS[43]*ALGEBRAIC[125])/ALGEBRAIC[127];
ALGEBRAIC[129] = ( 0.500000*log(ALGEBRAIC[127]/CONSTANTS[46]) - pow(ALGEBRAIC[128], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[128], 4.00000);
ALGEBRAIC[130] =  exp(ALGEBRAIC[129])*CONSTANTS[0];
ALGEBRAIC[136] = fmax((ALGEBRAIC[130] - STATES[11])/0.0400000, - 0.0200000);
ALGEBRAIC[131] = fmax( CONSTANTS[15]*log(ALGEBRAIC[130]/1.80000), 0.00000);
ALGEBRAIC[132] = log(ALGEBRAIC[130]/CONSTANTS[0])+0.100000;
ALGEBRAIC[133] =  0.120000*(cosh( 5.00000*ALGEBRAIC[131]) - 1.00000)+ALGEBRAIC[132];
ALGEBRAIC[134] =  CONSTANTS[8]*ALGEBRAIC[133];
ALGEBRAIC[135] =  tanh( 10.0000*STATES[12]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[134], 2.00000)));
ALGEBRAIC[119] =  CONSTANTS[9]*STATES[12]*ALGEBRAIC[117];
ALGEBRAIC[121] =  CONSTANTS[9]*CONSTANTS[12]*ALGEBRAIC[117];
ALGEBRAIC[137] = (fmax( 0.200000*ALGEBRAIC[134], ALGEBRAIC[134])+ (ALGEBRAIC[119]+ALGEBRAIC[121])*ALGEBRAIC[136]) - ALGEBRAIC[121];
ALGEBRAIC[138] =  (( ALGEBRAIC[137]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[128], 2.00000)))/ALGEBRAIC[127])*CONSTANTS[43];
ALGEBRAIC[139] =  2.00000*ALGEBRAIC[138]*ALGEBRAIC[125];
ALGEBRAIC[141] = (STATES[15]>=STATES[16] ?  STATES[17]*CONSTANTS[48]*(ALGEBRAIC[139] - STATES[14]) :  STATES[17]*CONSTANTS[49]*(ALGEBRAIC[139] - STATES[14]));
ALGEBRAIC[140] =  CONSTANTS[51]*STATES[17]+0.000100000;
ALGEBRAIC[143] = CONSTANTS[22]/ALGEBRAIC[140]+CONSTANTS[50];
ALGEBRAIC[145] = CONSTANTS[24]/pow(ALGEBRAIC[140], 2.00000);
ALGEBRAIC[146] = fmax((STATES[18] - 1.51000)/1.00000, 0.000100000);
ALGEBRAIC[142] = ((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17]))/CONSTANTS[161];
ALGEBRAIC[144] = fmin(8.00000, fmax(ALGEBRAIC[142], 0.00000));
ALGEBRAIC[149] = (  tanh( 4.00000*pow(ALGEBRAIC[146], 2.00000))*pow(ALGEBRAIC[144], 3.00000)*exp(- ALGEBRAIC[144])*pow(8.00000 - ALGEBRAIC[144], 2.00000)*0.0200000)/CONSTANTS[161];
ALGEBRAIC[147] =  CONSTANTS[158]*(0.650000+ 0.700000*ALGEBRAIC[146]);
ALGEBRAIC[151] = (((VOI - CONSTANTS[54]) -  CONSTANTS[17]*floor((VOI - CONSTANTS[54])/CONSTANTS[17])) - ALGEBRAIC[147])/CONSTANTS[162];
ALGEBRAIC[153] = (0.500000+ 0.500000* sin( (ALGEBRAIC[151]/fabs(ALGEBRAIC[151]))*fmin( 3.14159265358979/2.00000, fabs(ALGEBRAIC[151]))))/CONSTANTS[162];
ALGEBRAIC[152] = STATES[20]+ 0.500000*CONSTANTS[53];
ALGEBRAIC[154] = pow(( 4.00000* 3.14159265358979)/( 3.00000*ALGEBRAIC[152]), 1.00000/3.00000);
ALGEBRAIC[155] = ( 4.00000* 3.14159265358979)/pow(ALGEBRAIC[154], 2.00000);
ALGEBRAIC[156] = ALGEBRAIC[155] - CONSTANTS[55];
ALGEBRAIC[157] = ( 1.50000*CONSTANTS[53]*ALGEBRAIC[154])/ALGEBRAIC[156];
ALGEBRAIC[158] = ( 0.500000*log(ALGEBRAIC[156]/CONSTANTS[56]) - pow(ALGEBRAIC[157], 2.00000)/12.0000) -  0.0190000*pow(ALGEBRAIC[157], 4.00000);
ALGEBRAIC[159] =  exp(ALGEBRAIC[158])*CONSTANTS[0];
ALGEBRAIC[165] = fmax((ALGEBRAIC[159] - STATES[18])/0.0400000, - 0.0200000);
ALGEBRAIC[160] = fmax( CONSTANTS[36]*log(ALGEBRAIC[159]/1.80000), 0.00000);
ALGEBRAIC[161] = log(ALGEBRAIC[159]/CONSTANTS[0])+0.100000;
ALGEBRAIC[162] =  0.120000*(cosh( 5.00000*ALGEBRAIC[160]) - 1.00000)+ALGEBRAIC[161];
ALGEBRAIC[163] =  CONSTANTS[30]*ALGEBRAIC[162];
ALGEBRAIC[164] =  tanh( 10.0000*STATES[19]+fmax(0.00000,  0.000100000*pow(ALGEBRAIC[163], 2.00000)));
ALGEBRAIC[170] = STATES[34]+STATES[72];
ALGEBRAIC[148] =  CONSTANTS[31]*STATES[19]*ALGEBRAIC[146];
ALGEBRAIC[150] =  CONSTANTS[31]*CONSTANTS[12]*ALGEBRAIC[146];
ALGEBRAIC[166] = (fmax( 0.200000*ALGEBRAIC[163], ALGEBRAIC[163])+ (ALGEBRAIC[148]+ALGEBRAIC[150])*ALGEBRAIC[165]) - ALGEBRAIC[150];
ALGEBRAIC[167] =  (( ALGEBRAIC[166]*0.500000*(1.00000+ 0.270000*pow(ALGEBRAIC[157], 2.00000)))/ALGEBRAIC[156])*CONSTANTS[53];
ALGEBRAIC[168] =  2.00000*ALGEBRAIC[167]*ALGEBRAIC[154];
ALGEBRAIC[172] = ALGEBRAIC[168];
ALGEBRAIC[169] = STATES[48] - STATES[72];
ALGEBRAIC[173] = STATES[31]+ALGEBRAIC[169];
ALGEBRAIC[175] = (ALGEBRAIC[170]>=STATES[15] ?  STATES[21]*CONSTANTS[58]*(ALGEBRAIC[168] - ALGEBRAIC[139]) :  STATES[21]*CONSTANTS[59]*(ALGEBRAIC[168] - ALGEBRAIC[139]));
ALGEBRAIC[177] = (ALGEBRAIC[173]>=STATES[4] ?  STATES[10]*CONSTANTS[38]*(ALGEBRAIC[110] - ALGEBRAIC[81]) :  STATES[10]*CONSTANTS[39]*(ALGEBRAIC[110] - ALGEBRAIC[81]));
ALGEBRAIC[171] =  CONSTANTS[61]*STATES[21]+0.000100000;
ALGEBRAIC[174] = CONSTANTS[22]/ALGEBRAIC[171]+CONSTANTS[60];
ALGEBRAIC[178] = CONSTANTS[24]/pow(ALGEBRAIC[171], 2.00000);
ALGEBRAIC[176] = ALGEBRAIC[110];
ALGEBRAIC[179] = (ALGEBRAIC[169]>=0.00000 ? ALGEBRAIC[176]+ CONSTANTS[149]*pow(fabs(ALGEBRAIC[169]), 0.625000) : ALGEBRAIC[176] -  CONSTANTS[149]*pow(fabs(ALGEBRAIC[169]), 0.625000));
ALGEBRAIC[180] = ALGEBRAIC[168];
}
