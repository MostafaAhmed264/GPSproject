#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "string.h"
#include "tm4c123.h"
char readChar() {
    while ((UART7_FR_R & 0x0010) != 0);
    return ((char)UART7_DR_R & 0xFF);
}


char* getDest() {

    static char dest[21];
    char arr[70];
    int i = 0;
    int k = 0;
    int x = 1;
    int y = 1;
    GPIO_PORTF_DATA_R = 0x02;
    while (y) {
        int f;
        char arr3[6];
        for (f = 0; f < 6; ++f) {
            arr3[f] = readChar();
        }
        if (strcmp(arr3, "$GPRMC") == 0 || strcmp(arr3, "$GPGGA") == 0) {
            GPIO_PORTF_DATA_R = 0x08;
            y = 0;
        }

    }


    while (x) {

        arr[i] = readChar();

        if ((arr[i] == 'N') || (arr[i] == 'S')) {
            int j = i;

            while (arr[j - 2] != ',') {
                dest[k] = arr[j - 2]; // put number between two commas in reverse order in array example:,12345.678 -->{8,7,6,.,5,4,3,2,1}
                k++;
                j--;

            }


        }

        else if ((arr[i] == 'E') || (arr[i] == 'W'))
        {
            int j = i;


            while (arr[j - 2] != ',')
            {
                dest[k] = arr[j - 2];
                k++;
                j--;
            }
            x = 0;
        }

        i++;
    }
    GPIO_PORTF_DATA_R = 0x04;
    return dest;
}
char* sortDestN()
{
    static char sortedDestN[10];
    int j = 0;
    char* d = dest;
    int i;
    for (i = 9; i >= 0; --i)
    {

        sortedDestN[j] = d[i];
        j++;
    }

    return sortedDestN;
}

char* sortDestE()
{
    static char sortedDestE[11];
    int j = 0;
    char* d = dest;
    int i;
    GPIO_PORTF_DATA_R = 0x02;
    for (i = 20; i >= 10; --i)
    {

        sortedDestE[j] = d[i];
        j++;
    }

    return sortedDestE;
}
int* charToIntN(char *c)
    {

        char *d = c;
        static int intNDest[9];
        int j=0;
            int i;

        for ( i = 0; i < 9; ++i)
        {


            switch (d[i])
            {

            case '0':
                intNDest[j] = 0;
                j++;
                break;
            case '1':
                intNDest[j] = 1;
                j++;
                break;
            case '2':
                intNDest[j] = 2;
                j++;
                break;
            case '3':
                intNDest[j] = 3;
                j++;
                break;
            case '4':
                intNDest[j] = 4;
                j++;
                break;
            case '5':
                intNDest[j] = 5;
                j++;
                break;
            case '6':
                intNDest[j] = 6;
                j++;
                break;
            case '7':
                intNDest[j] = 7;
                j++;
                break;
            case '8':
                intNDest[j] = 8;
                j++;
                break;
            case '9':
                intNDest[j] = 9;
                j++;
                break;
            default:
                continue;
            }
        }

        return     intNDest;
    }
int *charToIntE(char *c) {
    char *d = c;
    static int intDest[10];
    int j = 0;
int i;

        for (i = 0; i < 10; ++i)
    {

        switch (d[i])
        {

        case '0':
            intDest[j] = 0;
            j++;
            break;
        case '1':
            intDest[j] = 1;
            j++;
            break;
        case '2':
            intDest[j] = 2;
            j++;
            break;
        case '3':
            intDest[j] = 3;
            j++;
            break;
        case '4':
            intDest[j] = 4;
            j++;
            break;
        case '5':
            intDest[j] = 5;
            j++;
            break;
        case '6':
            intDest[j] = 6;
            j++;
            break;
        case '7':
            intDest[j] = 7;
            j++;
            break;
        case '8':
            intDest[j] = 8;
            j++;
            break;
        case '9':
            intDest[j] = 9;
            j++;
            break;
        default:
            continue;
        }
    }

    return intDest;
    }

float getLatitude(int* x){
	
	int degrees;
	float minutes;
	float latitude;
	//SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2));
	degrees = x[0]*10 + x[1];
	//minutes =(x[2] * 10) + (x[3]) + (x[4] * 0.1) + (x[5] * 0.01) + (x[6] * 0.001) + (x[7] * 0.0001) + (x[8] * 0.00001);
	//latitude = degrees + (minutes* 0.0166667);

	 
	minutes = (x[2] * 10);
	minutes += x[3];
minutes += x[4] * 0.1;
	minutes += (x[5] * 0.01);
	minutes += (x[6] * 0.001);
minutes += (x[7] * 0.0001);
minutes += x[8] * 0.00001;
	latitude = degrees +  minutes/60.00;
	return latitude;
}
		
		
float getLongitude(int* x){

	int degrees;
	float minutes;
	float longitude;
	//	SCB->CPACR|=((3UL<<10*2)|(3UL<<11*2));
	degrees = x[0]*100 + x[1]*10+x[2];
	//minutes =x[3]*10 + x[4] + (x[5] / 10.0) + (x[6] / 100.0) + (x[7] / 1000.0) + (x[8] / 10000.0) + (x[9]/100000.0);
	minutes = (x[2] * 10);
	minutes += x[3];
	minutes += x[4] * 0.1;
	minutes += (x[5] * 0.01);
	minutes += (x[6] * 0.001);
	minutes += (x[7] * 0.0001);
	minutes += x[8] * 0.00001;
	//minutes+=(x[9]/100000.0);
	longitude = degrees +  minutes/60.00;
	return longitude;
}

