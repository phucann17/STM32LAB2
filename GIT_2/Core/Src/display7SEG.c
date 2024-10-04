/*
 * Ex1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Admin
 */
#include "main.h";
void display7SEG(int num){
	switch(num){
		  	  case 0:
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin, 0);
		  		  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
		  		  break;
		  	  case 1:
		  		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, 0);
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin | SEG3_Pin, 1);
		  		  break;
		  	  case 2:
		  		  HAL_GPIO_WritePin(GPIOB, SEG2_Pin | SEG5_Pin, 1);
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG4_Pin | SEG1_Pin | SEG6_Pin | SEG3_Pin, 0);
		  		  break;
		  	  case 3:
		  		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin | SEG5_Pin, 1);
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG1_Pin | SEG6_Pin | SEG3_Pin, 0);
		  		  break;
		  	  case 4:
		  		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin | SEG3_Pin | SEG0_Pin, 1);
		  		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin | SEG5_Pin | SEG6_Pin, 0);
		  		  break;
		  	  case 5:
		  		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin | SEG1_Pin, 1);
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin | SEG5_Pin, 0);
		  		  break;
		  	  case 6:
		  		  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin | SEG5_Pin | SEG4_Pin, 0);
		  		  break;
		  	  case 7:
		  		  HAL_GPIO_WritePin(GPIOB, SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
		  		  break;
		  	  case 8:
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
		  		  break;
		  	  case 9:
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
		  		  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, 1);
		  		  break;
		  	  default:
		  		  HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
		  		  break;
		  }
}
