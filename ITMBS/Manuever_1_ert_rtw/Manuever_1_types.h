/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Manuever_1_types.h
 *
 * Code generated for Simulink model 'Manuever_1'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jul  4 12:32:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Manuever_1_types_h_
#define RTW_HEADER_Manuever_1_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_ChartModeType_
#define DEFINED_TYPEDEF_FOR_ChartModeType_

typedef enum {
  ChartModeType_None = 0,              /* Default value */
  ChartModeType_Off,
  ChartModeType_TurnOnConfirm,
  ChartModeType_On1,
  ChartModeType_EmergencySTOP,
  ChartModeType_mid_state,
  ChartModeType_TurnOffConfirm
} ChartModeType;

#endif

/* Parameters (default storage) */
typedef struct P_Manuever_1_T_ P_Manuever_1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Manuever_1_T RT_MODEL_Manuever_1_T;

#endif                                 /* RTW_HEADER_Manuever_1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
