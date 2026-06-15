#ifndef JOBS_H
#define JOBS_H

#include <sys/types.h>   // for pid_t

typedef struct {
    pid_t pid;
    char command[1024];
    int running;
} Job;

void add_job(pid_t pid, const char *cmd);
void list_jobs(void);
void bring_foreground(int jobid);
void resume_background(int jobid);

#endif
