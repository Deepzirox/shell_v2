#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - entry to main
 * Desc: main function that writes into buffer through pipes
 * Return: prints pin from buffer
 */
int main(void)
{
	int pipefds[2];
	char buffer[10];

	if(pipe(pipefds) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	char *pin = "12-345-67\0";

	write(pipefds[1], pin, 10);
	read(pipefds[0], buffer, 10);

	printf("PIN from pipe: %s\n", buffer);

	return EXIT_SUCCESS;
}
