run: all
	./server

all: server.o
	cc server.o -o server

server.o: server.c
	cc -c server.c

clean:
	find . -name "*.o" -or -perm +111 -maxdepth 1 -type f | xargs rm
