/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_err_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:16:16 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/19 17:19:26 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "libft.h"

int	ft_map_err_msg(int num_err)
{
	ft_putstr("Error\n");
	if (num_err == LINE_NOT_ONLY_WALL)
		ft_putstr("The first and/or the last line is not only made of walls\n");
	else if (num_err == MAP_NOT_FOUND)
		ft_putstr("Map not found\n");
	else if (num_err == NOT_BER)
		ft_putstr("The map's name doesn't end by a .ber\n");
	else if (num_err == NO_MAP)
		ft_putstr("There is nothing in this file\n");
	else if (num_err == NOT_START_WALL)
		ft_putstr("A line doesn't start by a wall\n");
	else if (num_err == NOT_END_WALL)
		ft_putstr("A line doesn't end by a wall\n");
	else if (num_err == WRONG_CHR)
		ft_putstr("There is wrong character in this map\n");
	else if (num_err == MISSING_PEC)
		ft_putstr("The map must have at least one player/exit/collectible\n");
	else if (num_err == FAIL_OPEN)
		ft_putstr("Couldn't open the file with the good right\n");
	return (CHECK_ERR);
}