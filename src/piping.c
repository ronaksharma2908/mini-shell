#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "piping.h"

int execute_multi_pipe(char *cmd) {
    char *commands[10];
    int n = 0;

    char *token = strtok(cmd, "|");
    while (token != NULL && n < 10) {
        commands[n++] = token;
        token = strtok(NULL, "|");
    }

    int fd[2], in_fd = 0;
    for (int i = 0; i < n; i++) {
        pipe(fd);
        pid_t pid = fork();

        if (pid == 0) {
            dup2(in_fd, 0);
            if (i < n-1) dup2(fd[1], 1);
            close(fd[0]);
            execlp("sh", "sh", "-c", commands[i], NULL);
            perror("exec");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
            close(fd[1]);
            in_fd = fd[0];
        }
    }
    return 1;
}
