/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Copy_of_Manuever_1.h
 *
 * Code generated for Simulink model 'Copy_of_Manuever_1'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 27 13:24:30 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_of_Manuever_1_h_
#define RTW_HEADER_Copy_of_Manuever_1_h_
#ifndef Copy_of_Manuever_1_COMMON_INCLUDES_
#define Copy_of_Manuever_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* Copy_of_Manuever_1_COMMON_INCLUDES_ */

#include "Copy_of_Manuever_1_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T motor;                        /* '<Root>/Chart' */
  real_T motor1;                       /* '<Root>/Chart' */
  ChartModeType ChartMode;             /* '<Root>/Chart' */
} B_Copy_of_Manuever_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T turn_count;                   /* '<Root>/Chart' */
  int32_T clockTickCounter;            /* '<S3>/Pulse Generator' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint32_T previousTicks;              /* '<Root>/Chart' */
} DW_Copy_of_Manuever_1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[5];        /* '<Root>/Chart' */
} PrevZCX_Copy_of_Manuever_1_T;

/* Parameters (default storage) */
struct P_Copy_of_Manuever_1_T_ {
  real_T DistanceinMeter_Value;        /* Expression: 100
                                        * Referenced by: '<Root>/Distance in Meter'
                                        */
  real_T SpeedinMeterSec_Value;        /* Expression: 90
                                        * Referenced by: '<Root>/Speed in Meter//Sec'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S3>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_Manuever_1_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Copy_of_Manuever_1_T Copy_of_Manuever_1_P;

/* Block signals (default storage) */
extern B_Copy_of_Manuever_1_T Copy_of_Manuever_1_B;

/* Block states (default storage) */
extern DW_Copy_of_Manuever_1_T Copy_of_Manuever_1_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Copy_of_Manuever_1_T Copy_of_Manuever_1_PrevZCX;

/* Model entry point functions */
extern void Copy_of_Manuever_1_initialize(void);
extern void Copy_of_Manuever_1_step(void);
extern void Copy_of_Manuever_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_Manuever_1_T *const Copy_of_Manuever_1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Copy_of_Manuever_1'
 * '<S1>'   : 'Copy_of_Manuever_1/Chart'
 * '<S2>'   : 'Copy_of_Manuever_1/Distance Needed to Travel in Straight Line'
 * '<S3>'   : 'Copy_of_Manuever_1/inputs'
 * '<S4>'   : 'Copy_of_Manuever_1/outputs'
 * '<S5>'   : 'Copy_of_Manuever_1/Distance Needed to Travel in Straight Line/Distance Needed to Travel in Straight Line'
 * '<S6>'   : 'Copy_of_Manuever_1/outputs/Motor'
 * '<S7>'   : 'Copy_of_Manuever_1/outputs/Motor1'
 */
#endif                                 /* RTW_HEADER_Copy_of_Manuever_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
