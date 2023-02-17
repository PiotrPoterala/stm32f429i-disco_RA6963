#include <stdio.h>	
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "config.h"

#include "pp_lcdgraph.h"
#include "pp_signals.h"
#include "input_signals.h"

void writeTestText(PLCDgraph *lcd);
void writeTestIcon(PLCDgraph *lcd);

PLCDgraph lcd;
PCheckSignals checkButtons;

int screen=0;

int main(void){

		RCC_Config();
		NVIC_Config();
		GPIO_Config();
		TIM_Config();

		PCheckSignalsConstruct(&checkButtons);

		uPin outputsPins[LCD_PINS_SIZE]={{GPIOD, Pin2}, {GPIOD, Pin4}, {GPIOD, Pin5}, {GPIOE, Pin2}, {GPIOE, Pin3}, {GPIOE, Pin4}, {GPIOE, Pin5}, {GPIOE, Pin6},
																			{GPIOC, Pin3}, {GPIOC, Pin8}, {GPIOC, Pin11}, {GPIOC, Pin12}, {GPIOC, Pin13}}; 
		uPortMask outputsPortMask[3]={{GPIOC, 0, 0}, {GPIOD, 0, 0}, {GPIOE, 0, 0}};
		PLCDgraphConstruct(&lcd, outputsPins, outputsPortMask, 3);
		
		if(SysTick_Config(16000000)){while(1);}	
		
		TIM1->DIER |= TIM_DIER_UIE;					
		TIM1->CR1 |= TIM_CR1_CEN ;
		
		writeTestIcon(&lcd);
		
		while(1){
			
			if((checkButtons.data.checkedSetSignals & nBUTTON) && !(checkButtons.data.madeSignals & nBUTTON)){

				switch(screen){
					case 0:writeTestText(&lcd);
								break; 
					default: writeTestIcon(&lcd);
							break;
					
				}
				
				screen++;
				if(screen>1)screen=0;
			}else if(!(checkButtons.data.checkedSetSignals & nBUTTON) && (checkButtons.data.madeSignals & nBUTTON)){
				checkButtons.data.madeSignals &=~nBUTTON;
				
			}
			
			
		}

}


void writeTestText(PLCDgraph *lcd){
	
		lcd->reset(&lcd->data, 1);
//	lcd->data.typeOfFont=BASE_FONT;
		lcd->setTextAtribiuteModeEnable(&lcd->data, true);
		
		lcd->seek(&lcd->data, 0, 0);
		lcd->write(&lcd->data, "Hello!");
		
		lcd->seek(&lcd->data, 0, 1);
		lcd->setReverse(&lcd->data, true);
		lcd->write(&lcd->data, "Hello!");
		lcd->setReverse(&lcd->data, false);
		
		lcd->seek(&lcd->data, 0, 2);
		lcd->setBlink(&lcd->data, true);
		lcd->write(&lcd->data, "Hello!");
		lcd->setBlink(&lcd->data, false);
		
		lcd->seek(&lcd->data, 0, 3);
		lcd->setIndependentWriteTextAtribiutes(&lcd->data, true);
		lcd->setReverse(&lcd->data, true);
		lcd->writeTextAtribiutesOnTheArea(&lcd->data, 2, 3, 5, 1);
		lcd->write(&lcd->data, "Hello!");
		lcd->setReverse(&lcd->data, false);
	
}

void writeTestIcon(PLCDgraph *lcd){
		extern const unsigned char logoZAPppLarge[]; 
	
		lcd->reset(&lcd->data, 1);
	
		lcd->seek(&lcd->data, 0, 5);
		lcd->drawIcon(&lcd->data, logoZAPppLarge);
}
