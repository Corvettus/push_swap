#include "push_swap.h"

static t_duo    find_min_max(t_stack *s1)
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

static void 	choose_elems(t_params *p, t_duo duo, t_stack stack, int min)
{
	if (p->fl == 0 && (stack.data[p->i] != duo.min
	&& stack.data[p->i] != duo.max))
		p->fl = stack.data[p->i];
	else if (stack.data[p->i] != duo.min && stack.data[p->i]
	!= duo.max && stack.data[p->i] != p->fl)
	{
		p->k = stack.size - p->i;
		if (p->k < min)
		{
			p->pos = p->i + 1;
			min = p->k;
		}
	}
	p->i++;
}

static void 	push_3_elems(t_stack *s1, t_stack *s2, t_duo duo)
{
	t_params	p;
	int			min;

	p.fl = 0;
	while (s1->size >= 4)
	{
		p.i = 0;
		min = s1->size;
		while (p.i < s1->size)
			choose_elems(&p, duo, *s1, min);
		push_concrete(s1, s2, p.pos);
	}
}

static void 	sort_3(t_stack *s1, t_duo duo)
{
	if ((s1->data[0] == duo.min && s1->data[2] == duo.max)
	|| (s1->data[1] == duo.min && s1->data[0] == duo.max) ||
	(s1->data[2] == duo.min && s1->data[1] == duo.max))
		ft_sa(s1, 1);
}

static void	    push_swap(t_stack *s1, t_stack *s2)
{
	t_duo		duo;
	int			mas[s1->size];
	int			len;

	duo = find_min_max(s1);
	push_3_elems(s1, s2, duo);
	sort_3(s1, duo);
	push_back(s2, s1);
	sort_final(s1, duo);
}

int	            main(int argc, char **argv)
{
	t_stack s1;
	t_stack s2;
	int		i;

	ft_init(&s1, &s2);
	i = 0;
	if ((i = ft_input(argc, argv, &s1)) == 0)
		return (ft_err());
	else if (i == -1)
		return (0);
	if (ft_check_sort(s1) == 0)
		return (0);
	if (ft_check_dup(s1) == 0)
		return (ft_err());
	push_swap(&s1, &s2);
	return (0);
}