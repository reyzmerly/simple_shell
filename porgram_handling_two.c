#include "shell.h"
/**
 * command_execution - MAKE EXcute the COMMAND
 * @my_cmd: The command RUN
 * Return: Nothind \NONE
 **/
void command_execution(char *my_cmd)
{
	char *argv[4];

	argv[0] = "sh";
	argv[1] = "-c";
	argv[2] = my_cmd;
	argv[3] = NULL;

	execvp("/bin/sh", argv);
	perror("execvp");
	exit(EXIT_FAILURE);
}
/**
 * sys_cust - INTerface to excute THe cmd
 * @my_cmd: TAKE The command
 * @in_fd: CHECK FILE  DEScribtor for it
 * Return: make an Exit_Status
 */
int sys_cust(char *my_cmd, int in_fd)
{
	int exit_stat;
	pid_t my_child = create_my_child(&in_fd);

	if (my_child == 0)
	{
		command_execution(my_cmd);
	}
	exit_stat = wait_for_my_child(my_child);
	return (exit_stat);
}
