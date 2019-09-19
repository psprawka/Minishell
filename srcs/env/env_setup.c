/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:32 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/19 22:00:45 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_setup(char **envp)
{
	int		i;
	int		len;
	
	i = 0;
	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (!(g_shell.environ[i] = ft_strncpy(envp[i], len)))
		{
			g_shell.environ[i] = NULL;
			ft_2Darr_free(g_shell.environ);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}