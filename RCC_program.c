/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */ 
/*  File name     :       RCC_program.c                                        */ 
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interfacing.h"
#include "RCC_private.h"
#include "RCC_config.h"

static void RCC_voidResetReversed(tRCC_Bus bus);

void RCC_voidInit (tPLL_State pll_state ,tSystem_MainCLK sys_clk ,Clock_SecurityState css_state ,PLL_MultibilFactor factor)
{
	switch(sys_clk)
	{
		case HSE : 
		  SET_REGISTER_PIN(RCC_CR,HSEBYP,HIGH) ;
		  SET_REGISTER_PIN(RCC_CR,HSEON,HIGH) ;
		  SET_REGISTER_PIN(RCC_CFGR,SW_0,HIGH) ;
		  SET_REGISTER_PIN(RCC_CFGR,SW_1,LOW) ;
		  while(READ_REGISTER_PIN(RCC_CR,HSERDY) == LOW ) ; // wait untill the HSE becomes ready
		  break ; // Break for HSE 
		case HSI : 
		  SET_REGISTER_PIN(RCC_CR,HSION,HIGH) ;
		  SET_REGISTER_PIN(RCC_CFGR,SW_0,LOW) ;
		  SET_REGISTER_PIN(RCC_CFGR,SW_1,LOW) ;
		  while(READ_REGISTER_PIN(RCC_CR,HSIRDY) == LOW ) ; // wait untill the HSI becomes ready
		  break ; // Break for HSE 
		default : /* shoud not be here */
		  break ; 
	}
	switch(css_state)
	{
	    case CSS_ON :
		  SET_REGISTER_PIN(RCC_CR,CSSON,HIGH) ;
		  break ; 
		case CSS_OFF :
		  SET_REGISTER_PIN(RCC_CR,CSSON,LOW) ;
		  break ; 
		default : /* shoud not be here */
		  break ; 
	}
	switch(pll_state)
	{
		case PLL_ON : 
		  SET_REGISTER_PIN(RCC_CR,PLLON,LOW) ; // because These bits can be written only when PLL is disabled.
		  switch(sys_clk)
	      {
		     case HSE : 
		        SET_REGISTER_PIN(RCC_CFGR,PLLSRC,HIGH) ;
				 /* Here i have to choose the proper PLLXTPRE but i am going to make it high */ 
                SET_REGISTER_PIN(RCC_CFGR,PLLXTPRE,HIGH) ; 				 
		        break ; // Break for HSE 
		     case HSI : 
		        SET_REGISTER_PIN(RCC_CFGR,PLLSRC,LOW) ;
		        break ; // Break for HSE 
		     default : /* shoud not be here */
		        break ; 
	      }
		  switch (factor)
		  {
			case PLL_IP_X_1  :                                           ; break ;                         
	        case PLL_IP_X_2  : RCC_CFGR |= (CLK_X_2 <<PLL_SHIFT_OFFSET)  ; break ; 
	        case PLL_IP_X_3  : RCC_CFGR |= (CLK_X_3 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_4  : RCC_CFGR |= (CLK_X_4 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_5  : RCC_CFGR |= (CLK_X_5 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_6  : RCC_CFGR |= (CLK_X_6 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_7  : RCC_CFGR |= (CLK_X_7 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_8  : RCC_CFGR |= (CLK_X_8 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_9  : RCC_CFGR |= (CLK_X_9 <<PLL_SHIFT_OFFSET)  ; break ;
	        case PLL_IP_X_10 : RCC_CFGR |= (CLK_X_10 <<PLL_SHIFT_OFFSET) ; break ;
	        case PLL_IP_X_11 : RCC_CFGR |= (CLK_X_11 <<PLL_SHIFT_OFFSET) ; break ;
	        case PLL_IP_X_12 : RCC_CFGR |= (CLK_X_12 <<PLL_SHIFT_OFFSET) ; break ;
	        case PLL_IP_X_13 : RCC_CFGR |= (CLK_X_13 <<PLL_SHIFT_OFFSET) ; break ;
	        case PLL_IP_X_14 : RCC_CFGR |= (CLK_X_14 <<PLL_SHIFT_OFFSET) ; break ;
	        case PLL_IP_X_15 : RCC_CFGR |= (CLK_X_15 <<PLL_SHIFT_OFFSET) ; break ;
	        case PLL_IP_X_16 : RCC_CFGR |= (CLK_X_16 <<PLL_SHIFT_OFFSET) ; break ;
            default : /* shoud not be here */                              break ; 
		  }		
          SET_REGISTER_PIN(RCC_CFGR,SW_0,LOW) ;
		  SET_REGISTER_PIN(RCC_CFGR,SW_1,HIGH) ;		  
		  SET_REGISTER_PIN(RCC_CR,PLLON,HIGH) ;
		  while(READ_REGISTER_PIN(RCC_CR,HSERDY) == LOW ) ; // wait untill the PLL becomes HIGH		 
		break ; 
		case PLL_OFF : 
		  SET_REGISTER_PIN(RCC_CR,PLLON,LOW) ;
		  while(READ_REGISTER_PIN(RCC_CR,PLLRDY) == HIGH ) ; // wait untill the PLL becomes LOW
		  break ; 
		default : /* shoud not be here */
		  break ; 
	}
	/* set Microcontroller output as 000 */ 
	   SET_REGISTER_PIN(RCC_CFGR,MCO_0,LOW);
	   SET_REGISTER_PIN(RCC_CFGR,MCO_1,LOW);
	   SET_REGISTER_PIN(RCC_CFGR,MCO_2,LOW);
}
void RCC_voidSetPeripheralClockState (tRCC_Bus bus,tRCC_PeripheralControl peripheral,RCC_PeripheralClockState state)
{
	RCC_voidResetReversed(bus) ; 
	switch(bus)
	{
		case RCC_AHB :
		              switch(peripheral)
					  {
						  case DMA1     : SET_REGISTER_PIN(RCC_AHBENR,0,state)   ; break ;
						  case DMA2     : SET_REGISTER_PIN(RCC_AHBENR,1,state)   ; break ;
						  case SRAM     : SET_REGISTER_PIN(RCC_AHBENR,2,state)   ; break ;
						  case FLITF    : SET_REGISTER_PIN(RCC_AHBENR,4,state)   ; break ;
						  case CRC      : SET_REGISTER_PIN(RCC_AHBENR,6,state)   ; break ;
						  case FSMC     : SET_REGISTER_PIN(RCC_AHBENR,8,state)   ; break ;      
						  case SDIO     : SET_REGISTER_PIN(RCC_AHBENR,10,state)  ; break ; 
						  default       :  /* should not be here */ break ;
					  }
		break ; // for RCC_AHB
		case RCC_APB2 :
		               switch(peripheral)
					   {
						  case AFIO     : SET_REGISTER_PIN(RCC_APB2ENR,0,state)   ; break ;
						  case IOPA     : SET_REGISTER_PIN(RCC_APB2ENR,2,state)   ; break ;
						  case IOPB     : SET_REGISTER_PIN(RCC_APB2ENR,3,state)   ; break ;
						  case IOPC     : SET_REGISTER_PIN(RCC_APB2ENR,4,state)   ; break ;
						  case IOPD     : SET_REGISTER_PIN(RCC_APB2ENR,5,state)   ; break ;
						  case IOPE     : SET_REGISTER_PIN(RCC_APB2ENR,6,state)   ; break ;      
						  case IOPF     : SET_REGISTER_PIN(RCC_APB2ENR,7,state)   ; break ; 
						  case IOPG     : SET_REGISTER_PIN(RCC_APB2ENR,8,state)   ; break ;
						  case ADC1     : SET_REGISTER_PIN(RCC_APB2ENR,9,state)   ; break ;
						  case ADC2     : SET_REGISTER_PIN(RCC_APB2ENR,10,state)  ; break ;
						  case TIM1     : SET_REGISTER_PIN(RCC_APB2ENR,11,state)  ; break ;
						  case SPI1     : SET_REGISTER_PIN(RCC_APB2ENR,12,state)  ; break ;
						  case TIM8     : SET_REGISTER_PIN(RCC_APB2ENR,13,state)  ; break ;      
						  case USART    : SET_REGISTER_PIN(RCC_APB2ENR,14,state)  ; break ;
						  case ADC3     : SET_REGISTER_PIN(RCC_APB2ENR,15,state)  ; break ;
						  case TIM9     : SET_REGISTER_PIN(RCC_APB2ENR,19,state)  ; break ;
						  case TIM10    : SET_REGISTER_PIN(RCC_APB2ENR,20,state)  ; break ;      
						  case TIM11    : SET_REGISTER_PIN(RCC_APB2ENR,21,state)  ; break ;
						  default       : /* should not be here */ break ;
					   }
		
		break ; // RCC_APB2
		case RCC_APB1 :
	                   switch(peripheral)
					   {
						  case TIM2   : SET_REGISTER_PIN(RCC_APB1ENR,0,state)   ; break ; 
                          case TIM3   : SET_REGISTER_PIN(RCC_APB1ENR,1,state)   ; break ;
                          case TIM4   : SET_REGISTER_PIN(RCC_APB1ENR,2,state)   ; break ; 
                          case TIM5   : SET_REGISTER_PIN(RCC_APB1ENR,3,state)   ; break ;
                          case TIM6   : SET_REGISTER_PIN(RCC_APB1ENR,4,state)   ; break ; 
                          case TIM7   : SET_REGISTER_PIN(RCC_APB1ENR,5,state)   ; break ; 
                          case TIM12  : SET_REGISTER_PIN(RCC_APB1ENR,6,state)   ; break ;
                          case TIM13  : SET_REGISTER_PIN(RCC_APB1ENR,7,state)   ; break ; 
                          case TIM14  : SET_REGISTER_PIN(RCC_APB1ENR,8,state)   ; break ; 
                          case WWD    : SET_REGISTER_PIN(RCC_APB1ENR,11,state)  ; break ;
                          case SPI2   : SET_REGISTER_PIN(RCC_APB1ENR,14,state)  ; break ; 
                          case SPI3   : SET_REGISTER_PIN(RCC_APB1ENR,15,state)  ; break ;
                          case USART2 : SET_REGISTER_PIN(RCC_APB1ENR,17,state)  ; break ; 
                          case USART3 : SET_REGISTER_PIN(RCC_APB1ENR,18,state)  ; break ;
                          case UART4  : SET_REGISTER_PIN(RCC_APB1ENR,19,state)  ; break ;
                          case UART5  : SET_REGISTER_PIN(RCC_APB1ENR,20,state)  ; break ;
                          case I2C1   : SET_REGISTER_PIN(RCC_APB1ENR,21,state)  ; break ;
                          case I2C2   : SET_REGISTER_PIN(RCC_APB1ENR,22,state)  ; break ;
                          case USB    : SET_REGISTER_PIN(RCC_APB1ENR,23,state)  ; break ;
                          case CAN    : SET_REGISTER_PIN(RCC_APB1ENR,25,state)  ; break ;
                          case BKP    : SET_REGISTER_PIN(RCC_APB1ENR,27,state)  ; break ;
                          case PWR    : SET_REGISTER_PIN(RCC_APB1ENR,28,state)  ; break ;
                          case DAC    : SET_REGISTER_PIN(RCC_APB1ENR,29,state)  ; break ;
                          default     : /* should not be here */ break ;
					   }
		break ; // RCC_APB1
	default : /* shoud not be herer */   break ;
	}
}
// i want thins funcion to be static 
static void RCC_voidResetReversed(tRCC_Bus bus)
{
switch(bus)
	{
		case RCC_AHB :
		RCC_AHBENR  &= 0x00000557 ;
		break ; 
		case RCC_APB2 :
		RCC_APB2ENR &=  0x0038FFFD ; 
		break ; 
		case RCC_APB1 :
		RCC_APB1ENR &= 0x3AFEC9FF ; 
		break ;
		default :
		/* shoud not be herer */
		break ; 
	}
	
}
