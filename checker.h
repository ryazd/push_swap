/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:49:59 by hluthor           #+#    #+#             */
/*   Updated: 2020/07/09 19:53:56 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

long long			ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					check_valid(t_list **stack_a, char **av, int ac);
int					ft_strlen(char *str);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstnew(int content);
int					check_content(char *content);
int					check_duplicates(t_list **stack_a);
int					ft_strchr(char *str);
int					reterr(t_list **lst);
int					pars_argv(t_list **stack_a, char *str);
void				ft_splitwhitespace(char *av, char ***new);
int					numstr(char *av);
char				*makemas(char **av);
void				ft_freearray(char ***new);
int					check_instruction(t_list **st_a, t_list **st_b,
									char **inst);
int					ft_strcmp(char *str1, char *str2);
int					ft_swap(t_list **lst1, t_list **lst2, char *str);
int					ft_push(t_list **lst1, t_list **lst2, char *str);
int					ft_rotate(t_list **lst1, t_list **lst2, int i, char *str);
int					freestacks(t_list **stack_a, t_list **stack_b);
int					check_stacks(t_list **stack_a, t_list **stack_b);
int					ok_ko(int i);
int					freestacks_b(t_list **stack_b);
int					ft_lstnum(t_list **lst);
int					ft_num_of_action(t_list **s_a, t_list **s_b, int i, int j);
int					sort(t_list **stack_a, t_list **stack_b, int b);
int					sort_stc3(t_list **lst);
int					ft_mas(int **mas, t_list *lst);
void				ft_sortmas(int **mas, int i);
int					ft_massearch(int c, int nach, int con, int *mas);
void				check_stc(t_list **lst);
int					ft_first_second(int *mas, int *arr, t_list **s_a,
									t_list **s_b);
int					part_selection(t_list **lst, t_list **lst2, int i);
int					search_nach_con(int sch, int *con, int kol, int i);
int					naction_a(t_list *s_a, int cont);
int					naction_b(t_list *s_a, t_list *s_b, int i, int cont);
void				vsp(t_list **s_a, t_list **s_b, int i);
void				vsp1(t_list **lst, int i);
int					vsp2(t_list **s_b, t_list *cp, int k);
int					vsp3(t_list **s_b, t_list *cp, int k);
void				swap_a(t_list **s_a, t_list **s_b, int k);
void				sort_b(t_list **s_a, t_list **s_b, int j, int i);
int					print_action(char *str);
int					check_sort(t_list *lst);
int					ft_vsp4(t_list **lst, t_list **lst2);
int					sort_stc4(t_list **lst, t_list **lst2);
int					ft_vsp5(t_list **lst, t_list **lst2, int i);
int					sort_stc5(t_list **lst, t_list **lst2);
int					instcheck(t_list **stack_a, t_list **stack_b, char *str);
int					readinstructions(t_list **stack_a, t_list **stack_b,
									int ret);
char				*ft_strjoin(char *s1, char *s2);
void				print_action1(char *str);
int					check_instruction1(t_list **st_a, t_list **st_b,
										char **inst);

#endif
