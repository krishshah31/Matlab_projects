/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Test_lego_stopbtn.c
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

#include "Test_lego_stopbtn.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include "Test_lego_stopbtn_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Test_l_event_Center_btn_pressed (1)
#define Test_lego_st_event_e_btnPressed (0)
#define Test_lego_stop_IN_Confirmation1 (2U)
#define Test_lego_stopb_IN_Confirmation (1U)
#define Test_lego_stopbtn_IN_Off       (3U)
#define Test_lego_stopbtn_IN_On        (4U)
#define Test_lego_stopbtn_IN_On1       (5U)
#define Test_lego_stopbtn_IN_mid_state (6U)
#define Test_lego_stopbtn_event_confirm (2)
#define Test_lego_stopbtn_event_deny   (3)

/* Block signals (default storage) */
B_Test_lego_stopbtn_T Test_lego_stopbtn_B;

/* Block states (default storage) */
DW_Test_lego_stopbtn_T Test_lego_stopbtn_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Test_lego_stopbtn_T Test_lego_stopbtn_PrevZCX;

/* Real-time model */
static RT_MODEL_Test_lego_stopbtn_T Test_lego_stopbtn_M_;
RT_MODEL_Test_lego_stopbtn_T *const Test_lego_stopbtn_M = &Test_lego_stopbtn_M_;

/* Forward declaration for local functions */
static void chartstep_c3_Test_lego_stopbtn(const int32_T *sfEvent);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Test_lego_stopbtn_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Test_lego_stopbtn_M, 1));
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
  Test_lego_stopbtn_M->Timing.RateInteraction.TID0_1 =
    (Test_lego_stopbtn_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Test_lego_stopbtn_M->Timing.TaskCounters.TID[1])++;
  if ((Test_lego_stopbtn_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    Test_lego_stopbtn_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void chartstep_c3_Test_lego_stopbtn(const int32_T *sfEvent)
{
  switch (Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn) {
   case Test_lego_stopb_IN_Confirmation:
    if (*sfEvent == Test_lego_stopbtn_event_confirm) {
      Test_lego_stopbtn_B.screen = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_On1;
      Test_lego_stopbtn_B.motor = 100.0;
    } else if ((*sfEvent == Test_lego_stopbtn_event_deny) || (*sfEvent ==
                Test_lego_stopbtn_event_confirm)) {
      Test_lego_stopbtn_B.screen = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_Off;
      Test_lego_stopbtn_B.motor = 0.0;
    }
    break;

   case Test_lego_stop_IN_Confirmation1:
    switch (*sfEvent) {
     case Test_lego_stopbtn_event_deny:
      Test_lego_stopbtn_B.screen = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_On1;
      Test_lego_stopbtn_B.motor = 100.0;
      break;

     case Test_lego_stopbtn_event_confirm:
      Test_lego_stopbtn_B.screen = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_Off;
      Test_lego_stopbtn_B.motor = 0.0;
      break;
    }
    break;

   case Test_lego_stopbtn_IN_Off:
    Test_lego_stopbtn_B.motor = 0.0;
    switch (*sfEvent) {
     case Test_lego_st_event_e_btnPressed:
      Test_lego_stopbtn_B.idle_state = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn =
        Test_lego_stopbtn_IN_mid_state;
      break;

     case Test_l_event_Center_btn_pressed:
      Test_lego_stopbtn_B.idle_state = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn =
        Test_lego_stopb_IN_Confirmation;
      Test_lego_stopbtn_B.screen = 1.0;
      break;

     default:
      Test_lego_stopbtn_B.idle_state = 1.0;
      break;
    }
    break;

   case Test_lego_stopbtn_IN_On:
    Test_lego_stopbtn_B.motor = 100.0;
    if (*sfEvent == Test_lego_st_event_e_btnPressed) {
      Test_lego_stopbtn_B.running_state = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_Off;
      Test_lego_stopbtn_B.motor = 0.0;
    } else {
      Test_lego_stopbtn_B.running_state = 1.0;
    }
    break;

   case Test_lego_stopbtn_IN_On1:
    Test_lego_stopbtn_B.motor = 100.0;
    if (*sfEvent == Test_l_event_Center_btn_pressed) {
      Test_lego_stopbtn_B.running_state = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn =
        Test_lego_stop_IN_Confirmation1;
      Test_lego_stopbtn_B.screen = 1.0;
    } else if (*sfEvent == Test_l_event_Center_btn_pressed) {
      Test_lego_stopbtn_B.running_state = 0.0;
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn =
        Test_lego_stopb_IN_Confirmation;
      Test_lego_stopbtn_B.screen = 1.0;
    } else {
      Test_lego_stopbtn_B.running_state = 1.0;
    }
    break;

   default:
    /* case IN_mid_state: */
    if (*sfEvent == Test_lego_st_event_e_btnPressed) {
      Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_On;
      Test_lego_stopbtn_B.motor = 100.0;
    }
    break;
  }
}

/* Model step function for TID0 */
void Test_lego_stopbtn_step0(void)     /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp_0;
  int32_T sfEvent;
  int8_T tmp;
  uint8_T rtb_Button1_0;
  uint8_T rtb_Button2_0;
  uint8_T rtb_Button_0;
  boolean_T zcEvent_idx_0;
  boolean_T zcEvent_idx_1;
  boolean_T zcEvent_idx_2;
  boolean_T zcEvent_idx_3;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Test_lego_stopbtn_DW.Chart_SubsysRanBC);

  /* S-Function (ev3_buttons): '<Root>/Button' */
  rtb_Button_0 = getButtonValue(2U);

  /* S-Function (ev3_buttons): '<Root>/Button1' */
  rtb_Button1_0 = getButtonValue(4U);

  /* S-Function (ev3_buttons): '<Root>/Button2' */
  rtb_Button2_0 = getButtonValue(5U);

  /* RateTransition generated from: '<Root>/Data Type Conversion' */
  if (Test_lego_stopbtn_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Data Type Conversion' */
    Test_lego_stopbtn_B.TmpRTBAtDataTypeConversionOutpo =
      Test_lego_stopbtn_DW.TmpRTBAtDataTypeConversionOutpo;
  }

  /* End of RateTransition generated from: '<Root>/Data Type Conversion' */

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/input events'
   */
  zcEvent_idx_0 = ((Test_lego_stopbtn_B.TmpRTBAtDataTypeConversionOutpo > 0) &&
                   (Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[0] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<Root>/Button' */
  zcEvent_idx_1 = ((rtb_Button_0 > 0) &&
                   (Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[1] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<Root>/Button1' */
  zcEvent_idx_2 = ((rtb_Button1_0 > 0) &&
                   (Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[2] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<Root>/Button2' */
  zcEvent_idx_3 = ((rtb_Button2_0 > 0) &&
                   (Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[3] != POS_ZCSIG));
  if (zcEvent_idx_0 || zcEvent_idx_1 || zcEvent_idx_2 || zcEvent_idx_3) {
    /* Chart: '<Root>/Chart' incorporates:
     *  TriggerPort: '<S1>/input events'
     */
    Test_lego_stopbtn_B.inputevents[0] = (int8_T)zcEvent_idx_0;
    Test_lego_stopbtn_B.inputevents[1] = (int8_T)zcEvent_idx_1;
    Test_lego_stopbtn_B.inputevents[2] = (int8_T)zcEvent_idx_2;
    Test_lego_stopbtn_B.inputevents[3] = (int8_T)zcEvent_idx_3;
    if (Test_lego_stopbtn_B.inputevents[0U] == 1) {
      sfEvent = Test_lego_st_event_e_btnPressed;
      chartstep_c3_Test_lego_stopbtn(&sfEvent);
    }

    if (Test_lego_stopbtn_B.inputevents[1U] == 1) {
      sfEvent = Test_l_event_Center_btn_pressed;
      chartstep_c3_Test_lego_stopbtn(&sfEvent);
    }

    if (Test_lego_stopbtn_B.inputevents[2U] == 1) {
      sfEvent = Test_lego_stopbtn_event_confirm;
      chartstep_c3_Test_lego_stopbtn(&sfEvent);
    }

    if (Test_lego_stopbtn_B.inputevents[3U] == 1) {
      sfEvent = Test_lego_stopbtn_event_deny;
      chartstep_c3_Test_lego_stopbtn(&sfEvent);
    }

    Test_lego_stopbtn_DW.Chart_SubsysRanBC = 4;
  }

  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[0] = (ZCSigState)
    (Test_lego_stopbtn_B.TmpRTBAtDataTypeConversionOutpo > 0);

  /* S-Function (ev3_buttons): '<Root>/Button' */
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[1] = (ZCSigState)(rtb_Button_0 > 0);

  /* S-Function (ev3_buttons): '<Root>/Button1' */
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[2] = (ZCSigState)(rtb_Button1_0 > 0);

  /* S-Function (ev3_buttons): '<Root>/Button2' */
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[3] = (ZCSigState)(rtb_Button2_0 > 0);

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp_0 = floor(Test_lego_stopbtn_B.screen);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  /* S-Function (ev3_lcd): '<S2>/LCD' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  lcdDisplay(tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0,
             Test_lego_stopbtn_ConstP.LCD_p1, 1U, 1U);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  tmp_0 = floor(Test_lego_stopbtn_B.running_state);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  /* S-Function (ev3_lcd): '<S3>/LCD' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  lcdDisplay(tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0,
             Test_lego_stopbtn_ConstP.LCD_p1_o, 1U, 1U);

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  tmp_0 = floor(Test_lego_stopbtn_B.idle_state);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  /* S-Function (ev3_lcd): '<S4>/LCD' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  lcdDisplay(tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)(uint32_T)tmp_0,
             Test_lego_stopbtn_ConstP.LCD_p1_l, 1U, 1U);

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  tmp_0 = floor(Test_lego_stopbtn_B.motor);
  if (tmp_0 < 128.0) {
    if (tmp_0 >= -128.0) {
      /* S-Function (ev3_motor): '<S5>/Motor' */
      tmp = (int8_T)tmp_0;
    } else {
      /* S-Function (ev3_motor): '<S5>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S5>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S5>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* S-Function (ev3_touch_sensor): '<Root>/Touch Sensor' */
  getTouchSensorValue(1U);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Test_lego_stopbtn_M->Timing.taskTime0 =
    ((time_T)(++Test_lego_stopbtn_M->Timing.clockTick0)) *
    Test_lego_stopbtn_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Test_lego_stopbtn_step1(void)     /* Sample time: [1.0s, 0.0s] */
{
  real_T tmp;
  uint8_T rtb_DataTypeConversion_d;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(Test_lego_stopbtn_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rtb_DataTypeConversion_d = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)
    (uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* RateTransition generated from: '<Root>/Data Type Conversion' */
  Test_lego_stopbtn_DW.TmpRTBAtDataTypeConversionOutpo =
    rtb_DataTypeConversion_d;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Test_lego_stopbtn_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Test_lego_stopbtn_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Test_lego_stopbtn_step0();
    break;

   case 1 :
    Test_lego_stopbtn_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Test_lego_stopbtn_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Test_lego_stopbtn_M, 10.0);
  Test_lego_stopbtn_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Test_lego_stopbtn_M->Sizes.checksums[0] = (1749737107U);
  Test_lego_stopbtn_M->Sizes.checksums[1] = (2904538658U);
  Test_lego_stopbtn_M->Sizes.checksums[2] = (3133107925U);
  Test_lego_stopbtn_M->Sizes.checksums[3] = (2625966930U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Test_lego_stopbtn_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Test_lego_stopbtn_DW.Chart_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Test_lego_stopbtn_M->extModeInfo,
      &Test_lego_stopbtn_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test_lego_stopbtn_M->extModeInfo,
                        Test_lego_stopbtn_M->Sizes.checksums);
    rteiSetTPtr(Test_lego_stopbtn_M->extModeInfo, rtmGetTPtr(Test_lego_stopbtn_M));
  }

  /* Start for S-Function (ev3_buttons): '<Root>/Button' */
  initButton(2U);

  /* Start for S-Function (ev3_buttons): '<Root>/Button1' */
  initButton(4U);

  /* Start for S-Function (ev3_buttons): '<Root>/Button2' */
  initButton(5U);

  /* Start for RateTransition generated from: '<Root>/Data Type Conversion' */
  Test_lego_stopbtn_B.TmpRTBAtDataTypeConversionOutpo =
    Test_lego_stopbtn_P.TmpRTBAtDataTypeConversionOutpo;

  /* Start for S-Function (ev3_lcd): '<S2>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_lcd): '<S3>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_lcd): '<S4>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_motor): '<S5>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_touch_sensor): '<Root>/Touch Sensor' */
  initTouchSensor(1U);
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[0] = POS_ZCSIG;
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[1] = POS_ZCSIG;
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[2] = POS_ZCSIG;
  Test_lego_stopbtn_PrevZCX.Chart_Trig_ZCE[3] = POS_ZCSIG;

  /* InitializeConditions for RateTransition generated from: '<Root>/Data Type Conversion' */
  Test_lego_stopbtn_DW.TmpRTBAtDataTypeConversionOutpo =
    Test_lego_stopbtn_P.TmpRTBAtDataTypeConversionOutpo;

  /* Chart: '<Root>/Chart' */
  Test_lego_stopbtn_DW.is_active_c3_Test_lego_stopbtn = 1U;
  Test_lego_stopbtn_DW.is_c3_Test_lego_stopbtn = Test_lego_stopbtn_IN_Off;
}

/* Model terminate function */
void Test_lego_stopbtn_terminate(void)
{
  /* Terminate for S-Function (ev3_buttons): '<Root>/Button' */
  terminateButton(2U);

  /* Terminate for S-Function (ev3_buttons): '<Root>/Button1' */
  terminateButton(4U);

  /* Terminate for S-Function (ev3_buttons): '<Root>/Button2' */
  terminateButton(5U);

  /* Terminate for S-Function (ev3_lcd): '<S2>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_lcd): '<S3>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_lcd): '<S4>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_motor): '<S5>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_touch_sensor): '<Root>/Touch Sensor' */
  terminateTouchSensor(1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
