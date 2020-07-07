/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:18:37 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/07 17:18:55 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_lstnum(t_list **lst)
{
    int i;
    t_list *cp;

    i = 0;
    if (lst && *lst)
    {
        i++;
        cp = *lst;
        while (cp->next)
        {
            cp = cp->next;
            i++;
        }
    }
    return (i);
}

int ft_mas(int **mas, t_list *lst)
{
    int i;
    int j;

    j = 0;
    i = ft_lstnum(&lst);
    *mas = (int *)malloc(sizeof(int) * i);
    while (j < i)
    {
        (*mas)[j] = lst->content;
        lst = lst->next;
        j++;
    }
    return (i);
}
