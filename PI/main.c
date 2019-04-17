#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h> 
#include <unistd.h>
#include <math.h>


int save(double ap) {
  FILE *fp;
  fp = fopen("pi.dat", "w+");

  if(fp == NULL) {
    perror("Error fopen(...)");
    exit(-1);
  }

  fprintf(fp, "%f", ap);
  fclose(fp);

  return 0;
}

int readf(double *ap) {
  FILE *fp;
  fp = fopen("pi.dat", "r+");
  if(fp == NULL) {
    perror("Error fread(...)");
    exit(-1);
  }

  fscanf(fp, "%lf", ap);
  fclose(fp);
  return EXIT_SUCCESS;
}

double pi(int start, int end) {
  double out = 0.0;
  double signo = 1;
  double x = 0.0;

  for(unsigned long i = start; i < end; i+=2) {
    x = (double)(1.0/(double)i);
    x = x * signo;
    signo *= -1;
    out += x;
  }
  return out * 4.0;
}


int main(void) {

  pid_t p;
  p = fork();

  double aux = 0;
  double result = 0;

  unsigned long number = 200000000;

  if(p < 0) {
    perror("Error fork(...)\n");
    exit(-1);
  } else if(p == 0){
    result = pi(1, number/2);

    save(result);
    printf("Hola soy Hijo %f\n", result);

  } else{
    wait(NULL);
    
    readf(&aux);
    result += pi(number/2, number);

    result += aux;
    printf("Hola soy Padre %.10f\n", result);
  }

  
  return 0;
} 