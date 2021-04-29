/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum
{
  MODE_LSB = 0x00,
  MODE_USB = 0x01,
  MODE_CW  = 0x02,  //CW-USB
  MODE_CWR = 0x03,  //CW-LSB
  MODE_AM  = 0x04,
  MODE_FM  = 0x08,
  MODE_DIG = 0x0A,  //DIG-U
  MODE_PKT = 0x0C   //DIG-L
} Mode;

typedef struct
{
  Mode mode;
  uint64_t vfoa;
  uint64_t vfob;
  uint8_t vfo;
  uint8_t split;
  uint8_t is_tx;
  uint32_t sysclock;
  uint8_t systicks;
} TRX_TypeDef;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TX_Pin GPIO_PIN_13
#define TX_GPIO_Port GPIOC
#define PTT_Pin GPIO_PIN_0
#define PTT_GPIO_Port GPIOB
#define PTT_EXTI_IRQn EXTI0_IRQn
#define KEY_DIT_Pin GPIO_PIN_1
#define KEY_DIT_GPIO_Port GPIOB
#define KEY_DIT_EXTI_IRQn EXTI1_IRQn
#define KEY_DAH_Pin GPIO_PIN_2
#define KEY_DAH_GPIO_Port GPIOB
#define KEY_DAH_EXTI_IRQn EXTI2_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
