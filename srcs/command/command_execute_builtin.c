/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute_builtin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:06:53 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/18 16:26:28 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct	s_builtins
{
	char	*builtin_name;
	int		(*fct)(char **args);
}				t_builtins;

t_builtins	g_builtins[] =
{
	{"cd", builtin_cd}
	{"clear", builtin_clear}
	{"echo", builtin_echo},
	{"exit", builtin_exit},
	{"env", builtin_env},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{NULL, NULL}
};

int		command_execute_builtin(char *cmd, char **cmd_args)
{
	int i;
	
	i = 0;
	while (g_builtins[i].builtin_name)
	{
		if (!ft_strcmp(cmd, g_builtins[i].builtin_name))
		{
			return ();
		}
		i++;
	}
	return (EXIT_FAILURE);
}