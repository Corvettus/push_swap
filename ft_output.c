/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:43:53 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 14:42:31 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *s)
{
	int	i;

	i = 0;
	ft_putstr("stack ");
	ft_putnbr(s->stack_num);
	ft_putstr(" consists of ");
	ft_putnbr(s->size);
	if (s->size % 10 == 1)
		ft_putendl(" element");
	else
		ft_putendl(" elements");
	while (i < s->size)
	{
		ft_putnbr(s->data[s->size - i - 1]);
		if (i != s->size - 1)
			ft_putendl("");
		i++;
	}
	ft_putendl("");
}

int		ft_ko(t_stack s1, t_stack s2)
{
	int	i;

	i = s1.size - 1;
	if (s2.size != 0)
		return (0);
	while (i > 1)
	{
		if (s1.data[i] > s1.data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int		ft_print_ko(void)
{
	ft_putendl("KO");
	return (0);
}

int		ft_err(void)
{
	ft_putendl("Error");
	return (0);
}

int		ft_peek(t_stack *s)
{
	return (s->data[s->size - 1]);
}
