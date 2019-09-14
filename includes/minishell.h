/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:23:31 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 12:51:31 by psprawka         ###   ########.fr       */
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

#define CMD_NAME    cmd_args[0]
#define PATHS		g_shell.path;

typedef struct	s_shell
{
	char    **environ;
	int		environ_size;
	char	**env_path;
}				t_shell;

extern t_shell	g_shell;

int     display_prompt(void);
int     get_input(char **input);
int		error(int errnb, char *msg, bool if_failure);

/*
** command/
*/
int     command_execute(char *cmd, char **cmd_args);
char    *command_search_bins(char *cmd);
int     handle_command(char *cmds);

/*
** enviroment/
*/
int		env_setup(char **environ);

/*
** shell/
*/
int     shell_setup(char **envp);

#endif