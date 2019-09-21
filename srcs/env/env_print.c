/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:24:17 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/20 11:42:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_print(void)
{
	int i;
	
	if (!g_shell.environ) //is it even necessary?
		return (EXIT_FAILURE);
	i = 0;
	while (g_shell.environ[i])
		printf("%s\n", g_shell.environ[i++]);
	return (EXIT_SUCCESS);
}