# **************************************************************************** #
#                            PROGRAM CONFIGURATION                             #
# **************************************************************************** #
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# **************************************************************************** #
#                               DIRECTORY PATHS                                #
# **************************************************************************** #
SRC_DIR     = src/
OBJ_DIR     = obj/
INC_DIR     = include/
LIBFT_DIR   = libft/

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #
SRC_FILES   = main.c \
              stack_init.c \
              handle_errors.c \
              stack_utils.c \
			  init_a_to_b.c \
			  init_b_to_a.c \
			  commands_push.c \
			  commands_swap.c \
			  commands_rotate.c \
			  commands_rev_rotate.c \
			  sort_three.c \
			  sort_stacks.c \
			  rotate_stacks.c
# **************************************************************************** #
#                               DERIVED VARIABLES                              #
# **************************************************************************** #
OBJ_FILES   = $(SRC_FILES:.c=.o)
OBJS        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT       = $(LIBFT_DIR)libft.a
INCLUDES    = -I$(INC_DIR)

# **************************************************************************** #
#                                VISUAL OUTPUT                                 #
# **************************************************************************** #
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

# **************************************************************************** #
#                                 MAIN TARGETS                                 #
# **************************************************************************** #
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "$(GREEN)Building push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Done!$(RESET)"

clean:
	@echo "$(RED)[PUSHSWAP] Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)[PUSHSWAP] Cleaning everything...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

# **************************************************************************** #
#                               HELPER TARGETS                                 #
# **************************************************************************** #
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

# **************************************************************************** #
#                                PHONY TARGETS                                 #
# **************************************************************************** #
.PHONY: all clean fclean re
