#include "monty.h"

/**
 * isComment - checks for comments
 * @line: the line to check
 * Return: 1 or 0 accordingly
 */
int isComment(const char *line)
{
	int i = 0;
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
	}
	return line[i] == '#';
}

/**
 * isEmptyLine - checks for empty lines and skips them
 * @line: the line to check
 * Return: 1 or 0 accordingly
 */
int isEmptyLine(const char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\r' && line[i] != '\t')
			return (0);
	}
	return (1);
}

char *curr_arg;
FILE *cur_file;
char *curr_command;

/**
 * main - the monty program
 * @ac: the arg count
 * @av: the arg list
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *file;
	char *command;
	stack_t *head = NULL;
	int line_number;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (file == NULL)
	{   fprintf(stderr, "Error opening file");
		return (EXIT_FAILURE);
	}
	command = malloc(MAX_COMMAND_LENGTH);
	if (command == NULL)
	{   fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cur_file = file;
	line_number = 1;
	while (fgets(command, MAX_COMMAND_LENGTH, file) != NULL)
	{
		size_t len = strlen(command);

		if (isEmptyLine(command) || strcmp(command, "nop") == 0
			|| isComment(command))
		{   line_number++;
			continue;
		}
		if (len > 0 && command[len - 1] == '\n')
			command[len - 1] = '\0';
		curr_command = command;
		get_func_args(&head, command, line_number, file);
		line_number++;
	}
    free_stack(head);
	exit_prog();
	return (0);
}
