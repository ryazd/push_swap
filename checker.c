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

int reterr(t_list **lst)
{
    if (*lst && lst)
        freestacks(lst, NULL);
    write(2, "Error\n", 6);
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
            return (reterr(stack_a));
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
                return (reterr(stack_a));
        }
        else
        {
            c = ft_atoi(av[i]);
            if (check_content(av[i]) == 0 || ((c < -2147483648) || (c > 2147483647)) || ft_strlen(av[i]) > 11)
                return (reterr(stack_a));
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

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    if (!str1[i] && !str2[i])
        return (1);
    return (0);
}

int ft_swap(t_list **lst1, t_list **lst2)
{
    int i;
    int j;
    t_list **lst;

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

int ft_push(t_list **lst1, t_list **lst2)
{
    t_list *cp;

    if (lst2 && *lst2)
    {
        cp = *lst2;
        *lst2 = (*lst2)->next;
        cp->next = *lst1;
        *lst1 = cp;
    }
    return (1);
}

int ft_rotate(t_list **lst1, t_list **lst2, int i)
{
    t_list *cp;

    cp = *lst1;
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
        return (ft_rotate(lst2, NULL, i));
    return (1);
}

int check_instruction(t_list **st_a, t_list **st_b, char *inst)
{
    if (ft_strcmp(inst, "sa"))
        return (ft_swap(st_a, NULL));
    if (ft_strcmp(inst, "sb"))
        return (ft_swap(st_b, NULL));
    if (ft_strcmp(inst, "ss"))
        return (ft_swap(st_a, st_b));
    if (ft_strcmp(inst, "pa"))
        return (ft_push(st_a, st_b));
    if (ft_strcmp(inst, "pb"))
        return (ft_push(st_b, st_a));
    if (ft_strcmp(inst, "ra"))
        return (ft_rotate(st_a, NULL, 1));
    if (ft_strcmp(inst, "rb"))
        return (ft_rotate(st_b, NULL, 1));
    if (ft_strcmp(inst, "rr"))
        return (ft_rotate(st_a, st_b, 1));
    if (ft_strcmp(inst, "rra"))
        return (ft_rotate(st_a, NULL, 2));
    if (ft_strcmp(inst, "rrb"))
        return (ft_rotate(st_b, NULL, 2));
    if (ft_strcmp(inst, "rrr"))
        return (ft_rotate(st_a, st_b, 2));
    return (0);
}

int readinstructions(t_list **stack_a, t_list **stack_b)
{
    char str[5];
    int ret;

    while ((ret = read(0, str, 5)) > 2)
    {
        if (str[0] == '\n')
            return (1);
        str[4] = '\0';
        str[ret - 1] = '\0';
        if (!check_instruction(stack_a, stack_b, str))
            return (reterr(NULL));
    }
    return (1);
}

int freestacks(t_list **stack_a, t_list **stack_b)
{
    t_list *cp;

    if (stack_a && *stack_a)
    {
        while ((*stack_a)->next)
        {
            cp = *stack_a;
            *stack_a = (*stack_a)->next;
            free(cp);
        }
        if (*stack_a)
        free(*stack_a);
    }
    if (stack_b && *stack_b)
    {
        while ((*stack_b)->next)
        {
            cp = *stack_b;
            *stack_b = (*stack_b)->next;
            free(cp);
        }
        free(*stack_b);
        return (0);
    }
    return (1);
}

int check_stacks(t_list **stack_a, t_list **stack_b)
{
    t_list *cp;

    cp = *stack_a;
    if (cp->content > (cp->next)->content)
    {
        while (cp->next)
        {
            if (cp->content < (cp->next)->content)
                return (0);
            cp = cp->next;
        }
    }
    else
    {
        while (cp->next)
        {
            if (cp->content > (cp->next)->content)
                return (0);
            cp = cp->next;
        }
    }
    return (freestacks(stack_a, stack_b));
}

int ok_ko(int i)
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

void print(t_list *s_a, t_list *s_b)
{
    if (s_a) {
        while ((s_a)->next) {
            printf("%i\n", (s_a)->content);
            s_a = (s_a)->next;
        }
        printf("%i\n", (s_a)->content);
    }
    if (s_b) {
        while ((s_b)->next) {
            printf("   %i\n", (s_b)->content);
            s_b = (s_b)->next;
        }
        printf("   %i\n", (s_b)->content);
    }
    else
        printf("   %c\n", 'n');
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    int i;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    if (check_valid(&stack_a, argv, argc) == 0)
        return (0);
    readinstructions(&stack_a, &stack_b);
    //print(stack_a, stack_b);
    if (stack_a && stack_a->next)
        i = check_stacks(&stack_a, &stack_b);
    else
        i = freestacks(&stack_a, &stack_b);
    return (ok_ko(i));
}
