

void lights_off()
// Turns off all three digits  
{
  
}


void turnON_Digit(int number) 
{ // Turns on a single digit 
  switch (number) 
  {
    // first digit
    case 1:  
      GPIO_PORTD_DATA_R|=0x01;
      break;
    // second digit 
    case 2:
      GPIO_PORTD_DATA_R|=0x02;
      break;
    // third digit 
    case 3:
      GPIO_PORTD_DATA_R|=0x04;
      break;
  }
}


void turnOFF_Digit(int number) 
{ // Turns OFF a single digit 
  switch (number) 
  {
    // first digit
    case  1:  
      GPIO_PORTD_DATA_R&=~0x01;
      break;
    // second digit 
    case 2:
      GPIO_PORTD_DATA_R&=~0x02; 
      break;
    // third digit 
    case 3:
      GPIO_PORTD_DATA_R&=~0x04;
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
      GPIO_PORTB_DATA_R=0x5B; // a b g e d
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

while (n != 0)//get number of digits
{
    n /= 10;
    c++;
}

int numberArray[c];

c = 0;    
n = number;

/* extract each digit */
while (n != 0)// if we n= 100  numberArray[]={0,0,1}
{
    numberArray[c] = n % 10;
    n /= 10;
    c++;
}
if(number>=100)
{
    while(true)//if you need to make the bonus change true 
        //turning on digit one and putting right most digit in it
        turnON_Digit(1);
        turnOFF_Digit(2);
        turnOFF_Digit(3);
        displayNum(numberArray[0]);
        //put for loop here for delay at testing

        //turning digit two and putting the middle digit in it
        turnON_Digit(2);
        turnOFF_Digit(1);
        turnOFF_Digit(3);
        displayNum(numberArray[1]);
        //put for loop here for delay at testing 

        //turning digit three and putting the left digit in it

        turnON_Digit(3);
        turnOFF_Digit(1);
        turnOFF_Digit(2);
        displayNum(numberArray[2]);
        //put for loop here for delay at testing
        

        





}





   
 
}
