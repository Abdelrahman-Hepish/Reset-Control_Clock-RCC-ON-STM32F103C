/*******************************************************************************/
/*  Author        :       Abdelrahman Mohammed Hepish                          */ 
/*  File name     :       RCC_private.h                                        */
/*  Version       :       1.0                                                  */ 
/*  Date          :       11/11/2020                                           */
/*  Github        :       https://github.com/Abdelrahman-Hepish                */ 
/*******************************************************************************/

#ifnedf __RCC_PRIVATE_H__
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

void RCC_voidResetReversed(RCC_Bus bus) ; 

#endif //__RCC_PRIVATE_H__