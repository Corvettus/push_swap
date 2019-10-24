/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:44:02 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 13:28:51 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_stack *s, int mode)
{
	int	x;
	int	y;
	int	i;

	if (s->size == 0)
		return (ft_err());
	i = s->size - 1;
	y = s->data[s->size - 1];
	while (i > 0)
	{
		x = s->data[i];
		s->data[i] = s->data[i - 1];
		s->data[i - 1] = x;
		i--;
	}
	s->data[0] = y;
	if (mode)
		ft_putendl("ra");
	return (0);
}

int	ft_rb(t_stack *s, int mode)
{
	int	x;
	int	y;
	int	i;

	if (s->size == 0)
		return (ft_err());
	i = s->size - 1;
	y = s->data[s->size - 1];
	while (i > 0)
	{
		x = s->data[i];
		s->data[i] = s->data[i - 1];
		s->data[i - 1] = x;
		i--;
	}
	s->data[0] = y;
	if (mode)
		ft_putendl("rb");
	return (0);
}

int	ft_rr(t_stack *s1, t_stack *s2, int mode)
{
	ft_ra(s1, 0);
	ft_rb(s2, 0);
	if (mode)
		ft_putendl("rr");
	return (0);
}
