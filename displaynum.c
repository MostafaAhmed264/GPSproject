
#include "tm4c123gh6pm.h"
void delay(){
for (x = 1; x <= 100; x++)
for (d = 1; d <= 100;d++)
{}
}

void turnON_Digit(int number) 
{ // Turns on a single digit 
  switch (number) 
  {
    // first digit
    case 1:
      GPIO_PORTD_DATA_R=0x06;
      break;
    // second digit 
    case 2:
      GPIO_PORTD_DATA_R=0x05;
      break;
    // third digit 
    case 3:
      GPIO_PORTD_DATA_R=0x03;
      break;
  }
}
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
      GPIO_PORTB_DATA_R=0x6B; // a b g e d
      break;  
		
   case 3:
      GPIO_PORTB_DATA_R=0x4F; // a b c d g
      break;
   case 4:
      GPIO_PORTB_DATA_R=0x66; // b c f g
      break;
  case 5:
      GPIO_PORTB_DATA_R=0x6D; //a f g c d
      break;  
  case 6:
      GPIO_PORTB_DATA_R=0x7D; // all except b
      break;   
  case 7:
      GPIO_PORTB_DATA_R=0x07; // a b c
      break;
  case 8:
      GPIO_PORTB_DATA_R=0x7F; // all
      break;
  case 9:
      GPIO_PORTB_DATA_R=0x6F; // all except e
      break;
  }
}



void displayNum3(int number)
{
    /* count number of digits */
    int c = 0; /* digit position */
    int n = number;
    int numberArray[3] = { 0,0,0 };
    int x, d;
    /* extract each digit */
    while (n != 0)// if we n= 100  numberArray[]={0,0,1}
    {
        numberArray[c] = n % 10;
        n /= 10;
        c++;
    }

    while (1)//if you need to make the bonus change true 

    {

        //turning on digit one and putting right most digit in it
        turnON_Digit(3);
        displayNum(numberArray[0]);
        delay();
        //turning digit two and putting the middle digit in it
        turnON_Digit(2);
        displayNum(numberArray[1]);
        delay();
        //turning digit three and putting the left digit in it
        turnON_Digit(1);
        displayNum(numberArray[2]);
        delay();
        lightLed();
    }
}