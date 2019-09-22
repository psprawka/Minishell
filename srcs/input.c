/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:16:02 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 19:15:06 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **parse_input(char *input)
{
    char    **cmds;
    
    if (!input)
        return (NULL);
    cmds = ft_strsplit_chr(input, ';');
    return (cmds);    
}

int     get_input(char **input)
{
    ft_get_next_line(STDIN_FILENO, input);
    return (EXIT_SUCCESS);
}
