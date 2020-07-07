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
/*
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

int ft_first_second(int *mas, int *arr, t_list **s_a, t_list **s_b)
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
        ft_massearch(cp1->content, arr[0], arr[1], mas) ? c++ : j++;
        cp1 = cp1->next;
    }
    k = j + 1;
    while (cp1)
    {
        ft_massearch(cp1->content, arr[0], arr[1], mas) ? r = k && k++ : k++;
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
    int *arr;

    arr = (int *)malloc(sizeof(int) * 2);
    i = ft_mas(&mas, *stack_a);
    ft_sortmas(&mas, i);
    sch = 1;
    while (sch <= b)
    {
        arr[0] = search_nach_con(sch, &(arr[1]), b, i);
        while (ft_first_second(mas, arr, stack_a, stack_b))
            sch += 0;
        sch++;
    }
    sort_stc3(stack_a);
    sort_b(stack_a, stack_b, 0, 0);
    free(mas);
    free(arr);
    return (0);
}
*/
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

/*int print_action(char *str)
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
        write(1, "\n", 2);
    }
    return (0);
}
*/
int check_sort(t_list *lst)
{
    while (lst->next)
    {
        if (lst->content > (lst->next)->content)
            return (0);
        lst = lst->next;
    }
    return (1);
}

int sort_stc3(t_list **lst)
{
    t_list *cp;
    t_list *cp1;

    cp = (*lst)->next;
    cp1 = cp->next;
    if (check_sort(*lst) == 0)
    {
        if ((*lst)->content < cp->content && cp->content > cp1->content && (*lst)->content < cp1->content)
            return (ft_rotate(lst, NULL, 2, "rra") + ft_swap(lst, NULL, "sa"));
        if ((*lst)->content > cp->content && cp->content > cp1->content)
            return (ft_rotate(lst, NULL, 1, "ra") + ft_swap(lst, NULL, "sa"));
        if ((*lst)->content > cp->content && cp->content < cp1->content && (*lst)->content > cp1->content)
            return (ft_rotate(lst, NULL, 1, "ra"));
        if ((*lst)->content > cp->content && cp->content < cp1->content)
            return (ft_swap(lst, NULL, "sa"));
        if ((*lst)->content < cp->content && cp->content > cp1->content)
            return (ft_rotate(lst, NULL, 2, "rra"));
    }
    return (1);
}

int part_selection(t_list **lst, int i)
{
    if (i == 2)
        return (ft_swap(lst, NULL, "sa") - 1);
    if (i == 3)
        return (sort_stc3(lst) - 1);
    if (i > 5 && i < 90)
        return (2);
    if (i > 90 && i < 400)
        return (5);
    return (11);
}

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    int b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1)
        return (0);
    if (check_valid(&stack_a, argv, argc) == 0)
        return (0);
    if (!check_sort(stack_a))
    {
        if ((b = part_selection(&stack_a, ft_lstnum(&stack_a))) > 0)
            sort(&stack_a, &stack_b, b);
    }
    print(stack_a, stack_b);
    freestacks(&stack_a, &stack_b);
    return (0);
}
