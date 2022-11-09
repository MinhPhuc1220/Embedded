/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t status = 0;
void delay_msX(uint16_t t);
void LED(unsigned char name, unsigned char x){
	switch(name){
		case 0:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, x);
			break;
		}
		case 1:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, x);
			break;
		}
		case 2:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, x);
			break;
		}
		case 3:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, x);
			break;
		}
		case 4:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, x);
			break;
		}
		case 5:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, x);
			break;
		}
		case 6:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, x);
			break;
		}
		case 7:
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, x);
			break;
		}
	}
}

void sang_het(){
	for(unsigned char i = 0; i <= 7; i++){
		LED(i,1);
	}
}

void tat_het(){
	for(unsigned char i = 0; i <= 7; i++){
		LED(i,0);
	}
}

void chop_tat(uint8_t n){
	for(uint8_t i = 0; i < n; i++){
		for(unsigned char j = 0; j <= 7; j++){
			LED(j,1);
		}
		delay_msX(200);
		for(unsigned char j = 0; j <= 7; j++){
			LED(j,0);
		}
		delay_msX(200);
	}
	status = 2;
}

void sang_duoi(){
	unsigned char sangduoi;
	tat_het();
	delay_msX(1000);
	for(sangduoi = 0; sangduoi <= 7; sangduoi++){
		LED(sangduoi,1);
		delay_msX(1000);
		LED(sangduoi,0);
	}
}

void sang_don(uint8_t n){
	unsigned char sangduoi, sangdon;
	for(uint8_t i = 0; i < n; i++){
		tat_het();
		delay_msX(100);
		for(sangdon = 7; sangdon > 0; sangdon--){
			for(sangduoi = 0; sangduoi <= sangdon; sangduoi++){
				LED(sangduoi,1);
				delay_msX(100);
				LED(sangduoi,0);
			}
			LED(sangdon,1);
		}
		LED(0,1);
		delay_msX(100);
	}
	status = 2;
}

void delay_msX(uint16_t t){
	uint16_t i;
	for(i = 0; i < t; i++){
		HAL_Delay(1);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0){
			status = 1;
			break;
		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0){
			status = 0;
			break;
		}
	}
}

void btn_sangdon(){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0){
			status = 1;
			while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0);
		}
	}
}

void btn_choptat(){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0){
		HAL_Delay(20);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0){
			status = 0;
			while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0);
		}
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	status = 2;
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	btn_choptat();
	btn_sangdon();
	if(status == 0){
		chop_tat(5);
	}else if ((status == 1)){
		sang_don(3);
	}else{
		tat_het();
	}
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PD0 PD1 PD2 PD3
                           PD4 PD5 PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
