/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:55 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/18 15:54:56 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			error(int errnb, char *msg, int ret)
{
	if (errnb == 1)
		printf("%sError: %s%s\n", RED, msg, NORMAL);
    if (errnb == 2)
        printf("%sError: %s: command not found%s\n", RED, msg, NORMAL);
    if (errnb == 3)
        printf("%sError: %s: failed opendir%s\n", RED, msg, NORMAL);
    if (errnb == 4)
        printf("Usage: ./42sh, \n");
	else
		printf("%s%s: %s%s\n", RED, msg, strerror(errnb), NORMAL);
        
	return (ret);
}

int     display_prompt(void)
{
    ft_putstr_fd("$> ", 1);
    return (EXIT_SUCCESS);
}

