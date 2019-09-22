/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_remalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:16:36 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 20:42:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_remalloc(int new_size)
{
	int i;
	char **new_environ;

	if (!(new_environ = (char **)malloc(sizeof(char *) * new_size)))
		return (EXIT_FAILURE);
		i = 0;
	while (g_shell.environ[i])
	{
		new_environ[i] = g_shell.environ[i];
		free(g_shell.environ[i]);
		i++;
	}
	new_environ[i] = NULL;
	free(g_shell.environ);
	g_shell.environ_size = new_size;
	return (EXIT_SUCCESS);
}