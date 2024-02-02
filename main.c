#include "monty.h"



int isEmptyLine(const char *line) {
    int i;

    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '\r' && line[i] != '\t') {
            return 0;
        }
    }
    return 1;
}




char *curr_arg;
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
    command = malloc(MAX_COMMAND_LENGTH);
    if (command == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    line_number = 1;
    while (fgets(command, MAX_COMMAND_LENGTH, file) != NULL)
    {
        size_t len = strlen(command);

        if (isEmptyLine(command)) {
            line_number++;
            continue;
        }

        if (strcmp(command, "nop") == 0) {
            line_number++;
            continue;
        }

        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }
        if (command) {
        get_func_args(&head, command, line_number, file);
        }
        line_number++;
    }

    (void)ac;

    return (0);
}
