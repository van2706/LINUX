CC := gcc
CLASS := -I.

%.o:%.c
	$(CC) -o $@ -c $<
make1:main.o
	$(CC) -o $@ $<
make2:main2.o
	$(CC) -o $@ $<
clear:
	rm -rf make* *.o
