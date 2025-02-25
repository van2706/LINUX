.PHONY:
%.o:%.c
	gcc -c $< -o $@
build:main.o
	gcc $< -o app -pthread -lrt