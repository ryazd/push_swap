/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:18:37 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 14:04:18 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_lstnum(t_list **lst)
{
	int		i;
	t_list	*cp;

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

int			ft_mas(int **mas, t_list *lst)
{
	int		i;
	int		j;

	j = 0;
	i = ft_lstnum(&lst);
	*mas = (int *)malloc(sizeof(int) * i);
	while (j < i)
	{
		(*mas)[j] = lst->content;
		lst = lst->next;
		j++;
	}
	return (i);
}

int			sort_stc4(t_list **lst, t_list **lst2)
{
	t_list	*cp;
	int		j;

	j = 0;
	ft_push(lst2, lst, "pb");
	sort_stc3(lst);
	cp = (*lst);
	while (j < 3 && (*lst2)->content > cp->content)
	{
		cp = cp->next;
		j++;
	}
	if (j == 0)
		return (ft_push(lst, lst2, "pa") - 1);
	if (j == 1)
		return (ft_push(lst, lst2, "pa") + ft_swap(lst, NULL, "sa") - 2);
	if (j == 3)
		return (ft_push(lst, lst2, "pa") + ft_rotate(lst, NULL, 1, "ra") - 2);
	else
		return (ft_vsp4(lst, lst2));
}

int			ft_vsp5(t_list **lst, t_list **lst2, int i)
{
	if (i == 2)
	{
		ft_rotate(lst, NULL, 1, "ra");
		ft_push(lst, lst2, "pa");
		ft_swap(lst, NULL, "sa");
		ft_rotate(lst, NULL, 2, "rra");
	}
	else
	{
		ft_rotate(lst, NULL, 2, "rra");
		ft_push(lst, lst2, "pa");
		ft_rotate(lst, NULL, 1, "ra");
		ft_rotate(lst, NULL, 1, "ra");
	}
	return (0);
}

int			sort_stc5(t_list **lst, t_list **lst2)
{
	t_list	*cp;
	int		j;

	j = 0;
	ft_push(lst2, lst, "pb");
	sort_stc4(lst, lst2);
	cp = (*lst);
	while (j < 4 && (*lst2)->content > cp->content)
	{
		cp = cp->next;
		j++;
	}
	if (j == 0)
		return (ft_push(lst, lst2, "pa") - 1);
	if (j == 1)
		return (ft_push(lst, lst2, "pa") + ft_swap(lst, NULL, "sa") - 2);
	if (j == 4)
		return (ft_push(lst, lst2, "pa") + ft_rotate(lst, NULL, 1, "ra") - 2);
	else
		return (ft_vsp5(lst, lst2, j));
}
