#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "commands.h"
#include "utils.h"
#include "jobs.h"

int execute_command(char **args, int background, pid_t pid, const char *full_cmd) {
    if (args[0] == NULL) return 1;

    if (strcmp(args[0], "jobs") == 0) {
        list_jobs();
        return 1;
    } else if (strcmp(args[0], "fg") == 0) {
        if (args[1]) bring_foreground(atoi(args[1]));
        else print_colored("Usage: fg <jobid>\n", YELLOW);
        return 1;
    } else if (strcmp(args[0], "bg") == 0) {
        if (args[1]) resume_background(atoi(args[1]));
        else print_colored("Usage: bg <jobid>\n", YELLOW);
        return 1;
    } else {
        if (!background) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            add_job(pid, full_cmd);  // store full command string
            print_colored("Process running in background\n", YELLOW);
        }
    }
    return 1;
}
