#include "monty.h"

int get_func_args(stack_t **head, char *line, int line_number, FILE *file)
{
    char *func_name = NULL;
    int i = 0;
    instruction_t code_funcs[] = {
        {"push", push},
        {"pall", pall}};

    (void)file;

    func_name = strtok(line, " ");
    curr_arg = strtok(NULL, " ");

    for (i = 0; i < 2; i++)
    {
        if (strcmp(code_funcs[i].opcode, func_name) == 0)
        {
            code_funcs[i].f(head, line_number);
            return (0);
        }
    }
    return 0;
}
