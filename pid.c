#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define P 1
#define I 0.01
#define D 1

float accumulated_error = 0;
float time_called_previously = 0;
float past_temperature = 0;
time_t seconds = 0;
time_t time_passed = 0;


float PID(float currentTemp, float setPoint) {
  time_t seconds;
  seconds = time(NULL);

  // proportional part
  float p_value = 0;
  p_value = (currentTemp - setPoint) * P;
  

  // integral part
  time_passed = seconds - time_passed;
  accumulated_error = (currentTemp - accumulated_error)*(time_passed) + accumulated_error;
  float i_value = accumulated_error * I;
  
  float d_value = 0;
  d_value = (currentTemp - past_temperature) / (time_passed);
  d_value = d_value * D;

  time_passed = seconds;

  printf("p_value = %f, i_value = %f, d_value = %f\n", p_value, i_value, d_value);
  return p_value + i_value + d_value;
  
}


int main(int argc, char argv[]) {
  
  int i = 0;
  float setPoint = 75.00;
  time_passed = time(NULL);
  for (i = 0; i < 10; i++) {
    sleep(2);
    printf("currentTemp = %f, setPoint = %f, fanSpeed = %f \n", (float)(i + 60), setPoint, PID((float)(i + 60), setPoint));
  }  

  return 0;
}
