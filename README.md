# 🖥️ Mini Shell (C Language)

A fully‑featured **Unix‑like shell** written in **C**, designed as an advanced systems programming project.  
This shell replicates core Bash functionality including **pipes, redirection, background jobs, job control, tab completion, and signal handling** — all built from scratch.

---

## ✨ Features
- **Command Execution**: Run external programs (`ls`, `gcc`, etc.).
- **Built‑in Commands**: `cd`, `exit`, `help`, `history`, `jobs`, `fg`, `bg`.
- **Persistent History**: Commands saved across sessions (`~/.mini-shell-history`).
- **Tab Completion**: Integrated with GNU Readline for smooth UX.
- **Pipes**: Supports multi‑pipe chaining (`ls | grep .c | sort`).
- **I/O Redirection**: Input `<`, output `>`, combined redirection (`grep foo < in.txt > out.txt`).
- **Background Jobs**: Run commands with `&`.
- **Job Control**: Manage jobs with `jobs`, bring to foreground with `fg`, resume with `bg`.
- **Signal Handling**: Ctrl+C (SIGINT), Ctrl+Z (SIGTSTP), SIGCONT for resuming processes.
- **Colorful Prompt**: Enhanced UI with ANSI colors for better readability.

---

## 📂 Project Structure
mini-shell/
│── include/          # Header files
│   ├── shell.h
│   ├── commands.h
│   ├── utils.h
│   ├── history.h
│   ├── piping.h
│   ├── input.h
│   ├── jobs.h
│── src/              # Source files
│   ├── main.c
│   ├── shell.c
│   ├── commands.c
│   ├── utils.c
│   ├── history.c
│   ├── piping.c
│   ├── input.c
│   ├── jobs.c
│── Makefile
│── README.md

Code

---

## ⚙️ Installation & Build
### Prerequisites
- GCC compiler
- GNU Readline library (`sudo apt-get install libreadline-dev` on Linux)

### Build
```bash
make
Run
bash
./mini-shell
🛠️ Usage Examples
bash
mini-shell> ls -l
mini-shell> ls | grep .c | sort
mini-shell> cat < input.txt > output.txt
mini-shell> sleep 10 &
mini-shell> jobs
mini-shell> fg 1
mini-shell> bg 1
mini-shell> history
📖 Learning Outcomes
Process creation (fork, exec, waitpid)

Signal handling (SIGINT, SIGTSTP, SIGCONT)

File descriptors & redirection (dup2)

Pipes & inter‑process communication

Job control & background process management

Readline library integration for UX

Modular project structure with headers and source files

👨‍💻 Author
Ronak  
Built as an advanced systems programming project to explore OS internals and shell design.

📜 License
This project is licensed under the MIT License.

---


