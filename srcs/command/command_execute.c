/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:38:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 21:34:23 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

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
        //if ((path = search_builtins(args[0]) || search_bins(args[0])) == NULL)
        if ((path = command_search_bins(cmd)) == NULL)
            return (error(2, cmd, true));
        printf("PATH: %s | cmd_args[0]: %s\n", path, cmd_args[0]);
        execve(path, cmd_args, g_shell.environ);
        free(path);
    }
    else
        waitpid(pid, 0, 0);
    return (EXIT_SUCCESS);
}
