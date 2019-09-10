/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:11 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 21:13:25 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     handle_commands(char *cmds, int n_cmds)
{
    char    *path;
    char    **cmd_args;
    int     i;
    
    i = 0;
    while (i < n_cmds)
    {
        if (!(cmd_args = ft_strsplit_chr(cmds, ';')) ||
            command_execute(cmd_args[0], cmd_args) == -1)
        {
            //ft_strarr_free(cmd_args);
            return (error(2, cmds, true));
        }
         //ft_strarr_free(cmd_args);
        i++;
    }
    return (EXIT_SUCCESS);
}