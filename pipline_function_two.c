#include "shell.h"
/**
 * create_pipes - create ASOME  Pipes Function.
 * @pipefd: CAN COntaiN AND   store the fd of |
 * @num_pipes: AND  How many numbers of | tp create
 * Return: IF  we did AWESOME =>0 on success,IF NO =>1 ON FAIL
 */
int create_pipes(int pipefd[][2], int num_pipes)
{
	int j;

	for (j = 0; j < num_pipes; j++)
	{
		if (pipe(pipefd[j]) == -1)
		{
			perror("pipe");
			return (1);
		}
	}
	return (0);
}
/**
 * free_commands - MAKE A free MeMORY.
 * @commands:TAKE  Commandds Array
 * @num_commands: DO THE COUNT OF commands
 * Return: Ohhh none unfurtutnately
 */
void free_commands(char *commands[], int num_commands)
{
	int j;

	for (j = 0; j < num_commands; j++)
	{
		free(commands[j]);
	}
}
/**
 * my_pipline_handler - PIP  cmd Handler.
 * @pipeline: DISPLAY STR of pipline  cmds
 * @envp: envP Var Array
 * Return: Display  0 on success, 1 on fail
 */
int my_pipline_handler(char *pipeline, char *envp[])
{
	return (run_shell(pipeline, envp));
}
