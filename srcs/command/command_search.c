/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:50:09 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/11 18:16:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



char    *command_search_bins(char *cmd)
{
    int     i;
    DIR     *bins; 
    struct dirent *dp;
    
    i = 0;
    
    while (PATHS[i])
    {
        if ((bins = opendir(PATHS[i])) == NULL)
        {
            error(3, NULL, true);
            return (NULL);
        }
        while ((dp = readdir(bins)) != NULL)
        {
            if (ft_strcmp(cmd, dp->d_name) == 0)
                return (PATHS[i]);
        }
        i++;
    }
    return (NULL);
}