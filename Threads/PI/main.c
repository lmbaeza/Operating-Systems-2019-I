
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct args {
    double x;
    double y;
};

double *result;


void * function_thread(void *ap) {
  // Casting a los Argumentos
  struct args *arg = (struct args *) ap;

  // Asignando los Argumentos
  double start = arg->x, end = arg->y;

  double out = 0.0;
  double signo = 1;
  double x = 0.0;

  for(double i = start; i < end; i+=2.0) {
    x = 4.0/i;
    x = x * signo;
    signo *= -1;
    out += x;
  }

  *result += out;

}

int main(void) {

  int n = 4;

  // Puntero que funciona como memoria compartida
  double *_result = (double *)malloc(sizeof(double *));
  *_result = 0.0;

  result = &_result;
  
  pthread_t idThread;

  pthread_t ids[n];

  // Rangos para el calculo de PI con 4 Hilos
  int ranges[n + 1];
  ranges[0] = 1;
  ranges[1] = 5e8;
  ranges[2] = 1e9;
  ranges[3] = 5e8 + 1e9;
  ranges[4] = 2e9;


  for(int i = 0; i < n; ++i) {
    // Puntero con argumentos
    struct args * arg = (struct args * )malloc(sizeof(struct args));
    arg->x = ranges[i];
    arg->y = ranges[i + 1];
    
    // Creación de los threads
    pthread_create(&idThread, NULL, &function_thread, arg);

    ids[i] = idThread;
  }

  for(int i = 0; i < n; ++i) {
    pthread_join(ids[i], NULL);
  }

  printf("PI %.10f\n", *result);
  // PI 3.1415926526
  
  return 0;
}