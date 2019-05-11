#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>  // mkfifo(...)
#include <unistd.h>    // write(...), close(...)
#include <fcntl.h>     // open(...)


struct buffer {
    char message[32];
    short status;
};

typedef struct buffer Buffer;


int main(int argc, char *argv[]) {

    int fd;



    Buffer buffer1 = {"Hola Soy Buffer 1", 301};
    Buffer buffer2 = {"Hola Soy Buffer 2", 302};
    Buffer buffer3 = {"Hola Soy Buffer 2", 303};

    Buffer arrBuffers[3] = {[0]=buffer1, [2]=buffer3, [1]=buffer2};



    char *pathFifo = "/tmp/mkfifo";

    mkfifo(pathFifo, 0666);

    fd = open(pathFifo, O_WRONLY);

    write(fd, arrBuffers, sizeof(Buffer) * 3);
    close(fd);

    return 0;
}
