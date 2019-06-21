# Semaforos en C

### Definición
*En Ciencias de la Computación, un semáforo es un tipo de datos variable o abstracto que se utiliza para controlar el acceso a un recurso común mediante múltiples procesos en un sistema concurrente, como un sistema operativo multitarea.*

### Prototipos

```c++
int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_wait(sem_t * sem);
int sem_post(sem_t * sem);
int sem_destroy(sem_t * sem);
```
### Codigo

```c++
// main.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_PROCESOS 1
#define NUM_HILOS 8

struct datos_tipo {
    int dato;
    int p;
};

// VARIABLE DE REFERENCIA DEL SEMAFORO
sem_t sem1;

void * process(void * datos) {
    struct datos_tipo * datos_proceso;
    datos_proceso = (struct datos_tipo *) datos;

    int a, i, j, p;

    a = datos_proceso->dato;
    p = datos_proceso->p;

    // PUNTO CRITICO - EMPIEZA A FUNCIONAR EL SEMAFORO
    // ---------->

    sem_wait(&sem1);

    for(int i = 0; i <= p; i++) {
        printf("%i ", a);
    }

    fflush(stdout);

    sleep(1);

     for(int i = 0; i <= p; i++) {
        printf("- ");
    }

    fflush(stdout);
    printf("\n");

    // PUNTO CRITICO - TERMINA DE FUNCIONAR EL SEMAFORO
    // ---------->
    sem_post(&sem1);

}


int main(void) {
    int error, i;

    char * valor_devuelto;

    struct datos_tipo hilos_datos[NUM_HILOS];

    pthread_t idHilos[NUM_HILOS];

    // INICIALIZAR EL SEMAFORO
    sem_init(&sem1, 0, 1);

    
    // INICIALIZAR LAS ESTRUCTURAS
    for(i = 0; i < NUM_HILOS; i++) {
        hilos_datos[i].dato = i;
        hilos_datos[i].p = i+1;
    }

    // CREAR LOS HILOS

    for(i=0; i<NUM_HILOS; i++){
        error = pthread_create(&idHilos[i], NULL, *process, &hilos_datos[i]);
        if (error != 0) {
            perror ("No puedo crear hilo");
        }
    }

    // SE LANZAN LOS HILOS
    for(i=0; i<NUM_HILOS; i++){
        pthread_join(idHilos[i], NULL);
    }

    sem_destroy(&sem1);


    return 0;
}

// CON SEMAFORO

// 0 0 - - 
// 1 1 1 - - - 
// 5 5 5 5 5 5 5 - - - - - - - 
// 6 6 6 6 6 6 6 6 - - - - - - - - 
// 2 2 2 2 - - - - 
// 4 4 4 4 4 4 - - - - - - 
// 7 7 7 7 7 7 7 7 7 - - - - - - - - - 
// 3 3 3 3 3 - - - - - 

// COMPARACION SEMAFORO VS MUTEX

// CON MUTEX

// 0 0 - - 
// 1 1 1 - - - 
// 2 2 2 2 - - - - 
// 3 3 3 3 3 - - - - - 
// 4 4 4 4 4 4 - - - - - - 
// 5 5 5 5 5 5 5 - - - - - - - 
// 6 6 6 6 6 6 6 6 - - - - - - - - 
// 7 7 7 7 7 7 7 7 7 - - - - - - - - - 


// SIN SEMAFORO

// 0 2 2 2 2 0 4 4 4 4 4 4 3 3 3 3 3 1 1 1 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 - - - - - - 
// - - - - - - 
// - - - - - - - - - 
// - - - - - - 
// - 
// - - - - - - - - 
// - - - - - - 
// - - 
```

### Makefile

```makefile

app: clean exe.o

exe.o: main.o
	gcc main.o -o exe.o -pthread && ./exe.o

main.o:
	gcc -c main.c -o main.o -pthread

clean:
	rm -f *.o
```