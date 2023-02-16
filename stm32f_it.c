#include <stdio.h>
#include <string.h>	
#include <stdbool.h>	
#include <stdlib.h>	



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

}





//void TIM8_UP_TIM13_IRQHandler(void){

//		if((TIM8->DIER & TIM_DIER_UIE) && (TIM8->SR & TIM_SR_UIF)){
//			TIM8->SR&=~TIM_SR_UIF;

//			oSystemsData.oTimeOfWork.changeTime(&oSystemsData.oTimeOfWork.time, oSystemsData.oTimeOfWork.clockActive);
//			oSystemsData.oOverallWorkingTime.changeTime(&oSystemsData.oOverallWorkingTime.time, oSystemsData.oOverallWorkingTime.clockActive);
//			oSystemsData.oTurnOnTime.changeTime(&oSystemsData.oTurnOnTime.time, oSystemsData.oTurnOnTime.clockActive);

//			PIN_TOG(LED_PORT, LED1);
//		}
//}




//void TIM1_UP_TIM10_IRQHandler(void){

//	if((TIM1->DIER & TIM_DIER_UIE) && (TIM1->SR & TIM_SR_UIF )){
//			TIM1->SR&=~TIM_SR_UIF;

//			if(oFeatures.item & onLINEARS){
//				for(int i=0; i<encoders.data.size;i++){
//					encoders.data.encoder[i].checkRotate(&encoders.data.encoder[i].behaveData);
//					if(!encoders.data.encoder[i].checkRotateBackwards(&encoders.data.encoder[i].behaveData))encoders.data.encoder[i].checkRotateFarward(&encoders.data.encoder[i].behaveData);
//				}
//				
//			}
//		}
//}


//void TIM2_IRQHandler(void){
//	static _Bool wykonano_prace=false;
//	static unsigned int WIB_odjechano=11;
//	static unsigned int previousOWEsignal=0;


//	if((TIM2->DIER & TIM_DIER_UIE) && (TIM2->SR & TIM_SR_UIF )){
//			TIM2->SR&=~TIM_SR_UIF;
//		


//			if((oCheckSignalsAutWork.checkedResetSignals & nOWE)!=previousOWEsignal){
//				if(!(oCheckSignalsAutWork.checkedResetSignals & nOWE)){
//					if(pAutPathDrive.algorithm.params.departureOWEendOfProg){
//						pAutPathDrive.algorithm.params.sumStepOWE=pAutPathDrive.algorithm.params.nrOfStepOWE;
//						pAutPathDrive.algorithm.params.nrOfStepOWE=0;
//						pAutPathDrive.algorithm.params.departureOWE=false;
//						pAutPathDrive.algorithm.params.arrivalOWE=true;
//					}else{
//						
//						PStepMotDriver2clock *motor=stepMotors.getMotorPtr(&stepMotors.data, pAutPathDrive.algorithm.getMasterAxis(&pAutPathDrive.algorithm.params));
//						if(motor!=NULL){
//							SParam auxPhyCoord=motor->getPhyCoord(&motor->behaveData);
//							SParam velocity=motor->getVelocity(&motor->behaveData);
//							SParam accelerate=motor->getAccelerate(&motor->behaveData);
//							
//							unsigned int accelerateNumberOfSteps=calculateAccelerateNumberOfSteps(fs_mulBy10_pp(accelerate.value, auxPhyCoord.unit-3-accelerate.unit),
//																																				fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit),
//																																				auxPhyCoord.precision);
//							pAutPathDrive.algorithm.params.sumStepOWE=(pAutPathDrive.algorithm.params.nrOfStepOWE>accelerateNumberOfSteps)?pAutPathDrive.algorithm.params.nrOfStepOWE+accelerateNumberOfSteps:pAutPathDrive.algorithm.params.nrOfStepOWE*2;
//						}
//					}
//				}
//				previousOWEsignal=(oCheckSignalsAutWork.checkedResetSignals & nOWE);
//			}
//				

//			if(oCheckSignalsAutWork.checkedResetSignals & nZSA){
//				if(!oComunicationUART3.transmitParam.busy){
//					wyslijUART_ISR(oComunicationUART3.transmitParam.UARTx, oComunicationUART3.transmitParam.buforTx, "AT+ERR?\r\n");
//				}
//				oCheckSignalsAutWork.checkedResetSignals |= nZSAP;
//				PAlertDialogConstruct(&dialog, infoTextList[idLIST_OF_ERRORS], NULL, okText, NULL);
//				pAutPathDrive.infoDrive=PRZEJ_SPAUZOWANO;
//			}else if((oCheckSignalsAutWork.checkedResetSignals & nSYGP) && (oAutWorkFunctions.item & fDET_P)){	//jeżeli zdetekowano przypalenie i aktywna jest funkcja "detekcja przypalenia"
//				PAlertDialogConstruct(&dialog, infoTextList[idSCORCH], NULL, okText, NULL);
//				pAutPathDrive.infoDrive=PRZEJ_SPAUZOWANO;
//			}else if(pAutPathDrive.errorDrive & B_POCZ_PROG){
//				pAutPathDrive.errorDrive=0;
//				PAlertDialogConstruct(&dialog, infoTextList[idWITHDRAW_BEGIN_PROG], NULL, okText, NULL);
//				pAutPathDrive.infoDrive=PRZEJ_PORZUCONO;
//			}else if((pAutPathDrive.errorDrive & B_POCZ_SEG) && !(oAutWorkFunctions.item & fAUT_ROZ)){
//				pAutPathDrive.errorDrive=0;
//				PAlertDialogConstruct(&dialog, infoTextList[idWITHDRAW_BEGIN_SEG], NULL, okText, NULL);
//				pAutPathDrive.infoDrive=PRZEJ_SPAUZOWANO;
//			}else if(stepMotors.isSomeLimStopPush(&stepMotors.data)){
//				pAutPathDrive.infoDrive=PRZEJ_PORZUCONO;
//				PAlertDialogConstruct(&dialog, infoTextList[idPUSH_LIMSTOP], NULL, okText, NULL);
//			}else if(oKeyboard.KBR.KBRL & kSTOP){
//				oKeyboard.KBR.KBRL&=KBRL_CLR;
//				pAutPathDrive.infoDrive=PRZEJ_SPAUZOWANO;
//				PAlertDialogConstruct(&dialog, infoTextList[idSTOP_WORK], NULL, okText, NULL);
//			}else{
//				checkDriveError(&pAutPathDrive.infoDrive);
//				
//				if(stepMotors.exists(&stepMotors.data, 'Z')){
//					PStepMotDriver2clock *motor=stepMotors.getMotorPtr(&stepMotors.data, 'Z');
//					if(motor->behaveData.phyCoord->value-oProg.progParam.startProgCoordinates.getAxValue(&oProg.progParam.startProgCoordinates.data, 'Z')>5*pow_pp(10, motor->behaveData.phyCoord->unit)){
//						PAlertDialogConstruct(&dialog, infoTextList[idEXCEEDING_COORD_Z], NULL, okText, NULL);
//						pAutPathDrive.infoDrive=PRZEJ_PORZUCONO;
//					}
//				}
//				
//				
//				
//				
//			}
//			

//			if(pAutPathDrive.infoDrive==DRIVE_IN_PROGRESS){	
//				oScreen.idScreen=idAUT_WORK_SCREEN;

//				if((oCheckSignalsAutWork.checkedResetSignals & nOWE) && wykonano_prace){
//					
//					if(pAutPathDrive.algorithm.params.departureOWE==false){
//						stepMotors.setAllLinearsMotorsVelocity(&stepMotors.data, workParams.getParamPtr(&workParams.data, 'J'));
//						pAutPathDrive.algorithm.params.departureOWE=true;
//					}
//					
//					pAutPathDrive.algorithm.timerServiceStrategy(&stepMotors, &pAutPathDrive.algorithm.params, BACKWARD, &pAutPathDrive.infoDrive, &pAutPathDrive.errorDrive, &oAutWorkFunctions, &oProg.progParam.startProgCoordinates, TIM2);		

//					PStepMotDriver2clock *motor=stepMotors.getMotorPtr(&stepMotors.data, pAutPathDrive.algorithm.getMasterAxis(&pAutPathDrive.algorithm.params));
//					if(motor!=NULL){
//						SParam auxPhyCoord=motor->getPhyCoord(&motor->behaveData);
//						SParam velocity=motor->getVelocity(&motor->behaveData);
//						SParam accelerate=motor->getAccelerate(&motor->behaveData);
//						
//						unsigned int clockDivider=getClockDividerResponsibleForDriveSpeed(pAutPathDrive.algorithm.params.nrOfStepOWE, pAutPathDrive.algorithm.params.nrOfStepOWE, 																																
//																																	fs_mulBy10_pp(accelerate.value, auxPhyCoord.unit-3-accelerate.unit),
//																																	fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit), 
//																																	BASE_FREQUENCY_OF_TIM2,
//																																	auxPhyCoord.precision)-1;
//						if(TIM2->PSC<clockDivider)TIM2->PSC=clockDivider;
//					}
//				}else if(pAutPathDrive.algorithm.params.departureOWE){
//					pAutPathDrive.algorithm.timerServiceStrategy(&stepMotors, &pAutPathDrive.algorithm.params, BACKWARD, &pAutPathDrive.infoDrive, &pAutPathDrive.errorDrive, &oAutWorkFunctions, &oProg.progParam.startProgCoordinates, TIM2);		

//					PStepMotDriver2clock *motor=stepMotors.getMotorPtr(&stepMotors.data, pAutPathDrive.algorithm.getMasterAxis(&pAutPathDrive.algorithm.params));
//					if(motor!=NULL){
//						SParam auxPhyCoord=motor->getPhyCoord(&motor->behaveData);
//						SParam velocity=motor->getVelocity(&motor->behaveData);
//						SParam accelerate=motor->getAccelerate(&motor->behaveData);
//						
//						unsigned int clockDivider=getClockDividerResponsibleForDriveSpeed(pAutPathDrive.algorithm.params.nrOfStepOWE, (pAutPathDrive.algorithm.params.sumStepOWE-pAutPathDrive.algorithm.params.nrOfStepOWE>=0)?pAutPathDrive.algorithm.params.sumStepOWE-pAutPathDrive.algorithm.params.nrOfStepOWE:0, 																																
//																																	fs_mulBy10_pp(accelerate.value, auxPhyCoord.unit-3-accelerate.unit),
//																																	fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit), 
//																																	BASE_FREQUENCY_OF_TIM2,
//																																	auxPhyCoord.precision)-1;
//						if(TIM2->PSC<clockDivider)TIM2->PSC=clockDivider;
//					}

//					if(pAutPathDrive.algorithm.params.sumStepOWE<=pAutPathDrive.algorithm.params.nrOfStepOWE || pAutPathDrive.algorithm.params.departureOWEendOfProg){
//						pAutPathDrive.algorithm.params.sumStepOWE=pAutPathDrive.algorithm.params.nrOfStepOWE;
//						pAutPathDrive.algorithm.params.nrOfStepOWE=0;
//						pAutPathDrive.algorithm.params.departureOWE=false;
//						pAutPathDrive.algorithm.params.arrivalOWE=true;
//					}
//				}else if(pAutPathDrive.algorithm.params.arrivalOWE){
//					pAutPathDrive.algorithm.timerServiceStrategy(&stepMotors, &pAutPathDrive.algorithm.params, FORWARD, &pAutPathDrive.infoDrive, &pAutPathDrive.errorDrive, &oAutWorkFunctions, &oProg.progParam.startProgCoordinates, TIM2);

//					PStepMotDriver2clock *motor=stepMotors.getMotorPtr(&stepMotors.data, pAutPathDrive.algorithm.getMasterAxis(&pAutPathDrive.algorithm.params));
//					if(motor!=NULL){
//						SParam auxPhyCoord=motor->getPhyCoord(&motor->behaveData);
//						SParam velocity=motor->getVelocity(&motor->behaveData);
//						SParam accelerate=motor->getAccelerate(&motor->behaveData);
//						
//						unsigned int clockDivider=getClockDividerResponsibleForDriveSpeed(pAutPathDrive.algorithm.params.nrOfStepOWE, (pAutPathDrive.algorithm.params.sumStepOWE-pAutPathDrive.algorithm.params.nrOfStepOWE>=0)?pAutPathDrive.algorithm.params.sumStepOWE-pAutPathDrive.algorithm.params.nrOfStepOWE:0, 																																
//																																	fs_mulBy10_pp(accelerate.value, auxPhyCoord.unit-3-accelerate.unit),
//																																	fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit), 
//																																	BASE_FREQUENCY_OF_TIM2,
//																																	auxPhyCoord.precision)-1;
//						if(TIM2->PSC<clockDivider)TIM2->PSC=clockDivider;
//					}
//					if(pAutPathDrive.algorithm.params.sumStepOWE<=pAutPathDrive.algorithm.params.nrOfStepOWE || ZWARCIE){
//						stepMotors.setAllLinearsMotorsVelocity(&stepMotors.data, workParams.getParamPtr(&workParams.data, 'F'));
//						pAutPathDrive.algorithm.params.nrOfStepOWE=0;
//						pAutPathDrive.algorithm.params.arrivalOWE=false;
//						wykonano_prace=false;
//					}
//				}else{
//					//wycofaj się jeżeli:
//					if(ZWARCIE ||			//wystąpiło zwarcie (Cplus=1) 
//							((oAutWorkFunctions.item & fWIB) && WIB_odjechano<=10 && (WIB_odjechano%2))){ 	//włączona jest funkcja "wibracji" i nie wykonano 10 wibracji i wibracja nieparzysta lub...

//						if(WIB_odjechano<=10) WIB_odjechano++;	
//						pAutPathDrive.algorithm.timerServiceStrategy(&stepMotors, &pAutPathDrive.algorithm.params, BACKWARD, &pAutPathDrive.infoDrive, &pAutPathDrive.errorDrive, &oAutWorkFunctions, &oProg.progParam.startProgCoordinates, TIM2);
//	
//					//jedź do przodu jeżeli: 
//					}else if(BRAK_PRACY ||			//brak pracy (Cmin=1)
//										((oAutWorkFunctions.item & fWIB) && WIB_odjechano<=10 && !(WIB_odjechano%2))){	
//						wykonano_prace=false;
//						if(WIB_odjechano<=10) WIB_odjechano++;

//						pAutPathDrive.algorithm.timerServiceStrategy(&stepMotors, &pAutPathDrive.algorithm.params, FORWARD, &pAutPathDrive.infoDrive, &pAutPathDrive.errorDrive, &oAutWorkFunctions, &oProg.progParam.startProgCoordinates, TIM2);

//					//stój jeżeli: 
//					}else if(PRACA){	//praca (Cmin=0)		
//						wykonano_prace=true;			//zapisz pojawienie się pracy elektroerozyjnej
//						if(oAutWorkFunctions.item & fWIB) WIB_odjechano=1;
//						if(pAutPathDrive.algorithm.params.driveToFirstDischarge)pAutPathDrive.infoDrive=PRZEJ_ZREALIZOWANO;
//					}
//				}

//			}
//			
//			
//			if(pAutPathDrive.infoDrive!=DRIVE_IN_PROGRESS){	
//				TIM2->CR1&=~TIM_CR1_CEN;
//				TIM2->DIER&=~TIM_DIER_UIE;	

//				pAutPathDrive.algorithm.params.arrivalOWE=false; 
//				pAutPathDrive.algorithm.params.departureOWE=false;
//				pAutPathDrive.algorithm.params.nrOfStepOWE=0;
//			}
//			
//			
//			
//		}

//}


//void TIM3_IRQHandler(void){	

//		if((TIM3->DIER & TIM_DIER_UIE) && (TIM3->SR & TIM_SR_UIF)){
//				TIM3->SR&=~TIM_SR_UIF;

//			if(pConditionDrive.driveConditionParam.motor->isLimStopPush(&pConditionDrive.driveConditionParam.motor->behaveData, pConditionDrive.driveConditionParam.turn) || 
//					((oCheckSignalsAutWork.checkedSetSignals & nZWARCIE) && !(oAutWorkFunctions.item & fIZR)) || 
//					(pConditionDrive.driveConditionParam.motor->behaveData.error & (PHY_COORD_ERROR | BASE_COORD_ERROR))){
//					pConditionDrive.driveConditionParam.motor->behaveData.error=0;
//					pConditionDrive.infoDrive=PRZEJ_PORZUCONO;
//					TIM3->CR1&=~TIM_CR1_CEN;
//					TIM3->DIER &=~ TIM_DIER_UIE;
//			}else if(oKeyboard.KBR.KBRL){// jeżeli spuszczony został klawisz kierunku (a tym samy zapisany do rejestru określający który klawisz został wciśnięty i spuszczony) to...
//				SSimpleParam auxPhyCoord=pConditionDrive.driveConditionParam.motor->getSimplePhyCoord(&pConditionDrive.driveConditionParam.motor->behaveData);
//				SSimpleParam velocity=pConditionDrive.driveConditionParam.motor->getSimpleVelocity(&pConditionDrive.driveConditionParam.motor->behaveData);
//				SSimpleParam accelerate=pConditionDrive.driveConditionParam.motor->getSimpleAccelerate(&pConditionDrive.driveConditionParam.motor->behaveData);
//							
//				
//				unsigned int accelerateNumberOfSteps=calculateAccelerateNumberOfSteps(fs_mulBy10_pp(accelerate.value, auxPhyCoord.unit-3-accelerate.unit),
//																																				fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit),
//																																				auxPhyCoord.precision);

//					pConditionDrive.driveTimerService(&pConditionDrive.driveConditionParam);
//				// dohamuj silnik
//					if(!pConditionDrive.driveConditionParam.l_krok_tot)pConditionDrive.driveConditionParam.l_krok_tot=(pConditionDrive.driveConditionParam.l_krok_pom>accelerateNumberOfSteps)?pConditionDrive.driveConditionParam.l_krok_pom+accelerateNumberOfSteps:pConditionDrive.driveConditionParam.l_krok_pom*2;
//					if(pConditionDrive.driveConditionParam.l_krok_tot-pConditionDrive.driveConditionParam.l_krok_pom>0){
//						TIM3->PSC=(uint16_t)getClockDividerResponsibleForDriveSpeed(pConditionDrive.driveConditionParam.l_krok_tot-pConditionDrive.driveConditionParam.l_krok_pom, pConditionDrive.driveConditionParam.l_krok_tot-pConditionDrive.driveConditionParam.l_krok_pom, 
//																																				fs_mulBy10_pp(accelerate.value,auxPhyCoord.unit-3-accelerate.unit),
//																																				fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit), 
//																																				BASE_FREQUENCY_OF_TIM3, auxPhyCoord.precision)-1;
//					}else{
//						pConditionDrive.infoDrive=PRZEJ_PORZUCONO;
//						TIM3->CR1&=~TIM_CR1_CEN;
//						TIM3->DIER &=~ TIM_DIER_UIE;
//						oAutWorkFunctions.item&=~fIZR;
//					}
//			}else{
//				SSimpleParam auxPhyCoord=pConditionDrive.driveConditionParam.motor->getSimplePhyCoord(&pConditionDrive.driveConditionParam.motor->behaveData);
//				SSimpleParam velocity=pConditionDrive.driveConditionParam.motor->getSimpleVelocity(&pConditionDrive.driveConditionParam.motor->behaveData);
//				SSimpleParam accelerate=pConditionDrive.driveConditionParam.motor->getSimpleAccelerate(&pConditionDrive.driveConditionParam.motor->behaveData);
//				
//				pConditionDrive.driveTimerService(&pConditionDrive.driveConditionParam);
//				TIM3->PSC=(uint16_t)getClockDividerResponsibleForDriveSpeed(pConditionDrive.driveConditionParam.l_krok_pom, pConditionDrive.driveConditionParam.l_krok_pom, 
//																																				fs_mulBy10_pp(accelerate.value, auxPhyCoord.unit-3-accelerate.unit),
//																																				fs_mulBy10_pp(velocity.value, auxPhyCoord.unit-3-velocity.unit), 
//																																				BASE_FREQUENCY_OF_TIM3, auxPhyCoord.precision)-1;
//			}
//		}

//}

//void TIM6_DAC_IRQHandler(void){	
//		#define DELAY_DISTANCE_01MM		0.1
//		#define DELAY_DISTANCE_02MM		0.2
//	
//	
//		if((TIM6->DIER & TIM_DIER_UIE) && (TIM6->SR & TIM_SR_UIF)){
//			TIM6->SR&=~TIM_SR_UIF;

//			if(pCenteringDrive.driveCenteringParam.centeringStage==CENTER_I_STAGE){
//				SParam auxPhyCoord=pCenteringDrive.driveCenteringParam.driveConditionParam.motor->getPhyCoord(&pCenteringDrive.driveCenteringParam.driveConditionParam.motor->behaveData);
//				
//				TIM6->PSC=(uint16_t)getClockDividerInUniformMovement(1250, BASE_FREQUENCY_OF_TIM6, auxPhyCoord.precision);

//				if(pCenteringDrive.driveCenteringParam.driveConditionParam.l_krok_pom>(int)(DELAY_DISTANCE_01MM*pow_pp(10, auxPhyCoord.unit))/auxPhyCoord.precision)pCenteringDrive.driveCenteringParam.delayShortCircuitDet=false;
//				
//				if(oCheckSignalsAutWork.checkedSetSignals & nZWARCIE){ 	//sprawdzenie czy jest potwierdzone zwarcie
//					if(!pCenteringDrive.driveCenteringParam.delayShortCircuitDet)pCenteringDrive.errorDrive|=ZWR;
//				}else if(pCenteringDrive.driveCenteringParam.centrStartCoord!=NULL && pCenteringDrive.driveCenteringParam.centrTrackedCoord!=NULL && *pCenteringDrive.driveCenteringParam.centrStartCoord==*pCenteringDrive.driveCenteringParam.centrTrackedCoord){
//					pCenteringDrive.infoDrive=PRZEJ_WARUN_ZREALIZOWANO;
//				}else if(pCenteringDrive.driveCenteringParam.centrMaxDistans/auxPhyCoord.precision>0 
//								&& pCenteringDrive.driveCenteringParam.driveConditionParam.l_krok_pom>=pCenteringDrive.driveCenteringParam.centrMaxDistans/auxPhyCoord.precision){
//					pCenteringDrive.infoDrive=PRZEJ_ZREALIZOWANO;
//				}else if(pCenteringDrive.driveCenteringParam.driveConditionParam.motor->isLimStopPush(&pCenteringDrive.driveCenteringParam.driveConditionParam.motor->behaveData, pCenteringDrive.driveCenteringParam.driveConditionParam.turn)){
//					pCenteringDrive.infoDrive=PRZEJ_PORZUCONO;
//					PAlertDialogConstruct(&dialog, infoTextList[idPUSH_LIMSTOP], NULL, okText, NULL);
//				}else if(oKeyboard.KBR.KBRL & kSTOP){
//					oKeyboard.KBR.KBRL&=KBRL_CLR;
//					pCenteringDrive.infoDrive=PRZEJ_SPAUZOWANO;
//					PAlertDialogConstruct(&dialog, infoTextList[idSTOP_WORK], infoTextList[idASK_CONTINUE], okText, cancelText);
//				}else{
//					checkDriveError(&pCenteringDrive.infoDrive);
//				}
//			

//			}else if(pCenteringDrive.driveCenteringParam.centeringStage==CENTER_II_STAGE){
//				SParam auxPhyCoord=pCenteringDrive.driveCenteringParam.driveConditionParam.motor->getPhyCoord(&pCenteringDrive.driveCenteringParam.driveConditionParam.motor->behaveData);
//				
//				TIM6->PSC=(uint16_t)getClockDividerInUniformMovement(250, BASE_FREQUENCY_OF_TIM6, auxPhyCoord.precision);

//				if(oCheckSignalsAutWork.checkedResetSignals & nZWARCIE){ 	//sprawdzenie czy jest potwierdzenie braku zwarcia
//					pCenteringDrive.infoDrive=PRZEJ_ZREALIZOWANO;
//				}else	if(pCenteringDrive.driveCenteringParam.driveConditionParam.l_krok_pom>=(int)(DELAY_DISTANCE_02MM*pow_pp(10, auxPhyCoord.unit))/auxPhyCoord.precision){
//					pCenteringDrive.infoDrive=PRZEJ_PORZUCONO;
//					PAlertDialogConstruct(&dialog, infoTextList[idINDELIBLE_CIRCUIT], NULL, okText, NULL);
//				}else if(pCenteringDrive.driveCenteringParam.driveConditionParam.motor->isLimStopPush(&pCenteringDrive.driveCenteringParam.driveConditionParam.motor->behaveData, pCenteringDrive.driveCenteringParam.driveConditionParam.turn)){
//					pCenteringDrive.infoDrive=PRZEJ_PORZUCONO;
//					PAlertDialogConstruct(&dialog, infoTextList[idPUSH_LIMSTOP], NULL, okText, NULL);
//				}else{
//					checkDriveError(&pCenteringDrive.infoDrive);
//				}
//			
//			}


//			if(pCenteringDrive.infoDrive!=DRIVE_IN_PROGRESS || (pCenteringDrive.errorDrive & ZWR)){
//				TIM6->CR1&=~TIM_CR1_CEN;
//				TIM6->DIER&=~TIM_DIER_UIE;
//			}else{
//				pCenteringDrive.driveTimerService(&pCenteringDrive.driveCenteringParam.driveConditionParam);
//			}

//		}
//}

//void TIM4_IRQHandler(void)
//{

//	if((TIM4->DIER & TIM_DIER_UIE) && (TIM4->SR & TIM_SR_UIF)){	
////	if(TIM4->SR & TIM_SR_UIF){	
//		TIM4->SR&=~TIM_SR_UIF;

//		if(oKeyboard.KBR.KBRL & kSTOP){
//			oKeyboard.KBR.KBRL&=KBRL_CLR;
//			pDrive.algorithm.calcAndSetIndEndPointStrategy(&stepMotors, &pDrive.algorithm.params);
//		}
//	
//			SValue tabToComp[MAX_NO_MOTORS];
//			if(pDrive.algorithm.params.phyIndEndPoint.comparePointWithValTab(&pDrive.algorithm.params.phyIndEndPoint.data, phyCoord.getParamValues(&phyCoord.data, tabToComp, MAX_NO_MOTORS), MAX_NO_MOTORS)){	//jezeli wszystkie silniki zrealizowaly swoje przejazdy do punktu spauzowania ruchu
//				if(pDrive.algorithm.params.phyEndPoint.exacComparePoints(&pDrive.algorithm.params.phyEndPoint.data, &pDrive.algorithm.params.phyIndEndPoint.data)){	//jezeli wszystkie silniki zrealizowaly swoje przejazdy to ustaw flage kończącą przejazd
//					pDrive.infoDrive=PRZEJ_ZREALIZOWANO;	
//					oAutWorkFunctions.item&=~fIZR;
//				}else{
//					pDrive.infoDrive=PRZEJ_SPAUZOWANO;
//					PAlertDialogConstruct(&dialog, infoTextList[idSTOP_WORK], infoTextList[idASK_CONTINUE], okText, cancelText);
//				}
//			}else if((oCheckSignalsAutWork.checkedSetSignals & nZWARCIE) && !(oAutWorkFunctions.item & fIZR)){	//jezeli zdetekowano zwarcie to ustaw flage wstrzymującą przejazd
//				pDrive.infoDrive=PRZEJ_PORZUCONO;
//				PAlertDialogConstruct(&dialog, infoTextList[idCIRCUIT], NULL, okText, NULL);
//			}else{
//				checkDriveError(&pDrive.infoDrive);
//			}
//		
//		if(pDrive.infoDrive!=DRIVE_IN_PROGRESS){
//			TIM4->CR1&=~TIM_CR1_CEN;
//			TIM4->DIER &=~ TIM_DIER_UIE;
//		}else{	
//			pDrive.algorithm.timerServiceStrategy(&stepMotors, &pDrive.algorithm.params, pDrive.algorithm.TIM, BASE_FREQUENCY_OF_TIM4);
//			
//		}

//	}

//}


//void TIM7_IRQHandler(void){

//	if((TIM7->DIER & TIM_DIER_UIE) && (TIM7->SR & TIM_SR_UIF )){
//			TIM7->SR&=~TIM_SR_UIF;

//			
//			SValue tabToComp[MAX_NO_MOTORS];
//			if(pAutPathDrive.algorithm.params.arcPar.phyEndPoint.comparePointWithValTab(&pAutPathDrive.algorithm.params.arcPar.phyEndPoint.data, phyCoord.getParamValues(&phyCoord.data, tabToComp, MAX_NO_MOTORS), MAX_NO_MOTORS)){	//jezeli wszystkie silniki zrealizowaly swoje przejazdy do punktu spauzowania ruchu
//				pAutPathDrive.infoDrive=PRZEJ_ZREALIZOWANO;	
//				oAutWorkFunctions.item&=~fIZR;
//			}else if(stepMotors.isSomeLimStopPush(&stepMotors.data)){
//				pAutPathDrive.infoDrive=PRZEJ_PORZUCONO;
//				PAlertDialogConstruct(&dialog, infoTextList[idPUSH_LIMSTOP], NULL, okText, NULL);
//			}else if(oKeyboard.KBR.KBRL & kSTOP){
//				oKeyboard.KBR.KBRL&=KBRL_CLR;
//				pAutPathDrive.infoDrive=PRZEJ_SPAUZOWANO;
//				PAlertDialogConstruct(&dialog, infoTextList[idSTOP_WORK], infoTextList[idASK_CONTINUE], okText, cancelText);
//			}else if((oCheckSignalsAutWork.checkedSetSignals & nZWARCIE) && !(oAutWorkFunctions.item & fIZR)){	//jezeli zdetekowano zwarcie to ustaw flage wstrzymującą przejazd
//				pAutPathDrive.infoDrive=PRZEJ_PORZUCONO;
//				PAlertDialogConstruct(&dialog, infoTextList[idCIRCUIT], NULL, okText, NULL);
//			}else{
//				checkDriveError(&pAutPathDrive.infoDrive);
//			}
//			
//			if(pAutPathDrive.infoDrive!=DRIVE_IN_PROGRESS){	
//				TIM7->CR1&=~TIM_CR1_CEN;
//				TIM7->DIER&=~TIM_DIER_UIE;	
//			}else{
//							
//				drivePathArc(&stepMotors, &pAutPathDrive.algorithm.params.arcPar, &pAutPathDrive.algorithm.params.arcPar.phyStartPoint, &pAutPathDrive.algorithm.params.arcPar.phyEndPoint, 
//										pAutPathDrive.algorithm.params.arcPar.turnCircle, FORWARD, TIM7);
//			}
//		}

//}















//void checkDriveError(int *infoDrive){
//			_Bool rangeCoordError=false;
//			_Bool encoderError=false;
//	
//			for(int i=0; i<stepMotors.data.size; i++){
//				if(stepMotors.data.driver[i].behaveData.error==PHY_COORD_ERROR || stepMotors.data.driver[i].behaveData.error==BASE_COORD_ERROR){
//					rangeCoordError=true;
//				}else if(stepMotors.data.driver[i].behaveData.error==SAFTY_STEP_COUNTER_ERROR)encoderError=true;
//				stepMotors.data.driver[i].behaveData.error=0;
//			}
//	
//	
//			if(rangeCoordError){		
//				PAlertDialogConstruct(&dialog, infoTextList[idCOORD_OVERFLOW], NULL, okText, NULL);
//				*infoDrive=PRZEJ_PORZUCONO;
//			}else if(encoderError){		
//				PAlertDialogConstruct(&dialog, infoTextList[idLINEAR_CRITICAL_ERROR], NULL, okText, NULL);
//				*infoDrive=PRZEJ_PORZUCONO;
//			}else if(oCheckSignalsMotorOverload.checkedResetSignals & mAC_SERVO_TPOS_X){	
//				PAlertDialogConstruct(&dialog, infoTextList[idOVERLOAD_X_DRIVE], NULL, okText, NULL);
//				*infoDrive=PRZEJ_PORZUCONO;
//			}else if(oCheckSignalsMotorOverload.checkedResetSignals & mAC_SERVO_TPOS_Y){	
//				PAlertDialogConstruct(&dialog, infoTextList[idOVERLOAD_Y_DRIVE], NULL, okText, NULL);
//				*infoDrive=PRZEJ_PORZUCONO;
//			}else if(oCheckSignalsMotorOverload.checkedResetSignals & mAC_SERVO_TPOS_Z){	
//				PAlertDialogConstruct(&dialog, infoTextList[idOVERLOAD_Z_DRIVE], NULL, okText, NULL);
//				*infoDrive=PRZEJ_PORZUCONO;
//			}
//}


//void TIM5_IRQHandler(void)
//{	
//	
//	extern PSemaphore xChangeParSemaphore;
//	extern PQueue qCommand;
//	extern PSemaphore xCommandSemaphore;
//	
//	
//	static unsigned int i=0, j=0;
//	static _Bool waitScreenDisplay=false;
//	

//	if((TIM5->DIER & TIM_DIER_UIE) && (TIM5->SR & TIM_SR_UIF )){	//jeżeli jest włączone przerwanie od przepełnienia timera	i timer się przepełnił to wykonaj podprogram
//			TIM5->CR1 &= ~TIM_CR1_CEN;
//			TIM5->SR &= ~TIM_SR_UIF;		//wyzerowanie flagi przerwania
//			i++;

//		
//			if(xChangeParSemaphore.tryAcquire(xChangeParSemaphore.available, 1) && !oComunicationUART3.transmitParam.busy){
//				xChangeParSemaphore.acquire(&xChangeParSemaphore.available, 1);
//						
//				if(workParams.getParamValue(&workParams.data, 'T')==calculateMostEffImpulseUS(effPar.AimpulseUSmostEffCurrentAPlot, effPar.BimpulseUSmostEffCurrentAPlot, workParams.getParamValue(&workParams.data, 'a'))){		
//					expectedRoughnessNM=calculateRoughnessNMbaseCurrentA(effPar.AroughnessNMcurrentAPlot, effPar.BroughnessNMcurrentAPlot, workParams.getParamValue(&workParams.data, 'a'));
//				}else{
//					expectedRoughnessNM=getRoughnessNMfromTab(effPar.roughnessNMtab, workParams.getParamValue(&workParams.data, 'a'), workParams.getParamValue(&workParams.data, 'T'));
//				}
//				
//				char lineWithPar[64]={0};
//				sprintf(oComunicationUART3.transmitParam.buforTx, "AT+PAR %s\r\n", workParams.getStringWithParams(&workParams.data, lineWithPar, sizeof(lineWithPar)));
//				wyslijUART_ISR(oComunicationUART3.transmitParam.UARTx, oComunicationUART3.transmitParam.buforTx, NULL);
//			}

//			if(!qTool.isEmpty(&qTool.data) && !oComunicationUART3.transmitParam.busy){
//				int toolCommandToSend=qTool.dequeue(&qTool.data);
//				
//				if(toolCommandToSend<=NR_OF_TOOLS){
//					sprintf(oComunicationUART3.transmitParam.buforTx, "AT+TOOLON T%i\r\n", toolCommandToSend);
//				}else{
//					sprintf(oComunicationUART3.transmitParam.buforTx, "AT+TOOLOFF T%i\r\n", toolCommandToSend-NR_OF_TOOLS);
//				}
//			
//				wyslijUART_ISR(oComunicationUART3.transmitParam.UARTx, oComunicationUART3.transmitParam.buforTx, NULL);
//				
//			}
//		
//			//sprawdzanie klawiatury
//			if(!(i%10)){
//				oKeyboard.readKeyboard(oKeyboard.port, &oKeyboard.KBR, &oKeyboard.checkingLine, &oKeyboard.checkingButton, &oKeyboard.step, B_LOW);
//				
//				
//				if(oKeyboard.KBR.KBRH & kIZR){	
//					oAutWorkFunctions.item^=fIZR;
//					oKeyboard.KBR.KBRH&=KBRH_CLR;
//				}
//						

//				oComunicationUART3.getAutWorkParamByUARTComunication(&oComunicationUART3.transmitParam, &workParams, &xChangeParSemaphore, &qCommand, &xCommandSemaphore, &baseCoord, &oErrors);

//				if(oScreen.idScreen==idAUT_WORK_SCREEN){
//					_Bool changePar=false;
//					
//					oJoystick.scrollCursorY(&oKeyboard.KBR, workParams.data.size, 1, &oScreen.highlightedY);
//					
//					if(oKeyboard.KBR.KBRL & k4){	
//						oAutWorkFunctions.item^=fWIB;
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}else if(oKeyboard.KBR.KBRL & k3){	
//						oAutWorkFunctions.item^=fDET_P;
//						if((oAutWorkFunctions.item) & fDET_P)qTool.enqueue(&qTool.data, AT_TAG_DET_P_ON);
//						else qTool.enqueue(&qTool.data, AT_TAG_DET_P_OFF);
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}else if(oKeyboard.KBR.KBRL & k2){	
//						if(effPar.erodeName[0]!='\0' && electrode.name[0]!='\0' && oMachineConfig.workSurfaceMM2>0){
//							int newCurrent, newImpulse, newBreak;
//						
//							newCurrent=calculateMostEffCurrent(electrode.currentDensityA_MM2, oMachineConfig.workSurfaceMM2);
//							workParams.setParamValue(&workParams.data, 'a', newCurrent);
//							
//							newImpulse=calculateMostEffImpulseUS(effPar.AimpulseUSmostEffCurrentAPlot, effPar.BimpulseUSmostEffCurrentAPlot, workParams.getParamValue(&workParams.data, 'a'));
//							workParams.setParamValue(&workParams.data, 'T', newImpulse);

//							newBreak=calculateMostEffTimeOfBreakUS(electrode.TimeOfBreakDivider, newImpulse);
//							workParams.setParamValue(&workParams.data, 't', newBreak);
//														
//							workParams.setParamValue(&workParams.data, 'P', effPar.threshOfWork);
//							workParams.setParamValue(&workParams.data, 'z', effPar.threshOfCircuit);
//							
//							changePar=true;
//						}
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}else if(oKeyboard.KBR.KBRL & k1){	
//						if(effPar.erodeName[0]!='\0' && electrode.name[0]!='\0' && oMachineConfig.workSurfaceMM2>0 && oMachineConfig.desiredRaNM>0){
//							int newCurrent1, newCurrent2,  newImpulse, newBreak;
//							
//							newCurrent1=calculateMostEffCurrent(electrode.currentDensityA_MM2, oMachineConfig.workSurfaceMM2);
//							newCurrent2=calculateCurrentAbaseRoughnessNM(effPar.AroughnessNMcurrentAPlot, effPar.BroughnessNMcurrentAPlot, oMachineConfig.desiredRaNM);	
//							(newCurrent2<newCurrent1)?workParams.setParamValue(&workParams.data, 'a', newCurrent2):workParams.setParamValue(&workParams.data, 'a', newCurrent1);	
//							
//							newImpulse=calculateMostEffImpulseUS(effPar.AimpulseUSmostEffCurrentAPlot, effPar.BimpulseUSmostEffCurrentAPlot, workParams.getParamValue(&workParams.data, 'a'));
//							workParams.setParamValue(&workParams.data, 'T', newImpulse);

//							newBreak=calculateMostEffTimeOfBreakUS(electrode.TimeOfBreakDivider, newImpulse);
//							workParams.setParamValue(&workParams.data, 't', newBreak);
//														
//							workParams.setParamValue(&workParams.data, 'P', effPar.threshOfWork);
//							workParams.setParamValue(&workParams.data, 'z', effPar.threshOfCircuit);
//							
//							changePar=true;
//						}
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}else if(oKeyboard.KBR.KBRL & kA){	
//						oAutWorkFunctions.item^=fAUT_ROZ;
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}else if(oKeyboard.KBR.KBRL & (kSP | kSL)){
//						char acronims[workParams.data.size];
//								
//						workParams.getParamsAcronims(&workParams.data, acronims, sizeof(acronims));
//						
//						if(oScreen.highlightedY<=workParams.data.size){
//							switch(acronims[oScreen.highlightedY-1]){
//								case 'a':	
//											if(oKeyboard.KBR.KBRL & kSL)changePar=workParams.decrementValue(workParams.getParamPtr(&workParams.data, 'a'), workParams.getParamPrecision(&workParams.data, 'a'));
//											else if(oKeyboard.KBR.KBRL & kSP)changePar=workParams.incrementValue(workParams.getParamPtr(&workParams.data, 'a'), workParams.getParamPrecision(&workParams.data, 'a'));
//							
//											if(changePar){
//												if(effPar.erodeName[0]!='\0' && electrode.name[0]!='\0'){
//													int newImpulse, newBreak;
//													
//													newImpulse=calculateMostEffImpulseUS(effPar.AimpulseUSmostEffCurrentAPlot, effPar.BimpulseUSmostEffCurrentAPlot, workParams.getParamValue(&workParams.data, 'a'));
//													workParams.setParamValue(&workParams.data, 'T', newImpulse);

//													newBreak=calculateMostEffTimeOfBreakUS(electrode.TimeOfBreakDivider, newImpulse);
//													workParams.setParamValue(&workParams.data, 't', newBreak);
//													
//												}
//											}
//											break;
//							case 'T':	
//											if(oKeyboard.KBR.KBRL & kSL)changePar=workParams.decrementValue(workParams.getParamPtr(&workParams.data, 'T'), workParams.getParamPrecision(&workParams.data, 'T'));
//											else if(oKeyboard.KBR.KBRL & kSP)changePar=workParams.incrementValue(workParams.getParamPtr(&workParams.data, 'T'), workParams.getParamPrecision(&workParams.data, 'T'));
//							
//											if(changePar){
//												if(electrode.name[0]!='\0'){
//													int newBreak=calculateMostEffTimeOfBreakUS(electrode.TimeOfBreakDivider, workParams.getParamValue(&workParams.data, 'T'));
//													workParams.setParamValue(&workParams.data, 't', newBreak);
//												}
//											}
//											break;
//							default:	
//											if(oKeyboard.KBR.KBRL & kSL)changePar=workParams.decrementValue(workParams.getParamPtr(&workParams.data, acronims[oScreen.highlightedY-1]), workParams.getParamPrecision(&workParams.data, acronims[oScreen.highlightedY-1]));
//											else if(oKeyboard.KBR.KBRL & kSP)changePar=workParams.incrementValue(workParams.getParamPtr(&workParams.data, acronims[oScreen.highlightedY-1]), workParams.getParamPrecision(&workParams.data, acronims[oScreen.highlightedY-1]));
//											break;
//							}
//						}
//						
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}
//					
//					if(changePar)xChangeParSemaphore.release(&xChangeParSemaphore.available, 1);
//					
//				}else if(oScreen.idScreen==idDRIVE_SCREEN || oScreen.idScreen==idSTEP_DRIVE_SCREEN || oScreen.idScreen==idHAND_WORK_SCREEN){
//						
//					if(oKeyboard.KBR.KBRL & (kSP | kSL)){
//						if(oKeyboard.KBR.KBRL & kSL)workParams.decrementValue(workParams.getParamPtr(&workParams.data, 'J'), workParams.getParamPrecision(&workParams.data, 'J'));
//						else if(oKeyboard.KBR.KBRL & kSP)workParams.incrementValue(workParams.getParamPtr(&workParams.data, 'J'), workParams.getParamPrecision(&workParams.data, 'J'));
//						oKeyboard.KBR.KBRL&=KBRL_CLR;
//					}
//				}else if(oScreen.idScreen==idALERT_DIALOG_SCREEN){
//						if(oErrors.item!=0){
//						char line[P_DIALOG_MESSAGE_MAX_SIZE]={0};
//						char mes[P_DIALOG_MESSAGE_MAX_SIZE]={0};
//						int noOfErr=1;
//						
//						for(int k=0; k<oErrors.nrOfItems; k++){;
//							if((oErrors.item & (1<<k))){
//								sprintf(line, "%i.%s\n", noOfErr, (*oErrors.itemsList)[k]);
//								strncat(mes, line, P_DIALOG_MESSAGE_MAX_SIZE-strlen(mes));
//								noOfErr++;
//							}
//						}	
//						oErrors.item=0;
//						PAlertDialogConstruct(&dialog, infoTextList[idLIST_OF_ERRORS], mes, okText, NULL);
//					}
//					
//				}
//				
//			}
//			
//			//w przypadku programowego wygenerowania ZSAP blokowane jest zezwolenie na włączenie generatora
//			if(oCheckSignalsAutWork.checkedResetSignals & nZSAP){
//				PIN_CLR(GPIOD, NZPA_GEN);
//			}else{
//				PIN_SET(GPIOD, NZPA_GEN);
//			}

//			//programowe wygenerowanie ZSAP nie może blokować włączenia generatora dłużej niż 50ms
//			if(oCheckSignalsAutWork.checkedResetSignals & nZSAP){
//				j++;
//				if(!(j%125)){oCheckSignalsAutWork.checkedResetSignals&=~nZSAP; j=0;}
//			}

//			//sprawdzenie sygnałów wejściowych w trakcie pracy automatycznej
//			oCheckSignalsAutWork.checkSignal(oCheckSignalsAutWork.port, wejSYGP, B_LOW, nSYGP, &oCheckSignalsAutWork.currCheckingResetSignals, &oCheckSignalsAutWork.checkedResetSignals);
//			oCheckSignalsAutWork.checkSignal(oCheckSignalsAutWork.port, wejZSA, B_LOW, nZSA, &oCheckSignalsAutWork.currCheckingResetSignals, &oCheckSignalsAutWork.checkedResetSignals);
//			oCheckSignalsAutWork.checkSignal(oCheckSignalsAutWork.port, wejOWE, B_LOW, nOWE, &oCheckSignalsAutWork.currCheckingResetSignals, &oCheckSignalsAutWork.checkedResetSignals);
//			oCheckSignalsAutWork.checkSignal(oCheckSignalsAutWork.port, wejCplus, B_HIGH, nZWARCIE, &oCheckSignalsAutWork.currCheckingSetSignals, &oCheckSignalsAutWork.checkedSetSignals);
//			oCheckSignalsAutWork.checkSignal(oCheckSignalsAutWork.port, wejCplus, B_LOW, nZWARCIE, &oCheckSignalsAutWork.currCheckingResetSignals, &oCheckSignalsAutWork.checkedResetSignals);

//			//sprawdzenie krańcówek
//			
//			checkSigLimStopX.checkSignal(checkSigLimStopX.port, PIN_KRAN_Xplus, B_HIGH, FORWARD_LIM_STOP_MASK, &checkSigLimStopX.currCheckingSetSignals, &checkSigLimStopX.checkedSetSignals);
//			checkSigLimStopX.checkSignal(checkSigLimStopX.port, PIN_KRAN_Xmin, B_HIGH, BACKWARD_LIM_STOP_MASK, &checkSigLimStopX.currCheckingSetSignals, &checkSigLimStopX.checkedSetSignals);
//			checkSigLimStopY.checkSignal(checkSigLimStopY.port, PIN_KRAN_Yplus, B_HIGH, FORWARD_LIM_STOP_MASK, &checkSigLimStopY.currCheckingSetSignals, &checkSigLimStopY.checkedSetSignals);
//			checkSigLimStopY.checkSignal(checkSigLimStopY.port, PIN_KRAN_Ymin, B_HIGH, BACKWARD_LIM_STOP_MASK, &checkSigLimStopY.currCheckingSetSignals, &checkSigLimStopY.checkedSetSignals);
//			checkSigLimStopZ.checkSignal(checkSigLimStopZ.port, PIN_KRAN_Zplus, B_HIGH, FORWARD_LIM_STOP_MASK, &checkSigLimStopZ.currCheckingSetSignals, &checkSigLimStopZ.checkedSetSignals);
//			checkSigLimStopZ.checkSignal(checkSigLimStopZ.port, PIN_KRAN_Zmin, B_HIGH, BACKWARD_LIM_STOP_MASK, &checkSigLimStopZ.currCheckingSetSignals, &checkSigLimStopZ.checkedSetSignals);


//			//sprawdzenie przeciążenia silników
//				oCheckSignalsMotorOverload.checkSignal(oCheckSignalsMotorOverload.port, PIN_AC_SERVO_TPOS_X, B_LOW, mAC_SERVO_TPOS_X, &oCheckSignalsMotorOverload.currCheckingResetSignals, &oCheckSignalsMotorOverload.checkedResetSignals);
//				oCheckSignalsMotorOverload.checkSignal(oCheckSignalsMotorOverload.port, PIN_AC_SERVO_TPOS_Y, B_LOW, mAC_SERVO_TPOS_Y, &oCheckSignalsMotorOverload.currCheckingResetSignals, &oCheckSignalsMotorOverload.checkedResetSignals);
//				oCheckSignalsMotorOverload.checkSignal(oCheckSignalsMotorOverload.port, PIN_AC_SERVO_TPOS_Z, B_LOW, mAC_SERVO_TPOS_Z, &oCheckSignalsMotorOverload.currCheckingResetSignals, &oCheckSignalsMotorOverload.checkedResetSignals);	

//			if(!(i%500)){
//				
//				if(oProg.interpretProgParam.interpret && waitScreenDisplay==false){
//					lcd.reset(&lcd.data, 1);
//					oScreen.displayWaitScreen(&lcd);
//					
//					waitScreenDisplay=true;
//				}else if(oProg.interpretProgParam.interpret==false && waitScreenDisplay==true){
//					lcd.reset(&lcd.data, 1);
//					waitScreenDisplay=false;
//				}
//				
//				if(waitScreenDisplay==false){
//					if(oScreen.previousIdScreen!=oScreen.idScreen){
//						lcd.reset(&lcd.data, oScreen.dispParam.nrOfPage);
//						oScreen.dispParam.nrOfPage=1;
//						oScreen.previousIdScreen=oScreen.idScreen;
//						oScreen.highlightedX=1;
//						oScreen.highlightedY=1;
//					}
//					
//					switch(oScreen.idScreen){
//						case idHAND_WORK_SCREEN:
//							oScreen.displayHandWorkScreen(&lcd, &stepMotors, &oMenu.menuParam, oScreen.highlightedY, &oClockRTC, &oAutWorkFunctions, &workParams);
//							break;
//						case idDRIVE_SCREEN:
//							oScreen.displayDriveScreen(&lcd, &stepMotors, &oMenu.menuParam, &oClockRTC,  &oAutWorkFunctions, &workParams);
//							break;
//						case idSTEP_DRIVE_SCREEN:
//							oScreen.displayStepDriveScreen(&lcd, &stepMotors, &oMenu.menuParam, &oClockRTC, &oAutWorkFunctions, pDrive.stepDrive, &workParams);
//							break;
//						case idAUT_WORK_SCREEN:		
//							oScreen.displayAutWorkScreen(&lcd, &stepMotors, &oMenu.menuParam, &oSystemsData.oTimeOfWork.time, &oAutWorkFunctions, &workParams, &progFileInfo, oScreen.highlightedY, expectedRoughnessNM);
//							break;
//						case idINPUT_SCREEN:
//							oScreen.displayInputScreen(&lcd, &auxCoord, &oMenu.menuParam, entryList.data.names[0], oScreen.markEntryField, &oClockRTC, &oAutWorkFunctions, signToWrite);
//							break;
//						case idLIST_BASE_COORD:
//							oScreen.displayListBaseCoordScreen(&lcd, gBasePoints, noOfGBase, &oMenu.menuParam, oScreen.highlightedX, oScreen.highlightedY);
//							break;
//						case idLIST_PROG:
//							oScreen.displayListProgScreen(&lcd, &progList.data, &progFileInfo, &oMenu.menuParam, oScreen.highlightedY);
//							break;
//						case idCHANGE_TIME:
//							oScreen.displayChangeTimeScreen(&lcd, &oClockRTC.auxTime, &oMenu.menuParam, oScreen.highlightedX);
//							break;
//						case idSTAT:
//							oScreen.displayStatScreen(&lcd, &oScreen.dispParam, &statFile);
//							oScreen.idScreen=LACK_ofIdSCREEN;
//							oScreen.previousIdScreen=oScreen.idScreen;
//							break;
//						case idLANGUAGE:
//							oScreen.displaySelectListScreen(&lcd, &oMenu.menuParam, &oLanguage, oScreen.highlightedY);
//							break;
//						case idEQUIPMENT:
//							oScreen.displaySelectListScreen(&lcd, &oMenu.menuParam, &oEquipment, oScreen.highlightedY);
//							break;
//						case idSELECT_CURRENT_BLOCK:
//							oScreen.displaySelectListScreen(&lcd, &oMenu.menuParam, &oCurrentBlock, oScreen.highlightedY);
//							break;
//						case idSELECT_TYPE_OF_MOTOR:
//							oScreen.displaySelectListScreen(&lcd, &oMenu.menuParam, &oTypeOfMotor, oScreen.highlightedY);
//							break;
//						case idSELECT_LINEARS_MOTORS_PRECISION:
//							oScreen.displaySelectListScreen(&lcd, &oMenu.menuParam, &oStepPrecision, oScreen.highlightedY);
//							break;
//						case idFEATURES:
//							oScreen.displayFeaturesScreen(&lcd, &oMenu.menuParam, &oFeatures, oScreen.highlightedY);
//							break;
//						case idFILE_VIEW:
//							if(fileRawsReserve.tryTake(fileRawsReserve.available)){
//								fileRawsReserve.take(&fileRawsReserve.available);
//								{
//									oScreen.displayTextFileScreen(&lcd, &oMenu.menuParam, &oScreen.dispParam, &fileRaws, oScreen.highlightedX, oScreen.highlightedY, signToWrite);
//								}
//								fileRawsReserve.give(&fileRawsReserve.available);		
//							}
//							break;
//						case idGET_FILE_NAME:
//							oScreen.displayInputListScreen(&lcd, &oMenu.menuParam, &editLinesList.data, oScreen.markEntryField, oScreen.highlightedX, oScreen.highlightedY, signToWrite);
//							break;
//						case idWRITE_GPROG:
//							oScreen.displayWriteNewGprogScreen(&lcd, &oDataNewGprog.paramNewGprog, &oMenu.menuParam, oScreen.markEntryField, oScreen.highlightedX, oScreen.highlightedY, signToWrite);
//							break;
//						case idALERT_DIALOG_SCREEN:
//							oScreen.displayAlertDialogScreen(&lcd, &dialog.data);
//							break;
//						case idLIST_EFF_PAR:
//							oScreen.displayMaterialListScreen(&lcd, &effParamsList.data, &effPar, &oMenu.menuParam, oScreen.highlightedY);
//							break;
//						case idINFO:
//							oScreen.displayInfoScreen(&lcd, &oSystemsData, oMenu.menuParam.header);
//							break;
//						case idINPUT_MACHINE_PARAMS:
//							oScreen.displayInputListScreen(&lcd, &oMenu.menuParam, &editLinesList.data, oScreen.markEntryField, oScreen.highlightedX, oScreen.highlightedY, signToWrite);
//							break;
//						case idINPUT_MACHINE_MOTION_PARAMS:
//							oScreen.displayInputListScreen(&lcd, &oMenu.menuParam, &editLinesList.data, oScreen.markEntryField, oScreen.highlightedX, oScreen.highlightedY, signToWrite);
//							break;
//					}	
//				}
//				
//			}

//			if(i>=0xFFFFFFF0)i=0;
//			
//			TIM5->CR1 |= TIM_CR1_CEN;
//	}
//}



