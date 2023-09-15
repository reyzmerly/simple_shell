#include "shell.h"
/**
 * parse_pipeline_commands - make A Break DOWN OF THE commands in SMALLER PARTS
 * @pipeline: FOR The Line INput
 * @num_commands: THIS  CONtain A Count of cmd
 * Return: CAN RETUR AN ARRAY of commands
**/
char **parse_pipeline_commands(char *pipeline, int *num_commands)
{
	int j = 0;
	char *token = strtok(pipeline, "|");
	char **commands = malloc(MAX_COMMANDS * sizeof(char *));

	if (commands == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		*num_commands = 0;
		return (NULL);
	}
	while (token != NULL && j < MAX_COMMANDS)
	{
		commands[j] = strdup(token);
		if (commands[j] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			*num_commands = j;
			free_commands(commands, j);
			return (NULL);
		}
		j++;
		token = strtok(NULL, "|");
	}
	*num_commands = j;
	return (commands);
}
