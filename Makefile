CC := gcc
CFLAGS := -Wall -Wextra

HackAssembler: main.o
	$(CC) $^ -o HackAssembler $(CFLAGS)

main.o: main.c
	$(CC) main.c -c $(CFLAGS)

.PHONY: clean
clean:
	rm *.o
