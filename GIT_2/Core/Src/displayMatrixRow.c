/*
 * Ex9.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */
#include "main.h"
void displayMatrixRow(uint8_t value){
	switch(value){
	case 0x01:
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 0);
		break;

	case 0x02:
	    HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
	    HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 1);
	    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 0);
		break;

	case 0x03:
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 0);
	    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 1);
		break;

	case 0x04:
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 1);
		break;

	case 0x05:
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 0);
	    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 1);
		break;

	case 0x06:
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 0);
	    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 1);
		break;

	case 0x07:
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 1);
	    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 0);
		break;

	case 0x08:
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 0);
		break;

	default:
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW2_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, 1);
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, 1);
		break;
	}

}
