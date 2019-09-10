/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:50:09 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/10 18:50:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *command_search_bins(char *cmd)
{
    int     i;
    char    **paths_bin;
    DIR     *bins; 
    struct dirent *dp;
    
    i = 0;
    if ((paths_bin = ft_strsplit_chr("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", ':')) == NULL)
        return (NULL);
    
    while (paths_bin[i])
    {
        if ((bins = opendir(paths_bin[i])) == NULL)
        {
            error(3, NULL, true);
            return (NULL);
        }
        while ((dp = readdir(bins)) != NULL)
        {
            if (ft_strcmp(cmd, dp->d_name) == 0)
                return (paths_bin[i]);
        }
        i++;
    }
    return (NULL);
}