#include "Light_command.h"

Light_command::Light_command(){

}

Light_command::~Light_command(){

}




//Get Byte array of commands

string Light_command::getSessionIdRequest(){
	string command(SESSION_ID_REQUEST,27);
	return command;
}

string Light_command::getRequestHeader(){
	string command(REQUEST_HEADER,5);
	return command;
}

string Light_command::getCommandLightOn(){
	string command(COMMAND_LIGHT_ON,9);
	return command;
}


//Send commands

string Light_command::getSessionId(UDP_client* client){
	socklen_t len;

	string msg =	getSessionIdRequest();
	client->write(msg, 27);

	len = 0;
	char* buffer = (char*)malloc(100*sizeof(char));
	client->read(buffer, 22, &len);

	char id[2];
	id[0] = buffer[19];
	id[1] = buffer[20];

	string ID(id, 2);
	return ID;
}

void Light_command::printString(string msg, int size){
	int i;
	for(i = 0 ; i < size ; i++){
		printf("%0x - ", (Byte)msg.c_str()[i]);
	}
	printf("\n");
}
