#include "monty.h"

void push(stack_t **head, unsigned int line_number)
{
    (void)line_number;
    stack_t *new = malloc(sizeof(stack_t));
    int y = 0;

    // curr_arg = NULL;
    // if (curr_arg == NULL)
    //     printf("%s\n", "curr_arg");
    // printf("%s\n", "curr_arg");

    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }


    if (curr_arg != NULL)
    {
        while (curr_arg[y] != '\0')
        {
            if (curr_arg[y] == '-')
            {
                y++;
                continue;
            }
            if (curr_arg[y] < 48 || curr_arg[y] > 57)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            } else 
            {
                y++;
                continue;
            }
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new->n = atoi(curr_arg);
    new->prev = NULL;
    new->next = *head;
    *head = new;
}

void pall(stack_t **head, unsigned int line_number)
{
    stack_t *temp;
    (void)line_number;
    temp = *head;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
