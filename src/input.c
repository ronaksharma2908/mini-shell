#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "input.h"

// Custom prompt with color
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

char *read_input(void) {
    char *line = readline(GREEN "mini-shell> " RESET);
    if (line && *line) {
        add_history(line);  // readline's built-in history
    }
    return line;
}
