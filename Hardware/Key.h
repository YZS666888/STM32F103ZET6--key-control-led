#ifndef __KEY_H
#define __KEY_H

#define KEY_UP        GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
#define KEY_DOWN      GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_15)
#define KEY_LEFT      GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)
#define KEY_RIGHT     GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)

void Key_Init(void);
uint8_t Key_Get(void);

#endif
