#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int testmain() {
    // char *tok = NULL;
    char *comm = "     push          7";

    char line[MAX_COMMAND_LENGTH];
    strcpy(line, comm);
    // printf("%s\n", tok);
    get_func_args(line);
    return (0);
}