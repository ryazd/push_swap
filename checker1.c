/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:33:59 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/08 15:32:27 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_swap(t_list **lst1, t_list **lst2, char *str)
{
	int		i;
	int		j;
	t_list	**lst;

	print_action(str);
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

int			ft_push(t_list **lst1, t_list **lst2, char *str)
{
	t_list	*cp;

	print_action(str);
	if (lst2 && *lst2)
	{
		cp = *lst2;
		*lst2 = (*lst2)->next;
		cp->next = *lst1;
		*lst1 = cp;
	}
	return (1);
}

int			ft_rotate(t_list **lst1, t_list **lst2, int i, char *str)
{
	t_list	*cp;

	cp = *lst1;
	print_action(str);
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
		return (ft_rotate(lst2, NULL, i, ""));
	return (1);
}
