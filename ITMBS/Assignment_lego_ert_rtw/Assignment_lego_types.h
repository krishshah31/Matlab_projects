/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Assignment_lego_types.h
 *
 * Code generated for Simulink model 'Assignment_lego'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 20 15:06:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment_lego_types_h_
#define RTW_HEADER_Assignment_lego_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_ChartModeType_
#define DEFINED_TYPEDEF_FOR_ChartModeType_

typedef enum {
  ChartModeType_None = 0,              /* Default value */
  ChartModeType_Off,
  ChartModeType_mid_state,
  ChartModeType_On1,
  ChartModeType_Confirmation1,
  ChartModeType_Confirmation
} ChartModeType;

#endif

/* Parameters (default storage) */
typedef struct P_Assignment_lego_T_ P_Assignment_lego_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Assignment_lego_T RT_MODEL_Assignment_lego_T;

#endif                                 /* RTW_HEADER_Assignment_lego_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
