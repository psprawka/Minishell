/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:02:06 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/15 23:04:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  v_environ_setup(char **envp)
{
    int     i;
    int     size;
    
    if ((size = ft_2Darr_size(envp)) == -1 ||
        !(g_shell.environ = (char **)malloc(sizeof(char *) * size + 1)))
        return (EXIT_FAILURE);
    i = 0;
    while (i < size)
    {
        if (!(g_shell.environ[i] = ft_strncpy(envp[i], ft_strlen(envp[i]))))
        {
            //free arr
            return (EXIT_FAILURE);
        }
        i++;
    }
    g_shell.environ[i] = NULL;
    g_shell.environ_size = size;
    return (EXIT_SUCCESS);
}

static int  v_path_setup(void)
{
    char    **paths;
    int     index_path;
    
    index_path = 0;
    while (g_shell.environ[index_path])
    {
        if (!(ft_strncmp(g_shell.environ[index_path], "PATH", 4)))  
            break;
        index_path++;
    }
    if (!g_shell.environ[index_path] ||
        !(paths = ft_strsplit_chr(&g_shell.environ[index_path][5], ':')))
        return (error(0, "[v_path_setup]: failed to exctract path_env", EXIT_FAILURE));
    
    g_shell.env_path = paths;
    return (EXIT_SUCCESS);    
}

int     shell_setup(char **envp)
{
    if (v_environ_setup(envp) == EXIT_FAILURE ||
        v_path_setup() == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}