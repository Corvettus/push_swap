/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:43:56 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 14:42:26 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_stack *s1, t_stack *s2)
{
	s1->size = 0;
	s2->size = 0;
	s2->stack_num = 2;
	s1->stack_num = 1;
}

void	ft_push(t_stack *s, const int value)
{
	s->data[s->size] = value;
	s->size++;
}

void	ft_push_rev(t_stack *s, const int value)
{
	int	i;

	s->size++;
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = value;
}

int		ft_pop(t_stack *s)
{
	s->size--;
	return (s->data[s->size]);
}

int		ft_pop_n(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		ft_pop(s);
	return (s->data[s->size]);
}
