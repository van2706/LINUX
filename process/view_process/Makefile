CC := gcc
CLASS := -I.
%.o:%.c
	gcc -o $@ -c $< $(CLASS)
rule1:exam.o
	gcc -o $@ exam.o $(CLASS)
rule2:main.o
	$(CC) -o $@ main.o $(CLASS)

clear:
	rm -rf rule* *.o
