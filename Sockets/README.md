# Sockets in C/C++

La programación de socket es una forma de conectar dos nodos en una red para comunicarse entre sí. Un socket (nodo) escucha en un puerto en particular en una IP, mientras que otro socket se acerca al otro para formar una conexión. El servidor forma el zócalo del oyente mientras que el cliente llega al servidor.

![Sockets][sockets]

### Librerias
```c
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>   //sockaddr_in,
#include <unistd.h>       //close()
#include <arpa/inet.h>
```


### Servidor

```c
int socket(int domain, int type, int protocol);

int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int listen(int sockfd, int backlog);

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

### Cliente

```c
int socket(int domain, int type, int protocol);

int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```


### Enviar y Recibir

```c
ssize_t send(int sockfd, const void *buf, size_t len, int flags);

ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

### Constantes

```c
// Define la longitud máxima para la cola de conexiones pendientes.
#define BACKLOG 2

// Puerto en el que se va a hacer la comunicación
#define PORT 8080
```

### Structs

```c
#include <netinet/in.h>

struct sockaddr_in {
  short sin_family;
  unsigned short sin_port;
  struct in_addr sin_addr;
  char sin_zero[8];
}server, client;

//Contiene la dirección IP del host
struct in_addr {
  unsigned long s_addr;
};


// Protocolo para la conexión
server.sin_family = AF_INET;

// Puerto para la conexión
server.sin_port = htons(PORT);

// Estructura a la dirección IP
server.sin_addr.s_addr = INADDR_ANY;

// Relleno
bzero(server.sin_zero, 8);

```


## Referencias:
[Geeks For Geeks - Socket Programming in C/C++](https://www.geeksforgeeks.org/socket-programming-cc/)


[sockets]: http://cdncontribute.geeksforgeeks.org/wp-content/uploads/Socket-Programming-in-C-C-.jpg