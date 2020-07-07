/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:17:50 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/07 17:18:10 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_sortmas(int **mas, int i)
{
    int j;
    int k;
    int cp;

    j = 0;
    while (j - 1 < i)
    {
        k = 0;
        while (k + 1 < i)
        {
           if ((*mas)[k] > (*mas)[k + 1])
           {
               cp = (*mas)[k];
               (*mas)[k] = (*mas)[k + 1];
               (*mas)[k + 1] = cp;
           }
           k++;
        }
        j++;
    }
}

int ft_massearch(int c, int nach, int con, int *mas)
{
    while (nach < con)
    {
        if (mas[nach] == c)
            return (1);
        nach++;
    }
    return (0);
}

void check_stc(t_list **lst)
{
    if (lst && *lst && (*lst)->next)
    {
        if ((*lst)->content < (((*lst)->next)->content))
            ft_swap(lst, NULL, "sb");
    }
}

int ft_num_of_action(t_list **s_a, t_list **s_b, int i, int j)
{
    int k;

    k = ft_lstnum(s_a) + 1;
    if ((i - 1) < (k - j))
    {
        while (i > 0)
        {
            ft_rotate(s_a, NULL, 1, "ra");
            i--;
        }
    }
    else
    {
        while (j < k)
        {
            ft_rotate(s_a, NULL, 2, "rra");
            j++;
        }
    }
    ft_push(s_b, s_a, "pb");
    check_stc(s_b);
    return (1);
}

int ft_first_second(int *mas, int *arr, t_list **s_a, t_list **s_b)
{
    int j;
    int k;
    int c;
    int r;
    t_list *cp1;

    j = 0;
    c = 0;
    r = 0;
    cp1 = *s_a;
    while (j < (ft_lstnum(s_a) / 2) && c == 0)
    {
        ft_massearch(cp1->content, arr[0], arr[1], mas) ? c++ : j++;
        cp1 = cp1->next;
    }
    k = j + 1;
    while (cp1)
    {
        ft_massearch(cp1->content, arr[0], arr[1], mas) ? r = k && k++ : k++;
        cp1 = cp1->next;
    }
    if (c == 0 && r == 0)
        return (0);
    return (ft_num_of_action(s_a, s_b, j, r + 1));
}
