#include "shell.h"
/**
 * my_dubler - this Like the fork, can be separate the string into two
 * @str: SEARCH string that can  be devided into two
 * Return: POinter to my_dubler stR
 */
char *my_dubler(char *str)
{
	int mystr_length = 0;
	char *my_dub;

	if (str == NULL)
		return (NULL);
	while (*str++)
		mystr_length++;
	my_dub = malloc(sizeof(char) * (mystr_length + 1));
	if (!my_dub)
		return (NULL);
	for (mystr_length++; mystr_length--;)
		my_dub[mystr_length] = *--str;
	return (my_dub);
}

#include "shell.h"
/**
 * my_strlen - MAKE COUNT the num of charater in the str
 * @str: CHECK  String to be checked
 * Return: the Length of str
 */
int my_strlen(char *str)
{
	int my_counter = 0;

	if (!str)
		return (0);
	while (*str++)
		my_counter++;
	return (my_counter);
}
