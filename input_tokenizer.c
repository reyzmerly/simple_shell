#include "shell.h"
/**
 * my_strcmp - comp  Two STrings.
 * @string1: THIS IS FOR  First string to compare.
 * @string2: THIS IS FOR The Second string to compare.
 * Return: ON RETURN  0 on Equality
 * a - VAlue if @string1 < @string2,
 * OR A + value if @string1 > @string2.
 */
int my_strcmp(const char *string1, const char *string2)
{
	while (*string1 != '\0' && *string2 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}
	return ((int) (*string1) - (*string2));
}
