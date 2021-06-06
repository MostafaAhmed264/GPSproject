
#include "tm4c123gh6pm.h"

void displayNum(int number) 
{ // displays a number 0-9
  switch (number) 
  {
    case 0:
      GPIO_PORTB_DATA_R=0x3F; //all on except g
      break;
    case 1:
      GPIO_PORTB_DATA_R=0x06; //b and c on
      break;
    case 2:
      GPIO_PORTB_DATA_R=0x5B; // a b g e d
      break;  
		
   case 3:
      GPIO_PORTB_DATA_R=0x4F; // a b c d g
      break;
   case 4:
      GPIO_PORTB_DATA_R=0x66; // b c f g
      break;
  case 5:
      GPIO_PORTB_DATA_R=0x5D; //a f g c d
      break;  
  case 6:
      GPIO_PORTB_DATA_R=0x7D; // all except b
      break;   
  case 7:
      GPIO_PORTB_DATA_R=0x70; // a b c
      break;
  case 8:
      GPIO_PORTB_DATA_R=0x7F; // all
      break;
  case 9:
      GPIO_PORTB_DATA_R=0x6F; // all except e
      break;
  }
}