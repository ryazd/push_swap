CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME_1 = push_swap
NAME_2 = checker
SOURCES_1 = push_swap.c sort.c sort1.c sort2.c sort3.c checker1.c checker2.c \
            checker3.c checker4.c checker5.c print_action.c
OBJECTS_1 = $(subst .c,.o,$(SOURCES_1))
SOURCES_2 = checker.c checker1.c checker2.c checker3.c checker4.c checker5.c \
            print_action.c check_instruction.c
OBJECTS_2 = $(subst .c,.o,$(SOURCES_2))

PSC_HEADER = checker.h

.PHONY: all clean fclean re

all: $(NAME_1) $(NAME_2)

$(NAME_1):	$(OBJECTS_1)
			@$(CC) $^ -o $@

$(NAME_2):	$(OBJECTS_2)
			@$(CC) $^ -o $@

%.o: %.c	$(PSC_HEADER)
			@$(CC)	$(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJECTS_1)
		@rm -rf $(OBJECTS_2)

fclean:	clean
		@rm -rf $(NAME_1)
		@rm -rf $(NAME_2)

re:	fclean	all
