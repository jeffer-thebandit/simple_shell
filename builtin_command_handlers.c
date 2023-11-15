#include "header.h"

/**
 * check_function - Checks if parsed command in built-in
 * @cmd: Parsed command to be check
 * Return: 0 Succes -1 Fail
 */
int check_function(char **cmd)
{
	int i;
	builtin function[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((function + i)->command)
	{
		if (_strcmp(cmd[0], (function + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * handle_builtin_function - Handles predefined built in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 Failure 0 Success
 */
int handle_builtin_function(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exit_bultin - Exit Status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */
void exit_bultin(char **cmd, char *input, char **argv, int c, int stat)
{
	int status;
	int i;

	i = 0;
	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_print_error(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_print_error(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);

		}
	}
}
