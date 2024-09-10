/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: Copy_of_Manuever_2.c
 *
 * Code generated for Simulink model 'Copy_of_Manuever_2'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 27 15:51:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_Manuever_2.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Copy_of_Manuever_2_types.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Copy_o_event_Center_btn_pressed (1)
#define Copy_of_Manu_event_e_btnPressed (0)
#define Copy_of_Manuever_2_event_clock (4)
#define Copy_of_Manuever_2_event_deny  (3)
#define Copy_of_Manuever__event_confirm (2)

/* Block signals (default storage) */
B_Copy_of_Manuever_2_T Copy_of_Manuever_2_B;

/* Block states (default storage) */
DW_Copy_of_Manuever_2_T Copy_of_Manuever_2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Copy_of_Manuever_2_T Copy_of_Manuever_2_PrevZCX;

/* Real-time model */
static RT_MODEL_Copy_of_Manuever_2_T Copy_of_Manuever_2_M_;
RT_MODEL_Copy_of_Manuever_2_T *const Copy_of_Manuever_2_M =
  &Copy_of_Manuever_2_M_;

/* Forward declaration for local functions */
static void chartstep_c3_Copy_of_Manuever_2(const real_T *Divide1, const int32_T
  *sfEvent);

/* Function for Chart: '<Root>/Chart' */
static void chartstep_c3_Copy_of_Manuever_2(const real_T *Divide1, const int32_T
  *sfEvent)
{
  switch (Copy_of_Manuever_2_B.ChartMode) {
   case ChartModeType_EmergencySTOP:
    if (*sfEvent == Copy_of_Manu_event_e_btnPressed) {
      Copy_of_Manuever_2_DW.temporalCounter_i1 = 0U;
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_mid_state;
    }
    break;

   case ChartModeType_Off:
    if (*sfEvent == Copy_o_event_Center_btn_pressed) {
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_TurnOnConfirm;
    }
    break;

   case ChartModeType_On1:
    if (Copy_of_Manuever_2_DW.temporalCounter_i1 >= (uint32_T)ceil(*Divide1 *
         10.0)) {
      Copy_of_Manuever_2_DW.temporalCounter_i1 = 0U;
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_turn_state;
    } else {
      switch (*sfEvent) {
       case Copy_of_Manu_event_e_btnPressed:
        Copy_of_Manuever_2_B.ChartMode = ChartModeType_EmergencySTOP;
        Copy_of_Manuever_2_B.motor = 0.0;
        Copy_of_Manuever_2_B.motor1 = 0.0;
        break;

       case Copy_o_event_Center_btn_pressed:
        Copy_of_Manuever_2_B.ChartMode = ChartModeType_TurnOffConfirm;
        break;
      }
    }
    break;

   case ChartModeType_TurnOffConfirm:
    switch (*sfEvent) {
     case Copy_of_Manuever_2_event_deny:
      Copy_of_Manuever_2_DW.temporalCounter_i1 = 0U;
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_On1;

      /* Constant: '<Root>/Speed in Meter//Sec' */
      Copy_of_Manuever_2_B.motor = Copy_of_Manuever_2_P.SpeedinMeterSec_Value;
      Copy_of_Manuever_2_B.motor1 = Copy_of_Manuever_2_P.SpeedinMeterSec_Value;
      break;

     case Copy_of_Manuever__event_confirm:
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_Off;
      Copy_of_Manuever_2_B.motor = 0.0;
      Copy_of_Manuever_2_B.motor1 = 0.0;
      break;
    }
    break;

   case ChartModeType_TurnOnConfirm:
    switch (*sfEvent) {
     case Copy_of_Manuever__event_confirm:
      Copy_of_Manuever_2_DW.temporalCounter_i1 = 0U;
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_On1;

      /* Constant: '<Root>/Speed in Meter//Sec' */
      Copy_of_Manuever_2_B.motor = Copy_of_Manuever_2_P.SpeedinMeterSec_Value;
      Copy_of_Manuever_2_B.motor1 = Copy_of_Manuever_2_P.SpeedinMeterSec_Value;
      break;

     case Copy_of_Manuever_2_event_deny:
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_Off;
      Copy_of_Manuever_2_B.motor = 0.0;
      Copy_of_Manuever_2_B.motor1 = 0.0;
      break;
    }
    break;

   case ChartModeType_mid_state:
    if (Copy_of_Manuever_2_DW.temporalCounter_i1 >= 40U) {
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_EmergencySTOP;
      Copy_of_Manuever_2_B.motor = 0.0;
      Copy_of_Manuever_2_B.motor1 = 0.0;
    } else if (*sfEvent == Copy_of_Manu_event_e_btnPressed) {
      Copy_of_Manuever_2_DW.temporalCounter_i1 = 0U;
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_On1;

      /* Constant: '<Root>/Speed in Meter//Sec' */
      Copy_of_Manuever_2_B.motor = Copy_of_Manuever_2_P.SpeedinMeterSec_Value;
      Copy_of_Manuever_2_B.motor1 = Copy_of_Manuever_2_P.SpeedinMeterSec_Value;
    }
    break;

   case ChartModeType_turn_state:
    if (Copy_of_Manuever_2_DW.temporalCounter_i1 >= 30U) {
      Copy_of_Manuever_2_DW.temporalCounter_i1 = 0U;
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_turn_state1;
    } else {
      Copy_of_Manuever_2_B.motor = 0.0;
      Copy_of_Manuever_2_B.motor1 = 38.0;
    }
    break;

   default:
    /* State turn_state1 */
    if (Copy_of_Manuever_2_DW.temporalCounter_i1 >= 500U) {
      Copy_of_Manuever_2_B.ChartMode = ChartModeType_Off;
      Copy_of_Manuever_2_B.motor = 0.0;
      Copy_of_Manuever_2_B.motor1 = 0.0;
    } else {
      Copy_of_Manuever_2_B.motor = 50.0;
      Copy_of_Manuever_2_B.motor1 = 25.0;
    }
    break;
  }
}

/* Model step function */
void Copy_of_Manuever_2_step(void)
{
  real_T Divide1;
  real_T rtb_PulseGenerator;
  int32_T i;
  uint32_T elapsedTicks;
  int8_T rtb_inputevents[5];
  int8_T tmp;
  uint8_T rtb_Button1_0;
  uint8_T rtb_Button2_0;
  uint8_T rtb_Button_0;
  uint8_T rtb_DataTypeConversion;
  uint8_T rtb_TouchSensor_0;
  boolean_T zcEvent[5];
  boolean_T zcEvent_0;

  /* Product: '<S5>/Divide1' incorporates:
   *  Constant: '<Root>/Speed in Meter//Sec'
   *  Constant: '<Root>/radius in Meter'
   */
  Divide1 = Copy_of_Manuever_2_P.radiusinMeter_Value /
    Copy_of_Manuever_2_P.SpeedinMeterSec_Value;

  /* S-Function (ev3_touch_sensor): '<S3>/Touch Sensor' */
  rtb_TouchSensor_0 = getTouchSensorValue(1U);

  /* S-Function (ev3_buttons): '<S3>/Button' */
  rtb_Button_0 = getButtonValue(2U);

  /* S-Function (ev3_buttons): '<S3>/Button1' */
  rtb_Button1_0 = getButtonValue(4U);

  /* S-Function (ev3_buttons): '<S3>/Button2' */
  rtb_Button2_0 = getButtonValue(5U);

  /* DiscretePulseGenerator: '<S3>/Pulse Generator' */
  rtb_PulseGenerator = (Copy_of_Manuever_2_DW.clockTickCounter <
                        Copy_of_Manuever_2_P.PulseGenerator_Duty) &&
    (Copy_of_Manuever_2_DW.clockTickCounter >= 0) ?
    Copy_of_Manuever_2_P.PulseGenerator_Amp : 0.0;
  if (Copy_of_Manuever_2_DW.clockTickCounter >=
      Copy_of_Manuever_2_P.PulseGenerator_Period - 1.0) {
    Copy_of_Manuever_2_DW.clockTickCounter = 0;
  } else {
    Copy_of_Manuever_2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S3>/Pulse Generator' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  rtb_PulseGenerator = floor(rtb_PulseGenerator);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  rtb_DataTypeConversion = (uint8_T)(rtb_PulseGenerator < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_PulseGenerator : (int32_T)(uint8_T)
    rtb_PulseGenerator);

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/input events'
   */
  /* S-Function (ev3_touch_sensor): '<S3>/Touch Sensor' */
  zcEvent[0] = ((rtb_TouchSensor_0 > 0) &&
                (Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[0] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<S3>/Button' */
  zcEvent[1] = ((rtb_Button_0 > 0) &&
                (Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[1] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<S3>/Button1' */
  zcEvent[2] = ((rtb_Button1_0 > 0) &&
                (Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[2] != POS_ZCSIG));

  /* S-Function (ev3_buttons): '<S3>/Button2' */
  zcEvent[3] = ((rtb_Button2_0 > 0) &&
                (Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[3] != POS_ZCSIG));
  zcEvent[4] = ((rtb_DataTypeConversion > 0) &&
                (Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[4] != POS_ZCSIG));
  zcEvent_0 = false;
  for (i = 0; i < 5; i++) {
    zcEvent_0 = (zcEvent_0 || zcEvent[i]);
  }

  if (zcEvent_0) {
    for (i = 0; i < 5; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    elapsedTicks = Copy_of_Manuever_2_M->Timing.clockTick0 -
      Copy_of_Manuever_2_DW.previousTicks;
    Copy_of_Manuever_2_DW.previousTicks =
      Copy_of_Manuever_2_M->Timing.clockTick0;
    Copy_of_Manuever_2_DW.temporalCounter_i1 += elapsedTicks;
    if (rtb_inputevents[0U] == 1) {
      i = Copy_of_Manu_event_e_btnPressed;
      chartstep_c3_Copy_of_Manuever_2(&Divide1, &i);
    }

    if (rtb_inputevents[1U] == 1) {
      i = Copy_o_event_Center_btn_pressed;
      chartstep_c3_Copy_of_Manuever_2(&Divide1, &i);
    }

    if (rtb_inputevents[2U] == 1) {
      i = Copy_of_Manuever__event_confirm;
      chartstep_c3_Copy_of_Manuever_2(&Divide1, &i);
    }

    if (rtb_inputevents[3U] == 1) {
      i = Copy_of_Manuever_2_event_deny;
      chartstep_c3_Copy_of_Manuever_2(&Divide1, &i);
    }

    if (rtb_inputevents[4U] == 1) {
      i = Copy_of_Manuever_2_event_clock;
      chartstep_c3_Copy_of_Manuever_2(&Divide1, &i);
    }
  }

  /* S-Function (ev3_touch_sensor): '<S3>/Touch Sensor' */
  Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[0] = (ZCSigState)(rtb_TouchSensor_0 >
    0);

  /* S-Function (ev3_buttons): '<S3>/Button' */
  Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[1] = (ZCSigState)(rtb_Button_0 > 0);

  /* S-Function (ev3_buttons): '<S3>/Button1' */
  Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[2] = (ZCSigState)(rtb_Button1_0 > 0);

  /* S-Function (ev3_buttons): '<S3>/Button2' */
  Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[3] = (ZCSigState)(rtb_Button2_0 > 0);
  Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[4] = (ZCSigState)
    (rtb_DataTypeConversion > 0);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  rtb_PulseGenerator = floor(Copy_of_Manuever_2_B.motor);
  if (rtb_PulseGenerator < 128.0) {
    if (rtb_PulseGenerator >= -128.0) {
      /* S-Function (ev3_motor): '<S6>/Motor' */
      tmp = (int8_T)rtb_PulseGenerator;
    } else {
      /* S-Function (ev3_motor): '<S6>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S6>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S6>/Motor' */
  setMotor(&tmp, 1U, 2U);

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  rtb_PulseGenerator = floor(Copy_of_Manuever_2_B.motor1);
  if (rtb_PulseGenerator < 128.0) {
    if (rtb_PulseGenerator >= -128.0) {
      /* S-Function (ev3_motor): '<S7>/Motor' */
      tmp = (int8_T)rtb_PulseGenerator;
    } else {
      /* S-Function (ev3_motor): '<S7>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S7>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S7>/Motor' */
  setMotor(&tmp, 2U, 2U);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Copy_of_Manuever_2_M->Timing.clockTick0++;
}

/* Model initialize function */
void Copy_of_Manuever_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;

    /* Start for S-Function (ev3_touch_sensor): '<S3>/Touch Sensor' */
    initTouchSensor(1U);

    /* Start for S-Function (ev3_buttons): '<S3>/Button' */
    initButton(2U);

    /* Start for S-Function (ev3_buttons): '<S3>/Button1' */
    initButton(4U);

    /* Start for S-Function (ev3_buttons): '<S3>/Button2' */
    initButton(5U);

    /* Start for S-Function (ev3_motor): '<S6>/Motor' */
    initMotor(1U);

    /* Start for S-Function (ev3_motor): '<S7>/Motor' */
    initMotor(2U);
    for (i = 0; i < 5; i++) {
      Copy_of_Manuever_2_PrevZCX.Chart_Trig_ZCE[i] = POS_ZCSIG;
    }

    /* Chart: '<Root>/Chart' */
    Copy_of_Manuever_2_B.ChartMode = ChartModeType_Off;

    /* Enable for Chart: '<Root>/Chart' */
    Copy_of_Manuever_2_DW.previousTicks =
      Copy_of_Manuever_2_M->Timing.clockTick0;
  }
}

/* Model terminate function */
void Copy_of_Manuever_2_terminate(void)
{
  /* Terminate for S-Function (ev3_touch_sensor): '<S3>/Touch Sensor' */
  terminateTouchSensor(1U);

  /* Terminate for S-Function (ev3_buttons): '<S3>/Button' */
  terminateButton(2U);

  /* Terminate for S-Function (ev3_buttons): '<S3>/Button1' */
  terminateButton(4U);

  /* Terminate for S-Function (ev3_buttons): '<S3>/Button2' */
  terminateButton(5U);

  /* Terminate for S-Function (ev3_motor): '<S6>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_motor): '<S7>/Motor' */
  terminateMotor(2U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
