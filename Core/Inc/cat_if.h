/**
  *******************************************************************************
  *
  * @file    cat_if.h
  * @brief   Header for cat_if.c file
  * @version v1.0
  * @date    17.03.2020
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
#ifndef CAT_IF_H_
#define CAT_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void CAT_Handler (void);
void CAT_Buff_Write_Byte (uint8_t);

/* Private defines -----------------------------------------------------------*/
#define CAT_TIMEOUT   30 // 300 ms
#define CAT_BUFF_SIZE 256

#ifdef __cplusplus
}
#endif

#endif /* CAT_IF_H_ */
