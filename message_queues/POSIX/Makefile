.PHONY: build clean

%.o:%.c
	gcc -c $< -o $@
build:consumerA.o consumerB.o producer.o
	gcc consumerA.o -o consumerA -lrt
	gcc consumerB.o -o consumerB -lrt
	gcc producer.o -o producer -lrt
clean:
	rm -rf *.o consumerA consumerB producer