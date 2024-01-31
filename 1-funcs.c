#include "monty.h"

void push(stack_t **head, unsigned int line_number) {
    (void)line_number;
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->prev = NULL;
    new->next = *head;
    new->n = curr_arg;
    *head = new;
}


void pall(stack_t **head, unsigned int line_number) {
    stack_t *temp;
    (void) line_number;
    temp = *head;

    while (temp != NULL) {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

