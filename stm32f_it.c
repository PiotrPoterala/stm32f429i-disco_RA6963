#include <stdio.h>
#include <string.h>	
#include <stdbool.h>	
#include <stdlib.h>	

#include "input_signals.h"
#include "pp_signals.h"

extern PCheckSignals checkButtons;

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}


void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}


void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}


void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}


void SysTick_Handler(void)
{
	PIN_TOG(LED_PORT, LED1);
}



void TIM1_UP_TIM10_IRQHandler(void){

	if((TIM1->DIER & TIM_DIER_UIE) && (TIM1->SR & TIM_SR_UIF )){
			TIM1->SR&=~TIM_SR_UIF;
			checkButtons.checkSetSignal(&checkButtons.data, BUTTON_PORT->IDR, BUTTON, nBUTTON);
		}
}




