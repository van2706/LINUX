CC:= gcc
CLASS := -I.
%.o:%.c
	gcc -o $@ -c $<
make1:main.o
	gcc -o $@ $< -pthread
clear:
	rm -rf make* *.o
