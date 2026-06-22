#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "LED.h"
#include "Serial.h"


int main(void)
{
    LED_Init();
    Key_Init();
    Serial_Init();

    while(1)
    {       
        uint8_t num =  Key_Get();
        if(num == 1)
        {
            Serial_SendString("KEY_UP pressed\r\n");
            RLED_Turn();
        }
        else if(num == 2)
        {
            Serial_SendString("KEY_DOWN pressed\r\n");
            BLED_Turn();
        }
        else if(num == 3)
        {
            Serial_SendString("KEY_LEFT pressed\r\n");
            GLED_Turn();
        }
        else if(num == 4)
        {
            Serial_SendString("KEY_RIGHT pressed\r\n");
            if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_0) == 0 ||
                GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1) == 0 ||
                GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5) == 0)
            {
                LED_OFF();      // 有灯亮着 → 全灭
            }
            else
            {
                LED_ON();       // 全灭 → 全亮
            }
        }
    }
    
    
    //return 0;

}