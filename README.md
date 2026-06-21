# 🌟 Mini Shell (C Language)

![C](https://img.shields.io/badge/language-C-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-yellow.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows-lightgrey.svg)

A fully‑featured **Unix‑like shell** written in **C**, designed as an advanced systems programming project.  
It replicates core Bash functionality including **pipes, redirection, background jobs, job control. The **Mini Shell Project** is a lightweight implementation of a Unix-like shell written in **C language**.  
It provides basic command execution, input/output redirection, and process handling — designed to help understand how shells work internally.


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


---

📖 Learning Outcomes


🔧 Process creation (fork, exec, waitpid)
🛡️ Signal handling (SIGINT, SIGTSTP, SIGCONT)
📑 File descriptors & redirection (dup2)
🔗 Pipes & inter‑process communication
🎛️ Job control & background process management
⌨️ Readline library integration for UX
🗂️ Modular project structure with headers and source files



👨‍💻 Author

Ronak  
Built as an advanced systems programming project to explore OS internals and shell design.



📜 License

This project is licensed under the MIT License.
