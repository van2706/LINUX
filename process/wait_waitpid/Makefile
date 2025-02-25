CC := gcc
CLASS := -I.

%.o:%.c
	gcc -o $@ -c $<
app:main.o wait.o
	gcc -o $@ $<
	gcc -o wait wait.o
clear:
	rm -rf *.o app wait
