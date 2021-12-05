/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_data_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:14:09 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 14:14:11 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_set_player(int x, int y, t_so_long *ptr, int *yet_player)
{
	if (*yet_player == 0)
	{
		*yet_player = 1;
		ptr->player.x_player = x;
		ptr->player.y_player = y;
	}
	else
		ptr->map[y][x] = FLOOR;
}

void	ft_define_data_ptr(t_so_long *ptr)
{
	int	x;
	int	y;
	int	yet_player;

	y = -1;
	yet_player = 0;
	ptr->collectible = 0;
	while (ptr->map[++y])
	{
		x = -1;
		while (ptr->map[y][++x])
		{
			if (ptr->map[y][x] == COLLECT)
				ptr->collectible++;
			else if (ptr->map[y][x] == PLAYER)
				ft_set_player(x, y, ptr, &yet_player);
		}
	}
	ptr->x_map = x * 42;
	ptr->y_map = y * 42;
}
