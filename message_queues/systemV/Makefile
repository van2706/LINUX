.PHONY: buid buildproducer clean
%.o:%.c
	gcc -c $< -o $@
build: consumerA.o consumerB.o
	gcc consumerA.o -o consumerA -lpthread
	gcc consumerB.o -o consumerB -lpthread
buildproducer: producer.o
	gcc $<  -o producer -lpthread