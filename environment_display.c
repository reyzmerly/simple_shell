#include "shell.h"
/**
 * my_exit - MAKE Exit The program
 * @argument: IS IT an Array of arguments
 * Return: IF IT Doesn't MAKE any  return
 **/
void my_exit(char **argument)
{
	int my_stat = 0, j;

	if (argument[1] != NULL)
	{
		my_stat = my_atoi(argument[1]);
	}
	for (j = 0; argument[j] != NULL; j++)
	{
		free(argument[j]);
	}
	free(argument);
	exit(my_stat);
}
