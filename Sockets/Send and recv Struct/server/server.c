#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>   //socket(), setsockopt(), bind(), listen(), accept(), send()
#include <netinet/in.h>   //sockaddr_in,
#include <string.h>
#include <unistd.h>       //close()
#include <signal.h>      //signal()


// struct sockaddr_in {
//   short sin_family;
//   unsigned short sin_port;
//   struct in_addr sin_addr;
//   char sin_zero[8];
// };

//Contiene la dirección IP del host
// struct in_addr {
//   unsigned long s_addr;
// };


struct sockaddr_in server; 
struct sockaddr_in client; 

void signal_callback_handler(int);

// Define la longitud máxima para la cola de conexiones pendientes.
#define BACKLOG 2

// Puerto en el que se va a hacer la comunicación
#define PORT 3538

size_t tama;
socklen_t tamaClient;

int r, fd, fd1;

// Estructura que representa el buffer que se va a enviar
struct Dog {
  char name[32];
  int age;
};

int main() {

  // int socket(int domain, int type, int protocol);

  // AF_INET:
  // IPv4 Protocolo de Internet

  // SOCK_STREAM: 
  // proporciona flujos de bytes secuenciales, confiables, bidireccionales y basados en conexión.
  // Y el mecanismo de transmisión de datos fuera de banda puede ser compatible.

  fd = socket(AF_INET, SOCK_STREAM, 0);

  int option = 1;

  // int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
  // sockfd:
  // Identificador del socket

  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));


  if(fd == -1) {
    perror("ERROR : socket");
    exit(-EXIT_FAILURE);
  }

  // Protocolo para la conexión
  server.sin_family = AF_INET;

  // Puerto para la conexión
  server.sin_port = htons(PORT);

  // Estructura a la dirección IP
  server.sin_addr.s_addr = INADDR_ANY;

  // Relleno
  bzero(server.sin_zero, 8);

  tama = sizeof(struct sockaddr);

  //int bind(int sockfd, const struct sockaddr *addr,
  //              socklen_t addrlen);

  // La función bind (...) deberá asignar una dirección local socket dirección a una toma identificado
  // por descriptor de socket que no tiene una dirección de socket local asignada.
  // Los sockets creados con la función socket () inicialmente no tienen nombre;
  // son identificados solo por su direccion familia.

  // sockfd:
  // Especifica el descriptor de archivo del socket a enlazar.

  // addr:
  // Apunta a una estructura sockaddr que contiene la dirección que se vinculará al socket.
  // La longitud y el formato de la dirección dependen de la familia de direcciones del socket.

  // addrlen:
  //specifica la longitud de la estructura sockaddr apuntada por el argumento de dirección .

  r = bind(fd, (struct sockaddr *)&server, tama);

  if(r == -1) {
    perror("ERROR: bind\n");
    exit(-EXIT_FAILURE);
  }

  //void (*signal(int sig, void (*func)(int)))(int);

  //sig:
  //Codigo SIG

  //func:
  //Funcion que se ejecuta

  signal(SIGINT, signal_callback_handler);

  // int listen(int socket, int backlog);

  // socket:
  // identificador fd del socket que va a enlazar

  // backlog:
  // Define la longitud máxima para la cola de conexiones pendientes.

  r = listen(fd, BACKLOG);

  if(r == -1) {
    perror("ERROR: listen\n");
    exit(-EXIT_FAILURE);
  }

  //int accept(int socket, struct sockaddr *restrict address,
  //     socklen_t *restrict address_len);

  // socket:
  // identificador fd del socket que va a enlazar

  // address:
  // La dirección de socket del cliente de conexión que se completa con accept () antes de que se devuelva.
  // El formato de la dirección lo determina el dominio en el que reside el cliente.
  // Este parámetro puede ser NULL si la persona que llama no está interesada en la dirección del cliente.

  // addres_len:
  // debe apuntar a un entero que contenga el tamaño en bytes del almacenamiento apuntado por dirección

  tamaClient = 0;
  fd1 = accept(fd, (struct sockaddr *)&client, &tamaClient);

  if(fd1 == -1) {
    perror("ERROR: accept\n");
    exit(-EXIT_FAILURE);
  }


  // Buffer con los datos que va a enviar
  struct Dog message = {"Roco", 19};

  // ssize_t send(int socket, const void *buffer, size_t length, int flags);

  // socket:
  // identificador fd del socket que va a enlazar

  // buffer:
  // Apunta al buffer que contiene el mensaje a enviar.

  // length:
  // Especifica la longitud del mensaje (buffer) en bytes.

  // flag:
  // Especifica el tipo de transmisión del mensaje. Los valores de este argumento se forman
  // lógicamente O con cero o más de los siguientes indicadores:
  
  // MSG_EOR:
  // Termina un registro (si es compatible con el protocolo).
  
  // MSG_OOB:
  // Envía datos fuera de banda en sockets que admiten comunicaciones fuera de banda.
  // El significado y la semántica de los datos fuera de banda son específicos del protocolo.

  send(fd1, &message, sizeof(struct Dog), 0);


  //ssize_t recv(int sockfd, void *buf, size_t len, int flags);

  // sockfd:
  // identificador fd del socket que va a enlazar

  // buffer:
  // Apunta al buffer que contiene el mensaje a recibir.

  // length:
  // Especifica la longitud del mensaje (buffer) en bytes.

  // flags:
  // El parámetro flags se establece especificando uno o más de los siguientes flags.
  // Si se especifica más de una bandera, se debe usar el operador lógico OR (|) para separarlos.
  // El indicador MSG_CONNTERM se excluye mutuamente con otros indicadores.

  // MSG_CONNTERM, MSG_OOB, MSG_PEEK, MSG_WAITALL
  recv(fd1, &message, sizeof(struct Dog), 0);

  printf("Name : %s\n", message.name);
  printf("Age : %d\n", message.age);

  // close:
  //apaga un socket y libera los recursos asignados a ese socket.

  close(fd1);
  close(fd);
  
  return EXIT_SUCCESS;
}


void signal_callback_handler(int signum) {
  // Esta funcion se ejecuta si hay un Ctrl C
  printf("Callback Server: %d\n", signum);
  close(fd1);
  close(fd);
}

// SIGNAL
// Ctrl C  == SIGINT
// Ctrl \  == SIGQUIT
// Ctrl Z  == SIGTSTP