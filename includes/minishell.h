/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:23:31 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 21:28:05 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include <sys/select.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "libft/libft.h"

/*
**  -> ENV_EXTENTION - defines how bigger than size g_shell.environ array is;
**     this is done in order to avoid remalloc each time new variable is added.
**     Let's say the size of the environ array equals 27 - an array will have
**     27 + ENV_EXTENTION slots in array. When there are twice less variables as
**     ENV_EXTENTION in g_shell.environ, array is remalloced to a smaller size.
*/
#define CMD_NAME    cmd_args[0]
#define ENV_PATH	g_shell.path;
#define	ENV_EXTENTION	10 
#define	ENV_EMPTY_SLOTS	(g_shell.environ_elements < g_shell.environ_size - 1)
#define MAX_PATH_LEN 4096


typedef struct	s_builtins
{
	char	*builtin_name;
	int		(*fct)(char **args);
}				t_builtins;

typedef struct	s_shell
{
	char    **environ;
	int		environ_size;
	int		environ_elements;
	char	**env_path;
	bool	exit;
}				t_shell;

extern t_shell	g_shell;


int     display_prompt(void);
int     get_input(char **input);
char    **parse_input(char *input);
int		error(int errnb, char *msg, int ret);

/*
** builtins/
*/
int		builtin_cd(char **args);
int		builtin_clear(char **args);
int		builtin_echo(char **args);
int		builtin_env(char **args);
int		builtin_exit(char **args);
int		builtin_pwd(char **args);
int		builtin_setenv(char **args);
int		builtin_unsetenv(char **args);

/*
** command/
*/
int     command_execute_bin(char *cmd, char **cmd_args);
int		command_execute_builtin(char *cmd, char **cmd_args);
int     command_handle(char *cmds);

/*
** enviroment/
*/
int		env_print(void);
int		env_remalloc(int new_size);
int		env_setup(char **envp);

/*
** shell/
*/
void	shell_free(void);
int     shell_setup(char **envp);

#endif