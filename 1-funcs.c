#include "monty.h"

void push(stack_t **head, unsigned int line_number)
{
    stack_t *new;
    int y = 0;

    (void)line_number;
    new = malloc(sizeof(stack_t));

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
            }
            else
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

/**
 * pint - prints the top/front of stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        myFree(*stack);
        failed();
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the top of stack
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        myFree(*stack);
        failed();
    }
    ptr = *stack;
    *stack = ptr->next;
    if (*stack != NULL)
        ptr->next->prev = NULL;
    free(ptr);
}

/**
 * swap - swaps the top two elements of the stack/queue
 * @stack: stack type
 * @line_number: line number of monty file
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
    int n;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free_stack(*stack);
        exit_prog();
    }
    n = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = n;
}