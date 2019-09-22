/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:55 by psprawka          #+#    #+#             */
/*   Updated: 2019/09/22 09:47:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			error(int errnb, char *msg, int ret)
{
	if (errnb == 1)
		printf("%sError: %s%s\n", RED, msg, NORMAL);
    else if (errnb == 2)
        printf("%sminishell: %s: command not found%s\n", RED, msg, NORMAL);
    else if (errnb == 3)
        printf("Usage: ./42sh\n");
	//else if (error == 4)
    //   printf("%sError: %s: wrong number of arguments\n");
    else
		printf("%s%s: %s%s\n", RED, msg, strerror(errnb), NORMAL);
        
	return (ret);
}

int     display_prompt(void)
{
    char	pwd[MAX_PATH_LEN];
    char    *prompt;
    int     prompt_len;
    
    getcwd(pwd, MAX_PATH_LEN);
    prompt_len = ft_strlen(GREEN) + ft_strlen(pwd) + ft_strlen("$>  ") + ft_strlen(NORMAL);
    
    if (!(prompt = (char *)malloc(prompt_len)))
        return (EXIT_FAILURE);
    
    ft_strcpy(prompt, YELLOW);
    ft_strcat(prompt, pwd);
    ft_strcat(prompt, "$> ");
    ft_strcat(prompt, NORMAL);
    ft_putstr(prompt);
    return (EXIT_SUCCESS);
}

