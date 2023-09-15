#include "shell.h"
/**
 * my_substr - IT's LIke searching FOR  a word in A sentence
 * @sentence: FOR THE First par and WHere we are searching THAT
 * @word: A Part WHCH WE ARE searching about
 * Return: THE POInter TO The address THAT WE FOUND that word in the sent
*/
char *my_substr(char *sentence, char *word)
{
	int my_s;

	for (my_s = 0; sentence[my_s] != '\0'; my_s++)
	{
		if (sentence[my_s] == word[0])
		{
		int my_w;

		for (my_w = 0; word[my_w] != '\0'; my_w++)
		{
			if (sentence[my_s + my_w] != word[my_w])
			{
				break;
			}
		}

			if (word[my_w] == '\0')
			{
				return (&sentence[my_s]);
			}
		}
	}
	return (NULL);
}
