/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreground_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:25:17 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/29 15:49:58 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_foreground_layer(int wall_start_x, int wall_start_y,
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
				ft_texture_wall(mlx, wall_start_x, wall_start_y, 0);
			else if (ft_isinstr(ptr->map[y][x], SET_CHAR) >= 0)
				ft_texture_floor(mlx, wall_start_x, wall_start_y);
			wall_start_x += 42;
			x++;
		} 
		wall_start_y += 42;
		wall_start_x = 10;
		y++;
	}
}
