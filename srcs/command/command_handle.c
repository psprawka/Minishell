/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:11 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/19 22:25:49 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     command_handle(char *cmd)
{
    char    **cmd_args;

    if (!(cmd_args = ft_strsplit_chr(cmd, ' ')))
        return (error(0, "[handle_command]", EXIT_FAILURE));
    if (command_execute_builtin(CMD_NAME, cmd_args) == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    if (command_execute_bin(CMD_NAME, cmd_args) == EXIT_FAILURE)   
        return (error(2, CMD_NAME, true));
    return (EXIT_SUCCESS);
}