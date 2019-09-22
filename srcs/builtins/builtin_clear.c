/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:56:17 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 18:25:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_clear(char **args)
{
	(void)args;
	printf("\033[2J\n");
	ft_putstr("\033[1;1H");
	return (EXIT_SUCCESS);
}