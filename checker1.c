/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:33:59 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/04 14:34:02 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    if (!str1[i] && !str2[i])
        return (1);
    return (0);
}

int ft_swap(t_list **lst1, t_list **lst2)
{
    int i;
    int j;
    t_list **lst;

    lst = lst1;
    while (lst)
    {
        if (*lst && (*lst)->next)
        {
            i = (*lst)->content;
            j = ((*lst)->next)->content;
            (*lst)->content = j;
            ((*lst)->next)->content = i;
        }
        if (lst == lst2)
            return (1);
        lst = lst2;
    }
    return (1);
}

int ft_push(t_list **lst1, t_list **lst2)
{
    t_list *cp;

    if (lst2 && *lst2)
    {
        cp = *lst2;
        *lst2 = (*lst2)->next;
        cp->next = *lst1;
        *lst1 = cp;
    }
    return (1);
}

int ft_rotate(t_list **lst1, t_list **lst2, int i)
{
    t_list *cp;

    cp = *lst1;
    if (lst1 && *lst1 && (*lst1)->next && i == 1)
    {
        while (cp->next)
            cp = cp->next;
        cp->next = *lst1;
        *lst1 = (*lst1)->next;
        cp = cp->next;
        cp->next = NULL;
    }
    if (lst1 && *lst1 && (*lst1)->next && i == 2)
    {
        while ((*lst1)->next)
            *lst1 = (*lst1)->next;
        (*lst1)->next = cp;
        while (cp->next != *lst1)
            cp = cp->next;
        cp->next = NULL;
    }
    if (lst2)
        return (ft_rotate(lst2, NULL, i));
    return (1);
}

int check_instruction(t_list **st_a, t_list **st_b, char *inst)
{
    if (ft_strcmp(inst, "sa"))
        return (ft_swap(st_a, NULL));
    if (ft_strcmp(inst, "sb"))
        return (ft_swap(st_b, NULL));
    if (ft_strcmp(inst, "ss"))
        return (ft_swap(st_a, st_b));
    if (ft_strcmp(inst, "pa"))
        return (ft_push(st_a, st_b));
    if (ft_strcmp(inst, "pb"))
        return (ft_push(st_b, st_a));
    if (ft_strcmp(inst, "ra"))
        return (ft_rotate(st_a, NULL, 1));
    if (ft_strcmp(inst, "rb"))
        return (ft_rotate(st_b, NULL, 1));
    if (ft_strcmp(inst, "rr"))
        return (ft_rotate(st_a, st_b, 1));
    if (ft_strcmp(inst, "rra"))
        return (ft_rotate(st_a, NULL, 2));
    if (ft_strcmp(inst, "rrb"))
        return (ft_rotate(st_b, NULL, 2));
    if (ft_strcmp(inst, "rrr"))
        return (ft_rotate(st_a, st_b, 2));
    return (0);
}

