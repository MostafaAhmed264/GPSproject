		#include "tm4c123gh6pm.h" 
		void UARTinit(){
		SYSCTL_RCGCUART_R=0X80;
    SYSCTL_RCGCGPIO_R|=0X10;
    while ((SYSCTL_PRGPIO_R&0x10) == 0){};
    UART7_CTL_R &=~ (0X00000001); // disable uart
    UART7_IBRD_R =104;
    UART7_FBRD_R =11;
    UART7_LCRH_R =0x00000070;
    UART7_CTL_R |=0x00000301;
    GPIO_PORTE_AFSEL_R|=0X03;
    GPIO_PORTE_DEN_R|=0X03;
    GPIO_PORTE_PCTL_R|=(GPIO_PORTE_PCTL_R&0XFFFFFF00)+0X00000011;
    GPIO_PORTE_AMSEL_R &=~0x03;
		}