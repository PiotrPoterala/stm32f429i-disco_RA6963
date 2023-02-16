#include "config.h"

#include "def_pins_stm32f4.h"

//konfigurowanie sygnalow taktujacych
void RCC_Config(void){

		int StartUpCounter = 0;
//startowe ustawienia rejestrów zegara oraz flash
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
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLM) | RCC_PLLCFGR_PLLM_DIV12;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLN) | RCC_PLLCFGR_PLLN_MUL360;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLP) | RCC_PLLCFGR_PLLP_DIV2;
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLQ) | RCC_PLLCFGR_PLLQ_DIV8;
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
			RCC->PLLCFGR=(RCC->PLLCFGR & ~RCC_PLLCFGR_PLLQ) | RCC_PLLCFGR_PLLQ_DIV8;
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

//odblokowanie taktowania dla niezbędnych peryferiów
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;		
		RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;

		RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
		RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;
		RCC->APB1ENR|=RCC_APB1ENR_TIM4EN;
		RCC->APB1ENR|=RCC_APB1ENR_TIM5EN;
		RCC->APB1ENR|=RCC_APB1ENR_TIM6EN;
		RCC->APB1ENR|=RCC_APB1ENR_TIM7EN;
		RCC->APB1ENR|=RCC_APB1ENR_USART3EN;		//włącz USART3
		RCC->APB1ENR|=RCC_APB1ENR_UART4EN;
		RCC->APB1ENR|=RCC_APB1ENR_UART5EN;
		RCC->APB1ENR|=RCC_APB1ENR_PWREN;

		RCC->APB2ENR|=RCC_APB2ENR_TIM1EN;
		RCC->APB2ENR|=RCC_APB2ENR_TIM8EN;
		RCC->APB2ENR|=RCC_APB2ENR_SPI1EN;
		RCC->APB2ENR|= RCC_APB2ENR_SYSCFGEN;

}


void NVIC_Config(void){
		

		NVIC_SetPriorityGrouping(NVIC_PriGroup_4); //16 priorytetów preemption, brak subpriorytetów 
                 
		//priorytet 0 przypisany został SysTick

		NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 5); 	//obsługa liniałów
		NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}


void GPIO_Config(void)
{

//konfiguracja portu C

	OUT_SET_REG(GPIOC, Pin3, IO_OUT_HS);	//CD
	OUT_SET_REG(GPIOC, Pin8, IO_OUT_HS);	//RD
	OUT_SET_REG(GPIOC, Pin11, IO_OUT_HS);	//WR
	OUT_SET_REG(GPIOC, Pin12, IO_OUT_HS);	//CE
	OUT_SET_REG(GPIOC, Pin13, IO_OUT_HS);	//RES

//konfiguracja portu D
OUT_SET_REG(GPIOC, Pin3, IO_OUT_HS);	//CD

	OUT_SET_REG(GPIOD, Pin0, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin1, IO_OUT_HS);

	ALT_SET_REG(GPIOD, Pin2, IO_OUT_HS);
	GPIOD->AFR[0]=(GPIOD->AFR[0] & ~(0xFul<<(Pin2*4))) | (GPIO_AFR_AF8<<(Pin2*4)); //UART5 RX

	OUT_SET_REG(GPIOD, Pin3, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin4, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin5, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin6, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin7, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin8, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin9, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin10, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin11, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin12, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin13, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin14, IO_OUT_HS);
	OUT_SET_REG(GPIOD, Pin15, IO_OUT_HS);

//konfiguracja portu E
	OUT_SET_REG(GPIOE, Pin2, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin3, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin4, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin5, IO_OUT_HS);
	OUT_SET_REG(GPIOE, Pin6, IO_OUT_HS);


	PIN_SET(GPIOD, (PD0 | PD1 | PD3 | PD4 | PD5 | PD6 | PD7 | PD8 | PD9 | PD10 | PD11));	
	PIN_CLR(GPIOD, (PD12 | PD13 | PD14 | PD15));
	PIN_SET(GPIOE, (PE13 | PE14 | PE15));

	PIN_SET(PORT_SD_PWR, PIN_SD_PWR);
}


void TIM_Config(void){

//konfiguracja timera1 (sprawdzania liniałów) 
//ustawienie podstawy czasowej na 8x max częstotliwość ruchu (w tym przypadku 600Hz)
	TIM1->CR1&=~TIM_CR1_DIR;  //kierunek zliczania od 0 w górę
	TIM1->CR1&=~TIM_CR1_CMS;  //licznik zlicza zgodnie z kierunkiem podanym w DIR
	TIM1->PSC=100-1;	
	TIM1->ARR=((APB2_CORE_CLOCK/(TIM1->PSC+1))/BASE_FREQUENCY_OF_TIM1)-1;
  TIM1->EGR = TIM_EGR_UG;  // Generate an update event to reload the Prescaler immediately 
	
	TIM1->DIER &= ~TIM_DIER_UIE;					
	TIM1->CR1 &= ~TIM_CR1_CEN;



//konfiguracja timera2 (ustawienie podstawy czasowej na 1500Hz; obsluga przejazdów silnikow X,Y,Z,a w pracy automatycznej)
	TIM2->CR1&=~TIM_CR1_DIR;  
	TIM2->CR1&=~TIM_CR1_CMS; 

	TIM2->ARR=(APB2_CORE_CLOCK/BASE_FREQUENCY_OF_TIM2)-1;	
	TIM2->PSC=12-1;		
  TIM2->EGR = TIM_EGR_UG;  

	TIM2->DIER &= ~TIM_DIER_UIE;				
	TIM2->CR1 &= ~TIM_CR1_CEN;		
//--------------------------------------------------------------------------		
	
//konfiguracja timera3 (ustawienie podstawy czasowej na 2000Hz; obsluga recznych przejazdów silnikow X,Y,Z,a)
	TIM3->CR1&=~TIM_CR1_DIR;  
	TIM3->CR1&=~TIM_CR1_CMS; 
	TIM3->ARR=(APB2_CORE_CLOCK/BASE_FREQUENCY_OF_TIM3)-1;	//wartość do której dolicza timer
	TIM3->PSC=12-1;
  TIM3->EGR = TIM_EGR_UG; 	
	
	TIM3->DIER &= ~TIM_DIER_UIE;
	TIM3->CR1 &= ~TIM_CR1_CEN;		

//--------------------------------------------------------------------------	
	
//konfiguracja timera4 (ustawienie podstawy czasowej na 2000Hz;obsluga automatycznych przejazdów silnikow X,Y,Z,a w pracy ręcznej)
	TIM4->CR1&=~TIM_CR1_DIR; 
	TIM4->CR1&=~TIM_CR1_CMS;  
	TIM4->PSC=4-1;	
	TIM4->ARR=((APB2_CORE_CLOCK/(TIM4->PSC+1))/BASE_FREQUENCY_OF_TIM4)-1;		
	TIM4->EGR = TIM_EGR_UG; 

	TIM4->CR1&= ~TIM_DIER_UIE;		 
	TIM4->CR1&= ~TIM_CR1_CEN;		//wyłączenie timera4 
//--------------------------------------------------------------------------


//konfiguracja timera5 (ustawienie podstawy czasowej na 400Hz; sprawdzania podłączenie karty SD, stanu klawiatury oraz stanu krańcówek; odswiezanie ekranu)
	TIM5->CR1&=~TIM_CR1_DIR;  
	TIM5->CR1&=~TIM_CR1_CMS;  
	TIM5->PSC=4-1;	
	TIM5->ARR=((APB2_CORE_CLOCK/(TIM5->PSC+1))/BASE_FREQUENCY_OF_TIM5)-1;	
  TIM5->EGR = TIM_EGR_UG;  
	
	TIM5->DIER &= ~TIM_DIER_UIE;					
	TIM5->CR1 &= ~TIM_CR1_CEN;
//--------------------------------------------------------------------------


	TIM6->CR1&=~TIM_CR1_DIR;  
	TIM6->CR1&=~TIM_CR1_CMS;  
	TIM6->ARR=(APB2_CORE_CLOCK/BASE_FREQUENCY_OF_TIM6)-1;	
	TIM6->PSC=10;		
  TIM6->EGR = TIM_EGR_UG;  

	TIM6->DIER &= ~TIM_DIER_UIE;
	TIM6->CR1 &= ~TIM_CR1_CEN;	
//--------------------------------------------------------------------------

	TIM8->CR1&=~TIM_CR1_DIR;  
	TIM8->CR1&=~TIM_CR1_CMS;  
	TIM8->ARR=18000-1;
	TIM8->PSC=10000-1;		
  TIM8->EGR = TIM_EGR_UG;  

	TIM8->DIER &= ~TIM_DIER_UIE;
	TIM8->CR1 &= ~TIM_CR1_CEN;	
//--------------------------------------------------------------------------

	TIM7->CR1&=~TIM_CR1_DIR;  //kierunek zliczania od 0 w górę
	TIM7->CR1&=~TIM_CR1_CMS;  //licznik zlicza zgodnie z kierunkiem podanym w DIR
	TIM7->ARR=(APB2_CORE_CLOCK/BASE_FREQUENCY_OF_TIM7)-1;	
	TIM7->PSC=12-1;	
	
	TIM7->DIER &= ~TIM_DIER_UIE;					
	TIM7->CR1 &= ~TIM_CR1_CEN;

}

