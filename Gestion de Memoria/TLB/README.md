# TLB (Translation Lookaside Buffer) - Búfer de Traducción Anticipada

Un Búfer de Traducción Anticipada, es una **memoria caché** administrada por la unidad de gestión de memoria (MMU), que contiene partes de la tabla de paginación, la cual relaciona las direcciones lógicas con las físicas. Posee un número fijo de entradas y **se utiliza para obtener la traducción rápida de direcciones**. Si no existe una entrada buscada, se deberá revisar la tabla de paginación y tardará varios ciclos más, sobre todo si la página que contiene la dirección buscada no está en memoria primaria (véase memoria virtual). Si en la tabla de paginación no se encuentra la dirección buscada, saltará una interrupción conocida como fallo de página.

**Nota:**
* Es una parte de la unidad de gestión de memoria (MMU) y puede residir entre la CPU y el caché de la CPU.
* Siempre esta presente en procesadores que utilicen paginación.
* El TLB tiene un numero fijo de ranuras.

<img alt="Translation Lookaside Buffer" src="https://upload.wikimedia.org/wikipedia/commons/6/6e/Translation_Lookaside_Buffer.png" width="500">

### Funciones
* Se utiliza para obtener la traducción rápida de direcciones.
* Reducir el tiempo necesario para acceder a la ubicación de la memoria.
* El TLB almacena las traducciones recientes de la memoria virtual a la memoria física y puede llamarse un caché de traducción de direcciones.

### Bibliografia

[[1] Translation Lookaside Buffer By Wikipedia](https://es.wikipedia.org/wiki/Translation_Lookaside_Buffer)