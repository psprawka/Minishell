/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute_bin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:38:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/18 17:55:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

static char *command_search_bins(char *cmd)
{
    int             i;
    DIR             *bins; 
    struct dirent   *dp;
    
    i = 0;
    while (g_shell.env_path[i])
    {
        if ((bins = opendir(g_shell.env_path[i])) == NULL)
        {
            error(3, "[command_search_bins]", EXIT_FAILURE);
            return (NULL);
        }
        while ((dp = readdir(bins)) != NULL)
        {
            if (ft_strcmp(cmd, dp->d_name) == 0)
                return (g_shell.env_path[i]);
        }
        i++;
    }
    return (NULL);
}

static int  find_path_execute(char **path, char *cmd)
{
    char    *path_bin;
    int     path_bin_len;
    
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

int         command_execute_bin(char *cmd, char **cmd_args)
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
            return (error(0, "[command_execute_bin]", EXIT_FAILURE));
        free(path);
    }
    else
        waitpid(pid, 0, 0);
    ft_2Darr_free(cmd_args);
    return (EXIT_SUCCESS);
}
