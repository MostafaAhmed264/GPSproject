#include <stdio.h>
#include <math.h>
#include "tm4c123.h"
#include "tm4c123gh6pm.h"
extern void displayNum3(int number);
extern void Init_PORT(void); 
extern double distance(double x1, double x2, double y1, double y2);
extern double totalDistance(double distance);
extern void lightLed(void);
extern int int_total_Distance();
extern float arrToNumE(int *x);
extern float total_Distance;
extern int *charToIntE(char *c);
extern char* sortDestE();
extern int* charToIntN(char *c);
extern char* sortDestN();
extern float arrToNumN(int *x);
extern void test(void);
extern char readChar();
extern float getDistanceFromLatLonInM(float lat1,float lon1,float lat2,float lon2);
extern void delay_ms(int n);
extern void LCD_Cmd(unsigned char command);
extern void LCD_Write_Char(unsigned char data) ;
extern void LCD_String (char *str,int x);
extern void LCD_init(void) ;

extern char* makeArray();
extern float getLongitude(int* x);
extern float getLatitude(int* x);
extern float getDistanceFromLatLonInM(float lat1,float lon1,float lat2,float lon2);
extern void getDest();
void SystemInit();
#define clear_display     0x01  
#define moveCursorRight   0x06  
#define cursorBlink       0x0F  
#define Function_set_8bit 0x38  
#define Function_8_bit    0x32  
#define FirstRow          0x80  
#define SecondRow         0xC0  
#define RS 0x20 // PORTA BIT5 mask
#define RW 0x40 // PORTA BIT6 mask
#define EN 0x80 // PORTA BIT7 mask

void floatToString(char * x, float y){ 
	
	
	sprintf(x,"%f",y);
}
int main(){
	
int i=0;
char*x; 
char *m;
int* l; int* o;
float lat1,long1;
float lat2, long2;
char N[10];
	char M[11];
Init_PORT();
LCD_init();

	while (total_Distance <=100){
			
			GPIO_PORTF_DATA_R= 0x08;
			if (i==0){
				getDest();
				x =sortDestN();
				l = charToIntN(x);
				lat1 = getLatitude(l);
				m=sortDestE();
				o = charToIntE(m);
				long1 =	getLongitude(o);
				i++;
			}
				delay_ms(4000);
			getDest();
			x =sortDestN();
				l = charToIntN(x);
				lat2 = getLatitude(l);
				m=sortDestE();
				o = charToIntE(m);
				long2 =	getLongitude(o);
			total_Distance +=getDistanceFromLatLonInM( lat1,long1,lat2,long2);
			floatToString(N,total_Distance);
		//	floatToString(M,long1);			
			LCD_Cmd(clear_display);
 // WRITING IN THE FIRST ROW //
 
			
			LCD_Cmd(FirstRow); // Force cusor to begining of first row
			LCD_String(N,10);
//			LCD_Cmd(SecondRow); // Force cusor to begining of first row
//			LCD_String(M,11);
			lat1=lat2;
			long1 = long2;
			GPIO_PORTF_DATA_R= 0x02;
			
	
		}
		
			
	
}
