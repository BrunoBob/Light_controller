#include "UDP_client.h"
#include "Light_command.h"

#define DEFAULT_IP "192.168.1.53"
#define DEFAULT_PORT 5987

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

int UDP_client::write(string msg, int size){
	int i;
	const char* c_msg = msg.c_str();
	printf("\nUDP send : " );
	printMsg((void*)c_msg, size);
	if(sendto(sock, c_msg, size, 0, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) < 0){
    fprintf(stderr, "Error sending message message : %s\n", strerror(errno));
    return 1;
	}
	return 0;
}

int UDP_client::read(void* msg, int size, socklen_t* sizeRcv){
	int  i;
	size_t readSize;
	printf("\nUDP receive : " );
	if((readSize = recvfrom(sock, msg, size, 0, (struct sockaddr *)&sin, sizeRcv)) < 0){
    fprintf(stderr, "Error reading message : %s\n", strerror(errno));
    exit(EXIT_FAILURE);
	}
	printMsg(msg, readSize);
}

void UDP_client::printMsg(void* msg, int size){
	int i;
	for(i = 0 ; i < size ; i++){
		printf("%0x - ", ((Byte*)msg)[i]);
	}
	printf("\n");
}


int main(){
	UDP_client client(DEFAULT_IP, DEFAULT_PORT);
	Light_command light;

	light.sendCmd(&client, 2, 0, 2, 0);
	usleep(1000*1000);
	light.sendCmd(&client, 1, 0, 3, 0);
	usleep(1000*1000);
	light.sendCmd(&client, 4, 0, 4, 0);

	int i;
	for(i = 0 ; i < 256 ; i++){
		printf("%d\n", i);
		usleep(1000*10);
		light.sendCmd(&client, 5, i, i, 0);
	}

	light.sendCmd(&client, 4, 0, 4, 0);
	return 0;
}
