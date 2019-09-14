/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:11 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 12:52:04 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     handle_command(char *cmd)
{
    char    *path;
    char    **cmd_args;

    if (!(cmd_args = ft_strsplit_chr(cmd, ' ')))
        return (error(0, "[handle_commands]", EXIT_FAILURE));
    if (command_execute(CMD_NAME, cmd_args) == EXIT_FAILURE)
    {
        //ft_strarr_free(cmd_args);
        return (error(2, CMD_NAME, true));
    }
    //ft_strarr_free(cmd_args);
    return (EXIT_SUCCESS);
}