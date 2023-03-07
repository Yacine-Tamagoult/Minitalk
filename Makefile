SRCS_SERVER = server.c \
			  server_main.c \

SRCS_CLIENT = client.c \
			  client_main.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc

NAME = jsp

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBFT = ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : client server

client : $(OBJS_CLIENT)
	make -C ft_printf
	$(CC) $(OBJS_CLIENT) $(LIBFT) -o client 

server : $(OBJS_SERVER)
	make -C ft_printf
	$(CC) $(OBJS_SERVER) $(LIBFT) -o server 

clean : 
	make clean -C 
	$(RM) *.o 
	clear
	@echo "🧚 tout propre 🧚"

fclean :
	make fclean -C ft_printf
	$(RM) *.o server client
	clear
	@echo "🧚 tout propre 🧚"

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : re fclean clean all