#include "Light_command.h"

#define SESSION_ID_REQUEST "\x20\x00\x00\x00\x16\x02\x62\x3A\xD5\xED\xA3\x01\xAE\x08\x2D\x46\x61\x41\xA7\xF6\xDC\xAF\xD3\xE6\x00\x00\x1E"


Light_command::Light_command(){

}

Light_command::~Light_command(){

}




//Get table of commands

Byte* Light_command::getSessionIdRequest(){
	Byte* command = (Byte*)SESSION_ID_REQUEST;
	return command;
}



//Send commands

void Light_command::getSessionId(UDP_client client, Byte* id1, Byte* id2){
	socklen_t len;

	Byte* msg =	getSessionIdRequest();
	client.write(msg, 27);

	Byte* buffer = (Byte*)malloc(100*sizeof(char));
	client.read(buffer, 22, &len);

	*id1 = buffer[19];
	*id2 = buffer[20];
}
