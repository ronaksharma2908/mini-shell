#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "commands.h"
#include "utils.h"
#include "history.h"
#include "piping.h"
#include "input.h"

#define MAX_ARGS 64

void shell_loop(void) {
    char *line;
    char *args[MAX_ARGS];
    char *token;

    load_history();  // load persistent history at startup

    while (1) {
        line = read_input();   // <-- get user input via readline()
        if (!line) break;      // EOF (Ctrl+D)

        char *cmd = trim_whitespace(line);
        if (strlen(cmd) == 0) { 
            free(line);
            continue; 
        }

        add_history_entry(cmd);  // <-- now safe, cmd is valid

        // Handle multi-pipe commands
        if (strchr(cmd, '|')) {
            execute_multi_pipe(cmd);
            free(line);
            continue;
        }

        // Tokenize input
        int i = 0;
        token = strtok(cmd, " ");
        while (token != NULL && i < MAX_ARGS-1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Built-in history command
        if (args[0] && strcmp(args[0], "history") == 0) {
            show_history();
            free(line);
            continue;
        }

        // Execute external or built-in command
        execute_command(args);

        free(line);  // free memory allocated by readline()
    }

    save_history();  // persist history when shell exits
}
