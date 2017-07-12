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
#include <string>
#include <errno.h>
#include <string.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

using namespace std;

class UDP_client{

public:
	UDP_client(const char* hostname, int port);
	~UDP_client();

	int write(string msg, int size);
	int read(void* msg, int size, socklen_t* sizeRcv);

private:
	int sock;
	struct sockaddr_in sin;
	const char* hostname;
	int port;
};

#endif // _UDP_CLIENT_
