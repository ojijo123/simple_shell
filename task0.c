#include <unistd.h>
#include <stdio.h>

/**
 * main - main entry point of program
 *
 * Return: return 0 always
 */
int main(void)
{
	int i = 90;
	int j = 96;
	int sum;

	sum = i + j;
	printf("sum: %d\n", sum);
	return (0);
}
