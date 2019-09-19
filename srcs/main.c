/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:18:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/19 22:27:38 by psprawka         ###   ########.fr       */
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
            if (handle_command(cmd) == EXIT_FAILURE)
                return (EXIT_FAILURE);
            free(cmd);
        }
        display_prompt();
        ft_2Darr_free(cmds);
    }
    return (EXIT_SUCCESS);
}


int     main(int ac, char **av, char **envp)
{
    if (ac != 1)
        return (error(3, NULL, EXIT_SUCCESS));
    if (shell_setup(envp) == EXIT_FAILURE ||
        env_setup(envp) == EXIT_FAILURE ||
        minishell_loop() == EXIT_FAILURE)
        return (EXIT_FAILURE);
    shell_free();
    return (EXIT_SUCCESS);
}



