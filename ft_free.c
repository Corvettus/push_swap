/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:43:43 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/24 14:42:15 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_ret(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		free(line[i++]);
	free(line);
	return (0);
}

int		free_itoa(char **line, char *new, char **orig)
{
	int	i;

	i = 1;
	new = ft_itoa(ft_atoi(orig[i]));
	if (ft_strcmp(new, orig[i]) != 0)
	{
		i = 0;
		while (line[i] != NULL)
			free(line[i++]);
		free(line);
		free(new);
		return (0);
	}
	free(new);
	return (1);
}

int		free_ret_1(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		free(line[i++]);
	free(line);
	return (1);
}

int		free_new(char **orig, int i)
{
	char	*new;

	new = ft_itoa(ft_atoi(orig[i]));
	if (ft_strcmp(new, orig[i]) != 0)
	{
		free(new);
		return (0);
	}
	free(new);
	return (1);
}

int		ft_free_end(char **line)
{
	ft_putendl("Error");
	free(*line);
	return (0);
}
