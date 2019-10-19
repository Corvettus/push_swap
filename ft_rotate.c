#include "push_swap.h"

void	rotate_both(int *len_in, int *len_out, t_stack *s1, t_stack *s2)
{
	while (ft_abs(*len_out) > 0 && ft_abs(*len_in) > 0)
	{
		if (*len_out > 0)
			ft_rr(s1, s2, 1);
		else
			ft_rrr(s1, s2, 1);
		if (*len_out > 0)
		{
			(*len_out)--;
			(*len_in)--;
		}
		else
		{
			(*len_out)++;
			(*len_in)++;
		}
	}
}

void	rotate_one(int *len_in, int *len_out, t_stack *s1, t_stack *s2)
{
	if (ft_abs(*len_out) > 0)
	{
		if (*len_out > 0)
			while ((*len_out)-- > 0)
				ft_rb(s1, 1);
		else
			while ((*len_out)++ < 0)
				ft_rrb(s1, 1);
	}
	else
	{
		if (*len_in > 0)
			while ((*len_in)-- > 0)
				ft_ra(s2, 1);
		else
			while ((*len_in)++ < 0)
				ft_rra(s2, 1);
	}
}

void	rotate_one_alt(int *len_in, int *len_out,
t_stack *s1, t_stack *s2)
{
	if (*len_out > 0)
		while ((*len_out)-- > 0)
			ft_rb(s1, 1);
	else
		while ((*len_out)++ < 0)
			ft_rrb(s1, 1);
	if (*len_in > 0)
		while ((*len_in)-- > 0)
			ft_ra(s2, 1);
	else
		while ((*len_in)++ < 0)
			ft_rra(s2, 1);
}