proj: item.h item.c link.h link.c queue.h queue.c functions.h functions.c message_processing.c
	gcc -ansi -Wall -pedantic -o message_processing item.h item.c link.h link.c queue.h queue.c functions.h functions.c message_processing.c

clean:
	rm -f message_processing

