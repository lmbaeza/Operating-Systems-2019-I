# Unidad de Gestion de Memoria (MMU)

### Fragmentación Interna Vs Externa
Cada vez que se carga o se elimina un proceso del bloque de memoria física, se crea un pequeño agujero en el espacio de memoria que se denomina fragmento. Debido a la fragmentación, el sistema falla al asignar el espacio de memoria contiguo a un proceso aunque tenga la cantidad de memoria solicitada, pero de una manera no contigua. La fragmentación se clasifica en dos categorías: fragmentación interna y externa.

### Fragmentación Interna
La fragmentación interna se produce cuando la memoria se divide en bloques de tamaño fijo. Siempre que una solicitud de proceso para la memoria, el bloque de tamaño fijo se asigna al proceso. En caso de que la memoria asignada al proceso sea algo mayor que la memoria solicitada, entonces la diferencia entre la memoria asignada y la solicitada es la fragmentación interna .



<img alt="Fragmentación Interna" src="https://i.ibb.co/48TGnCT/Fragmentaci-n-Interna-OS.png" width="850">

### Bibliografia

[[1] Difference Between Internal and External fragmentation By Tech Differences](https://techdifferences.com/difference-between-internal-and-external-fragmentation.html)

[[2] Gestión de memoria: asignación By Juan V. Carrillo (jvprofe)](https://www.youtube.com/watch?v=hMhPTWUJX_M)