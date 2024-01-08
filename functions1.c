#include "shell.h"

/**
 * env_built_in - function that confirms foe env input
 * @first1: parameter that has first user input
 * @var: argument containing child process environment
 *
 * Return: return void
 */
void env_built_in(char *first1, char **var)
{
	if (strcmp(first1, "env") == 0)
	{
		int j;
		
		for (j = 0; var[j] != NULL; j++)
		{
			write(2, var[j], strlen((char *)var[j]));
			write(2, "\n", 1);
			j++;
		}
	}
}
