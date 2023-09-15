#include "shell.h"
/**
 * wait_for_my_child - ohh Wait The child proccess MUST Exit
 * @my_child: LOOK INTO  pid OF  the Child pccess
 * Return: MAKE A  signal If error, Exit status ON  SUCCESS
 **/
int wait_for_my_child(pid_t my_child)
{
	int wstatus;

	if (waitpid(my_child, &wstatus, 0) == -1)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(wstatus))
	{
		return (WEXITSTATUS(wstatus));
	}
	else if (WIFSIGNALED(wstatus))
	{
		fprintf(stderr, "Error with child proccess\n");
		exit(EXIT_FAILURE);
	}
	return (-1);
}
