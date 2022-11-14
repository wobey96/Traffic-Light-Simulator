/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

void CUSTOM_GPIO_Init()
{
	//---------------------------------------North Bound---------------------------------------
    //Init NB LED's
    GPIO_InitTypeDef GPIO_InitStructNB = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LD_NB_GPIO_Port, LD_NB_RED_Pin|LD_NB_YELLOW_Pin|LD_NB_GREEN_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStructNB.Pin = LD_NB_RED_Pin|LD_NB_YELLOW_Pin|LD_NB_GREEN_Pin;
    GPIO_InitStructNB.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructNB.Pull = GPIO_NOPULL;
    GPIO_InitStructNB.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LD_NB_GPIO_Port, &GPIO_InitStructNB);

    //---------------------------------------South Bound---------------------------------------
    //Init SB LED's
    GPIO_InitTypeDef GPIO_InitStructSB = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LD_SB_GPIO_Port, LD_SB_RED_Pin|LD_SB_YELLOW_Pin|LD_SB_GREEN_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStructSB.Pin = LD_SB_RED_Pin|LD_SB_YELLOW_Pin|LD_SB_GREEN_Pin;
    GPIO_InitStructSB.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructSB.Pull = GPIO_NOPULL;
    GPIO_InitStructSB.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LD_SB_GPIO_Port, &GPIO_InitStructSB);

}
/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, led_NB_RED_Pin|led_NB_YELLOW_Pin|led_NB_GREEN_Pin|led_WB_RED_Pin
                          |led_WB_YELLOW_Pin|led_WB_GREEN_Pin|led_SB_RED_Pin|led_SB_YELLOW_Pin
                          |led_SB_GREEN_Pin|led_EB_RED_Pin|led_EB_YELLOW_Pin|led_EB_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin
                           PCPin PCPin PCPin PCPin
                           PCPin PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = button_NB_Sensor_Pin|button_SB_Sensor_Pin|button_EB_Sensor_Pin|button_WB_Sensor_Pin
                          |button_BTN1_Pin|button_BTN2_Pin|button_BTN3_Pin|button_BTN4_Pin
                          |button_BTN5_Pin|button_BTN6_Pin|button_BTN7_Pin|button_BTN8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin PBPin PBPin PBPin
                           PBPin PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = led_NB_RED_Pin|led_NB_YELLOW_Pin|led_NB_GREEN_Pin|led_WB_RED_Pin
                          |led_WB_YELLOW_Pin|led_WB_GREEN_Pin|led_SB_RED_Pin|led_SB_YELLOW_Pin
                          |led_SB_GREEN_Pin|led_EB_RED_Pin|led_EB_YELLOW_Pin|led_EB_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
