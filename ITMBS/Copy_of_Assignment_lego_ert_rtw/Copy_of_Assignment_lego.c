/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Copy_of_Assignment_lego.c
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

#include "Copy_of_Assignment_lego.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Copy_of_Assignment_lego_types.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Copy_o_event_Center_btn_pressed (1)
#define Copy_of_Assi_event_e_btnPressed (0)
#define Copy_of_Assignmen_event_confirm (2)
#define Copy_of_Assignment__event_clock (4)
#define Copy_of_Assignment_l_event_deny (3)

/* Block signals (default storage) */
B_Copy_of_Assignment_lego_T Copy_of_Assignment_lego_B;

/* Block states (default storage) */
DW_Copy_of_Assignment_lego_T Copy_of_Assignment_lego_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Copy_of_Assignment_le_T Copy_of_Assignment_lego_PrevZCX;

/* Real-time model */
static RT_MODEL_Copy_of_Assignment_l_T Copy_of_Assignment_lego_M_;
RT_MODEL_Copy_of_Assignment_l_T *const Copy_of_Assignment_lego_M =
  &Copy_of_Assignment_lego_M_;

/* Forward declaration for local functions */
static void chartstep_c3_Copy_of_Assignment(const int32_T *sfEvent);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Copy_of_Assignment_lego_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Copy_of_Assignment_lego_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Copy_of_Assignment_lego_M->Timing.RateInteraction.TID0_1 =
    (Copy_of_Assignment_lego_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Copy_of_Assignment_lego_M->Timing.TaskCounters.TID[1])++;
  if ((Copy_of_Assignment_lego_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    Copy_of_Assignment_lego_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void chartstep_c3_Copy_of_Assignment(const int32_T *sfEvent)
{
  switch (Copy_of_Assignment_lego_B.ChartMode) {
   case ChartModeType_Confirmation:
    if (*sfEvent == Copy_of_Assignmen_event_confirm) {
      Copy_of_Assignment_lego_DW.temporalCounter_i1 = 0U;
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_manuver_1;
      Copy_of_Assignment_lego_B.motor = 0.0;
    } else if ((*sfEvent == Copy_of_Assignment_l_event_deny) || (*sfEvent ==
                Copy_of_Assignmen_event_confirm)) {
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Off;
      Copy_of_Assignment_lego_B.motor = 0.0;
    }
    break;

   case ChartModeType_Confirmation1:
    switch (*sfEvent) {
     case Copy_of_Assignment_l_event_deny:
      Copy_of_Assignment_lego_DW.temporalCounter_i1 = 0U;
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_manuver_1;
      Copy_of_Assignment_lego_B.motor = 0.0;
      break;

     case Copy_of_Assignmen_event_confirm:
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Off;
      Copy_of_Assignment_lego_B.motor = 0.0;
      break;
    }
    break;

   case ChartModeType_Emergency_state:
    if (*sfEvent == Copy_of_Assi_event_e_btnPressed) {
      Copy_of_Assignment_lego_DW.temporalCounter_i1 = 0U;
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_mid_state;
    } else {
      Copy_of_Assignment_lego_B.motor = 0.0;
    }
    break;

   case ChartModeType_Off:
    if (*sfEvent == Copy_o_event_Center_btn_pressed) {
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Confirmation;
    }
    break;

   case ChartModeType_manuver_1:
    switch (*sfEvent) {
     case Copy_of_Assi_event_e_btnPressed:
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Emergency_state;
      break;

     case Copy_o_event_Center_btn_pressed:
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Confirmation1;
      break;
    }
    break;

   default:
    /* State mid_state */
    if (Copy_of_Assignment_lego_DW.temporalCounter_i1 >= 40U) {
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Emergency_state;
    } else if (*sfEvent == Copy_of_Assi_event_e_btnPressed) {
      Copy_of_Assignment_lego_DW.temporalCounter_i1 = 0U;
      Copy_of_Assignment_lego_B.ChartMode = ChartModeType_manuver_1;
      Copy_of_Assignment_lego_B.motor = 0.0;
    }
    break;
  }
}

/* Model step function for TID0 */
void Copy_of_Assignment_lego_step0(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp_0;
  int32_T i;
  uint32_T elapsedTicks;
  int8_T rtb_inputevents[5];
  int8_T tmp;
  uint8_T rtb_Button1_0;
  uint8_T rtb_Button2_0;
  uint8_T rtb_Button_0;
  uint8_T rtb_TouchSensor_0;
  boolean_T zcEvent[5];
  boolean_T zcEvent_0;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (ev3_touch_sensor): '<S2>/Touch Sensor' */
  rtb_TouchSensor_0 = getTouchSensorValue(1U);

  /* S-Function (ev3_buttons): '<S2>/Button' */
  rtb_Button_0 = getButtonValue(2U);

  /* S-Function (ev3_buttons): '<S2>/Button1' */
  rtb_Button1_0 = getButtonValue(4U);

  /* S-Function (ev3_buttons): '<S2>/Button2' */
  rtb_Button2_0 = getButtonValue(5U);

  /* RateTransition generated from: '<S2>/Data Type Conversion' */
  if (Copy_of_Assignment_lego_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S2>/Data Type Conversion' */
    Copy_of_Assignment_lego_B.TmpRTBAtDataTypeConversionOutpo =
      Copy_of_Assignment_lego_DW.TmpRTBAtDataTypeConversionOutpo;
  }

  /* End of RateTransition generated from: '<S2>/Data Type Conversion' */

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/input events'
   */
  /* S-Function (ev3_touch_sensor): '<S2>/Touch Sensor' */
  zcEvent[0] = ((rtb_TouchSensor_0 > 0) &&
                (Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[0] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<S2>/Button' */
  zcEvent[1] = ((rtb_Button_0 > 0) &&
                (Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[1] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<S2>/Button1' */
  zcEvent[2] = ((rtb_Button1_0 > 0) &&
                (Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[2] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<S2>/Button2' */
  zcEvent[3] = ((rtb_Button2_0 > 0) &&
                (Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[3] != POS_ZCSIG));
  zcEvent[4] = ((Copy_of_Assignment_lego_B.TmpRTBAtDataTypeConversionOutpo > 0) &&
                (Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[4] != POS_ZCSIG));
  zcEvent_0 = false;
  for (i = 0; i < 5; i++) {
    zcEvent_0 = (zcEvent_0 || zcEvent[i]);
  }

  if (zcEvent_0) {
    for (i = 0; i < 5; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    elapsedTicks = Copy_of_Assignment_lego_M->Timing.clockTick0 -
      Copy_of_Assignment_lego_DW.previousTicks;
    Copy_of_Assignment_lego_DW.previousTicks =
      Copy_of_Assignment_lego_M->Timing.clockTick0;
    elapsedTicks += Copy_of_Assignment_lego_DW.temporalCounter_i1;
    if (elapsedTicks <= 63U) {
      Copy_of_Assignment_lego_DW.temporalCounter_i1 = (uint8_T)elapsedTicks;
    } else {
      Copy_of_Assignment_lego_DW.temporalCounter_i1 = 63U;
    }

    if (rtb_inputevents[0U] == 1) {
      i = Copy_of_Assi_event_e_btnPressed;
      chartstep_c3_Copy_of_Assignment(&i);
    }

    if (rtb_inputevents[1U] == 1) {
      i = Copy_o_event_Center_btn_pressed;
      chartstep_c3_Copy_of_Assignment(&i);
    }

    if (rtb_inputevents[2U] == 1) {
      i = Copy_of_Assignmen_event_confirm;
      chartstep_c3_Copy_of_Assignment(&i);
    }

    if (rtb_inputevents[3U] == 1) {
      i = Copy_of_Assignment_l_event_deny;
      chartstep_c3_Copy_of_Assignment(&i);
    }

    if (rtb_inputevents[4U] == 1) {
      i = Copy_of_Assignment__event_clock;
      chartstep_c3_Copy_of_Assignment(&i);
    }
  }

  /* S-Function (ev3_touch_sensor): '<S2>/Touch Sensor' */
  Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[0] = (ZCSigState)
    (rtb_TouchSensor_0 > 0);

  /* S-Function (ev3_buttons): '<S2>/Button' */
  Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[1] = (ZCSigState)(rtb_Button_0 >
    0);

  /* S-Function (ev3_buttons): '<S2>/Button1' */
  Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[2] = (ZCSigState)(rtb_Button1_0
    > 0);

  /* S-Function (ev3_buttons): '<S2>/Button2' */
  Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[3] = (ZCSigState)(rtb_Button2_0
    > 0);
  Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[4] = (ZCSigState)
    (Copy_of_Assignment_lego_B.TmpRTBAtDataTypeConversionOutpo > 0);

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  tmp_0 = floor(Copy_of_Assignment_lego_B.motor);
  if (tmp_0 < 128.0) {
    if (tmp_0 >= -128.0) {
      /* S-Function (ev3_motor): '<S4>/Motor' */
      tmp = (int8_T)tmp_0;
    } else {
      /* S-Function (ev3_motor): '<S4>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S4>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S4>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Copy_of_Assignment_lego_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void Copy_of_Assignment_lego_step1(void) /* Sample time: [1.0s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_DataTypeConversion;

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  rtb_PulseGenerator = (Copy_of_Assignment_lego_DW.clockTickCounter <
                        Copy_of_Assignment_lego_P.PulseGenerator_Duty) &&
    (Copy_of_Assignment_lego_DW.clockTickCounter >= 0) ?
    Copy_of_Assignment_lego_P.PulseGenerator_Amp : 0.0;
  if (Copy_of_Assignment_lego_DW.clockTickCounter >=
      Copy_of_Assignment_lego_P.PulseGenerator_Period - 1.0) {
    Copy_of_Assignment_lego_DW.clockTickCounter = 0;
  } else {
    Copy_of_Assignment_lego_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_PulseGenerator = floor(rtb_PulseGenerator);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  rtb_DataTypeConversion = (uint8_T)(rtb_PulseGenerator < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_PulseGenerator : (int32_T)(uint8_T)
    rtb_PulseGenerator);

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* RateTransition generated from: '<S2>/Data Type Conversion' */
  Copy_of_Assignment_lego_DW.TmpRTBAtDataTypeConversionOutpo =
    rtb_DataTypeConversion;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Copy_of_Assignment_lego_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Copy_of_Assignment_lego_step0();
    break;

   case 1 :
    Copy_of_Assignment_lego_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Copy_of_Assignment_lego_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;

    /* Start for S-Function (ev3_touch_sensor): '<S2>/Touch Sensor' */
    initTouchSensor(1U);

    /* Start for S-Function (ev3_buttons): '<S2>/Button' */
    initButton(2U);

    /* Start for S-Function (ev3_buttons): '<S2>/Button1' */
    initButton(4U);

    /* Start for S-Function (ev3_buttons): '<S2>/Button2' */
    initButton(5U);

    /* Start for RateTransition generated from: '<S2>/Data Type Conversion' */
    Copy_of_Assignment_lego_B.TmpRTBAtDataTypeConversionOutpo =
      Copy_of_Assignment_lego_P.TmpRTBAtDataTypeConversionOutpo;

    /* Start for S-Function (ev3_motor): '<S4>/Motor' */
    initMotor(1U);
    for (i = 0; i < 5; i++) {
      Copy_of_Assignment_lego_PrevZCX.Chart_Trig_ZCE[i] = POS_ZCSIG;
    }

    /* InitializeConditions for RateTransition generated from: '<S2>/Data Type Conversion' */
    Copy_of_Assignment_lego_DW.TmpRTBAtDataTypeConversionOutpo =
      Copy_of_Assignment_lego_P.TmpRTBAtDataTypeConversionOutpo;

    /* Chart: '<Root>/Chart' */
    Copy_of_Assignment_lego_B.ChartMode = ChartModeType_Off;

    /* Enable for Chart: '<Root>/Chart' */
    Copy_of_Assignment_lego_DW.previousTicks =
      Copy_of_Assignment_lego_M->Timing.clockTick0;
  }
}

/* Model terminate function */
void Copy_of_Assignment_lego_terminate(void)
{
  /* Terminate for S-Function (ev3_touch_sensor): '<S2>/Touch Sensor' */
  terminateTouchSensor(1U);

  /* Terminate for S-Function (ev3_buttons): '<S2>/Button' */
  terminateButton(2U);

  /* Terminate for S-Function (ev3_buttons): '<S2>/Button1' */
  terminateButton(4U);

  /* Terminate for S-Function (ev3_buttons): '<S2>/Button2' */
  terminateButton(5U);

  /* Terminate for S-Function (ev3_motor): '<S4>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
