#include "config.h"

#include "def_pins_stm32f4.h"
#include "input_signals.h"

void RCC_Config(void){
		int StartUpCounter = 0;
	
		SystemInit();
	
		RCC->CR |= RCC_CR_HSEON;
	
		while(!(RCC->CR & RCC_CR_HSERDY) && (StartUpCounter != 0xFFFF)){
			StartUpCounter++;
		};
	
		if(RCC->CR & RCC_CR_HSERDY){
			RCC->APB1ENR |= RCC_APB1ENR_PWREN;
			PWR->CR |= PWR_CR_VOS;

			RCC->CR&=~RCC_CR_PLLON;
			while(RCC->CR & RCC_CR_PLLRDY);
			RCC->PLLCFGR|=RCC_PLLCFGR_PLLSRC;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | RCC_PLLCFGR_PLLM_DIV4;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | RCC_PLLCFGR_PLLN_MUL180;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | RCC_PLLCFGR_PLLP_DIV2;
			RCC->CR|=RCC_CR_PLLON;
			while(!(RCC->CR & RCC_CR_PLLRDY)) 
				;
		
			PWR->CR |= PWR_CR_ODEN;
			while(!(PWR->CSR & PWR_CSR_ODRDY));
			PWR->CR |= PWR_CR_ODSWEN;
			while(!(PWR->CSR & PWR_CSR_ODSWRDY));    

			FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS;

			RCC->CFGR=(RCC->CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL;
			RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
			RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
			RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

			/* Wait till the main PLL is used as system clock source */
			while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
		}else{
			RCC->CR |= RCC_CR_HSION;
			
			while(!(RCC->CR & RCC_CR_HSIRDY)) 
			;
			
			RCC->APB1ENR |= RCC_APB1ENR_PWREN;

			RCC->CR&=~RCC_CR_PLLON;
			while(RCC->CR & RCC_CR_PLLRDY);
			RCC->PLLCFGR&=~RCC_PLLCFGR_PLLSRC;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | RCC_PLLCFGR_PLLM_DIV16;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | RCC_PLLCFGR_PLLN_MUL360;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | RCC_PLLCFGR_PLLP_DIV2;
			RCC->CR|=RCC_CR_PLLON;
			while(!(RCC->CR & RCC_CR_PLLRDY)) 
				;
		
		 
			PWR->CR |= PWR_CR_ODEN;
			while(!(PWR->CSR & PWR_CSR_ODRDY));
			PWR->CR |= PWR_CR_ODSWEN;
			while(!(PWR->CSR & PWR_CSR_ODSWRDY));    

			FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_5WS;

			RCC->CFGR=(RCC->CFGR & ~RCC_CFGR_SW) | RCC_CFGR_SW_PLL;
			RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
			RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
			RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

			/* Wait till the main PLL is used as system clock source */
			while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
			
		}
  
		SystemCoreClockUpdate();
		
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
		
		RCC->APB2ENR|=RCC_APB2ENR_TIM1EN;

}


void NVIC_Config(void){
		

		NVIC_SetPriorityGrouping(NVIC_PriGroup_4); //16 priorytetów preemption, brak subpriorytetów 
                 
		//priorytet 0 przypisany został SysTick

		NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 5); 
		NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}


void GPIO_Config(void)
{

	//konfiguracja portu A
	IN_SET_REG(GPIOA, Pin0, IO_IN_NPUD);	//user button	
	
//port C
//	OUT_SET_REG(GPIOC, Pin3, IO_OUT_HS);	//CD
//	OUT_SET_REG(GPIOC, Pin8, IO_OUT_HS);	//RD
//	OUT_SET_REG(GPIOC, Pin11, IO_OUT_HS);	//WR
//	OUT_SET_REG(GPIOC, Pin12, IO_OUT_HS);	//CE
//	OUT_SET_REG(GPIOC, Pin13, IO_OUT_HS);	//RES

////port D

//	OUT_SET_REG(GPIOD, Pin2, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin4, IO_OUT_HS);
//	OUT_SET_REG(GPIOD, Pin5, IO_OUT_HS);

////port E
//	OUT_SET_REG(GPIOE, Pin2, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin3, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin4, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin5, IO_OUT_HS);
//	OUT_SET_REG(GPIOE, Pin6, IO_OUT_HS);

//port G
	OUT_SET_REG(GPIOG, Pin13, IO_OUT_HS);	//LED

	PIN_CLR(LED_PORT, LED1);
}


void TIM_Config(void){

	TIM1->CR1&=~TIM_CR1_DIR;  
	TIM1->CR1&=~TIM_CR1_CMS;  
	TIM1->PSC=100-1;	
	TIM1->ARR=((APB2_CORE_CLOCK/(TIM1->PSC+1))/BASE_FREQUENCY_OF_TIM1)-1;
  TIM1->EGR = TIM_EGR_UG;  
	
	TIM1->DIER &= ~TIM_DIER_UIE;					
	TIM1->CR1 &= ~TIM_CR1_CEN;

}

