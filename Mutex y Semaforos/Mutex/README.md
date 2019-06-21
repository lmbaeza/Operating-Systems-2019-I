# Mutex en C

```c++
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

```c++
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 #include <unistd.h>

#define MAX_PROCESOS 1
#define NUM_HILOS 8

struct datos_tipo {
    int dato;
    int p;
};

// INICIALIZAR EL MUTEX
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// PTHREAD_MUTEX_INITIALIZER = { { 0, 0, 0, 0, 0, __PTHREAD_SPINS, { 0, 0 } } }

void * process(void * datos) {
    struct datos_tipo * datos_proceso;
    datos_proceso = (struct datos_tipo *) datos;

    int a, i, j, p;

    a = datos_proceso->dato;
    p = datos_proceso->p;

    // Iniciar el Mutex
    // PARTE DEL CODIGO CRITICA
    // ---------->
    pthread_mutex_lock(&mutex);


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

    // Cerrar el Mutex
    // ---------->

    pthread_mutex_unlock(&mutex);
}


int main(void) {
    int error, i;

    char * valor_devuelto;

    struct datos_tipo hilos_datos[NUM_HILOS];

    pthread_t idHilos[NUM_HILOS];

    
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


    return 0;
}

// CON MUTEX

// 0 0 - - 
// 1 1 1 - - - 
// 2 2 2 2 - - - - 
// 3 3 3 3 3 - - - - - 
// 4 4 4 4 4 4 - - - - - - 
// 5 5 5 5 5 5 5 - - - - - - - 
// 6 6 6 6 6 6 6 6 - - - - - - - - 
// 7 7 7 7 7 7 7 7 7 - - - - - - - - - 

// SIN MUTEX

// 0 2 2 2 2 0 4 4 4 4 4 4 3 3 3 3 3 1 1 1 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 - - - - - - 
// - - - - - - 
// - - - - - - - - - 
// - - - - - - 
// - 
// - - - - - - - - 
// - - - - - - 
// - - 
```