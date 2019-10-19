#include "push_swap.h"

int	ft_rra(t_stack *s, int mode)
{
	int	x;
	int	y;
	int	i;

	if (s->size == 0)
		return (ft_err());
	i = 0;
	y = s->data[0];
	while (i < s->size - 1)
	{
		x = s->data[i];
		s->data[i] = s->data[i + 1];
		s->data[i + 1] = x;
		i++;
	}
	s->data[s->size - 1] = y;
	if (mode == 1)
		ft_putendl("rra");
	return (0);
}

int	ft_rrb(t_stack *s, int mode)
{
	int	x;
	int	y;
	int	i;

	if (s->size == 0)
		return (ft_err());
	i = 0;
	y = s->data[0];
	while (i < s->size - 1)
	{
		x = s->data[i];
		s->data[i] = s->data[i + 1];
		s->data[i + 1] = x;
		i++;
	}
	s->data[s->size - 1] = y;
	if (mode == 1)
		ft_putendl("rrb");
	return (0);
}

int	ft_rrr(t_stack *s1, t_stack *s2, int mode)
{
	ft_rra(s1, 0);
	ft_rrb(s2, 0);
	if (mode == 1)
		ft_putendl("rrr");
	return (0);
}