
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <math.h>


int save(double ap) {
  FILE *fp;
  fp = fopen("pi.dat", "w+");

  if(fp == NULL) {
    perror("Error fopen(...)");
    exit(-1);
  }

  fprintf(fp, "%.10f", ap);
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

  fscanf(fp, "%le", ap);
  fclose(fp);
  return EXIT_SUCCESS;
}


double pi(double start, double end) {
  double out = 0.0;
  double signo = 1;
  double x = 0.0;

  for(double i = start; i < end; i+=2.0) {
    x = 4.0/i;
    x = x * signo;
    signo *= -1;
    out += x;
  }
  return out;
}


int main(void) {

  pid_t p;
  p = fork();

  double aux = 0.0;
  double result = 0.0;

  double number = 2e09;
  //3.14159265358

  if(p < 0) {
    perror("Error fork(...)\n");
    exit(-1);
  } else if(p == 0){
    result = pi(1.0, (number/2));

    save(result);
    printf("Hola soy Hijo  %f\n", result);

  } else{

    result += pi((double)(number/2), (double)number);

    wait(NULL);
    readf(&aux);
    
    result += aux;
    printf("Hola soy Padre %.10f\n", result);

  }
  
  return 0;
}
//Out[]
//Hola soy Hijo  3.141593
//Hola soy Padre 3.1415926526

