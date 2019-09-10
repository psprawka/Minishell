/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:02:06 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 21:32:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

int     shell_setup(char **envp)
{
    int     size;
    
    size = 0;
    while (envp[size])
        size++;
    if (!(g_shell.environ = (char **)malloc(sizeof(char *) * size)))
        return (EXIT_FAILURE);
    g_shell.environ_size = size;
    return (EXIT_SUCCESS);
}