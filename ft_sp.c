#include "push_swap.h"

int	ft_sa(t_stack *s, int mode)
{
	int	tmp;

	if (s->size == 0)
		return (ft_err());
	tmp = s->data[s->size - 1];
	s->data[s->size - 1] = s->data[s->size - 2];
	s->data[s->size - 2] = tmp;
	if (mode == 1)
		ft_putendl("sa");
	return (0);
}

int	ft_sb(t_stack *s, int mode)
{
	int	tmp;

	if (s->size == 0)
		return (ft_err());
	tmp = s->data[s->size - 1];
	s->data[s->size - 1] = s->data[s->size - 2];
	s->data[s->size - 2] = tmp;
	if (mode == 1)
		ft_putendl("sb");
	return (0);
}

int	ft_ss(t_stack *s1, t_stack *s2, int mode)
{
	int	tmp;

	if (s1->size == 0 || s2->size == 0)
		return (ft_err());
	tmp = s1->data[s1->size - 1];
	s1->data[s1->size - 1] = s1->data[s1->size - 2];
	s1->data[s1->size - 2] = tmp;
	tmp = s2->data[s2->size - 1];
	s2->data[s2->size - 1] = s2->data[s2->size - 2];
	s2->data[s2->size - 2] = tmp;
	if (mode == 1)
		ft_putendl("ss");
	return (0);
}

int	ft_pa(t_stack *s_send, t_stack *s_rec, int mode)
{
	int	tmp;

	if (s_send->size == 0)
		return (ft_err());
	if (s_send->size != 0)
	{
		tmp = s_send->data[s_send->size - 1];
		ft_push(s_rec, tmp);
		ft_pop(s_send);
	}
	if (mode == 1)
		ft_putendl("pa");
	return (0);
}

int	ft_pb(t_stack *s_send, t_stack *s_rec, int mode)
{
	int	tmp;

	if (s_send->size == 0)
		return (ft_err());
	if (s_send->size != 0)
	{
		tmp = s_send->data[s_send->size - 1];
		ft_push(s_rec, tmp);
		ft_pop(s_send);
	}
	if (mode == 1)
		ft_putendl("pb");
	return (0);
}
