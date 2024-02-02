#include "monty.h"

int get_func_args(stack_t **head, char *line, int line_number, FILE *file)
{
    char *func_name = NULL;
    int i = 0;
    instruction_t code_funcs[] = {
        {"push", push},
        {"pall", pall},
        {"mod", modu},
        {"div", division},
        {"sub", sub},
        {"add", add},
        {"pint", pint},
        {"swap", swap},
        {"pop", pop},
    };

    (void)file;

    func_name = strtok(line, " \n\t");
    curr_arg = strtok(NULL, " \n\t");

    for (i = 0; i < 9; i++)
    {
        if (strcmp(code_funcs[i].opcode, func_name) == 0)
        {
            code_funcs[i].f(head, line_number);
            return (0);
        }
    }
    return 0;
}

/**
 * exit_prog - exits the function
 */
void exit_prog()
{
    fclose(cur_file);
    free(curr_command);
    exit(EXIT_FAILURE);
}

/**
 * free_stack - frees a stack
 * @stack: stack head
 *
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}