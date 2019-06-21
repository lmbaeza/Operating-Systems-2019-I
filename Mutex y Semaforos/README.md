# Mutex y Semaforos

### Mutex

*Mutex sólo le permite a un Hilo el acceso al/los recursos, mientras que un semáforo general puede permitirle el acceso a cualquier cantidad de hilos simultaneamente.*

### Semaforo

*En Ciencias de la Computación, un semáforo es un tipo de datos variable o abstracto que se utiliza para controlar el acceso a un recurso común mediante múltiples procesos en un sistema concurrente, como un sistema operativo multitarea.*

### Comparación

```c++
// CON SEMAFORO

// 0 0 - - 
// 1 1 1 - - - 
// 5 5 5 5 5 5 5 - - - - - - - 
// 6 6 6 6 6 6 6 6 - - - - - - - - 
// 2 2 2 2 - - - - 
// 4 4 4 4 4 4 - - - - - - 
// 7 7 7 7 7 7 7 7 7 - - - - - - - - - 
// 3 3 3 3 3 - - - - - 

// COMPARACION SEMAFORO VS MUTEX

// CON MUTEX

// 0 0 - - 
// 1 1 1 - - - 
// 2 2 2 2 - - - - 
// 3 3 3 3 3 - - - - - 
// 4 4 4 4 4 4 - - - - - - 
// 5 5 5 5 5 5 5 - - - - - - - 
// 6 6 6 6 6 6 6 6 - - - - - - - - 
// 7 7 7 7 7 7 7 7 7 - - - - - - - - - 


// SIN SEMAFORO NI MUTEX

// 0 2 2 2 2 0 4 4 4 4 4 4 3 3 3 3 3 1 1 1 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 - - - - - - 
// - - - - - - 
// - - - - - - - - - 
// - - - - - - 
// - 
// - - - - - - - - 
// - - - - - - 
// - - 
```