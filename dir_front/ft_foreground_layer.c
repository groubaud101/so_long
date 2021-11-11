/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreground_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:25:17 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/11 16:10:24 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_foreground_layer(int start_x, int start_y,
							t_so_long *ptr, t_mlx *mlx)
{
	int	x;
	int	y;
	
	y = 0;
	while (ptr->map[y])
	{
		x = 0;
		while (ptr->map[y][x])
		{
			if (ptr->map[y][x] == '1')
				ft_texture_wall(mlx, start_x, start_y, 0);
			else if (ft_isinstr(ptr->map[y][x], SET_CHAR) >= 0)
				ft_texture_floor(mlx, start_x, start_y);
			if (ptr->map[y][x] == 'P')
			{
				ptr->player.y_player = y;
				ptr->player.x_player = x;
				ft_texture_player(mlx, start_x, start_y);
			}
			start_x += 42;
			x++;
		} 
		start_y += 42;
		start_x = 10;
		y++;
	}
}
