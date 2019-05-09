#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>   //socket(), setsockopt(), bind(), listen(), accept(), send()
#include <netinet/in.h>   //sockaddr_in,
#include <string.h>
#include <unistd.h>       //close()
#include <signal.h>      //signal()
#include <arpa/inet.h>


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

void signal_callback_handler(int);

struct sockaddr_in server; 
struct sockaddr_in client; 

// Puerto en el que se va a hacer la comunicación
#define PORT 3538

size_t tama, tamaClient;

int r, fd, fd1;

// Estructura que representa el buffer que se va a recibir
struct Dog {
  char name[32];
  int age;
} dogBuffer ;

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

  if(fd < 0) {
    perror("ERROR : socket");
    exit(-1);
  }

  // Protocolo para la conexión  
  server.sin_family = AF_INET;

  // Puerto para la conexión
  server.sin_port = htons(PORT);

  // Estructura a la dirección IP
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Relleno
  bzero(server.sin_zero, 8);

  //int connect(int socket, struct sockaddr *address, int address_len);

  // socket:
  // identificador fd del socket que va a enlazar

  // socekt:
  // El puntero a una estructura de dirección de socket que contiene
  // la dirección del socket al que se intentará una conexión.

  // address_len:
  // El tamaño de la dirección de socket señalada por la dirección en bytes.

  tama = sizeof(struct sockaddr);
  r = connect(fd, (struct sockaddr *)&server, tama);

  if(r == -1) {
    perror("ERROR: ");
  }
  
  //void (*signal(int sig, void (*func)(int)))(int);

  //sig:
  //Codigo SIG

  //func:
  //Funcion que se ejecuta
  signal(SIGINT, signal_callback_handler);

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

  r = recv(fd, &dogBuffer, sizeof(struct Dog), 0);
  
  printf("Name : %s\n", dogBuffer.name);
  printf("Age : %d\n", dogBuffer.age);

  // close:
  //apaga un socket y libera los recursos asignados a ese socket.
  close(fd);
  
  return 0;
}

void signal_callback_handler(int signum) {
  // Esta funcion se ejecuta si hay un Ctrl C
  printf("Callback client : %d", signum);
  close(fd);
}


// SIGNAL
// Ctrl C  == SIGINT
// Ctrl \  == SIGQUIT
// Ctrl Z  == SIGTSTP