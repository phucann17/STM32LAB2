/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int status = 1;
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
	switch(index){
		  		  case 0:
		  		  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
		  		  	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, 1);
		  		  	break;
		  		  case 1:
		  			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, 1);
		  			HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
		  		  	break;
		  		  case 2:
		  			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, 1);
		  			HAL_GPIO_WritePin(GPIOA, EN2_Pin, 0);
		  			break;
		  		  case 3:
		  			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, 1);
		  			HAL_GPIO_WritePin(GPIOA, EN3_Pin, 0);
		  			break;
		  		  default:
		  		  	break;
	}
	display7SEG(led_buffer[index]);
}

void updateClockBuffer(int h, int m){
	led_buffer[0] = h / 10;
	led_buffer[1] = h % 10;
	led_buffer[2] = m / 10;
	led_buffer[3] = m % 10;
}

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08};
void updateLEDMatrix (int index){
	switch(index){
			case 0:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 0);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 0);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 0);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 0);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 0);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 0);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 0);
				break;
			default:
				HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 1);
	          	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 1);
				break;
		}
		displayMatrixRow(matrix_buffer[index]);
}

////Biểu diễn chữ A
//  	1 1 1 1
//    1 1 1 1 1 1
//  1 1 	    1 1
//  1 1 	    1 1
//  1 1 1 1 1 1 1 1
//  1 1 1 1 1 1 1 1
//  1 1 	    1 1
//  1 1 	    1 1


void shiftLeft(){
	uint8_t tmp = matrix_buffer[0];
	for(int i = 0; i < 7; ++i){
		matrix_buffer[i] = matrix_buffer[i+1];
	}
	matrix_buffer[7] = tmp;
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, 1);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, 0);

  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer1(500);
  setTimer2(250);
  setTimer3(1000);
  setTimer4(10);
  int hour = 23, minute = 59, second = 50;
  while (1)
  {
//	  //EX1
//	  if(timer1_flag == 1){
//		  switch(status){
//		  	  case 1:
//		  		  display7SEG(status++);
//		  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
//		  		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
//		  		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//		  		  break;
//		  	  case 2:
//		  		  display7SEG(status++);
//		  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
//		  		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
//		  		  status = 1;
//		  		  break;
//		  	  default:
//		  		  break;
//		  }
//		  setTimer1(500);
//	  }

//	  //EX2
//	  if(timer1_flag == 1){
//		  switch(status){
//	  		  case 1:
//	  		  	display7SEG(status++);
//	  		  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
//	  		  	HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);
//	  		  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  		  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//	  		  	break;
//	  		  case 2:
//	  		  	display7SEG(status++);
//	  		  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
//	  		  	HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
//	  		  	break;
//	  		  case 3:
//	  			display7SEG(status++);
//	  			HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
//	  			HAL_GPIO_WritePin(GPIOA, EN2_Pin, 0);
//	  			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//	  			break;
//	  		  case 4:
//	  			display7SEG(0);
//	  			HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
//	  			HAL_GPIO_WritePin(GPIOA, EN3_Pin, 0);
//	  			status = 1;
//	  			break;
//	  		  default:
//	  		  	break;
//	  		  }
//	  		  setTimer1(500);
//	  	  }


//	  //EX3
//	  if(timer3_flag == 1){
//	  	 setTimer3(1000);
//	  	 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  	 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//	  }
//	  if(timer1_flag == 1){
//	  	 if(index_led >= MAX_LED) index_led = 0;
//	  	 update7SEG(index_led++);
//	  	 setTimer1(500);
//	  }

//	  //Ex4
//	  if(timer3_flag == 1){
//	  	 setTimer3(1000);
//	  	 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  	 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//	  }
//	  if(timer2_flag == 1){
//	  	 if(index_led >= MAX_LED) index_led = 0;
//	  	 update7SEG(index_led++);
//	  	 setTimer2(250);
//	  }

//	  //Ex5
//	  second++;
//	  if(second >= 60){
//		  second = 0;
//		  minute++;
//	  }
//	  if(minute >= 60){
//		  minute = 0;
//		  hour++;
//	  }
//	  if(hour >= 24){
//		  hour = 0;
//	  }
//	  updateClockBuffer(hour, minute);
//	  if(index_led >= MAX_LED) index_led = 0;
//	  update7SEG(index_led++);
//	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//	  HAL_Delay(1000);


//	  	  //Ex7
//	  if(timer3_flag == 1){
//		  setTimer3(1000);
//		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//	  	  second++;
//	  	  if(second >= 60){
//	  		  second = 0;
//	  		  minute++;
//	  	  }
//	  	  if(minute >= 60){
//	  		  minute = 0;
//	  		  hour++;
//	  	  }
//	  	  if(hour >= 24){
//	  		  hour = 0;
//	  	  }
//	  }
//	  if(timer2_flag == 1){
//	  	  updateClockBuffer(hour, minute);
//	  	  setTimer2(250);
//	  	  if(index_led >= MAX_LED) index_led = 0;
//	  	  update7SEG(index_led++);
//	  }


//	  //Ex9:
//	  if(timer4_flag == 1){
//		  if(index_led_matrix >= MAX_LED_MATRIX) index_led_matrix = 0;
//	      setTimer4(10);
//	      updateLEDMatrix(index_led_matrix++);
//	  }

//	  //Ex10:
//	  if(timer4_flag == 1){
//		  updateLEDMatrix(index_led_matrix++);
//		  if(index_led_matrix > MAX_LED_MATRIX){
//			  index_led_matrix = 0;
//			  shiftLeft();
//		  }
//		  setTimer4(10);
//	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
int cnt = 50;
int cnt2 = 25;
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim){
//	cnt--;
//	if(cnt <= 0){
//		cnt = 50;
//
//		//EX1
//		switch(status){
//			case 1:
//				display7SEG(status);
//				HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
//				HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//				status++;
//				break;
//			case 2:
//				display7SEG(status);
//				HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
//				HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
//				status = 1;
//				break;
//			default:
//				break;
//		}
//	}

//		//EX2
//		cnt--;
//		if(cnt <= 0){
//			cnt = 50;
//		switch(status){
//			case 1:
//			  	display7SEG(status++);
//			  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
//			  	HAL_GPIO_WritePin(GPIOA, EN3_Pin, 1);
//			  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//			  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//			  	break;
//			case 2:
//			  	display7SEG(status++);
//			  	HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
//			  	HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
//			  	break;
//			case 3:
//			  	display7SEG(status++);
//			  	HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
//			  	HAL_GPIO_WritePin(GPIOA, EN2_Pin, 0);
//			  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//			  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//			  	break;
//			case 4:
//			  	display7SEG(0);
//			  	HAL_GPIO_WritePin(GPIOA, EN2_Pin, 1);
//			  	HAL_GPIO_WritePin(GPIOA, EN3_Pin, 0);
//			  	status = 1;
//			  	break;
//			default:
//			  	break;
//		}
//		}

//		//EX3:
//		cnt--;
//		if(cnt <= 0){
//			cnt = 50;
//		if(index_led >= MAX_LED) index_led = 0;
//		switch(index_led){
//			 case 0:
//				 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//				 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//			  	 update7SEG(index_led++);
//			  	 break;
//			 case 1:
//			  	 update7SEG(index_led++);
//			  	 break;
//			 case 2:
//				 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//				 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//			  	 update7SEG(index_led++);
//			  	 break;
//			 case 3:
//			  	 update7SEG(index_led++);
//			  	 break;
//			 default:
//			  	 break;
//		}
//		}

//		cnt2--;
//		if(cnt2 <= 0){
//		   cnt2 = 25;
//		//EX4
//		if(index_led >= MAX_LED) index_led = 0;
//  		switch(index_led){
//  	  		  case 0:
//  	  		  	update7SEG(index_led++);
//  	  		  	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
//  	  			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//  	  		  	break;
//  	  		  case 1:
//  	  			update7SEG(index_led++);
//  	  		  	break;
//  	  		  case 2:
//  	  			update7SEG(index_led++);
//  	  			break;
//  	  		  case 3:
//  	  			update7SEG(index_led++);
//  	  			break;
//  	  		  default:
//  	  		  	break;
//  	  	}
//		}

	//EX 7-8-9-10
	timerRun();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
