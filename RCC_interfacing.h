/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */
/*  File name     :       RCC_interfacing.h                                    */  
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/

#ifndef __RCC_INTERFACING_H__
#define __RCC_INTERFACING_H__
#include "RCC_config.h"

void RCC_voidInit (tPLL_State pll_state ,tSystem_MainCLK sys_clk ,Clock_SecurityState css_state  ) ; 
void RCC_voidSetClockState (Bus bus,Peripheral peripheral,State state);       
#endif // __RCC_INTERFACING_H__