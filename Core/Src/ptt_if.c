/**
  *******************************************************************************
  *
  * @file    ptt_if.c
  * @brief   PTT driver
  * @version v1.0
  * @date    05.04.2020
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
#include "ptt_if.h"
#include "vfo_if.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
PTT_TypeDef ptt;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* External variables --------------------------------------------------------*/
extern TRX_TypeDef trx;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief This function sets TX mode
  *
  * The function also sets TX mode for VFO and DSP
  *
  */

void ptt_set_tx (void)
{
  if (!trx.is_tx)
  {
    if (trx.split) { VFO_Toggle_VFO (); }

    trx.is_tx = 1U;

    HAL_GPIO_WritePin (TX_GPIO_Port, TX_Pin, GPIO_PIN_RESET);
  }
}

/**
  * @brief This function sets RX mode
  *
  * The function sets RX mode if the PTT button is not pressed,
  * the telegraph key is not used and CAT status is not TX.
  * The function also sets RX mode for VFO and DSP
  *
  */

void ptt_set_rx (void)
{
  if (ptt.cat_is_on || ptt.ptt_is_on) return;

  if (trx.is_tx)
  {
    trx.is_tx = 0U;

    if (trx.split) { VFO_Toggle_VFO (); }

    HAL_GPIO_WritePin (TX_GPIO_Port, TX_Pin, GPIO_PIN_SET);
  }
}

/**
 * @brief This function sets TRX operating mode from CAT command
 *
 *@param TRX operating mode
 */

void PTT_Set_Mode (uint8_t trx_mode)
{
  if (trx.is_tx) return;

  switch (trx_mode)
  {
    case 0x00:
      trx.mode = MODE_LSB;
      break;
    case 0x01:
      trx.mode = MODE_USB;
      break;
    case 0x02:
      trx.mode = MODE_CW;   //CW-USB
      break;
    case 0x03:
      trx.mode = MODE_CWR;  //CW-LSB
      break;
    case 0x04:
      trx.mode = MODE_AM;
      break;
    case 0x08:
      trx.mode = MODE_FM;
      break;
    case 0x0A:
      trx.mode = MODE_DIG;  //DIG-U
      break;
    case 0x0C:
      trx.mode = MODE_PKT;  //DIG-L
      break;
    default:
      trx.mode = MODE_USB;
      break;
  }
}


/**
  * @brief This function sets TX mode from CAT command
  *
  */

void PTT_CAT_TX (uint8_t cat)
{
  if (ptt.cat_is_on != cat)
  {
    ptt.cat_is_on = cat;

    if (cat) { ptt_set_tx (); }
    else { ptt_set_rx (); }
  }
}

/**
  * @brief This function initialize PTT, VFO and DSP
  *
  */

void PTT_Init (void)
{
  trx.is_tx = 0U;
  HAL_GPIO_WritePin (TX_GPIO_Port, TX_Pin, GPIO_PIN_SET);

  trx.mode = MODE_LSB;

  VFO_Init ();
}

/**
  * @brief This function is GPIO_EXTI handler
  *
  * @param PTT_Pin     - PTT button
  * @param KEY_DAH_Pin - Telegraph key DAH paddle
  * @param KEY_DIT_Pin - Telegraph key DIT paddle
  *
  */

void HAL_GPIO_EXTI_Callback (uint16_t GPIO_Pin)
{
  switch (GPIO_Pin)
  {
    case PTT_Pin:
      ptt.ptt_is_on = !HAL_GPIO_ReadPin (PTT_GPIO_Port, PTT_Pin);

      if (ptt.ptt_is_on) { ptt_set_tx (); }
      else { ptt_set_rx (); }

      break;
    case KEY_DAH_Pin:
      break;
    case KEY_DIT_Pin:
      break;
  }
}

/****END OF FILE****/
