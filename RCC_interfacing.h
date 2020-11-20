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

void RCC_voidInit (tPLL_State  ,tSystem_MainCLK ,Clock_SecurityState ,PLL_MultibilFactor ) ;
void RCC_voidSetClockState (tRCC_Bus bus,tRCC_PeripheralControl peripheral,tPLL_State state);
#endif // __RCC_INTERFACING_H__
