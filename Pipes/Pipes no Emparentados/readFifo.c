#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>  // mkfifo(...)
#include <unistd.h>    // read(...), close(...)
#include <fcntl.h>     // open(...)

struct buffer {
    char message[32];
    short status;
};

typedef struct buffer Buffer;


int main(int argc, char *argv[]) {

    int fd;


    Buffer arrBuffer[3];

    char *pathFifo = "/tmp/mkfifo";

    mkfifo(pathFifo, 0666);

    fd = open(pathFifo, O_RDONLY);

    read(fd, arrBuffer, sizeof(Buffer) * 3);

    Buffer tmp;

    for(size_t i = 0; i < 3; ++i) {
        tmp = arrBuffer[i];
        printf("Message: %s\n", tmp.message);
        printf("Status: %i\n", tmp.status);
    }

    close(fd);

    return 0;
}
// Out[]:

// Message: Hola Soy Buffer 1
// Status: 301
// Message: Hola Soy Buffer 2
// Status: 302
// Message: Hola Soy Buffer 2
// Status: 303
