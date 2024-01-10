#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - main entry point of program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: return 0 always
 */
int main(void)
{
	char *pointer = "hello, this is a betty complying file";

	write(1, pointer, strlen(pointer));
	write(1, "\n", 1);
	return (0);
}
