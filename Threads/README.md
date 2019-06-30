# Thread en C/C++

Tambien Llamado:

* Hilo (Thread)
* Proceso Ligero
* Subproceso

### Caracteristicas de los Hilos (Threads) vs Procesos

* En unix a cada **proceso** se le asigna un espacio de memoria
* En cambio varios **Hilos** comparten el mismo espacio de memoria y los mismos recursos que el proceso.
* Un **Hilo** en si mismo no es un programa.
* Un **Hilo** no puede ser ejecutado por si solo.
* Un **Hilo** se ejecuta sobre un proceso.
* Un **Hilo** se considera liviano porque se ejecuta en el contexto de un proceso y aprovecha los recursos asignados a este proceso.

### Cada hilo posee
* Identificador
* Pila - Stack para la (Gestion de Hilos)
* Conjunto de registros del proceso
* Contador del Programa

### Los hilos comparten ciertos recursos con el resto de hilos como son:
* Señales
* Mapa de memoria
* Ficheros abiertos
* Semáforos

### Estados de un Hilo:
* Ejecución
* Listo
* Bloqueado

### Ventajas de los hilos contra procesos
* Un hilo se tarda mucho menos tiempo en crear que crear un proceso (algunas investigaciones llevan al resultado que esto es así en un factor de 10).
* Se tarda mucho menos en terminar un hilo que un proceso.
* Se tarda mucho menos tiempo en cambiar entre dos hilos de un mismo proceso.
* Los hilos aumentan la eficiencia de la comunicación entre programas en ejecución

### Bibliografia
[[1] - Hilo (informática) By es.wikipedia](https://es.wikipedia.org/wiki/Hilo_(inform%C3%A1tica))

[[2] - Linux - Threads By Fernando Cortes](http://cortesfernando.blogspot.com/2011/11/linux-threads.html)
