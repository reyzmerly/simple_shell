#include "shell.h"
/**
 * handle_input - MUST Ask if the input has || IT Calls the func to handle it
 * if it Doesn't Have it call A handle command function
 * @input: input the Line_input which we are searching in it
 * @envp: Enviro variable
 * Return: nothing or none
*/
void handle_input(char *input, char *envp[])
{
	if (my_substr(input, "|"))
	{
		run_shell(input, envp);
	}
	else
	{
		handle_command(input, envp);
	}
}
