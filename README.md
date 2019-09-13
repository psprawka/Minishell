
# Minishell 🖥️

Minishell is a second project system (UNIX) branch at 42. The purpose of this project is to learn and have a good understanding of process creation and synchronisation in C. Executing a command inside a shell implies creating a new process, which execution and final state will be monitored by its parent’s process. 

This project is an introdution to a project called 42sh - a fully functional and efficient shell (Minishell -> 21sh -> 42sh). 
</br>

# Minishell - what does it contain?
Minishell is very simple and does not have to contain complex features like key-bindings or piping. For this project, I implemented: `cd`, `setenv`, `usetenv`, `env`, `echo`, `exit`, as well as `auto completion`, `history` and `multiple commands management`.


# How to run Minishell?
```
git clone hhttps://github.com/psprawka/Minishell.git 42SV_Minishell
cd 42SV_Minishell
make
./minishell
```
</br>
Once in the shell, you can execute the builtins or any other simple command line that works on any other shell. Have fun with my minishell! 
