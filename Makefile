# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:52:32 by aitlopez          #+#    #+#              #
#    Updated: 2023/04/17 12:57:52 by aitlopez         ###   ########.fr        #
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
