#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_TypeDefStructer;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    
    GPIO_TypeDefStructer.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_TypeDefStructer.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5;
    GPIO_TypeDefStructer.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_TypeDefStructer);
    
    GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5);
}

/*
void RLED_ON(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_0);
}

void BLED_ON(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_1);
}

void GLED_ON(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_5);
}

void RLED_OFF(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_0);
}

void BLED_OFF(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_1);
}

void GLED_OFF(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_5);
}*/

void RLED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_0) == 0)		
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_0);					
	}
	else													
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);					
	}
}

void BLED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1) == 0)		
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_1);					
	}
	else													
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);					
	}
}

void GLED_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5) == 0)		
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);					
	}
	else													
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);					
	}
}

void LED_ON(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_0);
    GPIO_ResetBits(GPIOB,GPIO_Pin_1);
    GPIO_ResetBits(GPIOB,GPIO_Pin_5);	
}

void LED_OFF(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_0);
    GPIO_SetBits(GPIOB,GPIO_Pin_1);
    GPIO_SetBits(GPIOB,GPIO_Pin_5);	
}
