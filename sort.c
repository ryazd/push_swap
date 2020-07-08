/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:14:38 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/08 17:12:45 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			vsp2(t_list **s_b, t_list *cp, int k)
{
	int		i;

	i = k;
	while ((ft_lstnum(s_b) - i > 0))
	{
		ft_rotate(s_b, NULL, 2, "rrb");
		i--;
	}
	i = 0;
	while (cp->content < (*s_b)->content)
	{
		i++;
		cp = cp->next;
	}
	return (i);
}

int			vsp3(t_list **s_b, t_list *cp, int k)
{
	int		i;

	i = k;
	if (i > 0)
	{
		while (i > 1)
		{
			ft_rotate(s_b, NULL, 1, "rb");
			i--;
		}
		ft_swap(s_b, NULL, "sb");
	}
	i = 0;
	while (cp->content < (*s_b)->content)
	{
		i++;
		cp = cp->next;
	}
	return (i);
}

void		swap_a(t_list **s_a, t_list **s_b, int k)
{
	int		i;
	t_list	*cp;

	cp = *s_a;
	if (k <= (ft_lstnum(s_b) / 2))
	{
		i = vsp3(s_b, cp, k);
		vsp(s_a, s_b, i);
	}
	else
	{
		i = vsp2(s_b, cp, k);
		vsp(s_a, s_b, i);
	}
	vsp1(s_b, k);
}

void		sort_b(t_list **s_a, t_list **s_b, int j, int i)
{
	t_list	*cp;
	int		k;

	while (*s_b)
	{
		cp = *s_b;
		i = 0;
		j = 0;
		k = 0;
		j = naction_b(*s_a, *s_b, i, cp->content);
		while (cp->next)
		{
			if (j > naction_b(*s_a, *s_b, i, cp->content))
			{
				k = i;
				j = naction_b(*s_a, *s_b, i, cp->content);
			}
			cp = cp->next;
			i++;
		}
		swap_a(s_a, s_b, k);
	}
}

int			sort(t_list **stack_a, t_list **stack_b, int b)
{
	int		*mas;
	int		i;
	int		sch;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * 2);
	i = ft_mas(&mas, *stack_a);
	ft_sortmas(&mas, i);
	sch = 1;
	while (sch <= b)
	{
		arr[0] = search_nach_con(sch, &(arr[1]), b, i);
		while (ft_first_second(mas, arr, stack_a, stack_b))
			sch += 0;
		sch++;
	}
	sort_stc3(stack_a);
	sort_b(stack_a, stack_b, 0, 0);
	free(mas);
	free(arr);
	return (0);
}
