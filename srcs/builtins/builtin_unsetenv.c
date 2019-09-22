/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:48:37 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 20:41:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_unsetenv(char **args)
{
	int i;
	int len;
	
	i = 0;	
	len = ft_strlen(args[1]);
	while (g_shell.environ[i])
	{
		if (!(ft_strncmp(g_shell.environ[i], args[1], len)))  
        {
			free(g_shell.environ[i]);
			g_shell.environ_elements--;
			g_shell.environ[i] = g_shell.environ[g_shell.environ_elements];
			g_shell.environ[g_shell.environ_elements] = NULL;
			return (EXIT_SUCCESS);
		}
        i++;
	}
	return (EXIT_FAILURE);
}