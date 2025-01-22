# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 16:59:34 by sjupille          #+#    #+#              #
#    Updated: 2025/01/08 10:46:29 by sjupille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_BONUS	= checker
SRCS_DIR	= srcs/
BONUS_SRCS_DIR = bonus_srcs/
GNL_SRCS_DIR	= GNL_srcs/
MAIN_SRCS_DIR = MAIN_SRCS/
SRCS		= $(SRCS_DIR)algorithm.c \
			  $(SRCS_DIR)fill_stack_b.c \
			  $(SRCS_DIR)ft_init_stack.c \
			  $(SRCS_DIR)ft_split.c \
			  $(SRCS_DIR)index_list.c \
			  $(SRCS_DIR)parsing.c \
			  $(SRCS_DIR)push_swap.c \
			  $(SRCS_DIR)reverse.c \
			  $(SRCS_DIR)rotate.c \
			  $(SRCS_DIR)sort_by.c \
			  $(SRCS_DIR)utils.c
			  
MAIN_SRCS	= main.c

BONUS_SRCS	= $(BONUS_SRCS_DIR)checker.c \
			  $(BONUS_SRCS_DIR)checker_utils.c\
			  $(BONUS_SRCS_DIR)checker_op1.c\
			  $(BONUS_SRCS_DIR)checker_op2.c\
			  $(BONUS_SRCS_DIR)checker_op3.c

GNL_SRCS	= $(GNL_SRCS_DIR)get_next_line.c \
			  $(GNL_SRCS_DIR)get_next_line_utils.c

INCLUDES = -I includes

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
B_OBJS		= $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))
GNL_OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRCS:.c=.o)))
MAIN_OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(MAIN_SRCS:.c=.o)))


CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

# Couleurs
GREEN = \033[1;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
END = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(BONUS_SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(GNL_SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(MAIN_SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


all : $(NAME)

$(NAME) : $(OBJS) $(GNL_OBJS) $(MAIN_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MAIN_OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created !$(END)"

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(B_OBJS) $(GNL_OBJS) $(OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) $(GNL_OBJS) $(OBJS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) created!$(END)"

clean :
	@$(RM) $(OBJS) $(B_OBJS) $(GNL_OBJS) $(MAIN_OBJS)
	@echo "$(YELLOW)Object files deleted !$(END)"

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)All deleted !$(END)"

re : fclean all

.PHONY : all clean fclean re bonus

