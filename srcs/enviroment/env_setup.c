/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:32 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/11 17:10:12 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

int		env_setup(char **environ)
{
	int		i;
	int		len;
	
	i = 0;
	while (i < g_shell.environ_size)
	{
		len = ft_strlen(environ[i]);
		if (!(g_shell.environ[i] = ft_strncpy(environ[i], len)))
		{
			//free array
			return (EXIT_FAILURE);
		}
		printf("g_shell.environ[i]: \"%s\"\n", g_shell.environ[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}