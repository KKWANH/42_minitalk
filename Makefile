# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 09:50:52 by kimkwanho         #+#    #+#              #
#    Updated: 2021/10/25 19:25:00 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc $(CFLAGS)
CFLAGS			=	-Wall -Wextra -Werror

SERVER			=	server
CLIENT			=	client
SERVER_B		=	server_bonus
CLIENT_B		=	client_bonus

SERVER_SRCS		=	srcs/base/server.c \
					srcs/util/util.c
SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)
CLIENT_SRCS		=	srcs/base/client.c \
					srcs/util/util.c
CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)

SERVER_SRCS_B	=	srcs/base/server_bonus.c \
					srcs/util/util.c
SERVER_OBJS_B	=	$(SERVER_SRCS_B:.c=.o)
CLIENT_SRCS_B	=	srcs/base/client_bonus.c \
					srcs/util/util.c
CLIENT_OBJS_B	=	$(CLIENT_SRCS_B:.c=.o)

all: fclean
	@printf "\033[34m[MINITALK]\033[0m Building server : "
	@$(CC) $(SERVER_SRCS) -o $(SERVER)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"
	@printf "\033[34m[MINITALK]\033[0m Building client : "
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"
	@make clean
	@printf "\n\033[34m[MINITALK]\033[0m Now \033[32mMinitalk\033[0m is \033[33mexecutable\033[0m.\n"

bonus: fclean
	@printf "\033[34m[MINITALK]\033[0m Building server : "
	@$(CC) $(SERVER_SRCS_B) -o $(SERVER)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"
	@printf "\033[34m[MINITALK]\033[0m Building client : "
	@$(CC) $(CLIENT_SRCS_B) -o $(CLIENT)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\n"
	@make clean
	@printf "\n\033[34m[MINITALK]\033[0m Now \033[32mMinitalk - bonus\033[0m is \033[33mexecutable\033[0m.\n"

clean:
	@printf "\033[34m[MINITALK]\033[0m Removing object : "
	@rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_B) $(CLIENT_OBJS_B)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

fclean:
	@printf "\033[34m[MINITALK]\033[0m Removing result : "
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	@sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m." && sleep 0.1 && printf "\033[33m. "
	@printf "\033[32mOK\033[0m\n"

re: fclean all