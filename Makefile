# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:52:32 by aitlopez          #+#    #+#              #
#    Updated: 2023/04/18 16:13:37 by aitlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc

SRC_CLIENT = client.c
SRC_SERVER = server.c

FLAGS = -Wall -Werror -Wextra

OBJ_CLIENT = $(SRC:.c=.o)
OBJ_SERVER = $(SRC:.c=.o)

HADER_CLIENT = client.h
HEADER_SERVER = server.h

RM = rm -f

%.o : %.c $(HEADER_CLIENT) $(HEADER_SERVER)
	$(CC) $(FLAGS) -c $< -o $@

all: $(CLIENT) $(SERVER)
	
$(CLIENT) : $(OBJ_CLIENT) $(HEADER_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER) : $(OBJ_SERVER) $(HEADER_SERVER)
   $(CC) $(FLAGS) $(OBJ_SERVER) -o $(SERVER)

# all :	$(CLIENT) $(SERVER)


clean :
	$(RM) $(OBJ_CLIENT)
	$(RM) $(OBJ_SERVER)

fclean : clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	@echo "$(CLIENT), $(SERVER) cleaned!$(NC)"

re : fclean all
norm :
	@norminette .
	.PHONY = all clean fclean re norm
