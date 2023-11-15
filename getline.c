#include "header.h"

/**
 * _getline - read input from standard input by user
 * Return: the input on a buffer
 */
char *_getline(void)
{
	int i;
	int rd;
	int buffsize;
	char c;
	char *buffer;
	char *buf;


	buffsize = BUFSIZE;
	c = 0;
	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (i >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}

/**
 * enter - Handles newline character input
 * @string: String to be handled
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * space - function about removing spaces
 * @str-Input string to be processed.
 * Return: return Returns the modified string without leading spaces or an empty string
 */
char *space(char *str)
{
	int i;
	int j;
	char *buff;

	i = 0;
	j = 0;
	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] == ' ')
	{
		i++;
	}

	buff = malloc(sizeof(char) * (strlen(str) - i + 1));
	if (buff == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		buff[j] = str[i];
		i++;
		j++;
	}
	buff[j] = '\0';

	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return (strdup(""));
	}
	return (buff);
}


/**
 * hashtag_handler - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}


