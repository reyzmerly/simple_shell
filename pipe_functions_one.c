#include "shell.h"
/**
 * handle_error - make it  HADLE  ErrorS of PiPlines
 * @message: WARN A  Meesage ErrOR
 * Return: will be  nothing, or  void
**/
void handle_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
}
/**
 * close_pipes - MAKE Close OF  pipes
 * @pipefd: THIS  FILE descriB FOR the pipe
 * @num_pipes: DISPLAY ANY Number of pipes
 * Return: COMPLETELY Nothing
**/
void close_pipes(int pipefd[][2], int num_pipes)
{
	int j;

	for (j = 0; j < num_pipes; j++)
	{
		close(pipefd[j][0]);
		close(pipefd[j][1]);
	}
}
/**
 * wait_for_children - make a Handle TO WAIT  child proccess
 * @num_commands: MAKE A Number of commands
 * Return: DO Nothing
**/
void wait_for_children(int num_commands)
{
	int j;

	for (j = 0; j < num_commands; j++)
	{
		wait(NULL);
	}
}
