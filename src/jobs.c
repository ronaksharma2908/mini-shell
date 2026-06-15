#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "jobs.h"

#define MAX_JOBS 50
static Job jobs[MAX_JOBS];
static int job_count = 0;

void add_job(pid_t pid, const char *cmd) {
    if (job_count < MAX_JOBS) {
        jobs[job_count].pid = pid;
        strncpy(jobs[job_count].command, cmd, 1023);
        jobs[job_count].running = 1;
        job_count++;
    }
}

void list_jobs(void) {
    for (int i = 0; i < job_count; i++) {
        printf("[%d] %d %s %s\n", i+1, jobs[i].pid,
               jobs[i].running ? "Running" : "Stopped",
               jobs[i].command);
    }
}

void bring_foreground(int jobid) {
    if (jobid <= 0 || jobid > job_count) return;
    int idx = jobid - 1;
    int status;
    waitpid(jobs[idx].pid, &status, 0);
    jobs[idx].running = 0;
}

void resume_background(int jobid) {
    if (jobid <= 0 || jobid > job_count) return;
    int idx = jobid - 1;
    kill(jobs[idx].pid, SIGCONT);
    jobs[idx].running = 1;
}
