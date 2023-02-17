#ifndef _CONFIG_H
	#define _CONFIG_H
	#include "stm32f4xx.h"


	#define APB2_CORE_CLOCK	90000000
	
	#define BASE_FREQUENCY_OF_TIM1	2000

	#define NVIC_PriGroup_0         ((uint32_t)0x7) /*!< 0 bits for pre-emption priority
																															4 bits for subpriority */
	#define NVIC_PriGroup_1         ((uint32_t)0x6) /*!< 1 bits for pre-emption priority
																															3 bits for subpriority */
	#define NVIC_PriGroup_2         ((uint32_t)0x5) /*!< 2 bits for pre-emption priority
																															2 bits for subpriority */
	#define NVIC_PriGroup_3         ((uint32_t)0x4) /*!< 3 bits for pre-emption priority
																															1 bits for subpriority */
	#define NVIC_PriGroup_4         ((uint32_t)0x3) /*!< 4 bits for pre-emption priority
																															0 bits for subpriority */
	#define RCC_PLLCFGR_PLLM_DIV4			4
	#define RCC_PLLCFGR_PLLM_DIV16		16
	#define RCC_PLLCFGR_PLLN_MUL180		(180<<6)
	#define RCC_PLLCFGR_PLLN_MUL360		(360<<6)
	#define RCC_PLLCFGR_PLLP_DIV2			0
	#define RCC_PLLCFGR_PLLQ_DIV8			(8<<24)



	#define GPIO_AFR_AF0				0x0
	#define GPIO_AFR_AF1				0x1
	#define GPIO_AFR_AF2				0x2
	#define GPIO_AFR_AF3				0x3
	#define GPIO_AFR_AF4				0x4
	#define GPIO_AFR_AF5				0x5
	#define GPIO_AFR_AF6				0x6
	#define GPIO_AFR_AF7				0x7
	#define GPIO_AFR_AF8				0x8
	#define GPIO_AFR_AF9				0x9
	#define GPIO_AFR_AF10				0xA
	#define GPIO_AFR_AF11				0xB
	#define GPIO_AFR_AF12				0xC
	#define GPIO_AFR_AF13				0xD
	#define GPIO_AFR_AF14				0xE
	#define GPIO_AFR_AF15				0xF

	#define IO_SET_REG(REG, PIN, SETS) (REG & ~(0x3u<<(PIN*2))) | ((SETS)<<(PIN*2))
  #define IN_SET_REG(REG, PIN, SET1) (REG->MODER=IO_SET_REG(REG->MODER, PIN, IO_IN), REG->PUPDR=IO_SET_REG(REG->PUPDR, PIN, SET1))
  #define OUT_SET_REG(REG, PIN, SPEED) (REG->MODER=IO_SET_REG(REG->MODER, PIN, IO_OUT), REG->OTYPER&=~(1<<PIN), REG->OSPEEDR=IO_SET_REG(REG->OSPEEDR, PIN, SPEED))
	#define ALT_SET_REG(REG, PIN, SPEED) (REG->MODER=IO_SET_REG(REG->MODER, PIN, IO_ALT), REG->OTYPER&=~(1<<PIN), REG->OSPEEDR=IO_SET_REG(REG->OSPEEDR, PIN, SPEED))


	void RCC_Config(void);
	void NVIC_Config(void);
	void RTC_Config(void);
	void GPIO_Config(void);
	void TIM_Config(void);
	void SPI_Config(void);
	void USART_Config(void);
	void BKP_Config(void);
	void EXTI_Config(void);



#endif
