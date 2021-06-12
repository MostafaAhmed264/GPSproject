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