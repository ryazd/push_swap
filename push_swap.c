/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:50:41 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/04 14:50:44 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_lstnum(t_list **lst)
{
    int i;
    t_list *cp;

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

int ft_mas(int **mas, t_list *lst)
{
    int i;
    int j;

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

void ft_sortmas(int **mas, int i)
{
    int j;
    int k;
    int cp;

    j = 0;
    while (j - 1 < i)
    {
        k = 0;
        while (k + 1 < i)
        {
           if ((*mas)[k] > (*mas)[k + 1])
           {
               cp = (*mas)[k];
               (*mas)[k] = (*mas)[k + 1];
               (*mas)[k + 1] = cp;
           }
           k++;
        }
        j++;
    }
}

int ft_massearch(int c, int nach, int con, int *mas)
{
    while (nach < con)
    {
        if (mas[nach] == c)
            return (1);
        nach++;
    }
    return (0);
}

void check_stc(t_list **lst)
{
    if (lst && *lst && (*lst)->next)
    {
        if ((*lst)->content < (((*lst)->next)->content))
            ft_swap(lst, NULL, "sb");
    }
}

int ft_num_of_action(t_list **s_a, t_list **s_b, int i, int j)
{
    int k;

    k = ft_lstnum(s_a) + 1;
    if ((i - 1) < (k - j))
    {
        while (i > 0)
        {
            ft_rotate(s_a, NULL, 1, "ra");
            i--;
        }
    }
    else
    {
        while (j < k)
        {
            ft_rotate(s_a, NULL, 2, "rra");
            j++;
        }
    }
    ft_push(s_b, s_a, "pb");
    check_stc(s_b);
    return (1);
}

int ft_first_second(int *mas, int con, t_list **s_a, t_list **s_b, int nach)
{
    int j;
    int k;
    int c;
    int r;
    t_list *cp1;

    j = 0;
    c = 0;
    r = 0;
    cp1 = *s_a;
    while (j < (ft_lstnum(s_a) / 2) && c == 0)
    {
        ft_massearch(cp1->content, nach, con, mas) ? c++ : j++;
        cp1 = cp1->next;
    }
    k = j + 1;
    while (cp1)
    {
        ft_massearch(cp1->content, nach, con, mas) ? r = k && k++ : k++;
        cp1 = cp1->next;
    }
    if (c == 0 && r == 0)
        return (0);
    return (ft_num_of_action(s_a, s_b, j, r + 1));
}

int search_nach_con(int sch, int *con, int kol, int i)
{
    int nach;

    if (sch == 1)
        nach = 0;
    else
        nach = *con;
    if (kol == sch)
        *con = i - 3;
    else
        *con = i/kol;
    return (nach);
}

int naction_a(t_list *s_a, int cont)
{
    t_list *cp;
    int i;

    cp = s_a;
    i = 0;
    while (cp)
    {
        if (cp->content < cont)
            break;
        i++;
        cp = cp->next;
    }
    if (i < (ft_lstnum(&s_a) / 2))
        return (i * 2);
    return ((i * 2) + 1);
}

int naction_b(t_list *s_a, t_list *s_b, int i, int cont)
{
    int kol;

    if (i < (ft_lstnum(&s_b) / 2))
        kol = (i * 2) - 1;
    else
        kol = ((ft_lstnum(&s_b) - i) * 2) + 1;
    kol += naction_a(s_a, cont);
    return (kol);
}

void vsp(t_list **s_a, t_list **s_b, int i)
{
    int c;

    //write(1, "vsp  vsp\n", 10);
    if (i <= (ft_lstnum(s_a) / 2))
    {
        c = i;
        while (i-- > 0)
            ft_rotate(s_a, NULL, 1, "ra");
        ft_push(s_a, s_b, "pa");
        while (c-- > 0)
            ft_rotate(s_a, NULL, 2, "rra");
    }
    else
    {
        c = i;
        while (i-- > 0)
            ft_rotate(s_a, NULL, 2, "rra");
        ft_push(s_a, s_b, "pa");
        while (c-- > -1)
            ft_rotate(s_a, NULL, 1, "ra");
    }

}

void vsp1(t_list **lst, int i)
{
    //write(1, "vsp1  vsp1\n", 12);
    if (i <= ((ft_lstnum(lst) / 2) + 1))
    {
        while (i-- > 1)
            ft_rotate(lst, NULL, 2, "rrb");
    }
    else
    {
        while (i-- > 0)
            ft_rotate(lst, NULL, 1, "rb");
    }
}

int vsp2(t_list **s_b, t_list *cp, int k)
{
    int i;


    i = k;
    while ((ft_lstnum(s_b) - i > 0)) {
        ft_rotate(s_b, NULL, 2, "rrb");
        i--;
    }
    i = 0;
    while (cp->content < (*s_b)->content)
    {
        i++;
        cp = cp->next;
    }
    return (i);
}

int vsp3(t_list **s_b, t_list *cp, int k)
{
    int i;

    i = k;
    if (i > 0)
    {
        while (i > 1) {
            ft_rotate(s_b, NULL, 1, "rb");
            i--;
        }
        ft_swap(s_b, NULL, "sb");
    }
    i = 0;
    while (cp->content < (*s_b)->content)
    {
        i++;
        cp = cp->next;
    }
    return (i);
}


void swap_a(t_list **s_a, t_list **s_b, int k)
{
    int i;
    t_list *cp;

    i = k;
    cp = *s_a;
    if (k <= (ft_lstnum(s_b) / 2))
    {
        i = vsp3(s_b, cp, k);
        vsp(s_a, s_b, i);
    }
    else
    {
        i = vsp2(s_b, cp, k);
        vsp(s_a, s_b, i);
    }
    vsp1(s_b, k);
}

void sort_b(t_list **s_a, t_list **s_b, int j, int i)
{
    t_list *cp;
    int k;

    while (*s_b)
    {
        cp = *s_b;
        i = 0;
        j = 0;
        k = 0;
        j = naction_b(*s_a, *s_b, i, cp->content);
        while (cp->next)
        {
            if (j > naction_b(*s_a, *s_b, i, cp->content))
            {
                k = i;
                j = naction_b(*s_a, *s_b, i, cp->content);
            }
            cp = cp->next;
            i++;
        }
       swap_a(s_a, s_b, k);
    }
}

int sort(t_list **stack_a, t_list **stack_b, int b)
{
    int *mas;
    int i;
    int sch;
    int con;
    int nach;

    i = ft_mas(&mas, *stack_a);
    ft_sortmas(&mas, i);
    sch = 1;
    while (sch <= b)
    {
        nach = search_nach_con(sch, &con, b, i);
        while (ft_first_second(mas, con, stack_a, stack_b, nach))
            sch += 0;
        sch++;
    }
    sort_b(stack_a, stack_b, 0, 0);
    return (0);
}

void print(t_list *a, t_list *b)
{
   while (a)
   {
       printf("%i\n", a->content);
       a = a->next;
   }
   while (b)
   {
       printf("          %i\n", b->content);
       b = b->next;
   }
}

int print_action(char *str)
{
    int i;
    int j;

    j = ft_strlen(str);
    i = 0;
    if (j > 0)
    {
        while (i < j)
        {
            write(1, &(str[i]), 1);
            i++;
        }
        write(1, "\n", 3);
    }
    return (0);
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
    sort(&stack_a, &stack_b, 2);
    print(stack_a, stack_b);
}
