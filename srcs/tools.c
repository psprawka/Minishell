/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:55 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 08:59:58 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			error(int errnb, char *msg, bool if_failure)
{
	if (errnb == 1)
		printf("%sError: %s%s\n", RED, msg, NORMAL);
    if (errnb == 2)
        printf("%sError: %s: command not found%s\n", RED, msg, NORMAL);
    if (errnb == 3)
        printf("%sError: %s: failed opendir%s\n", RED, msg, NORMAL);
    if (errnb == 4)
        printf("%sError: %s: caassaas%s\n", RED, msg, NORMAL);
	else
		printf("%s%s: %s%s\n", RED, msg, strerror(errnb), NORMAL);
        
	return (if_failure == true ? EXIT_FAILURE : EXIT_SUCCESS);
}

int     display_prompt(void)
{
    ft_putstr_fd("$> ", 1);
    return (EXIT_SUCCESS);
}

