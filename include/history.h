#ifndef HISTORY_H
#define HISTORY_H

void add_history_entry(const char *cmd);
void show_history(void);
void load_history(void);
void save_history(void);

#endif
