/**
  *******************************************************************************
  *
  * @file    vfo_if.h
  * @brief   Header for vfo_if.c file
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef VFO_IF_H_
#define VFO_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void VFO_Init (void);
void VFO_Toggle_VFO (void);
void VFO_Set_Tune (uint64_t);
uint64_t VFO_Get_Tune (void);
void VFO_Set_Split (uint8_t);

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* VFO_IF_H_ */
