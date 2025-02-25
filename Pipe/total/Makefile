%.o:%.c
	gcc -c $< -o $@
build:total_server.o total_client.o
	gcc -o server total_server.o -pthread
	gcc -o client total_client.o -pthread
clean:
	rm -rf *.o server client HTTP_* server_fifo