/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:37:36 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 14:44:00 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_final(t_stack *s1, t_duo duo)
{
	int i;
	int position;

	i = 0;
	while (i < s1->size)
	{
		if (s1->data[i] == duo.max)
			position = i;
		i++;
	}
	if (position <= s1->size / 2)
		while (s1->data[0] != duo.max)
			ft_rra(s1, 1);
	else
		while (s1->data[0] != duo.max)
			ft_ra(s1, 1);
}

int		ft_check_sort(t_stack s)
{
	int	i;
	int	fl;

	i = 0;
	fl = 0;
	while (i < s.size - 1)
	{
		if (s.data[i] > s.data[i + 1])
			i++;
		else
		{
			fl = 1;
			i++;
		}
	}
	return (fl);
}

void	push_concrete(t_stack *s1, t_stack *s2, int i)
{
	int k;

	k = 0;
	if (i <= s1->size / 2)
	{
		while (k++ < i)
			ft_rra(s1, 1);
	}
	else
	{
		while (k++ < s1->size - i)
		{
			ft_ra(s1, 1);
		}
	}
	ft_pb(s1, s2, 1);
}

t_duo	find_min_max(t_stack *s1)
{
	t_duo	params;
	int		i;
	int		fl;

	fl = 0;
	i = 0;
	params.min = s1->data[0];
	params.max = s1->data[0];
	while (i++ < s1->size - 1)
	{
		if (s1->data[i] < params.min)
			params.min = s1->data[i];
		if (s1->data[i] > params.max)
			params.max = s1->data[i];
	}
	return (params);
}
