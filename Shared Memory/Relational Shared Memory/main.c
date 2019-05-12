#include <stdio.h>
#include <stdlib.h>

#include <sys/ipc.h> // ftok(...)
#include <sys/shm.h> // shmget(...), shmat(...), shmdt(...)

#include <sys/types.h>// pid_t
#include <unistd.h>  // fork(...)
#include <sys/wait.h> // wait(...)

#define ERROR -1

int main(void) {
	int status;

	// Crear una llave unica
    key_t key = ftok("secret_key", 50);

	// Al completarse con éxito, shmget ()
    // devuelve un identificador para el segmento de memoria compartida.
	int shmID = shmget(key, 2 * sizeof(int), 0666 | IPC_CREAT);

	if(shmID == ERROR) {
		perror("Error: shmget(...)\n");
		exit(ERROR);
	}

	// Retorna un puntero, hacia la memoria compartida
    // todos los cambios que le hagamos a este puntero
    // le llegaran al otro proceso
	int *sharedMemory = (int *)shmat(shmID, NULL, 0);

	pid_t pid = fork();

	if(pid == 0) { //Children
		printf("Children: \n");
		*sharedMemory = 512;
		*(sharedMemory + 1) = 1024;
	} else {      //Parend
		if(wait(&status) == pid) {
			printf("Parent: %i  - %i \n", *sharedMemory, *(sharedMemory + 1));
		}
	}

	// El proceso se desprende de la memoria compartida
	int r = shmdt(sharedMemory);

	if(r == ERROR) {
		perror("Error: shmdt(...)\n");
		exit(ERROR);
	}

	return 0;
}
// Out

// Children: 
// Parent: 512  - 1024
