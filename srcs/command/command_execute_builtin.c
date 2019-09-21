/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execute_builtin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:06:53 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/21 21:59:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtins	g_builtins[] =
{
	{"cd", builtin_cd},
	{"clear", builtin_clear},
	{"echo", builtin_echo},
	{"env", builtin_env},
	{"exit", builtin_exit},
	{"pwd", builtin_pwd},
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
			g_builtins[i].fct(cmd_args);
			//ft_2Darr_free(cmd_args);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	//ft_2Darr_free(cmd_args);
	return (EXIT_FAILURE);
}