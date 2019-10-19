#include "push_swap.h"
#include "get_next_line.h"

static int	        ft_cmd_valid(char *line)
{
	if (ft_strnequ(line, "sa", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "ss", 3))
		return (1);
	else if (ft_strnequ(line, "pa", 3))
		return (1);
	else if (ft_strnequ(line, "pb", 3))
		return (1);
	else if (ft_strnequ(line, "ra", 3))
		return (1);
	else if (ft_strnequ(line, "rb", 3))
		return (1);
	else if (ft_strnequ(line, "rr", 3))
		return (1);
	else if (ft_strnequ(line, "rra", 4))
		return (1);
	else if (ft_strnequ(line, "rrb", 4))
		return (1);
	else if (ft_strnequ(line, "rrr", 4))
		return (1);
	else
		return (0);
}

static int	ft_cmd_ctrl(char *line, t_stack *s1, t_stack *s2)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(s1, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(s2, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(s1, s2, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(s2, s1, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(s1, s2, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(s1, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(s2, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(s1, s2, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(s1, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(s2, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(s1, s2, 0);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	t_stack	s1;
	t_stack	s2;

	ft_init(&s1, &s2);
	line = 0;
	if ((i = ft_input(argc, argv, &s1)) == 0)
		return (ft_err());
	else if (i == -1)
		return (0);
	i = s1.size - 1;
	while (get_next_line(0, &line))
	{
		if (!ft_cmd_valid(line))
			return (ft_free_end(&line));
		if (ft_cmd_ctrl(line, &s1, &s2) == 0)
			return (ft_err());
		free(line);
	}
	if (ft_ko(s1, s2) == 0)
		return (ft_print_ko());
	ft_putendl("OK");
	return (0);
}
