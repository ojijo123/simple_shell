#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - main entry point of program
 *
 * Descpription: This is main function.
 * The function is tasked with...
 * The dispalying of a text...
 * To the standard output.
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
