/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:33:36 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 19:44:11 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_instruction1(t_list **st_a, t_list **st_b, char **inst)
{
	if (ft_strcmp(*inst, "rb"))
		ft_rotate(st_b, NULL, 1, "");
	else if (ft_strcmp(*inst, "rr"))
		ft_rotate(st_a, st_b, 1, "");
	else if (ft_strcmp(*inst, "rra"))
		ft_rotate(st_a, NULL, 2, "");
	else if (ft_strcmp(*inst, "rrb"))
		ft_rotate(st_b, NULL, 2, "");
	else if (ft_strcmp(*inst, "rrr"))
		ft_rotate(st_a, st_b, 2, "");
	else
	{
		free(*inst);
		*inst = NULL;
		return (reterr(NULL));
	}
	free(*inst);
	*inst = NULL;
	return (1);
}

int	check_instruction(t_list **st_a, t_list **st_b, char **inst)
{
	if (ft_strcmp(*inst, "sa"))
		ft_swap(st_a, NULL, "");
	else if (ft_strcmp(*inst, "sb"))
		ft_swap(st_b, NULL, "");
	else if (ft_strcmp(*inst, "ss"))
		ft_swap(st_a, st_b, "");
	else if (ft_strcmp(*inst, "pa"))
		ft_push(st_a, st_b, "");
	else if (ft_strcmp(*inst, "pb"))
		ft_push(st_b, st_a, "");
	else if (ft_strcmp(*inst, "ra"))
		ft_rotate(st_a, NULL, 1, "");
	else
		return (check_instruction1(st_a, st_b, inst));
	free(*inst);
	*inst = NULL;
	return (1);
}
