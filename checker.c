/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:08:24 by hluthor           #+#    #+#             */
/*   Updated: 2020/06/29 13:08:31 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int		ft_isspace(int c)
{
    if (c == '\t' || c == '\n' || c == '\v' ||
        c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
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

int reterr(void)
{
    write(1, "Error\n", 6);
    return (0);
}

void ft_freearray(char ***new)
{
    int i;

    i = 0;
    while ((*new)[i])
    {
        free((*new)[i]);
        i++;
    }
    free(*new);
}

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

int numstr(char *av)
{
    int i;

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

char *makemas(char **av)
{
    char *str;
    int i;

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

void ft_splitwhitespace(char *av, char ***new)
{
    int i;
    int j;
    char **str;

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

int check_content(char *content)
{
    int i;

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

t_list *ft_lstnew(int content)
{
    t_list *list;

    list = (t_list *)malloc(sizeof(t_list));
    list->content = content;
    list->next = NULL;
    return (list);
}

void ft_lstaddend(t_list **alst, t_list *new)
{
    t_list *current;

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

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int check_duplicates(t_list **stack_a)
{
    int a;
    t_list *current1;
    t_list *current2;

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
            return (reterr());
        current1 = current1->next;
    }
    return (1);
}

int check_valid(t_list **stack_a, char **av, int ac)
{
    int i;
    long long c;

    i = 1;
    while (i < ac)
    {
        if (ft_strchr(av[i]))
        {
            if (!pars_argv(stack_a, av[i]))
                return (reterr());
        }
        else
        {
            c = ft_atoi(av[i]);
            if (check_content(av[i]) == 0 || ((c < -2147483648) || (c > 2147483647)) || ft_strlen(av[i]) > 11)
                return (reterr());
            ft_lstaddend(stack_a, ft_lstnew((int) c));
        }
        i++;
    }
    return (check_duplicates(stack_a));
}

/*char **soz()
{
    char **argv;

    argv = (char **)malloc(sizeof(char *) * 3);
    argv[0] = (char *)malloc(sizeof(char) * 2);
    argv[1] = (char *)malloc(sizeof(char) * 2);
    argv[2] = (char *)malloc(sizeof(char) * 4);
    argv[0][0] = '0';
    argv[0][1] = '\0';
    argv[1][0] = '1';
    argv[1][1] = '\0';
    argv[2][0] = '2';
    argv[2][1] = ' ';
    argv[2][2] = '3';
    argv[2][3] = '\0';
    return (argv);
}*/

void readinstructions(t_list *stack_a, t_list *stack_b)
{
    char str[4];

    read(0, str, 4);
    printf("read: %s", str);
    while (*str != '\n') {
        read(0, str, 4);
        printf("read: %s", str);
    }
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    if (check_valid(&stack_a, argv, argc) == 0)
        return (0);
    readinstructions(stack_a, stack_b);
    while ((stack_a)->next)
    {
        printf("%i\n", (stack_a)->content);
        stack_a = (stack_a)->next;
    }
    printf("%i\n", (stack_a)->content);
    return (1);
}
