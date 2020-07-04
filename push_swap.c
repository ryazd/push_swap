/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:50:41 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/04 14:50:44 by hluthor          ###   ########.fr       */
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
    i = ft_ltsnum(&lst);
    *mas = (int *)malloc(sizeof(int) * i);
    while (j < i)
    {
        (*mas)[j] = lst->content;
        lst = lst->next;
        j++;
    }
    return (i);
}

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

int ft_massearch(int c, int i, int j, int *mas)
{
    while (i < j)
    {
        if (mas[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void ft_first_second(int *mas, int i, t_list **s_a, t_list **s_b, int b)
{
    int j;
    int k;
    int c;
    t_list *cp1;

    j = 1;
    c = 0;
    cp1 = *s_a;
    while (j < (ft_lstnum(s_a) / 2))
    {
        ft_massearch(cp1->content, b, i, mas) ? break() : j++;
        cp1 = cp1->next;
    }
    k = j;
    while (k < i)
    {
        ft_massearch(cp1->content, b, i, mas) ? c = k : k++;
        cp1 = cp1->next;
    }
}

int sort(t_list **stack_a, t_list **stack_b)
{
    int *mas;
    int i;

    i = ft_mas(&mas, *stack_a);
    ft_sortmas(&mas, i);
    while (ft_lstnum(stack_a) > 3)
        ft_first_second(mas, i, stack_a, stack_b);

}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    if (check_valid(&stack_a, argv, argc) == 0)
        return (0);
    sort(&stack_a, &stack_b);
}
