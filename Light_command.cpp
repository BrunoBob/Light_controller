#include "Light_command.h"

Light_command::Light_command(){

}

Light_command::~Light_command(){

}




//Get Byte array of commands

Byte* Light_command::getSessionIdRequest(){
	Byte* command = (Byte*)SESSION_ID_REQUEST;
	return command;
}

Byte* Light_command::getCommandLightOn(){
	Byte* command = (Byte*)COMMAND_LIGHT_ON;
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
