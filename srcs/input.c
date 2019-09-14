/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:16:02 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 12:52:17 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **parse_input(char *input)
{
    char    **cmds;
    
    if (!input)
        return (NULL);//(error(66, "meh", true));
    cmds = ft_strsplit_chr(input, ';');
    return (cmds);    
}

int     get_input(char **input)
{
    gnl(0, input);
    return (EXIT_SUCCESS);
}
