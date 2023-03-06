SRCS =	ft_printf.c \
		ft_putstr.c \
		ft_flag_c.c \
		ft_flag_di.c \
		ft_douane.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_flag_s.c \
		ft_flag_u.c \
		ft_flag_x.c \
		ft_flag_X.c \
		ft_percent.c \
		ft_flag_p.c \
		
CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

AR = ar rcs

RM = rm -f

NAME = libftprintf.a

all: $(NAME)

	
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS) 

clean:
	
	$(RM) $(OBJS)

fclean: 
	
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY : all clean fclean re