#include "shell.h"
/**
 * my_strcpy - copy the str
 * @to_dest: paste to its destination
 * @from_scr: get it from  the source
 *
 * Return: program ret  Pointer To DEStination
 */
char *my_strcpy(char *to_dest, char *from_scr)
{
	int my_counter = 0;

	if (to_dest == from_scr || from_scr == 0)
		return (to_dest);
	while (from_scr[my_counter])
	{
		to_dest[my_counter] = from_scr[my_counter];
		my_counter++;
	}
	to_dest[my_counter] = 0;
	return (to_dest);
}
#include "shell.h"
/**
 * my_strcat - FUNCT ConCatenate Two STrinG INTO ONE
 * @str1: MAKE  sstring One
 * @str2: MAKE  string Two
 * Return: MAKE  POinter to variable
 */
char *my_strcat(const char *str1, const char *str2)
{
	size_t strlength1 = strlen(str1);
	size_t strlength2 = strlen(str2);
	char *container = malloc(strlength1 + strlength2 + 1);

	if (container == NULL)
	{
		return (NULL);
	}
	strcpy(container, str1);
	strcpy(container + strlength1, str2);
		return (container);
}
