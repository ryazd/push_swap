

#ifndef UNTITLED_CHECKER_H
#define UNTITLED_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>

typedef struct		s_list
{
    int			    content;
    struct s_list	*next;
}                   t_list;

long long			ft_atoi(const char *str);
int		            ft_isdigit(int c);
int		            ft_isspace(int c);
int                 check_valid(t_list **stack_a, char **av, int ac);
int                 ft_strlen(char *str);
void                ft_lstaddend(t_list **alst, t_list *new);
t_list              *ft_lstnew(int content);
int                 check_content(char *content);
static int	        check_overflow(int sign, long long result, const char *str);
int                 check_duplicates(t_list **stack_a);
int                 ft_strchr(char *str);
int                 reterr(void);
int                 pars_argv(t_list **stack_a, char *str);
void                ft_splitwhitespace(char *av, char ***new);
int                 numstr(char *av);
char                *makemas(char **av);
int                 readinstructions(t_list **stack_a, t_list **stack_b);
void                ft_freearray(char ***new);

#endif //UNTITLED_CHECKER_H
