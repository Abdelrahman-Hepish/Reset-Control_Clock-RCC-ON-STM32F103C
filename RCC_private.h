/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */ 
/*  File name     :       RCC_private.h                                        */
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/

#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__

#define RCC_BASE_ADDRESS                       0x40021000
#define RCC_CONTROL_REG_OFFSET                 0x00
#define RCC_CONFIGUR_REG_OFFSET                0x04
#define RCC_INTERRUPT_REG_OFFSET               0x08
#define RCC_APB2_REST_REG_OFFSET               0x0C
#define RCC_APB1_REST_REG_OFFSET               0x010
#define RCC_AHB_ENABLE_REG_OFFSET              0x14
#define RCC_APB2_ENABLE_REG_OFFSET             0x18
#define RCC_APB1_ENABLE_REG_OFFSET             0x1C
#define RCC_BACKUP_DOMAIN_CONTROL_REG_OFFSET   0x20
#define RCC_CONTROL_STATUS_REG_OFFSET          0x24

#define RCC_CR        *((volatile u32*) (RCC_BASE_ADDRESS + RCC_CONTROL_REG_OFFSET))
#define RCC_CFGR      *((volatile u32*) (RCC_BASE_ADDRESS + RCC_CONFIGUR_REG_OFFSET))
#define RCC_CIR       *((volatile u32*) (RCC_BASE_ADDRESS + RCC_INTERRUPT_REG_OFFSET))
#define RCC_APB2RSTR  *((volatile u32*) (RCC_BASE_ADDRESS + RCC_APB2_REST_REG_OFFSET))
#define RCC_APB1RSTR  *((volatile u32*) (RCC_BASE_ADDRESS + RCC_APB1_REST_REG_OFFSET))
#define RCC_AHBENR    *((volatile u32*) (RCC_BASE_ADDRESS + RCC_AHB_ENABLE_REG_OFFSET))
#define RCC_APB2ENR   *((volatile u32*) (RCC_BASE_ADDRESS + RCC_APB2_ENABLE_REG_OFFSET))
#define RCC_APB1ENR   *((volatile u32*) (RCC_BASE_ADDRESS + RCC_APB1_ENABLE_REG_OFFSET))
#define RCC_BDCR      *((volatile u32*) (RCC_BASE_ADDRESS + RCC_BACKUP_DOMAIN_CONTROL_REG_OFFSET))
#define RCC_CSR       *((volatile u32*) (RCC_BASE_ADDRESS + RCC_CONTROL_STATUS_REG_OFFSET))

/* Clock Control Register (RCC_CR) */ 
#define   HSION                    0
#define   HSIRDY                   1
#define   HSITRIM_0                3
#define   HSITRIM_1                4
#define   HSITRIM_2                5
#define   HSITRIM_3                6
#define   HSITRIM_4                7
#define   HSICAL_0                 8
#define   HSICAL_1                 9
#define   HSICAL_2                10 
#define   HSICAL_3                11
#define   HSICAL_4                12
#define   HSICAL_5                13
#define   HSICAL_6                14
#define   HSICAL_7                15
#define   HSEON                   16
#define   HSERDY                  17
#define   HSEBYP                  18
#define   CSSON                   19
#define   PLLON                   24
#define   PLLRDY                  25

/* Clock configuration register (RCC_CFGR) */ 
#define   SW_0                     0
#define   SW_1                     1
#define   SWS_0                    2
#define   SWS_1                    3
#define   HPRE_0                   4
#define   HPRE_1                   5
#define   HPRE_2                   6
#define   HPRE_3                   7
#define   PPRE1_0                  8
#define   PPRE1_1                  9
#define   PPRE1_2                 10 
#define   PPRE2_0                 11
#define   PPRE2_1                 12
#define   PPRE2_3                 13
#define   ADCPRE_0                14
#define   ADCPRE_1                15
#define   PLLSRC                  16
#define   PLLXTPRE                17
#define   PLLMUL_0                18
#define   PLLMUL_1                19
#define   PLLMUL_2                20
#define   PLLMUL_3                21
#define   USBPRE                  22
#define   MCO_0                   24
#define   MCO_1                   25
#define   MCO_2                   26

/* PLLMUL: PLL multiplication factor */ 
#define   PLL_SHIFT_OFFSET       18
#define   CLK_X_2                0X0
#define   CLK_X_3                0X1
#define   CLK_X_4                0X2
#define   CLK_X_5                0X3
#define   CLK_X_6                0X4
#define   CLK_X_7                0X5
#define   CLK_X_8                0X6
#define   CLK_X_9                0X7
#define   CLK_X_10               0X8
#define   CLK_X_11               0X9
#define   CLK_X_12               0XA
#define   CLK_X_13               0XB
#define   CLK_X_14               0XC
#define   CLK_X_15               0XD
#define   CLK_X_16               0XE



#endif //__RCC_PRIVATE_H__
