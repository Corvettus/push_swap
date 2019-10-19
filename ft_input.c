#include "push_swap.h"


int	ft_check_dup(t_stack s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s.size)
	{
		j = 0;
		while (j < i)
		{
			if (s.data[i] == s.data[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		ft_line_in(char **argv, t_stack **s)
{
	char	**line;
	int		i;

	line = ft_strsplit(argv[1], ' ');
	i = 0;
	while (line[i] != NULL)
	{
		if (!(ft_isnumber(line[i]) || (line[i][0] == '-'
		&& ft_strcmp("-", line[i]) != 0)))
			return (0);
		if ((ft_atoi(line[i]) == -1 && ft_strcmp("-1", line[i]) != 0)
		|| (ft_atoi(line[i]) == 0 && ft_strcmp("0", line[i]) != 0))
			return (0);
		ft_push_rev(*s, ft_atoi(line[i]));
		i++;
	}
	return (1);
}

static int		ft_lines_in(char **argv, t_stack **s)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]) || (argv[i][0]
		== '-' && ft_strcmp("-", argv[i]) == 0))
			return (0);
		ft_push_rev(*s, ft_atoi(argv[i]));
		i++;
	}
	return (1);
}

int		ft_input(int argc, char **argv, t_stack *s)
{
	if (argc < 2)
		return (-1);
	if (argc == 2)
	{
		if (ft_line_in(argv, &s) == 0)
			return (0);
	}
	else
	{
		if (ft_lines_in(argv, &s) == 0)
			return (0);
	}
	if (ft_check_dup(*s) == 0)
		return (0);
	return (1);
}
