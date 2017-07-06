all: main

UDP_client.o: UDP_client.cpp UDP_client.h
	g++ -c -std=c++11 -o UDP_client.o UDP_client.cpp

main: UDP_client.o
	g++ -o main UDP_client.o

clean:
	rm -rf *.o main
