#include "header.h"

/**
 * separator - Separates command received from stdin by ;
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **separator(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize;
	char **temp;

	if (!input || input[0] == '\0')
	{
		return (NULL);
	}

	buffsize = BUFSIZE;
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	i = 0;
	command = _strtok(input, ";&");
	while (command != NULL)
	{
		if (i >= buffsize - 1)
		{
			buffsize *= 2;
			temp = realloc(commands, sizeof(char *) * buffsize);
			if (!temp)
			{
				perror("Memory reallocation error");
				free(commands);
				return (NULL);
			}
			commands = temp;
		}
		commands[i] = command;
		i++;
		command = _strtok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}
