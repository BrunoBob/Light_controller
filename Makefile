all: main

UDP_client.o: UDP_client.cpp UDP_client.h
	g++ -c -std=c++11 -o UDP_client.o UDP_client.cpp

Light_command.o: Light_command.cpp Light_command.h
	g++ -c -std=c++11 -o Light_command.o Light_command.cpp

main: UDP_client.o Light_command.o
	g++ -o main UDP_client.o Light_command.o

clean:
	rm -rf *.o main
