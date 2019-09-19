/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builin_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:27:27 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/19 22:15:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	builtin_setenv_add(char **args)
{
	g_shell.environ[g_shell.environ_elements] = args[1];
	g_shell.environ_elements++;
}

int			builtin_setenv(char **args)
{
	if (!args || !args[1])
		return (error(33, "builtin setenv", EXIT_FAILURE));
	if (ENV_EMPTY_SLOTS < 1)
		env_remalloc(g_shell.environ_size + ENV_EXTENTION);
	else if (ENV_EMPTY_SLOTS > ENV_EXTENTION * 2)
		env_remalloc(g_shell.environ_size - ENV_EXTENTION);
	builtin_setenv_add(args);
	return (EXIT_SUCCESS);
}