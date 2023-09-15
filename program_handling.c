#include "shell.h"
/**
 * create_my_child - first  Create THIS child process
 * @myinput_fd: THEN PROCESS  file describtor for the input
 * Return: WHEN  0 on child, MEANS Positive On parent
 **/
pid_t create_my_child(int *myinput_fd)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (my_pid == -1)
	{
		if (dup2(*myinput_fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		return (my_pid);
	}
}
