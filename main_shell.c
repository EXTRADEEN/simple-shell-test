#include "shell.h"

/**
  * main - start the shell
  * Return: 1
  */

int main(void)
{
	int status = 1;
	char *line;
	char **args;

	while (status)
	{
		status = isatty(0);

		if (status == 1)
			write(1, "♥♥ WE LOVE SIPHAN ♥♥ ", 29);

		line = func_read();
		if (line == NULL || (_strcmp(line, "exit") == 0))
		{
			free(line);
			exit(0);
		}
		else if (_strcmp(line, "env") == 0)
		{
			_printenv();
			free(line);
			continue;
		}
		args = func_split(line);
		if (args == NULL)
		{
			free_grid(args);
			free(line);
			free(args);
			continue;
		}
		if (line[0] != '\n' || line[1] != '\0')
			status = func_exec(args);
		free(line);
		free(args);
	}
	return (0);
}
