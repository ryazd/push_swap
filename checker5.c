/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:42:32 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/04 14:42:34 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int freestacks_b(t_list **stack_b)
{
    t_list *cp;

    if (stack_b && *stack_b)
    {
        while ((*stack_b)->next)
        {
            cp = *stack_b;
            *stack_b = (*stack_b)->next;
            cp->next = NULL;
            free(cp);
        }
        free(*stack_b);
        return (0);
    }
    return (1);
}

int freestacks(t_list **stack_a, t_list **stack_b)
{
    t_list *cp;

    if (stack_a && *stack_a)
    {
        while ((*stack_a)->next)
        {
            cp = *stack_a;
            *stack_a = (*stack_a)->next;
            cp->next = NULL;
            free(cp);
        }
        if (*stack_a)
            free(*stack_a);
    }
    return (freestacks_b(stack_b));
}

int		ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int		ft_isspace(int c)
{
    if (c == '\t' || c == '\n' || c == '\v' ||
        c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}
