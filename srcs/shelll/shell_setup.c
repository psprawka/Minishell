/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:02:06 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/11 22:06:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

static int  v_environ_setup(char **envp)
{
    int     i;
    int     size;
    
    if ((size = ft_2Darr_size()) == -1 ||
        !(g_shell.environ = (char **)malloc(sizeof(char *) * size + 1)))
        return (EXIT_FAILURE);
    
    i = 0;
    while (i < size)
    {
        if (!(g_shell.environ[i] = ft_strcpy(g_shell.environ[i], envp[i])))
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
    
    while (g_shell.environ[index_path])
    {
        if (!(ft_strncmp(g_shell.environ[index_path], "PATH", 4)))  
            break;
        index_path++;
    }
    if (!g_shell.environ[index_path] ||
        !(paths = ft_strsplit_chr(g_shell.environ[index_path], ':')))
        return (error(324, "wtf", EXIT_FAILURE));
    
    g_shell.path = paths;
    return (EXIT_SUCCESS);    
}

int     shell_setup(char **envp)
{
    if (v_environ_setup(envp) == EXIT_FAILURE ||
        v_path_setup() == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}