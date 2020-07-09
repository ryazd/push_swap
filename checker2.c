/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:34:13 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 19:51:46 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list			*ft_lstnew(int content)
{
	t_list		*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}

void			ft_lstaddend(t_list **alst, t_list *new)
{
	t_list		*current;

	if (*alst)
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*alst = new;
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

int				check_duplicates(t_list **stack_a)
{
	int			a;
	t_list		*current1;
	t_list		*current2;

	current1 = *stack_a;
	while (current1)
	{
		a = 0;
		current2 = *stack_a;
		while (current2)
		{
			current1->content == current2->content ? a++ : a + 0;
			current2 = current2->next;
		}
		if (a > 1)
			return (reterr(stack_a));
		current1 = current1->next;
	}
	return (1);
}

int				check_valid(t_list **stack_a, char **av, int ac)
{
	int			i;
	long long	c;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i]))
		{
			if (!pars_argv(stack_a, av[i]))
				return (reterr(stack_a));
		}
		else
		{
			c = ft_atoi(av[i]);
			if (check_content(av[i]) == 0 || ((c < -2147483648)
						|| (c > 2147483647)) || ft_strlen(av[i]) > 11)
				return (reterr(stack_a));
			ft_lstaddend(stack_a, ft_lstnew((int)c));
		}
		i++;
	}
	return (check_duplicates(stack_a));
}
