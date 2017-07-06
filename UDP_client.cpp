#include"UDP_client.h"

#define DEFAULT_IP "192.168.1.53"
#define DEFAULT_PORT 5987
#define test "\x20\x00\x00\x00\x16\x02\x62\x3A\xD5\xED\xA3\x01\xAE\x08\x2D\x46\x61\x41\xA7\xF6\xDC\xAF\xD3\xE6\x00\x00\x1E"

UDP_client::UDP_client(const char* hostname, int port){
	this->hostname = hostname;
	this->port = port;

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	if(sock == INVALID_SOCKET){
		fprintf(stderr, "Error creating socket\n");
		exit(EXIT_FAILURE);
	}

	struct hostent *hostinfo = NULL;
	sin = { 0 };

	hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
	if (hostinfo == NULL){
		fprintf (stderr, "Unknown host %s.\n", hostname);
		exit(EXIT_FAILURE);
	}

	sin.sin_addr = *(struct in_addr *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
	sin.sin_port = htons(port); /* on utilise htons pour le port */
	sin.sin_family = AF_INET;
}

UDP_client::~UDP_client(){
	close(sock);
}

int UDP_client::write(void* msg, int size){
	if(sendto(sock, msg, size, 0, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) < 0){
    fprintf(stderr, "Error sending message %s\n", (char*)msg);
    return 1;
	}
	return 0;
}

int UDP_client::read(void* msg, int size, socklen_t* sizeRcv){
	if((recvfrom(sock, msg, size, 0, (struct sockaddr *)&sin, sizeRcv)) < 0){
    fprintf(stderr, "Error reading message\n");
    exit(EXIT_FAILURE);
	}
}


int main(){
	UDP_client client(DEFAULT_IP, DEFAULT_PORT);
	client.write((char*)test, 27);
	char* buffer = (char*)malloc(1000*sizeof(char));
	Byte* buffer2 = (Byte*)malloc(1000*sizeof(char));

	socklen_t len;
	client.read(buffer2, 1000, &len);
	int i;
	for(i = 0 ; i < len ; i++){
		printf("%0x\t", (Byte)buffer2[i]);
	}
	printf("\n");
	return 0;
}