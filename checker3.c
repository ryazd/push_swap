/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:34:30 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/08 17:30:50 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_freearray(char ***new)
{
	int		i;

	i = 0;
	while ((*new)[i])
	{
		free((*new)[i]);
		i++;
	}
	free(*new);
}

int			numstr(char *av)
{
	int		i;

	i = 0;
	while (*av == ' ')
		av++;
	while (*av)
	{
		if (*av && *av != ' ')
		{
			while (*av != ' ' && *av)
				av++;
			i++;
		}
		while (*av == ' ')
			av++;
	}
	return (i);
}

char		*makemas(char **av)
{
	char	*str;
	int		i;

	i = 0;
	while (**av == ' ')
		(*av)++;
	while ((*av)[i] != ' ' && (*av)[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (**av != ' ' && **av)
	{
		str[i] = **av;
		i++;
		(*av)++;
	}
	str[i] = '\0';
	return (str);
}

void		ft_splitwhitespace(char *av, char ***new)
{
	int		i;
	int		j;
	char	**str;

	i = numstr(av);
	str = (char **)malloc(sizeof(char *) * (i + 1));
	str[i] = (char *)malloc(sizeof(char) * 1);
	str[i] = NULL;
	j = 0;
	while (j < i)
	{
		str[j] = makemas(&av);
		j++;
	}
	*new = str;
}

int			check_content(char *content)
{
	int		i;

	i = 0;
	while (content[i] != '\0')
	{
		if (ft_isdigit(content[i]) == 0 && content[i] != '-')
			return (0);
		if (content[i] == '-' && (i != 0 || content[i + 1] == '\0'))
			return (0);
		i++;
	}
	return (1);
}
