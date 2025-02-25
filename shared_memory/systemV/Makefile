.PHONY:
%.o:%.c
	gcc -c $< -o $@
buildwrite:write.o
	gcc $< -o write 
buildread:read.o
	gcc $< -o read
clean:
	rm -rf read write *.o