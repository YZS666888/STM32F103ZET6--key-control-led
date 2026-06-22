#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Key.h"

void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_TypeDefStructer;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
    
    GPIO_TypeDefStructer.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_TypeDefStructer.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_TypeDefStructer.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOA,&GPIO_TypeDefStructer);
    
    GPIO_TypeDefStructer.GPIO_Pin = GPIO_Pin_15;
    GPIO_Init(GPIOG,&GPIO_TypeDefStructer);
    
    GPIO_TypeDefStructer.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC,&GPIO_TypeDefStructer);
    
    GPIO_TypeDefStructer.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOE,&GPIO_TypeDefStructer);
}

uint8_t Key_Get(void)
{  
    uint8_t keynum = 0;    
    
    if(KEY_UP == 0)
    {
        Delay_ms(15);
        if(KEY_UP == 0)
        {
            keynum = 1;
            while(KEY_UP == 0);
        }
    }
    if(KEY_DOWN == 0)
    {
        Delay_ms(15);
        if(KEY_DOWN == 0)
        {
            keynum = 2;
            while(KEY_DOWN == 0);
        }
    }
    if(KEY_LEFT == 0)
    {
        Delay_ms(15);
        if(KEY_LEFT == 0)
        {
            keynum = 3;
            while(KEY_LEFT == 0);
        }
    }
    if(KEY_RIGHT == 0)
    {
        Delay_ms(15);
        if(KEY_RIGHT == 0)
        {
            keynum = 4;
            while(KEY_RIGHT == 0);           
        }
        
    }
    
    return keynum;
}

