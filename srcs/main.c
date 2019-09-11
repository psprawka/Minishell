/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:18:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/11 18:09:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// char    **parse_input(char *input)
// {
//     char    **cmds;
    
//     if (!input)
//         return NULL;//(error(66, "meh", true));
//     cmds = ft_strsplit_chr(input, ';');
//     return (cmds);    
// }

// int     main_shell_loop(void)
// {
//     char    *input;
//     char    **cmds;

//     display_prompt();
//     while (get_input(&input) != EXIT_FAILURE)
//     {
//         cmds = parse_input(input);
//         //printf("HEREEEE IT WORKS1\n");
//         handle_commands(cmds);
//         //printf("HEREEEE IT WORKS2\n");
//         display_prompt();
//         //printf("HEREEEE IT WORKS3\n");
//     }
//     //printf("outside loop\n");
//     return (EXIT_SUCCESS);
// }


// int     main(int ac, char **av, char **envp)
// {
//     if (shell_setup(envp) == EXIT_FAILURE ||
//         env_setup(envp) == EXIT_FAILURE ||
//         main_shell_loop() == EXIT_FAILURE)
//         return (EXIT_FAILURE);
        
//     return (EXIT_SUCCESS);
// }


#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int ac, char **av, char **envp)
{
    pid_t   pid;
    char    *path;
    int     i;
    
    i = 0;
    pid = fork();
    
    if (pid == 0)
    {
        char **args = (char **)malloc(sizeof(char *) * 2);
        args[0] = (char *)malloc(3);
        args[1] =(char *)malloc(4);
        args[0] = "ls";
        args[1] = "-la";
        execve("/bin/ls", args, envp);
        printf("error\n");
    }
    else
        waitpid(pid, 0, 0);
    return (0);
}
