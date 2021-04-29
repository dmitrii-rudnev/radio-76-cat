/**
  *******************************************************************************
  *
  * @file    vfo_if.c
  * @brief   VFO control
  * @version v1.0
  * @date    13.03.2020
  * @author  Dmitrii Rudnev
  *
  *******************************************************************************
  * Copyrigh &copy; 2020 Selenite Project. All rights reserved.
  *
  * This software component is licensed under [BSD 3-Clause license]
  * (http://opensource.org/licenses/BSD-3-Clause/), the "License".<br>
  * You may not use this file except in compliance with the License.
  *******************************************************************************
  */



/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "vfo_if.h"
//#include "si5351.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
extern TRX_TypeDef trx;

/* Private functions with user code ------------------------------------------*/

/**
  * @brief  This function starts si5351
  *
  */

void vfo_init (void)
{
  //si5351_init ();
  HAL_Delay (100);

  //si5351_clock_enable (SI5351_CLK0, 1);
  //si5351_clock_enable (SI5351_CLK2, 1);
}

/**
  * @brief  This function sets
  * in RX (VFO + IF) in Hz for first mixer and IF in Hz for second mixer
  * in TX IF in Hz for first mixer and (VFO + IF) in Hz for second mixer
  *
  */

void vfo_set_freq (void)
{
  uint32_t if_freq  = 500000U;
  uint32_t vfo_freq = (uint32_t) trx.vfoa;

  if (trx.vfo) { vfo_freq = (uint32_t) trx.vfob; }

  vfo_freq += if_freq;

  if (trx.is_tx)
  {
    //si5351_set_freq (vfo_freq, SI5351_CLK0);
    //si5351_set_freq (if_freq,  SI5351_CLK2);
  }
  else
  {
    //si5351_set_freq (if_freq,  SI5351_CLK0);
    //si5351_set_freq (vfo_freq, SI5351_CLK2);
  }
}

/*----------------------------------------------------------------------------*/




/* Private functions ---------------------------------------------------------*/

 /**
 * @brief  This function sets initial values
 *
 */

void VFO_Init (void)
{
  trx.split = 0U;
  trx.vfo   = 0U;

  vfo_init ();
  vfo_set_freq ();
}

/**
  * @brief  This function sets TRX main frequency according to toggled VFO and sets si5351
  *
  * @param  Main frequency in Hz
  */

void VFO_Set_Tune (uint64_t tune_new)
{
  switch (trx.vfo)
  {
    case 0:
      if (trx.vfoa != tune_new) trx.vfoa = tune_new;
      break;
    case 1:
      if (trx.vfob != tune_new) trx.vfob = tune_new;
      break;
  }

  vfo_set_freq ();
}

/**
  * @brief  This function returns TRX main frequency according to toggled VFO
  *
  * @retval Main frequency in Hz
  */

uint64_t VFO_Get_Tune (void)
{
  uint64_t retval;

  if (trx.vfo) { retval = trx.vfob; }
  else { retval = trx.vfoa; }

  return retval;
}

/**
  * @brief  This function switches VFO from one to another
  *
  */

void VFO_Toggle_VFO (void)
{
  if (trx.is_tx) return;

  if (trx.vfo)
  {
    trx.vfo = 0U;
    VFO_Set_Tune (trx.vfoa);
  }
  else
  {
    trx.vfo = 1U;
    VFO_Set_Tune (trx.vfob);
  }
}

/**
  * @brief This function sets VFO Split Mode On/Off
  *
  */

void VFO_Set_Split (uint8_t split)
{
  if (trx.is_tx) return;

  trx.split = split;
}

/***END OF FILE***/
