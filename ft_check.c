/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:40 by user42            #+#    #+#             */
/*   Updated: 2021/09/07 19:26:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "libft.h"

int	ft_check_path(char *path)
{
	int	len;
	int	i;
	char *ber;

	ber = ".ber";
	len = ft_strlen(path);
	len = len - 4;
	i = 0;
	while (path[len])
	{
		if (path[len++] != ber[i++])
			return (CHECK_ERR);
	}
	return (CHECK_OK);
}

int	ft_check_first_and_last_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (CHECK_ERR);
	while (line[i])
	{
		if (line[i++] != WALL)
			return (CHECK_ERR);
	}
	return (CHECK_OK);
}

int	ft_check_correct_line(char *set, char *line)
{
	int	i;

	i = 0;
	if (line[0] != WALL)
		return (CHECK_ERR);
	while (line[i + 1])
	{
		if (ft_isinstr(line[i++], set) == -1)
			return (CHECK_ERR);
	}
	if (line[i] != WALL)
		return (CHECK_ERR);
	return (CHECK_OK);
}

int	ft_check_enough_object(t_map *ptr, int *nb_line)
{
	int	p;
	int	e;
	int	c;
	int	i;

	p = 0;
	e = 0;
	c = 0;
	while (ptr)
	{
		i = 0;
		while (ptr->line[i])
		{
			p += (ptr->line[i] == PLAYER);
			e += (ptr->line[i] == EXIT);
			c += (ptr->line[i] == COLECT);
			i++;
		}
		(*nb_line)++;
		ptr = ptr->next;
	}
	if (!p || !e || !c)
		return (CHECK_ERR);
	return (CHECK_OK);
}