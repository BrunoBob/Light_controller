#include "Light_command.h"

Light_command::Light_command(){

}

Light_command::~Light_command(){

}

//Commands
string Light_command::getCommandLightOn(){
	string command(COMMAND_LIGHT_ON,9);
	return command;
}

string Light_command::getCommandLightOff(){
	string command(COMMAND_LIGHT_OFF,9);
	return command;
}

string Light_command::getCommandWhiteLight(){
	string command(COMMAND_WHITE_LIGHT,9);
	return command;
}

string Light_command::getCommandColor(int color){
	string start(COMMAND_COLOR, 5);
	char colors[4];
	colors[0] = (char)color;
	colors[1] = (char)color;
	colors[2] = (char)color;
	colors[3] = (char)color;
	string end(colors,4);
	string command = start + end;
	return command;
}

string Light_command::getSessionIdRequest(){
	string command(SESSION_ID_REQUEST,27);
	return command;
}

string Light_command::getRequestHeader(){
	string command(REQUEST_HEADER,5);
	return command;
}

string Light_command::getSeqNumber(int nb){
	char seq[3];
	seq[0] = 0;
	seq[1] = (char)nb;
	seq[2] = 0;
	string SEQ(seq,3);
	return SEQ;
}

string Light_command::getCmdEnd(int cmdNbr, int zone, int param){
	string cmd;
	switch (cmdNbr) {
		case 1:
			cmd = getCommandLightOn();
			break;
		case 2:
			cmd = getCommandLightOff();
			break;
		case 4:
			cmd = getCommandWhiteLight();
			break;
		case 5:
			cmd = getCommandColor(param);
			break;
	}
	char end[3];
	end[0] = (char)zone;
	end[1] = 0;
	end[2] = zone;
	int i;
	for(i = 0 ; i < cmd.size() ; i++){
		end[2] += cmd.c_str()[i];
	}
	string END(end,3);
	string CMD = cmd + END;
	return CMD;
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

int Light_command::sendCmd(UDP_client* client, int IdCmd, int param, int seqNbr, int zone){

	string cmd;

	string id = getSessionId(client);
	string SEQ = getSeqNumber(seqNbr);
	string END = getCmdEnd(IdCmd, zone, param);
	cmd = getRequestHeader() + id + SEQ + END;

	client->write(cmd,cmd.size());
	char* buffer = (char*)malloc(100*sizeof(char));
	socklen_t len = 0;
	client->read(buffer,8,&len);
}
