/**
  *******************************************************************************
  *
  * @file    ptt_if.h
  * @brief   Header for ptt_if.c file
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef PTT_IF_H_
#define PTT_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  uint8_t is_enable;
  uint8_t cat_is_on;
  uint8_t ptt_is_on;
} PTT_TypeDef;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void PTT_Init (void);
void PTT_Set_Mode (uint8_t);
void PTT_CAT_TX (uint8_t);

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* PTT_IF_H_ */
