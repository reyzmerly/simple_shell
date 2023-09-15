#include "shell.h"
/**
 * fork_execute_function - make A PEforM exe  program in a child PROC
 * @array_string: DO THE Line input from the user Array
 * @env: PArent Array ENv variable
 * Return: FUNCT void
 */
pid_t fork_execute_function(char **array_string, char *env[])
{
	pid_t my_child_pid;
	int waiting_status = 0;

	my_child_pid = fork();
	if (my_child_pid < 0)
	{
		perror("Error: Fork failed");
		return (-1);
	}
	else if (my_child_pid == 0)
	{
		if (execve(array_string[0], array_string, env) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", array_string[0]);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&waiting_status) == -1)
		{
			perror("Error: Wait failed");
		}
		return (WEXITSTATUS(waiting_status));
	}
	return (-1);
}
