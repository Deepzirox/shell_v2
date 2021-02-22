CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -c -g
OBJECTS = main.o alias.o argv.o env.o handlers.o input.o process.o strings.o shell.o virtual.o env2.o
all: hsh clean
hsh: $(OBJECTS)
	$(CC) $(OBJECTS) -o hsh
%.o: %.c
	$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o
