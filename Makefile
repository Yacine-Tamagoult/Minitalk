SRCS_SERVER = server.c \
			  server_main.c \

SRCS_CLIENT = client.c \
			  client_main.c \

SRCS_CLIENT_BONUS = Bonus/client_bonus.c \
			 		Bonus/client_main_bonus.c \

SRCS_SERVER_BONUS = Bonus/server_bonus.c \
			 		Bonus/server_main_bonus.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

CC = gcc

NAME = jsp

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

PRINTF = ft_printf/libftprintf.a

LIB = LIB/libft.a

all : $(NAME)

$(NAME) : client server

client : $(OBJS_CLIENT)
	make -C ft_printf
	make -C LIB
	$(CC) $(OBJS_CLIENT) $(PRINTF) $(LIB) -o client 

server : $(OBJS_SERVER)
	make -C ft_printf
	make -C LIB
	$(CC) $(OBJS_SERVER) $(PRINTF) $(LIB) -o server 

bonus : $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS) 
	make -C ft_printf
	make -C LIB
	$(CC) $(OBJS_SERVER_BONUS) $(PRINTF) $(LIB) -o server_bonus
	$(CC) $(OBJS_CLIENT_BONUS) $(PRINTF) $(LIB) -o client_bonus 

clean : 
	make clean -C ft_printf
	make clean -C LIB
	$(RM) *.o Bonus/*.o
	clear
	@echo "🧚 tout propre 🧚"

fclean :
	make fclean -C ft_printf
	make fclean -C LIB
	$(RM) *.o Bonus/*.o server client server_bonus client_bonus
	clear
	@echo "🧚 tout propre 🧚"

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : re fclean clean all