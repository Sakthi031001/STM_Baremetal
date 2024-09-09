#include <stm32f446xx.h>

void delay(long d)
{
	while(d--);
}

void printdata(unsigned char data) //8bit hexadecimal
{
	// Bit 0 => a = PA10
	if((data&0x01) == 0x01){GPIOA->ODR |= (1<<10);}
	else{GPIOA->ODR &= (~(1<<10));}
	// Bit 1 => b = PB3
	if((data&0x02) == 0x02){GPIOB->ODR |= (1<<3);}
	else{GPIOB->ODR &= (~(1<<3));}
	// Bit 2 => c = PB5
	if((data&0x04) == 0x04){GPIOB->ODR |= (1<<5);}
	else{GPIOB->ODR &= (~(1<<5));}
	// Bit 3 => d = PB4
	if((data&0x08) == 0x08){GPIOB->ODR |= (1<<4);}
	else{GPIOB->ODR &= (~(1<<4));}
	// Bit 4 => e = PB10
	if((data&0x10) == 0x10){GPIOB->ODR |= (1<<10);}
	else{GPIOB->ODR &= (~(1<<10));}
	// Bit 5 => f = PA8
	if((data&0x20) == 0x20){GPIOA->ODR |= (1<<8);}
	else{GPIOA->ODR &= (~(1<<8));}
	// Bit 6 => g = PA9
	if((data&0x40) == 0x40){GPIOA->ODR |= (1<<9);}
	else{GPIOA->ODR &= (~(1<<9));}
	// Bit 7 => h   dp = PC7
	if((data&0x80) == 0x80){GPIOC->ODR |= (1<<7);}
	else{GPIOC->ODR &= (~(1<<7));}
		
}

int main(void)
{
	//clock of GPIO's Enabled for GPIOA, GPIOB, GPIOC
	RCC->AHB1ENR = RCC->AHB1ENR | (1<<0) | (1<<1) | (1<<2);
	//setting all 7 segment terminals as output
	/* here is the pin config 
		segment pin		GPIO pin
			a							PA10
			b							PB3
			c							PB5
			d							PB4
			e							PB10
			f							PA8
			g							PA9
			dp						PC7
	*/ 
	GPIOA->MODER = GPIOA->MODER | (1<<16) | (1<<18) | (1<<20);
	GPIOA->MODER = GPIOA->MODER & (~(1<<17)) & (~(1<<19)) & (~(1<<21));//PA8,PA9,PA10 -> Output
	
	GPIOB->MODER = GPIOB->MODER | (1<<6) | (1<<8) | (1<<10) | (1<<20);
	GPIOB->MODER = GPIOB->MODER & (~(1<<7)) & (~(1<<9)) & (~(1<<11)) & (~(1<<21)); //PB3,PB4,PB5,PB10 -> Output
	
	GPIOC->MODER = GPIOC->MODER | (1<<14);
	GPIOC->MODER = GPIOC->MODER & (~(1<<15));//PC7 -> Output
	
	
	while(1)
	{
		// Common Cathode
		// 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f
		printdata(0x3f);
		delay(500000);delay(500000);
		printdata(0x06);
		delay(500000);delay(500000);
		printdata(0x5b);
		delay(500000);delay(500000);
		printdata(0x4f);
		delay(500000);delay(500000);
		printdata(0x66);
		delay(500000);delay(500000);
		printdata(0x6d);
		delay(500000);delay(500000);
		printdata(0x7c);
		delay(500000);delay(500000);
		printdata(0x07);
		delay(500000);delay(500000);
		printdata(0x7f);
		delay(500000);delay(500000);
		printdata(0x6f);
		delay(500000);delay(500000);
	}
}