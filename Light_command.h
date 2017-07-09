#ifndef _LIGHT_COMMAND_
#define _LIGHT_COMMAND_

#include <string.h>
#include "UDP_client.h"

typedef unsigned char Byte;

class Light_command{

public:

	Light_command();
	~Light_command();

	Byte* getSessionIdRequest();

	void getSessionId(UDP_client client, Byte* id1, Byte* id2);

};


#endif //_LIGHT_COMMAND_
