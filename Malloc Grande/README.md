# Practica Malloc Grande

Cuando se hace un un `malloc(...)` muy grande y en general el sistema operativo no reserva toda la memoria requerida en el `malloc`, sino que a medida que se vaya utilizando la memoria el sistema operativo se la va asignando.

```c++
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int gygabyte = 1e9;

    int * number = (int *) malloc(gygabyte);

    // Utiliza 10000000*4 Bytes
    for(int i = 0; i < 10000000; ++i) {
        number[i] = i * 100;
    }

    // Imprime solo la memoria utilizada
    for(int i = 0; i < 10000000; ++i) {
        printf("%i", number[i]);
    }

    while(1) {
        ; // Para que no salga del Programa
    }

    return 0;
}
```

### Make File

```makefile
app: clean mallocGrande.o

mallocGrande.o: main.o
	gcc main.o -o mallocGrande.o -pthread && ./mallocGrande.o

main.o:
	gcc -c main.c -o main.o -pthread

clean:
	rm -f *.o
```