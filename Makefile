CC=gcc
CFLAGS=-Wall -Werror -pedantic -c -g
OBJECTS = main.o alias.o argv.o env.o handlers.o input.o process.o strings.o
all: hsh clean
hsh: $(OBJECTS)
	$(CC) $(OBJECTS) -o hsh
%.o: %.c
	$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o
