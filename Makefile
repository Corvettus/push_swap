PUSH_SWAP = push_swap
CHECKER = checker

COMP = gcc

FLS =

LIB_NAME = libft

LIB_DIR = ./libft

SRCS = ft_push_pop.c \
       ft_input.c \
	   ft_output.c \
	   ft_sp.c \
	   ft_r.c \
	   ft_rr.c \
	   ft_free.c \
	   ft_push.c \
	   ft_rotate.c \
	   ft_sort.c

SRCS_PS = push_swap.c $(SRCS)

SRCS_CH = checker.c get_next_line.c $(SRCS)

OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)

all: $(LIB_NAME) $(PUSH_SWAP) $(CHECKER)

$(LIB_NAME):
	@make -C $(LIB_NAME)

$(PUSH_SWAP):
	@$(COMP) $(FLS) -c $(SRCS_PS)
	@$(COMP) $(FLS) -o $(PUSH_SWAP) $(OBJS_PS) -L $(LIB_DIR) -lft

$(CHECKER):
	@$(COMP) $(FLS) -c $(SRCS_CH)
	@$(COMP) $(FLS) -o $(CHECKER) $(OBJS_CH) -L $(LIB_DIR) -lft

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS_PS)
	@/bin/rm -f $(OBJS_CH)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(PUSH_SWAP)
	@/bin/rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re $(PUSH_SWAP) $(CHECKER) $(LIB_NAME)