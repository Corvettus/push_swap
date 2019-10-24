/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:43:59 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 14:36:48 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_out(t_stack *stack, int i)
{
	int	k;
	int	len_out;

	k = 0;
	if (i <= stack->size / 2)
		while (k++ < i)
			len_out = -k;
	else
	{
		while (k < stack->size - i + 1)
			k++;
		len_out = k - 1;
	}
	return (len_out);
}

static int	count_in(t_stack *stack_from, t_stack *stack_into, int i)
{
	int	fl;
	int	k;
	int	len_in;

	fl = 0;
	k = 0;
	while (fl == 0)
	{
		if (k == stack_from->size - 1)
		{
			fl = 1;
			k = -1;
		}
		else if (stack_into->data[i - 1] < stack_from->data[k]
		&& stack_into->data[i - 1] > stack_from->data[k + 1])
			fl = 1;
		k++;
	}
	if (k <= stack_from->size / 2)
		len_in = -k;
	else
		len_in = stack_from->size - k;
	return (len_in);
}

static int	count_concrete(t_stack *s1, t_stack *s2, int i)
{
	int	len_out;
	int	len_in;
	int	full_len;

	len_out = count_out(s1, i);
	len_in = count_in(s2, s1, i);
	if (len_out * len_in > 0)
	{
		if (ft_abs(len_out) > ft_abs(len_in))
			full_len = ft_abs(len_out);
		else
			full_len = ft_abs(len_in);
	}
	else
	{
		full_len = (ft_abs(len_out) + ft_abs(len_in));
	}
	return (full_len);
}

void		push_final(t_stack *s1, t_stack *s2, int i)
{
	int	len_out;
	int	len_in;

	len_out = count_out(s1, i);
	len_in = count_in(s2, s1, i);
	if (len_out * len_in > 0)
	{
		rotate_both(&len_in, &len_out, s1, s2);
		rotate_one(&len_in, &len_out, s1, s2);
	}
	else
		rotate_one_alt(&len_in, &len_out, s1, s2);
	ft_pa(s1, s2, 1);
}

void		push_back(t_stack *s2, t_stack *s1)
{
	int	i;
	int	min;
	int	k;
	int	position;

	while (s2->size)
	{
		i = 0;
		min = s2->size + s1->size;
		while (i < s2->size)
		{
			k = count_concrete(s2, s1, i + 1);
			if (k < min)
			{
				position = i + 1;
				min = k;
			}
			i++;
		}
		push_final(s2, s1, position);
	}
}
