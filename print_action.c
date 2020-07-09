/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:35:41 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 19:50:21 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_action1(char *str)
{
	if (ft_strcmp("rrb", str))
		write(1, "rrb\n", 4);
	if (ft_strcmp("rrr", str))
		write(1, "rrr\n", 4);
}

int		print_action(char *str)
{
	if (str)
	{
		if (ft_strcmp("sa", str))
			write(1, "sa\n", 3);
		else if (ft_strcmp("sb", str))
			write(1, "sb\n", 3);
		else if (ft_strcmp("ss", str))
			write(1, "ss\n", 3);
		else if (ft_strcmp("pa", str))
			write(1, "pa\n", 3);
		else if (ft_strcmp("pb", str))
			write(1, "pb\n", 3);
		else if (ft_strcmp("ra", str))
			write(1, "ra\n", 3);
		else if (ft_strcmp("rb", str))
			write(1, "rb\n", 3);
		else if (ft_strcmp("rr", str))
			write(1, "rr\n", 3);
		else if (ft_strcmp("rra", str))
			write(1, "rra\n", 4);
		else
			print_action1(str);
	}
	return (0);
}
