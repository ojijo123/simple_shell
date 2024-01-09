#include "shell.h"

/**
 * command - function checking for end of file condition
 * @buffer: parameter containing user input
 *
 * Return: return void
 */
void command(char *buffer)
{
	if (feof(stdin) && buffer != NULL)
	{
		write(1, "\n", 1);
		exit(0);
	}
}
/**
 * execute_command - function that executes commands
 * @buffer: parameter containing command
 * @string: buffer containing user input
 * @arg: arg[0]
 *
 * Return: return void
 */
void execute_command(char *buffer, char **string, char **arg)
{
	pid_t child_process = fork();

	if (child_process == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (child_process == 0 && buffer != NULL)
	{
		if (execve(buffer, string, NULL) == -1)
		{
			write(2, arg, strlen((char *)arg));
			write(2, ": ", 2);
			perror("execve failed");
			exit(1);
		}
		else
			execve(buffer, string, NULL);
	}
	else
		wait(0);
}

/**
 * tokenization - functiontaht string tokenizes
 * @formats: pointer containing user input
 * @user_inputs: pointer containing all user inputs
 * @argument: argv[0] the executable
 *
 * Return: return index 0
 */
void tokenization(char *formats, char **user_inputs, char **argument)
{
	int counter1 = 0, i;
	char *format[20];
	char *container1 = malloc(sizeof(char) * 1);

	if (container1 == NULL)
	{
		perror("memmory allocation failed");
		exit(1);
	}
	container1 = strtok(formats, " ");
	while (container1 != NULL)
	{
		format[counter1] = malloc(sizeof(char) * (strlen(container1) + 1));
		if (format[counter1] == NULL)
		{
			perror("memmory allocation failed");
			exit(1);
		}
		strcat(format[counter1], container1);
		container1 = strtok(NULL, " ");
		counter1++;
	}
	format[counter1] = NULL;
	exit_built_in(format[0]);
	env_built_in(format[0]);
	path_handler(format[0], user_inputs, argument);
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
	char *constant = "exit";

	if (strcmp(first, constant) == 0)
		exit(0);
}

/**
 * path_handler - function that handles path
 * @first_argument: command in array 0
 * @arguments: array containing user inputs
 * @argv_0: pointer containing argv[0]
 *
 * Return: return void
 */
void path_handler(char *first_argument, char **arguments, char **argv_0)
{
	if (access(first_argument, F_OK) == -1)
	{
		write(2, argv_0, strlen((char *)argv_0));
		write(2, ": ", 2);
		perror("command doesn't exist");
		exit(1);
	}
	if (access(first_argument, X_OK) == 0)
		execute_command(first_argument, arguments, argv_0);
}
