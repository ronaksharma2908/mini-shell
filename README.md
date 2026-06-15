# 🌟 Mini Shell (C Language)

![C](https://img.shields.io/badge/language-C-blue.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-yellow.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows-lightgrey.svg)

A fully‑featured **Unix‑like shell** written in **C**, designed as an advanced systems programming project.  
It replicates core Bash functionality including **pipes, redirection, background jobs, job control, tab completion, and signal handling** — all built from scratch.

---

## ✨ Features
- ⚡ **Command Execution**: Run external programs (`ls`, `gcc`, etc.)
- 📂 **Built‑in Commands**: `cd`, `exit`, `help`, `history`, `jobs`, `fg`, `bg`
- 📝 **Persistent History**: Commands saved across sessions (`~/.mini-shell-history`)
- 🔑 **Tab Completion**: Integrated with GNU Readline
- 🔗 **Pipes**: Multi‑pipe chaining (`ls | grep .c | sort`)
- 📥 **I/O Redirection**: Input `<`, output `>`, combined redirection
- 🚀 **Background Jobs**: Run commands with `&`
- 🎛️ **Job Control**: Manage jobs with `jobs`, bring to foreground with `fg`, resume with `bg`
- 🛡️ **Signal Handling**: Ctrl+C (SIGINT), Ctrl+Z (SIGTSTP), SIGCONT for resuming processes
- 🎨 **Colourful Prompt**: Enhanced UI with ANSI colours

---

## 📂 Project Structure
