/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:27:27 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/21 21:59:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	builtin_setenv_add(char **args)
{
	int	i;
	int	len;
	
	i = 0;
	if ((len = ft_strlen_chr(args[1], '=')) == -1)
		return ;
	len += 1; 														//'='
	while (g_shell.environ[i])
	{
		if (!(ft_strncmp(g_shell.environ[i], args[1], len)))  
        {
			//free(g_shell.environ[i]);
			g_shell.environ[i] = ft_strdup(args[i]);
			return ;
		}
        i++;
	}
	g_shell.environ[g_shell.environ_elements] = args[1];
	g_shell.environ_elements++;
}

int			builtin_setenv(char **args)
{
	if (!args || !args[0])
		return (error(0, "[builtin setenv]", EXIT_FAILURE));
	if (!args[1])
		return (env_print());
	if (ENV_EMPTY_SLOTS < 1)
		env_remalloc(g_shell.environ_size + ENV_EXTENTION);
	else if ((int)ENV_EMPTY_SLOTS > (int)(ENV_EXTENTION * 2))
		env_remalloc(g_shell.environ_size - ENV_EXTENTION);
	builtin_setenv_add(args);
	return (EXIT_SUCCESS);
}