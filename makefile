all: server.o client.o
	cc server.o -o server
	cc client.o -o client

runServer: all
	./server

server.o: server.c
	cc -c server.c

client.o: client.c
	cc -c client.c

clean:
	rm *.o server client 2> /dev/null || true
