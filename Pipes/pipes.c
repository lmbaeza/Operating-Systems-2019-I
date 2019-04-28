#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <math.h>


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

  double aux = 0.0;
  double _result = 0.0;
  double *result = &_result;

  double number = 2e09;
  //3.14159265358
  int pfd[2];
  pid_t pid;


  int r = pipe(pfd);

  if (r == -1) {
    perror("Error Pipe(...)");
    exit(-1);
  }

  pid = fork();

  if (pid == 0) {

    close(pfd[0]);
    double *ptr;

    double _pi = pi(1.0, (number/2));

    ptr = &_pi;

    r = write(pfd[1], ptr, sizeof(double));
    printf("Hola soy Hijo  %f\n", _pi);

    close(pfd[1]);

  } else {
    close(pfd[1]);


    double _pi2 = pi((double)(number/2), (double)number);

    r = read(pfd[0], result, sizeof(double));
    close(pfd[0]);

    _pi2 += *result;

    printf("Hola soy Padre %.10f\n", _pi2);
  }

  return 0;
}
