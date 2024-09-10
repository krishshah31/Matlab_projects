/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Copy_of_Assignment_lego.h
 *
 * Code generated for Simulink model 'Copy_of_Assignment_lego'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 20 14:15:33 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Copy_of_Assignment_lego_h_
#define RTW_HEADER_Copy_of_Assignment_lego_h_
#ifndef Copy_of_Assignment_lego_COMMON_INCLUDES_
#define Copy_of_Assignment_lego_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                            /* Copy_of_Assignment_lego_COMMON_INCLUDES_ */

#include "Copy_of_Assignment_lego_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T motor;                        /* '<Root>/Chart' */
  ChartModeType ChartMode;             /* '<Root>/Chart' */
  uint8_T TmpRTBAtDataTypeConversionOutpo;/* '<S2>/Data Type Conversion' */
} B_Copy_of_Assignment_lego_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<S2>/Pulse Generator' */
  uint32_T previousTicks;              /* '<Root>/Chart' */
  uint8_T TmpRTBAtDataTypeConversionOutpo;/* synthesized block */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Copy_of_Assignment_lego_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[5];        /* '<Root>/Chart' */
} PrevZCX_Copy_of_Assignment_le_T;

/* Parameters (default storage) */
struct P_Copy_of_Assignment_lego_T_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 2
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  uint8_T TmpRTBAtDataTypeConversionOutpo;
                          /* Computed Parameter: TmpRTBAtDataTypeConversionOutpo
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_Assignment_le_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Copy_of_Assignment_lego_T Copy_of_Assignment_lego_P;

/* Block signals (default storage) */
extern B_Copy_of_Assignment_lego_T Copy_of_Assignment_lego_B;

/* Block states (default storage) */
extern DW_Copy_of_Assignment_lego_T Copy_of_Assignment_lego_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Copy_of_Assignment_le_T Copy_of_Assignment_lego_PrevZCX;

/* External function called from main */
extern void Copy_of_Assignment_lego_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Copy_of_Assignment_lego_initialize(void);
extern void Copy_of_Assignment_lego_step0(void);
extern void Copy_of_Assignment_lego_step1(void);
extern void Copy_of_Assignment_lego_step(int_T tid);
extern void Copy_of_Assignment_lego_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_Assignment_l_T *const Copy_of_Assignment_lego_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Copy_of_Assignment_lego'
 * '<S1>'   : 'Copy_of_Assignment_lego/Chart'
 * '<S2>'   : 'Copy_of_Assignment_lego/inputs'
 * '<S3>'   : 'Copy_of_Assignment_lego/outputs'
 * '<S4>'   : 'Copy_of_Assignment_lego/outputs/Motor'
 */
#endif                               /* RTW_HEADER_Copy_of_Assignment_lego_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
