/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Test_lego_stopbtn.h
 *
 * Code generated for Simulink model 'Test_lego_stopbtn'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jun 12 16:00:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Test_lego_stopbtn_h_
#define RTW_HEADER_Test_lego_stopbtn_h_
#ifndef Test_lego_stopbtn_COMMON_INCLUDES_
#define Test_lego_stopbtn_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* Test_lego_stopbtn_COMMON_INCLUDES_ */

#include "Test_lego_stopbtn_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T idle_state;                   /* '<Root>/Chart' */
  real_T screen;                       /* '<Root>/Chart' */
  real_T running_state;                /* '<Root>/Chart' */
  real_T motor;                        /* '<Root>/Chart' */
  uint8_T TmpRTBAtDataTypeConversionOutpo;/* '<Root>/Data Type Conversion' */
  int8_T inputevents[4];               /* '<Root>/Chart' */
} B_Test_lego_stopbtn_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint32_T is_c3_Test_lego_stopbtn;    /* '<Root>/Chart' */
  int8_T Chart_SubsysRanBC;            /* '<Root>/Chart' */
  uint8_T TmpRTBAtDataTypeConversionOutpo;/* synthesized block */
  uint8_T is_active_c3_Test_lego_stopbtn;/* '<Root>/Chart' */
} DW_Test_lego_stopbtn_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[4];        /* '<Root>/Chart' */
} PrevZCX_Test_lego_stopbtn_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S2>/LCD'
   */
  uint8_T LCD_p1[9];

  /* Expression: lcdStr1
   * Referenced by: '<S3>/LCD'
   */
  uint8_T LCD_p1_o[8];

  /* Expression: lcdStr1
   * Referenced by: '<S4>/LCD'
   */
  uint8_T LCD_p1_l[5];
} ConstP_Test_lego_stopbtn_T;

/* Parameters (default storage) */
struct P_Test_lego_stopbtn_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T TmpRTBAtDataTypeConversionOutpo;
                          /* Computed Parameter: TmpRTBAtDataTypeConversionOutpo
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test_lego_stopbtn_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Test_lego_stopbtn_T Test_lego_stopbtn_P;

/* Block signals (default storage) */
extern B_Test_lego_stopbtn_T Test_lego_stopbtn_B;

/* Block states (default storage) */
extern DW_Test_lego_stopbtn_T Test_lego_stopbtn_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Test_lego_stopbtn_T Test_lego_stopbtn_PrevZCX;

/* Constant parameters (default storage) */
extern const ConstP_Test_lego_stopbtn_T Test_lego_stopbtn_ConstP;

/* External function called from main */
extern void Test_lego_stopbtn_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Test_lego_stopbtn_initialize(void);
extern void Test_lego_stopbtn_step0(void);
extern void Test_lego_stopbtn_step1(void);
extern void Test_lego_stopbtn_step(int_T tid);
extern void Test_lego_stopbtn_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Test_lego_stopbtn_T *const Test_lego_stopbtn_M;
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
 * '<Root>' : 'Test_lego_stopbtn'
 * '<S1>'   : 'Test_lego_stopbtn/Chart'
 * '<S2>'   : 'Test_lego_stopbtn/Display'
 * '<S3>'   : 'Test_lego_stopbtn/Display1'
 * '<S4>'   : 'Test_lego_stopbtn/Display2'
 * '<S5>'   : 'Test_lego_stopbtn/Motor'
 */
#endif                                 /* RTW_HEADER_Test_lego_stopbtn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
