.PHONY:
%.o:%.c
	gcc -c $< -o $@  -I.
buildwrite:write.o
	gcc $< -o write -lrt
buildread:read.o
	gcc $< -o read -lrt
clean:
	rm -rf read write *.o