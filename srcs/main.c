/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:18:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 21:50:09 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main_shell_loop(void)
{
    char *input;

    while (read(STDIN_FILENO, input, 1) > 0)
    {
        get_input
    handle_commands(input, 1);
}


int main(int ac, char **av, char **envp)
{
    if (shell_setup(envp) == EXIT_FAILURE ||
        env_setup(envp) == EXIT_FAILURE ||
        main_shell_loop() == EXIT_FAILURE)
        return (EXIT_FAILURE);
        
    return (EXIT_SUCCESS);
}

int 



