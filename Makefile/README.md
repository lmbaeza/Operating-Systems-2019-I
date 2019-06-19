# Make File

### Ficheros C++
```c++
// hola.cpp

#include "mensaje.h"

int main() {
    mensaje();
    // Hello World

    return 0;
}
```

```c++
// mensaje.h

#include <iostream>

using namespace std;

void mensaje();
```

```c++
// mensaje.cpp

#include "mensaje.h"

void mensaje() {
    cout<<"Hello World"<<endl;
}
```

### Makefile

```python
COMPILER = g++

CFLAGS= -Wall -g

app: clean exe.o

exe.o: hola.o mensaje.o
	$(COMPILER) hola.o mensaje.o -o exe.o && ./exe.o

hola.o:
	$(COMPILER) -c hola.cpp -o hola.o

mensaje.o:
	$(COMPILER) -c mensaje.cpp -o mensaje.o

clean: 
	$(RM) *.o
```