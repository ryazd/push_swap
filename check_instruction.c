/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:33:36 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/07 15:34:07 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.c"

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

int check_instruction(t_list **st_a, t_list **st_b, char *inst)
{
    if (ft_strcmp(inst, "sa"))
        return (ft_swap(st_a, NULL, ""));
    if (ft_strcmp(inst, "sb"))
        return (ft_swap(st_b, NULL, ""));
    if (ft_strcmp(inst, "ss"))
        return (ft_swap(st_a, st_b, ""));
    if (ft_strcmp(inst, "pa"))
        return (ft_push(st_a, st_b, ""));
    if (ft_strcmp(inst, "pb"))
        return (ft_push(st_b, st_a, ""));
    if (ft_strcmp(inst, "ra"))
        return (ft_rotate(st_a, NULL, 1, ""));
    if (ft_strcmp(inst, "rb"))
        return (ft_rotate(st_b, NULL, 1, ""));
    if (ft_strcmp(inst, "rr"))
        return (ft_rotate(st_a, st_b, 1, ""));
    if (ft_strcmp(inst, "rra"))
        return (ft_rotate(st_a, NULL, 2, ""));
    if (ft_strcmp(inst, "rrb"))
        return (ft_rotate(st_b, NULL, 2, ""));
    if (ft_strcmp(inst, "rrr"))
        return (ft_rotate(st_a, st_b, 2, ""));
    return (0);
}
