#include "tm4c123gh6pm.h"
#include "tm4c123.h"
#include <math.h>
#include <stdio.h>
#define PI 3.141592653589793238
float total_Distance = 105 ; 

float getDistanceFromLatLonInM(float lat1,float lon1,float lat2,float lon2) {
  int R = 6371; // Radius of the earth in km
  float dLat = ((lat2-lat1)*PI)/180;  
  float dLon = ((lon2-lon1)*PI)/180; 
  float a = sin(dLat/2) * sin(dLat/2) +  cos(((lat1)*PI)/180) * cos(((lat2)*PI)/180) * sin(dLon/2) * sin(dLon/2); 
  float c = 2 * atan2(sqrt(a), sqrt(1-a)); 
  float d = R * c; // Distance in km
  return d * 1000;
}

void calcTotalDistance(float distance){ 
	
	total_Distance += distance;
}


void lightLed(){
    if (total_Distance > 100){ 
        GPIO_PORTF_DATA_R |= 0x04; 
    }
}
int int_total_Distance(){ 
	
	return (int)(total_Distance); 
}