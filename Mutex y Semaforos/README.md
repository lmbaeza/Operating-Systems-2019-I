# Mutex y Semaforos

### Mutex

*Mutex sólo le permite a un Hilo el acceso al/los recursos, mientras que un semáforo general puede permitirle el acceso a cualquier cantidad de hilos simultaneamente.*

**Nota:** Conocido tambien como Semaforo Binario.

### Semaforo

*En Ciencias de la Computación, un semáforo es un tipo de datos variable o abstracto que se utiliza para controlar el acceso a un recurso común mediante múltiples procesos en un sistema concurrente, como un sistema operativo multitarea.*

#### Caracteristicas de un Semaforo:

* Cuando se crea un semáforo, se pueden inicializar su valor con cualquier entero, pero después de eso las únicas que pueden hacerlo son los incrementos y decrementos en una unidad.
* No puede leerse el valor actual del semáforo.
* Cuando un thread intenta decrementar el semáforo, si su valor es negativo, el subproceso se bloquea a sí mismo y no puede continuar hasta que otro subproceso incremente el semáforo.
* Cuando un thread incrementa el semáforo, si hay otros threads esperando, uno de ellos se desbloquea.

### Ventajas
En cuanto a la definición de semáforos, no es obvio por qué son útiles. Es cierto que no se necesitan para solucionar problemas de sincronización, pero sus ventajas de uso son:

* Los semáforos pueden imponer restricciones que ayuden a los programadores a evitar errores.
* Las soluciones que usan semáforos suelen ser limpias y organizadas, haciendo fácil demostrar su correctitud.
* Los semáforos pueden implementarse de manera eficiente en muchos sistemas, por lo que las soluciones que los usan son portables y usualmente eficientes.

### Desventajas
* El uso correcto de wait() y signal() es sólo una buena práctica de programación: es decir, su uso correcto no es obligatorio.
* No existe una asociación directa entre el semáforo y el recurso que regula
* Entre wait() y signal() el usuario puede realizar cualquier operación con el recurso.

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

### Bibliografia
[[1] Semaforos Informatico By utfsm](http://wiki.inf.utfsm.cl/index.php?title=Semaforos)