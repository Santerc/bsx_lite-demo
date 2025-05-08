/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define Bmi088GyroCs_Pin GPIO_PIN_14
#define Bmi088GyroCs_GPIO_Port GPIOC
#define Bmi088AccCs_Pin GPIO_PIN_15
#define Bmi088AccCs_GPIO_Port GPIOC
#define EncoderRA_Pin GPIO_PIN_0
#define EncoderRA_GPIO_Port GPIOA
#define EncoderRB_Pin GPIO_PIN_1
#define EncoderRB_GPIO_Port GPIOA
#define Bmi088Sck_Pin GPIO_PIN_5
#define Bmi088Sck_GPIO_Port GPIOA
#define Bmi088Miso_Pin GPIO_PIN_6
#define Bmi088Miso_GPIO_Port GPIOA
#define Bmi088Mosi_Pin GPIO_PIN_7
#define Bmi088Mosi_GPIO_Port GPIOA
#define SnailA_Pin GPIO_PIN_0
#define SnailA_GPIO_Port GPIOB
#define SnailB_Pin GPIO_PIN_1
#define SnailB_GPIO_Port GPIOB
#define EncoderLA_Pin GPIO_PIN_15
#define EncoderLA_GPIO_Port GPIOA
#define EncoderLB_Pin GPIO_PIN_3
#define EncoderLB_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
