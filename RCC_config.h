/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */
/*  File name     :       RCC_config.h                                         */  
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/
#ifndef  __RCC_CONFIG_H__
#define  __RCC_CONFIG_H__

#define  HIGH   1
#define  LOW    0 
typedef enum 
{
   RCC_AHB  ,
   RCC_APB2 ,
   RCC_APB1
}tRCC_Bus ;
typedef enum 
{
	OFF ,
	ON 
}RCC_PeripheralClockState ; 
typedef enum
{  DMA1   , // AHB
   DMA2   , // AHB
   SRAM   , // AHB
   FLITF  , // AHB
   CRC    , // AHB
   FSMC   , // AHB
   SDIO   , // AHB
   AFIO   , // APB2
   IOPA   , // APB2
   IOPB   , // APB2
   IOPC   , // APB2
   IOPD   , // APB2
   IOPE   , // APB2
   IOPF   , // APB2
   IOPG   , // APB2
   ADC1   , // APB2
   ADC2   , // APB2
   TIM1   , // APB2
   SPI1   , // APB2
   TIM8   , // APB2
   USART  , // APB2
   ADC3   , // APB2
   TIM9   , // APB2
   TIM10  , // APB2
   TIM11  , // APB2
   TIM2   , // APB1
   TIM3   , // APB1
   TIM4   , // APB1
   TIM5   , // APB1
   TIM6   , // APB1
   TIM7   , // APB1
   TIM12  , // APB1
   TIM13  , // APB1
   TIM14  , // APB1
   WWD    , // APB1
   SPI2   , // APB1
   SPI3   , // APB1
   USART2 , // APB1
   USART3 , // APB1
   UART4  , // APB1
   UART5  , // APB1
   I2C1   , // APB1
   I2C2   , // APB1
   USB    , // APB1
   CAN    , // APB1
   BKP    , // APB1
   PWR    , // APB1
   DAC      // APB1 
}tRCC_PeripheralControl ;  
typedef enum 
{
  PLL_OFF ,
  PLL_ON 
}tPLL_State ;  
typedef enum
{
  HSI ,
  HSE  
}tSystem_MainCLK ; 
typedef enum 
{
 CSS_OFF , 
 CSS_ON 
}Clock_SecurityState ;  
#endif // __RCC_CONFIG_H__
