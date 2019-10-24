/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:44:55 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 15:34:18 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define STACK_MAX_SIZE 10000
# define FD_MAX_NUM 4864
# define STACK_OVERFLOW  -100
# define STACK_UNDERFLOW -101

# include "./libft/libft.h"
# include "get_next_line.h"
# include <stdarg.h>

int				checker(int argc, char **argv);

typedef struct	s_duo
{
	int			max;
	int			min;
}				t_duo;

typedef struct	s_stack
{
	int			data[STACK_MAX_SIZE];
	size_t		size;
	int			stack_num;
}				t_stack;

typedef struct	s_params
{
	int			i;
	char		**line;
	int			k;
	int			fl;
	int			pos;
	t_stack		s1;
	t_stack		s2;
}				t_params;

int				ft_sa(t_stack *s, int mode);
int				ft_sb(t_stack *s, int mode);
int				ft_ss(t_stack *s1, t_stack *s2, int mode);

int				ft_pa(t_stack *s_send, t_stack *s_rec, int mode);
int				ft_pb(t_stack *s_send, t_stack *s_rec, int mode);

int				ft_ra(t_stack *s, int mode);
int				ft_rb(t_stack *s, int mode);
int				ft_rr(t_stack *s1, t_stack *s2, int mode);

int				ft_rra(t_stack *s, int mode);
int				ft_rrb(t_stack *s, int mode);
int				ft_rrr(t_stack *s1, t_stack *s2, int mode);

void			ft_init(t_stack *s1, t_stack *s2);
void			ft_push(t_stack *s, const int value);
void			ft_push_rev(t_stack *s, const int value);
int				ft_pop(t_stack *s);
int				ft_pop_n(t_stack *s, int n);
int				ft_peek(t_stack *s);

void			ft_print_stack(t_stack *s);
int				ft_ko(t_stack s1, t_stack s2);
int				ft_print_ko(void);
int				ft_free_end(char **line);
int				ft_err(void);

int				ft_input(int argc, char **argv, t_stack *s);

int				ft_check_dup(t_stack s);
int				ft_check_sort(t_stack s);

int				free_ret(char **line);
int				free_itoa(char **line, char *new, char **orig);
int				free_ret_1(char **line);
int				free_new(char **orig, int i);

void			push_back(t_stack *s2, t_stack *s1);
void			push_concrete(t_stack *s1, t_stack *s2, int i);
void			sort_final(t_stack *s1, t_duo duo);

void			rotate_both(int *len_in, int *len_out,
t_stack *s1, t_stack *s2);
void			rotate_one(int *len_in, int *len_out,
t_stack *s1, t_stack *s2);
void			rotate_one_alt(int *len_in, int *len_out,
t_stack *s1, t_stack *s2);

t_duo			find_min_max(t_stack *s1);

#endif
