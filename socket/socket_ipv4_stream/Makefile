.PHONY: buildsrever buildclient
%.o:%.c
	gcc -c $< -o $@
buildserver: server.o
	gcc $< -o server
buildclient:client.o
	gcc $< -o client
clean:
	rm -rf server client