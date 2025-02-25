%.o:%.c
	gcc -o $@ -c $<
producer:producer.o
	gcc -o $@ $<
consumer:consumer.o
	gcc -o $@ $<
clear: 
	rm -rf make* *.o
