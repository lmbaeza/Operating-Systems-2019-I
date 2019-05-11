#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


struct buffer {
    char message[32];
    short status;
};

typedef struct buffer Buffer;

int main(int argc, char *argv[]) {
    printf("Executing ....\n");

    int pp[2];
    
    //[0] Read, [1] Write
    Buffer *buffer = (Buffer *) malloc(sizeof(Buffer));

    printf("Executing ....\n");

    int pipeStatus = pipe(pp);

    if(pipeStatus == -1) {
        perror("Error pipe(...)");
        exit(-1);
    }

    pid_t pID = fork();
 
    if(pID == 0) {         //Children
        printf("Children\n");
        close(pp[1]);

        read(pp[0], buffer, 44);

        printf("End Children\n");

        printf("Message : %s\n", buffer->message);
        printf("Status : %i\n", buffer->status);
        close(pp[0]);

    } else {               //Parent
        printf("Parent\n");
        close(pp[0]);
        Buffer aux = {"Hola Mundo", 300};
        buffer = &aux;
        write(pp[1], buffer, sizeof(Buffer));
        close(pp[1]);
        printf("End Parent\n");
    }
    
    return 0;
}
