#include"UDP_client.h"

#define DEFAULT_IP "192.168.1.53"
#define DEFAULT_PORT 5987

UDP_client::UDP_client(const char* hostname, int port){
	this->hostname = hostname;
	this->port = port;
}

UDP_client::~UDP_client(){
	
}


int main(){
	UDP_client client(DEFAULT_IP, DEFAULT_PORT);
	return 0;
}
