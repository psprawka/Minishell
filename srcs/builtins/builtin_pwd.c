/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:22:26 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/21 16:05:19 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_pwd(char **args)
{
	char	buf[MAX_PATH_LEN];

	printf("%s\n", getcwd(buf, MAX_PATH_LEN));
	return (EXIT_SUCCESS);
}