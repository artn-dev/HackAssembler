CC := gcc
CFLAGS := -Wall -Wextra

HackAssembler: main.o tokens.o
	$(CC) $^ -o HackAssembler $(CFLAGS)

main.o: main.c tokens.h
	$(CC) main.c -c $(CFLAGS)

tokens.o: tokens.c tokens.h
	$(CC) tokens.c -c $(CFLAGS)

.PHONY: clean
clean:
	rm *.o
