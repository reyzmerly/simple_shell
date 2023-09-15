#include "shell.h"
/**
 * handle_command - THIS Looks IF the command and check
 * if is  a- build in function
 * OR b- Has a file in the dir /bin/, OR 3- Has a path
 * @command: MAKE  Line_input from the user and the one
 * which We Will Edit On It
 * @envp: MAKE  EnVP variable[]
 * Return: AN integerS value
*/
int handle_command(char *command, char *envp[])
{
	char **final_string;
	int buildin_containter, value_chpt_func, status;
	char *value_chfile;

	final_string = string_tokenization(command);

	if (final_string[0] == NULL || final_string[0][0] == '\0')
	{
		free(final_string);
		return (0);
	}
	if (my_strcmp("exit", final_string[0]) == 0)
		my_exit(final_string);

	buildin_containter = check_build_in_func(final_string[0], envp);
	value_chfile = file_check(final_string[0]);

	if (buildin_containter == 0 && value_chfile != NULL)
		final_string[0] = value_chfile;

	value_chpt_func = path_check_function(final_string[0]);
		if (value_chpt_func == 1)
		{
			status = fork_execute_function(final_string, envp);
			free(value_chfile);
			free(final_string);
			return (status);
		}

	if (value_chfile == NULL && value_chpt_func == 0 && buildin_containter == 0)
	{
		printf("%s: No such file or directory\n", final_string[0]);
	}
	free(value_chfile);
	free(final_string);
	return (127);
}
