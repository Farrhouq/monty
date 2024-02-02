#include "monty.h"

char *curr_arg;
int main(int ac, char **av)
{
    FILE *file;
    char *command;
    func_arg_t cur_func_arg;
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
        printf("\tloop main run for program and C: %s\n", command);
        if (command) {
        // printf("line %d\n", line_number);
        get_func_args(&head, command, line_number, file);
        }
        line_number++;

    }

    (void)ac;

    return (0);
}
