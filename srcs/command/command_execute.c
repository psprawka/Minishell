/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:38:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/11 22:15:41 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;


static int find_path_execute(char **path, char *cmd)
{
    char    *path_bin;
    //if ((path = search_builtins(args[0]) || search_bins(args[0])) == NULL)
    
    if ((path_bin = command_search_bins(cmd)) == NULL ||
        !(*path) = (char *)malloc(ft_)
        return (error(2, cmd, EXIT_FAILURE));
    
}

int     command_execute(char *cmd, char **cmd_args)
{
    pid_t   pid;
    char    *path;
    int     i;
    
    i = 0;
    pid = fork();
    if (pid == -1)
        return (EXIT_FAILURE);
    if (pid == 0)
    {
        if (find_path_execute(&path, cmd) == EXIT_FAILURE ||
            execve(path, cmd_args, g_shell.environ) == -1)
            return (EXIT_FAILURE);
        free(path);
    }
    else
        waitpid(pid, 0, 0);
    return (EXIT_SUCCESS);
}
