# Thread en C/C++

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

### **Los hilos comparten** ciertos recursos con el resto de hilos como son:
* Señales
* Mapa de memoria
* Ficheros abiertos
* Semáforos