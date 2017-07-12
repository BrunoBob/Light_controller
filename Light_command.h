#ifndef _LIGHT_COMMAND_
#define _LIGHT_COMMAND_

#include <string>
#include <iostream>
#include "UDP_client.h"
#include <unistd.h>

#define SESSION_ID_REQUEST "\x20\x00\x00\x00\x16\x02\x62\x3A\xD5\xED\xA3\x01\xAE\x08\x2D\x46\x61\x41\xA7\xF6\xDC\xAF\xD3\xE6\x00\x00\x1E"
#define REQUEST_HEADER "\x80\x00\x00\x00\x11"
#define COMMAND_LIGHT_ON "\x31\x00\x00\x08\x04\x01\x00\x00\x00"

using namespace std;

typedef unsigned char Byte;

class Light_command{

public:

	Light_command();
	~Light_command();

	string getSessionIdRequest();
	string getRequestHeader();
	string getCommandLightOn();

	string getSessionId(UDP_client* client);


	void printString(string msg, int size);

};


#endif //_LIGHT_COMMAND_
