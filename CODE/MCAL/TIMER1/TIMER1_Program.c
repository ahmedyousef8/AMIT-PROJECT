#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"


//INITIALIZE TIMER 1 TO OPERATE IN PWM PHASE CORRECT MODE 
void PWM_INIT(void){
	// SELECT WAVE GENERATION MODE PHASE CORRECT 8BIT 
	/*Set OC1A/OC1B on compare match when upcounting. Clear OC1A/OC1B on compare
	match when downcounting*/

	TCCR1A_REG = 0b11110001; 
	TCCR1B_REG = 0b00000101; // SELECT THE 1024 PRE SCALER
	TIMSK_REG = 0b00000000; // DISABLE INTERUPT REG

}





void TIMR1_Stop(void){
	TCCR1B_REG  &= 0b11111000; //stop
}







//SELECT THE DESIRED DUTY CYCLE FOR THE TIMER TO OPERATE
void PWM(u8 dutyCycle)
{
	//SELECT THE TOP VALUE OF THE TIMER IN REGS OCR1A & OCR1B
	OCR1AL_REG = 255-((dutyCycle/100.0)*255);
	
	OCR1BL_REG = OCR1AL_REG;
   
	}

