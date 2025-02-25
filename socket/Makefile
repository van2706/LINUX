%.o:%.c
	gcc -o $@ -c $<
server:server.o
	gcc -o $@ $<
client:client.o
	gcc -o $@ $<	
clear: 
	rm -rf make* *.o client_fifo_* server_fifo
