.PHONY:
%.o:%.c
	gcc -c $< -o $@
build:producer.o
	gcc $< -o app -lpthread