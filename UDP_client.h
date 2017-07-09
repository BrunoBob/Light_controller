#ifndef _UDP_CLIENT_
#define _UDP_CLIENT_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

class UDP_client{

public:
	UDP_client(const char* hostname, int port);
	~UDP_client();

	int write(void* msg, int size);
	int read(void* msg, int size, socklen_t* sizeRcv);

private:
	int sock;
	struct sockaddr_in sin;
	const char* hostname;
	int port;
};

#endif // _UDP_CLIENT_

/*#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;*/
