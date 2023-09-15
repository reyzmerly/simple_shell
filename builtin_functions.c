#include "shell.h"
/**
 * my_env - Print The environmental value
 * Return: WILL Return 0 success
 */
int my_env(void);
/**
 * check_build_in_func - TRY Checking the string built in function
 * @final_string: CHECK TO input from user
 * @envp: LOOK Array for environmental variables
 * Return: THEN  Return an integer value
 */
int check_build_in_func(char *final_string, char *envp[])
{
	char *array_buitin[] = {"cd", "exit", "env"};
	int num_builtins = sizeof(array_buitin) / sizeof(array_buitin[0]);
	int j;
	(void)envp;

	for (j = 0; j < num_builtins; j++)
	{
	if (my_strcmp(array_buitin[j], final_string) == 0)
	{
		switch (j + 1)
		{
		case 1:
			chdir(final_string);
			return (1);

		case 2:
			exit(EXIT_SUCCESS);

		case 3:
			my_env();
			return (1);

		default:
			return (0);
		}
	}
	}

	return (0);
}
