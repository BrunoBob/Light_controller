all: main

UDP_client.o: UDP_client.cpp UDP_client.h
	g++ -c -o udp_client.o UDP_client.cpp

main: UDP_client.o
	g++ -o main udp_client.o
