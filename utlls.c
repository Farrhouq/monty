#include "monty.h"

int get_func_args(stack_t **head, char *line, int line_number, FILE *file)
{
    char *func_name = NULL;
    func_arg_t func_arg;
    char *tok = NULL;
    int y = 0, i = 0;
    instruction_t code_funcs[] = {
        {"push", push},
        {"pall", pall}};

    func_name = strtok(line, " ");
    // printf("the time %s\n", func_name);
    curr_arg = strtok(NULL, " ");


    for (i = 0; i < 2; i++)
    {
        if (strcmp(code_funcs[i].opcode, func_name) == 0)
        {
            printf("so we have curr_arg as %s\n", curr_arg);
            // code_funcs[i].f(head, line_number);
            return (0);
        }
        
    }
    return 0;
}
