/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:06:40 by user42            #+#    #+#             */
/*   Updated: 2021/12/05 15:51:49 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_path(char *path)
{
	int		len;
	int		i;
	char	*ber;

	ber = ".ber";
	len = ft_strlen(path);
	len = len - 4;
	if (len < 0)
		return (ft_map_err_msg(NOT_BER));
	i = 0;
	while (path[len])
	{
		if (path[len++] != ber[i++])
			return (ft_map_err_msg(NOT_BER));
	}
	return (CHECK_OK);
}

int	ft_check_first_and_last_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (ft_map_err_msg(NO_MAP));
	while (line[i])
	{
		if (line[i++] != WALL)
			return (ft_map_err_msg(LINE_NOT_ONLY_WALL));
	}
	return (CHECK_OK);
}

int	ft_check_correct_line(char *set, char *line)
{
	int	i;

	i = 0;
	if (line[0] != WALL)
		return (ft_map_err_msg(NOT_START_WALL));
	while (line[i + 1])
	{
		if (ft_isinstr(line[i++], set) == -1)
			return (ft_map_err_msg(WRONG_CHR));
	}
	if (line[i] != WALL)
		return (ft_map_err_msg(NOT_END_WALL));
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
			c += (ptr->line[i] == COLLECT);
			i++;
		}
		(*nb_line)++;
		ptr = ptr->next;
	}
	if (!p || !e || !c)
		return (ft_map_err_msg(MISSING_PEC));
	return (CHECK_OK);
}
