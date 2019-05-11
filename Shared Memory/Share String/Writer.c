#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h> // ftok(...)
#include <sys/shm.h> // shmget(...), shmat(...), shmdt(...)

#include <string.h>

int main(int argc, char *argv[]) {

    // Crear una llave unica
    key_t key = ftok("secret_key", 50);

    // Al completarse con éxito, shmget ()
    // devuelve un identificador para el segmento de memoria compartida.
    int shmID = shmget(key, 1024, 0666 | IPC_CREAT);

    // Retorna un puntero, hacia la memoria compartida
    // todos los cambios que le hagamos a este puntero
    // le llegaran al otro proceso
    char *message = (char *) shmat(shmID, NULL, 0666);

    strcpy(message, "Hola desde Writer.c");

    // El proceso se desprende de la memoria compartida
    shmdt(message);

    return 0;
}
