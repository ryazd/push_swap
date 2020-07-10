/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:16:31 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/08 17:18:07 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			search_nach_con(int sch, int *con, int kol, int i)
{
	int		nach;

	if (sch == 1)
		nach = 0;
	else
		nach = *con;
	if (kol == sch)
		*con = i - 3;
	else
		*con = (i / kol) * sch;
	return (nach);
}

int			naction_a(t_list *s_a, int cont)
{
	t_list	*cp;
	int		i;

	cp = s_a;
	i = 0;
	while (cp)
	{
		if (cp->content < cont)
			break ;
		i++;
		cp = cp->next;
	}
	if (i < (ft_lstnum(&s_a) / 2))
		return (i * 2);
	return ((i * 2) + 1);
}

int			naction_b(t_list *s_a, t_list *s_b, int i, int cont)
{
	int		kol;

	if (i < (ft_lstnum(&s_b) / 2))
		kol = i;
	else
		kol = ((ft_lstnum(&s_b) - i) + 1);
	kol += naction_a(s_a, cont);
	return (kol);
}

void		vsp(t_list **s_a, t_list **s_b, int i)
{
	int		c;

	if (i <= (ft_lstnum(s_a) / 2))
	{
		c = i;
		while (i-- > 0)
			ft_rotate(s_a, NULL, 1, "ra");
		ft_push(s_a, s_b, "pa");
		while (c-- > 0)
			ft_rotate(s_a, NULL, 2, "rra");
	}
	else
	{
	    i = ft_lstnum(s_a) - i;
		c = i;
		while (i-- > 0)
			ft_rotate(s_a, NULL, 2, "rra");
		ft_push(s_a, s_b, "pa");
		while (c-- > -1)
			ft_rotate(s_a, NULL, 1, "ra");
	}
}
