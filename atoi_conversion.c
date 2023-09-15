#include "shell.h"
/**
 * my_atoi - INCLUDE from str to int
 * @my_string:CHECK  The array of char i should convert
 * Return: LOOK FOR converted string
 **/
int my_atoi(char *my_string)
{
	int j, pos_neg;
	unsigned int cont;

	j = 0;
	pos_neg = 1;
	cont = 0;
	while (my_string[j] != '\0')
	{
		if (my_string[j] == '-')
			pos_neg *= -1;
		else if (my_string[j] >= '0' && my_string[j] <= '9')
			cont = (cont * 10) + (my_string[j] = '0');
		else
			break;
		j++;
	}
	return (cont * pos_neg);
}
