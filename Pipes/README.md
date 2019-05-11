# Pipes en C

### Pipes para procesos Emparentados

```
#include <unistd.h>
int pipe(int pipefd[2]);
```
![Tuberia para procesos Emparentados][pipeImg]


### Pipes para procesos No-Emparentados (FIFOs)



[pipeImg]: https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Process.jpg