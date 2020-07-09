/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:50:41 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 21:27:31 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			check_sort(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > (lst->next)->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int			sort_stc3(t_list **lst)
{
	t_list	*cp;
	t_list	*cp1;

	cp = (*lst)->next;
	cp1 = cp->next;
	if (check_sort(*lst) == 0)
	{
		if ((*lst)->content < cp->content && cp->content > cp1->content &&
				(*lst)->content < cp1->content)
			return (ft_rotate(lst, NULL, 2, "rra") + ft_swap(lst, NULL, "sa"));
		if ((*lst)->content > cp->content && cp->content > cp1->content)
			return (ft_rotate(lst, NULL, 1, "ra") + ft_swap(lst, NULL, "sa"));
		if ((*lst)->content > cp->content && cp->content < cp1->content &&
				(*lst)->content > cp1->content)
			return (ft_rotate(lst, NULL, 1, "ra"));
		if ((*lst)->content > cp->content && cp->content < cp1->content)
			return (ft_swap(lst, NULL, "sa"));
		if ((*lst)->content < cp->content && cp->content > cp1->content)
			return (ft_rotate(lst, NULL, 2, "rra"));
	}
	return (1);
}

int			ft_vsp4(t_list **lst, t_list **lst2)
{
	ft_rotate(lst, NULL, 2, "rra");
	ft_push(lst, lst2, "pa");
	ft_rotate(lst, NULL, 1, "ra");
	ft_rotate(lst, NULL, 1, "ra");
	return (0);
}

int			part_selection(t_list **lst, t_list **lst2, int i)
{
	if (i == 2)
		return (ft_swap(lst, NULL, "sa") - 1);
	if (i == 3)
		return (sort_stc3(lst) - 1);
	if (i == 4)
		return (sort_stc4(lst, lst2));
	if (i == 5)
		return (sort_stc5(lst, lst2));
	if (i > 5 && i < 90)
		return (2);
	if (i > 90 && i < 400)
		return (5);
	return (11);
}

int			main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (check_valid(&stack_a, argv, argc) == 0)
		return (0);
	if (!check_sort(stack_a))
	{
		if ((b = part_selection(&stack_a, &stack_b, ft_lstnum(&stack_a))) > 0)
			sort(&stack_a, &stack_b, b);
	}
	freestacks(&stack_a, &stack_b);
	return (0);
}
