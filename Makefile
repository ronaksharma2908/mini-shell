CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude   # add include path here
LIBS = -lreadline

SRC = src/main.c src/shell.c src/commands.c src/utils.c src/history.c src/piping.c src/input.c src/jobs.c
OBJ = $(SRC:.c=.o)

mini-shell: $(OBJ)
    $(CC) $(CFLAGS) -o mini-shell $(OBJ) $(LIBS)

clean:
    rm -f $(OBJ) mini-shell
