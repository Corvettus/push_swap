#include "libft.h"

int	ft_isnumber(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (i == 0)
			{
				i++;
				continue ;
			}
			else
				return (0);
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
