# Pipes en C

### Pipes para procesos Emparentados

Conceptualmente, una tubería es una conexión entre dos procesos, de modo que la salida estándar de un proceso se convierte en la entrada estándar del otro proceso. En el sistema operativo UNIX, las tuberías son útiles para la comunicación entre procesos relacionados (comunicación entre procesos).

```c
#include <unistd.h>
int pipe(int pipefd[2]);
```
![Tuberia para procesos Emparentados][pipeImg]


### Pipes para procesos No-Emparentados (FIFOs)

Una canalización con nombre (también conocida como FIFO ) es uno de los métodos para la comunicación de procesos internos.

```c
#include <sys/types.h>
#include <sys/stat.h>

int mkfifo(const char *pathname, mode_t mode);
```



[pipeImg]: https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Process.jpg


## Referencias

[[1] Geeks for Geeks - pipe() System call](https://www.geeksforgeeks.org/pipe-system-call/)

[[2] Geeks for Geeks - Named Pipe or FIFO with example C program](https://www.geeksforgeeks.org/named-pipe-fifo-example-c-program/)