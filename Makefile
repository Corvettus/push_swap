PUSH_SWAP = push_swap
CHECKER = checker

COMP = gcc

FLS =

LIB = ./libft

SRCS = ft_push_pop.c \
       ft_input.c \
	   ft_output.c \
	   ft_sp.c \
	   ft_r.c \
	   ft_rr.c \
	   ft_free.c \
	   ft_push.c \
	   ft_rotate.c

SRCS_PS = push_swap.c $(SRCS)

SRCS_CH = checker.c get_next_line.c $(SRCS)

OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):
	make -C libft
	$(COMP) $(FLS) -c $(SRCS_PS)
	$(COMP) $(FLS) -o $(PUSH_SWAP) $(OBJS_PS) -L $(LIB) -lft

$(CHECKER):
	make -C libft
	$(COMP) $(FLS) -c $(SRCS_CH)
	$(COMP) $(FLS) -o $(CHECKER) $(OBJS_CH) -L $(LIB) -lft

clean:
	make clean -C libft
	@/bin/rm -f $(OBJS_PS)
	@/bin/rm -f $(OBJS_CH)

fclean: clean
	make fclean -C libft
	@/bin/rm -f $(PUSH_SWAP)
	@/bin/rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re