CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -c -g
OBJECTS = main.o builtin.o argv.o env.o builtin2.o input.o process.o strings.o shell.o env3.o env2.o
all: hsh clean
hsh: $(OBJECTS)
	$(CC) $(OBJECTS) -o hsh
%.o: %.c
	$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o
