# Unidad de Gestion de Memoria (MMU)

**Nota:**

* **Fragmentación Interna:** En esta fragmentación otros procesos no pueden utilizar los huecos.
* **Fragmentación Externa:** En esta fragmentación si es posible utilizar los huecos.

### Fragmentación Interna Vs Externa
Cada vez que se carga o se elimina un proceso del bloque de memoria física, se crea un pequeño agujero en el espacio de memoria que se denomina fragmento. Debido a la fragmentación, el sistema falla al asignar el espacio de memoria contiguo a un proceso aunque tenga la cantidad de memoria solicitada, pero de una manera no contigua. La fragmentación se clasifica en dos categorías: fragmentación interna y externa.

### Fragmentación Interna
La fragmentación interna se produce cuando la memoria se divide en bloques de tamaño fijo. Siempre que una solicitud de proceso para la memoria, el bloque de tamaño fijo se asigna al proceso. En caso de que la memoria asignada al proceso sea algo mayor que la memoria solicitada, entonces la diferencia entre la memoria asignada y la solicitada es la fragmentación interna .

<img alt="Fragmentación Interna" src="https://i.ibb.co/48TGnCT/Fragmentaci-n-Interna-OS.png" width="850">


### Fragmentación Externa
La fragmentación externa se produce cuando hay una cantidad suficiente de espacio en la memoria para satisfacer la solicitud de memoria de un proceso. Pero la solicitud de memoria del proceso no se puede satisfacer, ya que la memoria disponible no es contigua. Si aplica la estrategia de asignación de memoria de primer ajuste o de mejor ajuste, causará una fragmentación externa.


<img alt="Fragmentación Externa" src="https://i.ibb.co/D1dVpPS/Fragmentaci-n-Externa.png" width="850">

### Algoritmos de Reemplazo de Memoria

* Algoritmo Optimo
* Algoritmo FIFO
* Algoritmo del Reloj
* Algoritmo LRU

### Retención de Memoria

```c++
#include <sys/mman.h>

// mlock();
int mlock(const void *addr, size_t len);
int munlock(const void *addr, size_t len);

int mlockall(int flags);
int munlockall(void);
```

`mlock();` Permite que una referencia de memoria nunca sea expulsada a **swap**.


### Bibliografia

[[1] Difference Between Internal and External fragmentation By Tech Differences](https://techdifferences.com/difference-between-internal-and-external-fragmentation.html)

[[2] Gestión de memoria: asignación By Juan V. Carrillo (jvprofe)](https://www.youtube.com/watch?v=hMhPTWUJX_M)