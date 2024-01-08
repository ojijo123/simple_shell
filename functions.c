#include "shell.h"

 /**
  * command - function checking for end of file condition
  * @buffer: parameter containing user input
  *
  * Return: return void
  */
void command(char *buffer)
{
	if (**buffer != NULL &&** feof(stdin))
		feof
	{
		write(1, "\n", 1);
		exit(0);
	}
}
 /**
  * execute_command - function that executes commands
  * @buffer: parameter containing command
  * @string: buffer containg user input
  * @arg: arg[0]
  *
  * Return: return void
  */
void execute_command(char *buffer, char **string, char **arg)
{
	pid_t child = fork();

	buffer[strcspn(buffer, "\n")] = '\0';
	if (child == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (child == 0)
	{
		if (execve(buffer, string, NULL) == -1)
		{
			write(2, arg, strlen((char *)arg));
			write(2, ": ", 2);
			perror("execve");
			exit(1);
		}
		else
			execve(buffer, string, NULL);
	}
	else
		**free(buffer);
		wait(0);
}
 /**
  * tokenization - fuction that string tokenizes
  * @formats: pointer containing user input
  *
  * Return: return index 0
  */
void tokenization(char *formats, char **var)
{
	int counter1 = 0;
	char *format[100];
	char *container1 = malloc(sizeof(char) * 100);

	if (container1 == NULL)
		exit(1);
	container1 = strtok(formats, " ");
	while (container1 != NULL)
	{
		format[counter1] = malloc(sizeof(char) * (strlen(container1) + 1));
		if (format[counter1] == NULL)
			exit(1);
		strcat(format[counter1], container1);
		container1 = strtok(NULL, " ");
		counter1++;
	}
	exit_built_in(format[0]);
	env_built_in(format[0], var);
	for (i = 0; i < counter1; i++)
		free(format[i]);
	free(container1);
}

/**
 * exit_built_in - function that confirms for exit user input
 * @first: parameter containing user input
 *
 * Return: return void
 */
void exit_built_in(char *first)
{
        if (strcmp(first, "exit") == 0)
                exit(0);
}

 /**
  * path_handler - function that hanles path
  * @first_argument: command in array 0
  * @arguments: array containing user input
  * @arg_0: pointer containing argv[0]
  *
  * Return: return void
  */
void path_handler(char ***first_argument, char **arguments, char **argv_0)
{
	if (access((char **)first_argument, F_OK) == -1)
	{
		write(2, argv_0, strlen((char *)argv_0));
		write(2, ": ", 2);
		perror("execve");
		exit(1);
	}
	else
		execute_command((char *)first_argument, arguments, argv_0);
}
