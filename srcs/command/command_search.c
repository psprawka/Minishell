/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:50:09 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/14 12:50:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *command_search_bins(char *cmd)
{
    int             i;
    DIR             *bins; 
    struct dirent   *dp;
    
    i = 0;
    while (g_shell.env_path[i])
    {
        if ((bins = opendir(g_shell.env_path[i])) == NULL)
        {
            error(3, "[command_search_bins]", EXIT_FAILURE);
            return (NULL);
        }
        while ((dp = readdir(bins)) != NULL)
        {
            if (ft_strcmp(cmd, dp->d_name) == 0)
                return (g_shell.env_path[i]);
        }
        i++;
    }
    return (NULL);
}