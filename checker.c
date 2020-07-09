/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:08:24 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 21:32:26 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			readinstructions(t_list **stack_a, t_list **stack_b, int ret)
{
	char	*inst;
	char	*temp;
	char	buf[2];

	inst = NULL;
	while (ret)
	{
		ret = read(0, buf, 1);
		buf[ret] = '\0';
		if (buf[0] && buf[0] != '\n')
		{
			temp = inst;
			inst = ft_strjoin(inst, buf);
			free(temp);
		}
		else
		{
			if (!inst)
				break ;
			if (inst[0] && !check_instruction(stack_a, stack_b, &inst) && ret)
				return (0);
		}
	}
	return (1);
}

int			check_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*cp;

	cp = *stack_a;
	while (cp->next)
	{
		if (cp->content > (cp->next)->content)
			return (0);
		cp = cp->next;
	}
	return (freestacks(stack_a, stack_b));
}

int			ok_ko(int i)
{
	if (i == 1)
	{
		write(1, "OK\n", 4);
		return (i);
	}
	else
		write(1, "KO\n", 4);
	return (i);
}

int			main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		j;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (check_valid(&stack_a, argv, argc) == 0)
		return (0);
	j = readinstructions(&stack_a, &stack_b, 1);
	if (stack_a && stack_a->next)
		i = check_stacks(&stack_a, &stack_b);
	else
		i = freestacks(&stack_a, &stack_b);
	if (j != 0)
		return (ok_ko(i));
	return (0);
}
