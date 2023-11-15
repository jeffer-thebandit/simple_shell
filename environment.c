#include "header.h"

/**
 * create_environment- Creates an array of Enviroment Variables
 * @environment: Array to store Enviroment Variables
 */

void create_environment(char **environment)
{
	int i;

	for (i = 0; environ[i]; i++)
		environment[i] = _strdup(environ[i]);
	environment[i] = NULL;
}

/**
 * free_env - Frees the memory of the created Enviroment Variables array
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
