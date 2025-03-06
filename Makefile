# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 16:19:20 by rraumain          #+#    #+#              #
#    Updated: 2025/03/06 18:45:14 by rraumain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PARSING = $(addprefix parsing/, init.c parse.c)
SRC_SIMULATION = $(addprefix simulation/, actions.c print.c simulation.c)
SRC_UTILS = $(addprefix utils/, cleanup.c error.c string.c time.c)
SRC = $(addprefix src/, main.c $(SRC_PARSING) $(SRC_SIMULATION) $(SRC_UTILS))
INCLUDES = -Iincludes

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re