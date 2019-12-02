# minishell
my first minishell

# 42.Minishell

# Instructions
You must program a mini UNIX command interpreter.
This interpreter must display a prompt (a simple $> for example) and wait till you type a command line, validated by pressing enter.
The prompt is shown again only once the command has been completely executed.
The command lines are simple, no pipes, no redirections or any other advanced functions.
The executable are those you can find in the paths indicated in the PATH variable.
In cases where the executable cannot be found, it has to show an error message and display the prompt again.
You must manage the errors without using errno, by displaying a message adapted to the error output.
You must deal correctly with the PATH and the environment (copy of system char **environ).

# You must implement a series of builtins:
1. exit
2. echo
3. cd
4. env
5. setenv
6. unsetenv

You can choose as a reference whatever shell you prefer.
You must manage expansions $ and ~

# Allowed Functions
1. malloc, free
2. access
3. open, close, read, write
4. opendir, readdir, closedir
5. getcwd, chdir
6. stat, lstat, fstat
7. fork, execve
8. wait, waitpid, wait3, wait4
9. signal, kill
10. exi
