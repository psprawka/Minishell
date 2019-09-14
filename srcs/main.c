/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:18:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 12:52:11 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int     minishell_loop(void)
{
    char    *input;
    char    **cmds;
    char    *cmd;
    int     i;
    
    display_prompt();
    while (get_input(&input) != EXIT_FAILURE)
    {
        i = 0;
        cmds = parse_input(input);
        while (cmds[i])
        {
            cmd = ft_strtrim(cmds[i++]);
            handle_command(cmd);
            free(cmd);
        }
        display_prompt();
    }
    return (EXIT_SUCCESS);
}


int     main(int ac, char **av, char **envp)
{
    if (shell_setup(envp) == EXIT_FAILURE ||
        env_setup(envp) == EXIT_FAILURE ||
        minishell_loop() == EXIT_FAILURE)
        return (EXIT_FAILURE);
        
    return (EXIT_SUCCESS);
}



