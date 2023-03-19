runServer: all
	./server

all: server.o client.o
	cc server.o -o server && \
		cc client.o -o client

server.o: server.c
	cc -c server.c

client.o: client.c
	cc -c client.c

clean:
	find . -name "*.o" -or -perm +111 -maxdepth 1 -type f | xargs rm
