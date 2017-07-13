#ifndef _LIGHT_COMMAND_
#define _LIGHT_COMMAND_

#include <string>
#include <iostream>
#include "UDP_client.h"
#include <unistd.h>

#define SESSION_ID_REQUEST "\x20\x00\x00\x00\x16\x02\x62\x3A\xD5\xED\xA3\x01\xAE\x08\x2D\x46\x61\x41\xA7\xF6\xDC\xAF\xD3\xE6\x00\x00\x1E"
#define REQUEST_HEADER "\x80\x00\x00\x00\x11"
#define COMMAND_LIGHT_ON "\x31\x00\x00\x08\x04\x01\x00\x00\x00"
#define COMMAND_LIGHT_OFF "\x31\x00\x00\x08\x04\x02\x00\x00\x00"
#define COMMAND_WHITE_LIGHT "\x31\x00\x00\x08\x05\x64\x00\x00\x00"
#define COMMAND_COLOR "\x31\x00\x00\x08\x01"
#define COMMAND_SATURATION "\x31\x00\x00\x08\x02"
#define COMMAND_BRIGHTNESS "\x31\x00\x00\x08\x03"
#define COMMAND_KELVIN "\x31\x00\x00\x08\x05"

using namespace std;

typedef unsigned char Byte;

class Light_command{

public:

	Light_command();
	~Light_command();

	string getSessionIdRequest();
	string getRequestHeader();
	string getSeqNumber(int nb);
	string getCmdEnd(int cmd, int zone, int param);


	string getCommandLightOn();
	string getCommandLightOff();
	string getCommandWhiteLight();
	string getCommandColor(int color);

	string getSessionId(UDP_client* client);
	int sendCmd(UDP_client* client, int IdCmd, int param, int seqNbr, int zone);

};


#endif //_LIGHT_COMMAND_
