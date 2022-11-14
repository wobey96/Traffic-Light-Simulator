/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for mySystemTimer */
osTimerId_t mySystemTimerHandle;
const osTimerAttr_t mySystemTimer_attributes = {
  .name = "mySystemTimer"
};
/* Definitions for myOneShotTimer */
osTimerId_t myOneShotTimerHandle;
const osTimerAttr_t myOneShotTimer_attributes = {
  .name = "myOneShotTimer"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void mySystemTimerCallBack(void *argument);
void myOneShotTimerCallBack(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of mySystemTimer */
  mySystemTimerHandle = osTimerNew(mySystemTimerCallBack, osTimerPeriodic, NULL, &mySystemTimer_attributes);

  /* creation of myOneShotTimer */
  myOneShotTimerHandle = osTimerNew(myOneShotTimerCallBack, osTimerOnce, NULL, &myOneShotTimer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */

	osTimerStart(mySystemTimerHandle, 1000);   //TICK_RATE_HZ is 1000, so 1000 ticks is a second
	osTimerStart(myOneShotTimerHandle, 10000); //TICK_RATE_HZ is 1000, so 10000 ticks is 10 seconds

  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* mySystemTimerCallBack function */
void mySystemTimerCallBack(void *argument)
{
  /* USER CODE BEGIN mySystemTimerCallBack */

	HAL_GPIO_TogglePin(LD2_GPIO_Port,  LD2_Pin);
	HAL_GPIO_TogglePin(led_NB_RED_GPIO_Port,  led_NB_RED_Pin | led_NB_YELLOW_Pin );

  /* USER CODE END mySystemTimerCallBack */
}

/* myOneShotTimerCallBack function */
void myOneShotTimerCallBack(void *argument)
{
  /* USER CODE BEGIN myOneShotTimerCallBack */

	osTimerStop(mySystemTimerHandle);
	HAL_GPIO_WritePin(led_NB_RED_GPIO_Port,  led_NB_RED_Pin | led_NB_YELLOW_Pin, GPIO_PIN_RESET );
	HAL_GPIO_WritePin(led_NB_RED_GPIO_Port,  led_NB_GREEN_Pin, GPIO_PIN_SET );

  /* USER CODE END myOneShotTimerCallBack */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
