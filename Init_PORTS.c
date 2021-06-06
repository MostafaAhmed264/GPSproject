#include "tm4c123gh6pm.h"

void Init_PORT (void)
{



// PORT B 
SYSCTL_RCGCGPIO_R |= 0x02;
while ((SYSCTL_PRGPIO_R&0x02) == 0){};
GPIO_PORTB_LOCK_R = 0x4C4F434B; // unlocking the port B
GPIO_PORTB_CR_R = 0xFF; // Allow changes to PB321
GPIO_PORTB_DIR_R = 0XFF; // setting direction register "output"
GPIO_PORTB_DEN_R = 0xFF; // 
GPIO_PORTB_AMSEL_R = 0x00; 
GPIO_PORTB_AFSEL_R  = 0x00; 
GPIO_PORTB_PCTL_R  = 0x00000000; 
GPIO_PORTB_DATA_R = 0x00 ; 

// PORT F

SYSCTL_RCGCGPIO_R |= 0x20; 
while ((SYSCTL_PRGPIO_R&0x20) == 0){};  
GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlocking the port F
GPIO_PORTF_CR_R |= 0x0E; // Allow changes to PA321
GPIO_PORTF_DIR_R |= 0X0E; // setting direction register "output"
GPIO_PORTF_DEN_R |= 0x0E; 
GPIO_PORTF_AMSEL_R &= ~0x0E; 
GPIO_PORTF_AFSEL_R &=~0x00;
GPIO_PORTF_PCTL_R = 0x00000000;  
GPIO_PORTF_DATA_R = 0x00;

//portD   
SYSCTL_RCGCGPIO_R |= 0x08;
while ((SYSCTL_PRGPIO_R&0x08) == 0){}; 	
GPIO_PORTD_LOCK_R = 0x4C4F434B; // unlocking the port F
GPIO_PORTD_CR_R = 0x07; // Allow changes to PA321
GPIO_PORTD_DIR_R = 0X07; // setting direction register "output"
GPIO_PORTD_DEN_R = 0x07; 
GPIO_PORTD_AMSEL_R = 0x00; 
GPIO_PORTD_AFSEL_R = 0x00;
GPIO_PORTD_PCTL_R  = 0x00000000;  
GPIO_PORTD_DATA_R = 0x00; 


}
