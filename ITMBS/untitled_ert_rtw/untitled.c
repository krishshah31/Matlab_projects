/*
 * Academic Teaching License -- for classroom instructional use only.  Not
 * for academic research, government, commercial, or other organizational
 * use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 20 14:30:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include <math.h>
#include "zero_crossing_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define untitled_IN_off                ((uint8_T)1U)
#define untitled_IN_on                 ((uint8_T)2U)

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_untitled_T untitled_PrevZCX;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  real_T tmp_0;
  int8_T tmp;
  uint8_T rtb_Button_0;

  /* S-Function (ev3_buttons): '<Root>/Button' */
  rtb_Button_0 = getButtonValue(2U);

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/btn'
   */
  if ((rtb_Button_0 > 0) && (untitled_PrevZCX.Chart_Trig_ZCE != POS_ZCSIG)) {
    if (untitled_DW.is_active_c3_untitled == 0U) {
      untitled_DW.is_active_c3_untitled = 1U;
      untitled_DW.is_c3_untitled = untitled_IN_off;
    } else if (untitled_DW.is_c3_untitled == untitled_IN_off) {
      untitled_DW.is_c3_untitled = untitled_IN_on;
    } else {
      /* case IN_on: */
      untitled_DW.is_c3_untitled = untitled_IN_off;
    }
  }

  untitled_PrevZCX.Chart_Trig_ZCE = (ZCSigState)(rtb_Button_0 > 0);

  /* End of S-Function (ev3_buttons): '<Root>/Button' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp_0 = floor(untitled_B.motor);
  if (tmp_0 < 128.0) {
    if (tmp_0 >= -128.0) {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp = (int8_T)tmp_0;
    } else {
      /* S-Function (ev3_motor): '<S2>/Motor' */
      tmp = MIN_int8_T;
    }
  } else {
    /* S-Function (ev3_motor): '<S2>/Motor' */
    tmp = MAX_int8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (ev3_motor): '<S2>/Motor' */
  setMotor(&tmp, 1U, 2U);
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (ev3_buttons): '<Root>/Button' */
  initButton(2U);

  /* Start for S-Function (ev3_motor): '<S2>/Motor' */
  initMotor(1U);
  untitled_PrevZCX.Chart_Trig_ZCE = POS_ZCSIG;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (ev3_buttons): '<Root>/Button' */
  terminateButton(2U);

  /* Terminate for S-Function (ev3_motor): '<S2>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
