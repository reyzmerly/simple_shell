#include "shell.h"
/**
 * file_check - make it Check FOR the command file ExistING in /bin/
 * @final_string: DO AN  Input line from user to check
 * Return: MAKE A NULL if not found, OR the full path to the command
 */
char *file_check(char *final_string)
{
	DIR *in_dir = opendir("/bin/");
	struct dirent *entir_struct;

	if (in_dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}


	while ((entir_struct = readdir(in_dir)) != NULL)
	{
		char *dir_container = entir_struct->d_name;

		if (strcmp(dir_container, final_string) == 0)
	{
		char *cmd_exist = malloc(my_strlen("/bin/") + my_strlen(final_string) + 1);

	if (cmd_exist == NULL)
	{
		closedir(in_dir);
		perror("malloc");
		return (NULL);
	}
		cmd_exist = strcpy(cmd_exist, "/bin/");
		cmd_exist = my_strcat(cmd_exist, final_string);
		closedir(in_dir);
		return (cmd_exist);
	}
	}

		closedir(in_dir);
	return (NULL);
}
