#include "shell.h"
/**
 * string_tokenization - BReaking Down the input into small PARTS
 * @str: MAKE  Line input from the user
 * Return: AN Array OF Broken down commands
 **/
char **string_tokenization(char *str)
{
	char **array_string;
	char *token;
	int index = 0;

	array_string = malloc(8 * sizeof(char *));
	if (array_string == NULL)
	{
		perror("Cannot allocate memory");
		exit(1);
	}
	token = strtok(str, " \t\n");
	while (token != NULL)
	{
	array_string[index] = strdup(token);
	if (array_string[index] == NULL)
	{
		perror("Cannot allocate memory");
		exit(1);
	}
	index++;
	token = strtok(NULL, " \t\n");
	}
	array_string[index] = NULL;
	return (array_string);
}
