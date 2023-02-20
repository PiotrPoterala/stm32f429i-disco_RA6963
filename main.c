#include <stdio.h>	
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "config.h"

#include "pp_lcdgraph.h"
#include "pp_signals.h"
#include "input_signals.h"
#include "pp_const_ports_masks_list.h"

void writeTestText(PLCDgraph *lcd);
void writeTestIcon(PLCDgraph *lcd);
void writeTestTextGraph(PLCDgraph *lcd);

PLCDgraph lcd;
PCheckSignals checkButtons;
PConstPortsList lcdPortsList;
int screen=0;

int main(void){

		RCC_Config();
		NVIC_Config();
		GPIO_Config();
		TIM_Config();

		PCheckSignalsConstruct(&checkButtons);

		uPin ioPins[LCD_PINS_SIZE]={{GPIOD, Pin2}, {GPIOD, Pin4}, {GPIOD, Pin5}, {GPIOE, Pin2}, {GPIOE, Pin3}, {GPIOE, Pin4}, {GPIOE, Pin5}, {GPIOE, Pin6},
																			{GPIOC, Pin3}, {GPIOC, Pin8}, {GPIOC, Pin11}, {GPIOC, Pin12}, {GPIOC, Pin13}}; //DB0, DB1, DB2, DB3, DB4, DB5, DB6, DB7, CD, RD, WR, CE, RES
		uPortMask lcdPortsTab[5];																
		PConstPortsListConstruct(&lcdPortsList, lcdPortsTab, sizeof(lcdPortsTab)/sizeof(uPortMask));
		
		lcdPortsList.create(&lcdPortsList.data, ioPins, LCD_DATA_PINS_SIZE);																													
		PLCDgraphConstruct(&lcd, ioPins, &lcdPortsList.data);
		
		if(SysTick_Config(16000000)){while(1);}	
		
		TIM1->DIER |= TIM_DIER_UIE;					
		TIM1->CR1 |= TIM_CR1_CEN ;
		
		writeTestIcon(&lcd);
		
		while(1){
			
			if((checkButtons.data.checkedSetSignals & nBUTTON) && !(checkButtons.data.madeSignals & nBUTTON)){

				switch(screen){
					case 0:writeTestText(&lcd);
								break; 
					case 1:writeTestTextGraph(&lcd);
								break; 
					default: writeTestIcon(&lcd);
							break;
					
				}
				
				screen++;
				if(screen>2)screen=0;
			}else if(!(checkButtons.data.checkedSetSignals & nBUTTON) && (checkButtons.data.madeSignals & nBUTTON)){
				checkButtons.data.madeSignals &=~nBUTTON;
				
			}
			
			
		}

}


void writeTestText(PLCDgraph *lcd){
	
		lcd->reset(&lcd->data, 1);
		lcd->setTextAtribiuteModeEnable(&lcd->data, true);
		
		lcd->seek(&lcd->data, 0, 0);
		lcd->write(&lcd->data, "Hello!");
	
		lcd->seek(&lcd->data, 0, 1);
		lcd->write(&lcd->data, "Cze""\xA6\xA1");
		
		lcd->seek(&lcd->data, 0, 2);
		lcd->setReverse(&lcd->data, true);
		lcd->write(&lcd->data, "Hello!");
		lcd->setReverse(&lcd->data, false);
		
		lcd->seek(&lcd->data, 0, 3);
		lcd->setBlink(&lcd->data, true);
		lcd->write(&lcd->data, "Hello!");
		lcd->setBlink(&lcd->data, false);
		
		lcd->seek(&lcd->data, 0, 4);
		lcd->setIndependentWriteTextAtribiutes(&lcd->data, true);
		lcd->setReverse(&lcd->data, true);
		lcd->writeTextAtribiutesOnTheArea(&lcd->data, 2, 4, 5, 1);
		lcd->write(&lcd->data, "Hello!");
		lcd->setReverse(&lcd->data, false);
		
		lcd->setCursorEnable(&lcd->data, true);
		lcd->seekCursor(&lcd->data, 2, 5);
	
}

void writeTestTextGraph(PLCDgraph *lcd){
	
		lcd->reset(&lcd->data, 1);
		lcd->setFont(&lcd->data, FONT_1);
		
		lcd->seek(&lcd->data, 0, 0);
		lcd->write(&lcd->data, "XY");
	
		lcd->seek(&lcd->data, 1, 1);
		lcd->write(&lcd->data, "YZ");
	
}

void writeTestIcon(PLCDgraph *lcd){
		extern const unsigned char logoZAPppLarge[]; 
	
		lcd->reset(&lcd->data, 1);
	
		lcd->seek(&lcd->data, 0, 5);
		lcd->drawIcon(&lcd->data, logoZAPppLarge);
}
