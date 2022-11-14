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
#include "stm32f1xx_hal.h"

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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define button_NB_Sensor_Pin GPIO_PIN_0
#define button_NB_Sensor_GPIO_Port GPIOC
#define button_SB_Sensor_Pin GPIO_PIN_1
#define button_SB_Sensor_GPIO_Port GPIOC
#define button_EB_Sensor_Pin GPIO_PIN_2
#define button_EB_Sensor_GPIO_Port GPIOC
#define button_WB_Sensor_Pin GPIO_PIN_3
#define button_WB_Sensor_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define button_BTN1_Pin GPIO_PIN_4
#define button_BTN1_GPIO_Port GPIOC
#define button_BTN2_Pin GPIO_PIN_5
#define button_BTN2_GPIO_Port GPIOC
#define led_NB_RED_Pin GPIO_PIN_0
#define led_NB_RED_GPIO_Port GPIOB
#define led_NB_YELLOW_Pin GPIO_PIN_1
#define led_NB_YELLOW_GPIO_Port GPIOB
#define led_NB_GREEN_Pin GPIO_PIN_2
#define led_NB_GREEN_GPIO_Port GPIOB
#define led_WB_RED_Pin GPIO_PIN_10
#define led_WB_RED_GPIO_Port GPIOB
#define led_WB_YELLOW_Pin GPIO_PIN_11
#define led_WB_YELLOW_GPIO_Port GPIOB
#define led_WB_GREEN_Pin GPIO_PIN_12
#define led_WB_GREEN_GPIO_Port GPIOB
#define button_BTN3_Pin GPIO_PIN_6
#define button_BTN3_GPIO_Port GPIOC
#define button_BTN4_Pin GPIO_PIN_7
#define button_BTN4_GPIO_Port GPIOC
#define button_BTN5_Pin GPIO_PIN_8
#define button_BTN5_GPIO_Port GPIOC
#define button_BTN6_Pin GPIO_PIN_9
#define button_BTN6_GPIO_Port GPIOC
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define button_BTN7_Pin GPIO_PIN_10
#define button_BTN7_GPIO_Port GPIOC
#define button_BTN8_Pin GPIO_PIN_11
#define button_BTN8_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define led_SB_RED_Pin GPIO_PIN_4
#define led_SB_RED_GPIO_Port GPIOB
#define led_SB_YELLOW_Pin GPIO_PIN_5
#define led_SB_YELLOW_GPIO_Port GPIOB
#define led_SB_GREEN_Pin GPIO_PIN_6
#define led_SB_GREEN_GPIO_Port GPIOB
#define led_EB_RED_Pin GPIO_PIN_7
#define led_EB_RED_GPIO_Port GPIOB
#define led_EB_YELLOW_Pin GPIO_PIN_8
#define led_EB_YELLOW_GPIO_Port GPIOB
#define led_EB_GREEN_Pin GPIO_PIN_9
#define led_EB_GREEN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

// North Bound
#define LD_NB_RED_GPIO_Port    (GPIOB)
#define LD_NB_YELLOW_GPIO_Port (GPIOB)
#define LD_NB_GREEN_GPIO_Port  (GPIOB)
#define LD_NB_GPIO_Port        (GPIOB) //these are all on the same port - lets make a common def

#define LD_NB_RED_Pin          (GPIO_PIN_0)
#define LD_NB_YELLOW_Pin       (GPIO_PIN_1)
#define LD_NB_GREEN_Pin        (GPIO_PIN_2)

// South Bound
#define LD_SB_RED_GPIO_Port    (GPIOB)
#define LD_SB_YELLOW_GPIO_Port (GPIOB)
#define LD_SB_GREEN_GPIO_Port  (GPIOB)
#define LD_SB_GPIO_Port        (GPIOB) //these are all on the same port - lets make a common def

#define LD_SB_RED_Pin          (GPIO_PIN_4)
#define LD_SB_YELLOW_Pin       (GPIO_PIN_5)
#define LD_SB_GREEN_Pin        (GPIO_PIN_6)
// East Bound

// West Bound
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
