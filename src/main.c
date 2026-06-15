#include <signal.h>
#include <stdio.h>
#include "include/shell.h"

void sigint_handler(int sig) {
    printf("\nUse 'exit' to quit the shell.\n");
}

void sigtstp_handler(int sig) {
    printf("\nProcess stopped. Use 'fg' or 'bg' to manage jobs.\n");
}

int main() {
    signal(SIGINT, sigint_handler);    // Ctrl+C
    signal(SIGTSTP, sigtstp_handler);  // Ctrl+Z
    shell_loop();
    return 0;
}
