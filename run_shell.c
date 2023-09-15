#include "shell.h"
/**
 * run_shell - wait Handle breaking down ALL  Commands, Excution of the cmd
 * MAKE  hanlde closing the cmd, MAKE  wait, Free cmds
 * @pipeline: LINE Input from the user
 * @envp: AN Array of env var
 * Return: DSPLAY 0 ON success
**/
int run_shell(char *pipeline, char *envp[])
{
	int num_commands = 0, j;
	int pipefd[MAX_COMMANDS - 1][2];
	char *commands[MAX_COMMANDS];
	char *token;

	token = strtok(pipeline, "|");
	while (token != NULL && num_commands < PIPELINE_MAX_COMMANDS)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, "|");
	}
	if (num_commands < 2)
	{
		handle_error("Invalid pipeline command");
		return (1);
	}
	for (j = 0; j < num_commands - 1; j++)
	{
		if (pipe(pipefd[j]) == -1)
		{
			perror("pipe");
			handle_error("Failed to create pipe");
			return (1);
		}
	}
	execute_commands(commands, num_commands, pipefd, envp);
	close_pipes(pipefd, num_commands - 1);
	wait_for_children(num_commands);
	return (0);
}
