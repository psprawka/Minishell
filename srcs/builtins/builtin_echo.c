/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:16:03 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/21 16:49:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*builtin_echo_env(char *arg)
{
	int		i;
	int		len;
	
	i = 0;
	while (g_shell.env_path[i])
	{
		len = ft_strlen(&(arg[1]));
		if (ft_strncmp(&(arg[1]), g_shell.env_path[i], len))
			return (&(g_shell.env_path[i][len]));
		i++;
	}
	return ("");
}

int			builtin_echo(char **args)
{
	int		i;
	bool	is_newline; 
	
	if (!args)
		return (EXIT_FAILURE);
	is_newline = (args[1] && !ft_strcmp(args[1], "-n"));
	i = 1 + is_newline;
	while (args[i])
	{
		printf("%s", args[i][0] == '$' ? builtin_echo_env(args[i]) : args[i]);
		if (args[++i])
			printf(" ");
	}
	if (is_newline)
		printf("\n");
	return (EXIT_SUCCESS);
}