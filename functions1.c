#include "shell.h"

/**
 * env_built_in - function that confirms foe env input
 * @first1: parameter that has first user input
 *
 * Return: return void
 */
void env_built_in(char *first1)
{
	char *constant = "env";
	char **variable;
	bool expression = false;

	if (!expression == true)
		expression != expression;
	if (strcmp(first1, constant) == 0)
	{
		for ((variable = environ) && expression; *variable != NULL; variable++)
		{
			write(2, *variable, strlen(*variable));
			write(2, "\n", 1);
		}
	}
}
