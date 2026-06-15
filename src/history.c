#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "history.h"

#define MAX_HISTORY 100
static char history[MAX_HISTORY][1024];
static int count = 0;
static const char *HISTORY_FILE = ".mini-shell-history";

void add_history_entry(const char *cmd) {
    if (count < MAX_HISTORY) {
        strncpy(history[count], cmd, 1023);
        history[count][1023] = '\0';
        count++;
    }
}

void show_history(void) {
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i+1, history[i]);
    }
}

void load_history(void) {
    FILE *f = fopen(HISTORY_FILE, "r");
    if (!f) return;
    char line[1024];
    while (fgets(line, sizeof(line), f) && count < MAX_HISTORY) {
        line[strcspn(line, "\n")] = 0;
        strncpy(history[count], line, 1023);
        count++;
    }
    fclose(f);
}

void save_history(void) {
    FILE *f = fopen(HISTORY_FILE, "w");
    if (!f) return;
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s\n", history[i]);
    }
    fclose(f);
}
