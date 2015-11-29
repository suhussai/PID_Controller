#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pid.h"

int main(int argc, char argv[]) {
  
  int i = 0;
  float setPoint = 75.00;
  initialize_pid(); 
  for (i = 0; i < 15; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(i + 60), setPoint, PID((float)(i + 60), setPoint));
  }

  for (i = 0; i < 15; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(74 - i), setPoint, PID((float)(74 - i), setPoint));
  }  

  printf("-------------------------\n");
  printf("Changing setpoint to 90.00\n");
  printf("-------------------------\n");
  setPoint = 90.00;

  for (i = 0; i < 15; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(i + 60), setPoint, PID((float)(i + 60), setPoint));
  }

  for (i = 0; i < 15; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(74 - i), setPoint, PID((float)(74 - i), setPoint));
  }  


  printf("-------------------------\n");
  printf("Changing setpoint to 40\n");
  printf("-------------------------\n");
  setPoint = 40.00;


  for (i = 0; i < 15; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(i + 60), setPoint, PID((float)(i + 60), setPoint));
  }

  for (i = 0; i < 15; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(74 - i), setPoint, PID((float)(74 - i), setPoint));
  }  


  

  return 0;
}
