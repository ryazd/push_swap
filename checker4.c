/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:39:49 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/04 14:39:52 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int pars_argv(t_list **stack_a, char *av)
{
    char **new;
    int i;
    long long c;

    i = 0;
    ft_splitwhitespace(av, &new);
    while (new[i])
    {
        c = ft_atoi(new[i]);
        if (check_content(new[i]) == 0 || ((c < -2147483648) || (c > 2147483647)) || ft_strlen(new[i]) > 11)
            return (0);
        ft_lstaddend(stack_a, ft_lstnew((int) c));
        i++;
    }
    ft_freearray(&new);
    return (1);
}

static int	check_overflow(int sign, long long result, const char *str)
{
    if (sign > 0)
    {
        if (result < 922337203685477580)
            return (1);
        if (result == 922337203685477580)
        {
            if (*str == '8' || *str == '9')
                return (-1);
            return (1);
        }
        return (-1);
    }
    else
    {
        if (result < 922337203685477580)
            return (1);
        if (result == 922337203685477580)
        {
            if (*str == '9')
                return (0);
            return (1);
        }
        return (0);
    }
}

long long			ft_atoi(const char *str)
{
    int					sign;
    long long			result;

    result = 0;
    sign = 1;
    while (ft_isspace(*str))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str == '0')
        str++;
    while (ft_isdigit(*str))
    {
        if (check_overflow(sign, result, str) != 1)
            return (check_overflow(sign, result, str));
        result = (result * 10) + (*str - '0');
        str++;
    }
    return (sign * result);
}

int ft_strchr(char *str)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (str[j])
    {
        if (str[j] == ' ')
            i++;
        j++;
    }
    return (i);
}

int reterr(t_list **lst)
{
    if (*lst && lst)
        freestacks(lst, NULL);
    write(2, "Error\n", 6);
    return (0);
}