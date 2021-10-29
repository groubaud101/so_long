/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:41 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/29 15:50:55 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_wall_data	ft_init_wall_data(void)
{
	t_wall_data	wall;

	wall.len_x = 19;
	wall.len_y = 12;
	wall.size = 42;
	return (wall);
}

void	ft_texture_wall(t_mlx *mlx, int start_x, int start_y, int half)
{
	t_wall_data	wall;
	int			x;
	int			y;

	y = start_y;
	wall = ft_init_wall_data();
	ft_rectangle(mlx, start_x, start_y, wall.size, wall.size, WHITE);
	while (y + wall.len_y <= wall.size + start_y)
	{
		x = start_x;
		if (half % 2 == 1)
		{
			ft_rectangle(mlx, x, y, wall.len_x / 2, wall.len_y, BRICK);
			x += (wall.len_x / 2) + 2;
		}
		while (x + wall.len_x <= wall.size + start_x)
		{
			ft_rectangle(mlx, x, y, wall.len_x, wall.len_y, BRICK);
			x += wall.len_x + 2;
		}
		if (half % 2 == 1)
			ft_rectangle(mlx, x, y, wall.len_x / 2 + 1, wall.len_y, BRICK);
		y += wall.len_y + 2;
		half++;
	}
}