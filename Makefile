# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/06 17:04:55 by xmoreau      #+#   ##    ##    #+#        #
#    Updated: 2018/06/11 16:59:40 by xmoreau     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CHKR = checker
PSWAP = push_swap
PATH_OBJ = ./obj/
PATH_SRC = ./src/
PATH_INC = ./includes/

#******************************************************************************#
#                                  CHECKER                                     #
#******************************************************************************#

PATH_OBJ_CHECKER = $(PATH_OBJ)chkr/
PATH_SRC_CHECKER = $(PATH_SRC)chkr/
FILES_CHECKER = actions fill_stack_a get_cmd lst_management main make_cmd\
				miscleanous
OBJ_CHECKER = $(addprefix $(PATH_OBJ_CHECKER), $(addsuffix .o , $(FILES_CHECKER)))
SRC_CHECKER = $(addprefix $(PATH_SRC_CHECKER), $(addsuffix .c , $(FILES_CHECKER)))

#******************************************************************************#
#                                  PUSH_SWAP                                   #
#******************************************************************************#

PATH_OBJ_PSWAP = $(PATH_OBJ)pswap/
PATH_SRC_PSWAP = $(PATH_SRC)pswap/
FILES_PSWAP = actions back_to_base fill_stack_a find_algo\
			  find_best_move_insert find_important for_three\
			  get_proper_interval insertion lst_management main make_cmd\
			  medium miscleanous save_cmd write_prt_cmd
OBJ_PSWAP = $(addprefix $(PATH_OBJ_PSWAP), $(addsuffix .o , $(FILES_PSWAP)))
SRC_PSWAP = $(addprefix $(PATH_SRC_PSWAP), $(addsuffix .c , $(FILES_PSWAP)))

#******************************************************************************#
#                                  LIBFT                                       #
#******************************************************************************#

PATH_LIB = ./libft/
PATH_INC_LIB = ./libft/
NAME_LIB = ft
INC_LIB = -L $(PATH_LIB) -l $(NAME_LIB)

#******************************************************************************#
#                                     ALL                                      #
#******************************************************************************#

PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_CHECKER) $(PATH_OBJ_PSWAP)
OBJ = $(OBJ_CHECKER) $(OBJ_PSWAP)
SRC = $(SRC_CHECKER) $(SRC_PSWAP)
FILES = $(FILES_CHECKER) $(FILES_PSWAP)
HEADERS = $(PATH_INC)push_swap.h $(PATH_LIB)libft.h

#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: $(CHKR) $(PSWAP) 

clean:
	@printf "\n\033[1m SUPPRESSION DES OBJETS\033[0m\n"
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PATH_LIB)

fclean: clean
	@printf "\n\033[1mSUPPRESSION DE $(CHKR) ET $(PSWAP)\033[0m\n"
	@rm -rf $(CHKR) $(PSWAP)
	@rm -rf $(PATH_OBJ)
	@make fclean -C $(PATH_LIB)

re: fclean all

#******************************************************************************#
#                                  Compilation                                 #
#******************************************************************************#

$(CHKR): $(PATHS_OBJ) $(OBJ_CHECKER)
	@make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) -I $(PATH_INC) $(INC_LIB) -o $(CHKR)
	@echo "checker has been compiled"

$(PSWAP): $(PATHS_OBJ) $(OBJ_PSWAP)
	@make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) $(OBJ_PSWAP) -I $(PATH_INC) $(INC_LIB) -o $(PSWAP)
	@echo "push_swap has been compiled"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -I $(PATH_INC) -I $(PATH_INC_LIB) -c $< -o $@

$(PATHS_OBJ):
	@mkdir $(PATHS_OBJ)
