/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:38:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 12:53:24 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;


static int find_path_execute(char **path, char *cmd)
{
    char    *path_bin;
    int     path_bin_len;
    
    //if ((path = search_builtins(args[0]) || search_bins(args[0])) == NULL)
    if ((path_bin = command_search_bins(cmd)) == NULL)
        return (error(2, cmd, EXIT_FAILURE));
    path_bin_len = ft_strlen(path_bin);
    if (!((*path) = (char *)malloc(path_bin_len + ft_strlen(cmd))))
        return (error(0, "[find_path_execute]", EXIT_FAILURE));
    ft_strcpy(*path, path_bin);
    ft_strcat(*path, "/");
    ft_strcat(*path, cmd);
    return (EXIT_SUCCESS);
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
            access(path, F_OK) == EXIT_FAILURE || 
            execve(path, cmd_args, g_shell.environ) == -1)
            return (error(0, "[command_execute]", EXIT_FAILURE));
        free(path);
    }
    else
        waitpid(pid, 0, 0);
    return (EXIT_SUCCESS);
}
