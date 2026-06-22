# STM32F103ZET6 按键控制 LED

**开发板：** 100ASK_STM32F103_V12  
**MCU：** STM32F103ZE (Cortex-M3, 72MHz)  
**IDE：** Keil MDK V5 (ARM Compiler 5.06u7)

## 功能介绍

| 按键 | 功能 | 串口输出 |
|------|------|----------|
| KEY_UP (PA0) | 红灯 toggle | KEY_UP pressed |
| KEY_DOWN (PG15) | 蓝灯 toggle | KEY_DOWN pressed |
| KEY_LEFT (PC13) | 绿灯 toggle | KEY_LEFT pressed |
| KEY_RIGHT (PE3) | 全亮/全灭切换 | KEY_RIGHT pressed |

- KEY_RIGHT 通过读取 GPIO 实际输出状态判断当前是全亮还是全灭，不受单独 toggle 影响
- 串口输出通过 USART1 (PA9 TX / PA10 RX) 实现，**波特率 115200-8-N-1**

## 引脚分配

| 外设 | 引脚 | 配置 |
|------|------|------|
| LED_R (红灯) | PB0 | 推挽输出，低电平点亮 |
| LED_G (绿灯) | PB1 | 推挽输出，低电平点亮 |
| LED_B (蓝灯) | PB5 | 推挽输出，低电平点亮 |
| KEY1 (UP) | PA0 | 上拉输入，按下为低 |
| KEY2 (DOWN) | PG15 | 上拉输入，按下为低 |
| KEY3 (LEFT) | PC13 | 上拉输入，按下为低 |
| KEY4 (RIGHT) | PE3 | 上拉输入，按下为低 |
| USART1_TX | PA9 | 复用推挽输出 |
| USART1_RX | PA10 | 浮空输入 |

## 更新记录

**2026-06-22 — 初始版本**
- 实现 KEY_UP/DOWN/LEFT 单独 toggle 对应 LED
- KEY_RIGHT 全亮/全灭切换（依据实际灯状态判断）

**2026-06-22 — 添加串口打印**
- 新增 USART1 串口通信，波特率 115200
- 每次按键在串口打印按键名称
- 新增 Hardware/Serial.c + Hardware/Serial.h

## 使用方式

1. 用 Keil MDK 打开 Project.uvprojx
2. 编译并下载到开发板
3. 用 USB 线连接开发板到电脑
4. 打开串口助手，选择对应 COM 口，设置 115200-8-N-1
5. 按板上的按键测试