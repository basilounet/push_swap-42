MAIN = push_swap.c
BONUS_MAIN = checker.c
SRC = parse.c \
	struct_init.c \
	unleak.c \
	stack_a_instructions.c \
	stack_b_instructions.c \
	stack_shared_instructions.c \
	sort.c \
	get_extremes.c \
	move_stacks.c \
	utils.c
OBJS = $(SRC:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)
BONUS_MAIN_OBJ = $(BONUS_MAIN:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = $(LIBS) -fsanitize=address
NAME = push_swap
CHECKER = checker
LIBFT = libft/libft.a
LIBS := -Llibft -lft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MAIN_OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(MAIN_OBJ) $(OBJS) $(LDFLAGS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft --no-print-directory -j4

bonus : all $(CHECKER)

$(CHECKER) : $(OBJS) $(LIBFT) $(BONUS_MAIN_OBJ)
		$(CC) -o $(CHECKER) $(CFLAGS) $(BONUS_MAIN_OBJ) $(OBJS) $(LDFLAGS)

clean :
	@rm -rf $(OBJS)
	@rm -rf $(MAIN_OBJ)
	@rm -rf $(BONUS_MAIN_OBJ)
	@$(MAKE) -C libft clean --no-print-directory

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)
	@$(MAKE) -C libft fclean --no-print-directory
	@echo "Files cleaned"

re : fclean all

.PHONY : all bomus clean fclean re