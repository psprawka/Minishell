/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:11 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/11 18:14:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CMD_NAME    cmd_args[0]

int     handle_commands(char **cmds)
{
    char    *path;
    char    **cmd_args;
    int     i;
    
    i = 0;
    while (cmds[i])
    {
        if (!(cmd_args = ft_strsplit_chr(cmds[i], ' ')) ||
            command_execute(CMD_NAME, cmd_args) == -1)
        {
            //ft_strarr_free(cmd_args);
            return (error(2, "meeeeeh", true));
        }
         //ft_strarr_free(cmd_args);
        i++;
    }
    return (EXIT_SUCCESS);
}