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
int main(int ac, char **av)
{
	int i = 1, j;
	int sum = 0;
	char *pointer;

	while (i < ac)
	{
		pointer = (char *)av[i];
		j = atoi(pointer);
		if (j < 0)
			j *= -1;
		sum += j;
		i++;
	}
	printf("sum is: %d\n", sum);
	return (0);
}
