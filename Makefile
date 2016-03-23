all: proj

proj: item.h item.c link.h link.c queue.h queue.c message_processing.h message_processing.c main.c
	gcc -ansi -Wall -pedantic item.h item.c link.h link.c queue.h queue.c message_processing.h message_processing.c main.c

clean:
	rm -f *.o proj
