#include "stm32f4xx.h"

int main(void)
{
	RCC->AHB1ENR = RCC->AHB1ENR | (0b1); // Enabling port A
	
	GPIOA->MODER &= ~(0xa); // Resetting the values
	GPIOA->MODER |=  0xb; // Setting up Pin 5 AS Output
	
	GPIOA->OTYPER &= ~(0x01);
	GPIOA->ODR |= ~(0b0101);
}