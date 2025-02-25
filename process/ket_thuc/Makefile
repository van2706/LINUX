
%.o:%.c
	gcc -o obj/$@ -c $<
app: obj/main.o
	gcc -o obj/$@ $<
clear:
	rm -rf app *.o
