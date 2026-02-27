## 🗒 But du projet
Recoder de A à Z notre propre shell en C en prenant pour référence le TCSH

## 🧾 Ce qu'il faut gérer

├── commandes systèmes (`ls`, `grep`, `find`)
├── builtins
│  ├── cd
│  ├── env
│  ├── setenv
│  ├── unsetenv

🥱 _On n'est pas tenu de gérer `unsetenv *` `pipe `|` et les redirections_

## 📦 Structure générale du projet

├── include
│   └── my.h
├── library.zip
├── Makefile
├── mysh
├── README.md
├── src
│   ├── builtins.c
   ├── clean_str.c
│   ├── execute.c
│   ├── linked_list.c
│   ├── main.c
│   ├── my_getnbr.c
│   ├── my_strcat.c
│   ├── my_strcmp.c
│   ├── my_strcpy.c
│   ├── my_strdup.c
│   ├── my_strlen.c
│   ├── my_strncmp.c
│   ├── print_exit.c
│   ├── the_shell_loop.c
│   └── utils.c

## 🛠️ Compilation et exécution
```sh
make re
./mysh
```
## 🤝 Soutenir le projet
   Si tu apprécies ce projet et veux soutenir mon travail, tu peux m’offrir un café ☕😄

📱 Mobile money : +229 0190346201

🏦 Virement bancaire : disponible sur demande

Merci beaucoup 🙏
