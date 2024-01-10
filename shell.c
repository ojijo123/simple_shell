#include "shell.h"

#define MAX_SIZE 100

/**
 * main - main entry point of program
 * @ac: argument count
 * @argv: argument vector
 * @env: environmet parameter passed
 *
 * Return: return (0) always
 */
int main(int ac, char **argv)
{
	int byte = 0;
	char buffer_command[MAX_SIZE];
	char *args[] = {buffer_command, NULL};
	bool value = false;

	while (1 && !value)
	{
		if (isatty(0) == 1)
			write(1, "soloouma$ ", 10);
		if (fgets(buffer_command, MAX_SIZE, stdin) == NULL)
			command(buffer_command);
		else
		{
			byte = strcspn(buffer_command, "\n");
			buffer_command[byte] = '\0';
			tokenization(buffer_command, args, argv[0]);
			/*path_handler(index, args, argv[0];*/
			execute_command(buffer_command, args, argv[0]);
		}
	}
	return (0);
}
