#include "monty.h"

func_arg_t get_func_args(stack_t** head, char *line, int line_number, FILE *file) {
    char *func_name = NULL, *arg = NULL;
    func_arg_t func_arg;
    char *tok = NULL;

    instruction_t code_funcs[] = {
        {"push", push},
        {"pall", pall}};


    func_name = strtok(line, " ");
    arg = strtok(NULL, " ");
    if (arg != NULL)
        curr_arg = atoi(arg);
    
    
    for (int i = 0; i < 2; i++) {
        if (strcmp(code_funcs[i].opcode, func_name) == 0) {
            code_funcs[i].f(head, line_number);
            break;
        }
        else {
            func_arg.f = NULL;
            func_arg.arg = 0;
        }
    }
    // func_arg.f = code_funcs[0].f;
    // func_arg.arg = 2;
    return func_arg;

}
