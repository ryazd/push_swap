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
