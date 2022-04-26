CC = gcc
CFLAGS = -Wextra -Wall -Werror
CFLAGS2 = -g
AR = ar rcs

NAME = philo
FORDER = src/
D_UTIL = util/
SRC_LIST = philosoper.c\
	thread.c\
	philo_routine.c\
	$(D_UTIL)ft_atoi.c\
	$(D_UTIL)ft_strncmp.c\
	$(D_UTIL)ft_putstr_fd.c\
	$(D_UTIL)ft_putendl_fd.c\
	$(D_UTIL)ft_putchar_fd.c\
	$(D_UTIL)util_time.c\
	$(D_UTIL)util_print.c\
#addprefix 접두어 붙이기
SRC = $(addprefix $(FORDER), $(SRC_LIST))
OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)

re: fclean all
debug : $(OBJS)
	$(CC) $(CFLAGS2) $^ -o $@
phony : philo all re fclean clean