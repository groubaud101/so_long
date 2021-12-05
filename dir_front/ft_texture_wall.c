/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:41 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 15:27:10 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_wall_data	ft_init_wall_data(int start_x, int start_y)
{
	t_wall_data	wall;

	wall.len_x = 19;
	wall.len_y = 12;
	wall.size = 42;
	wall.start_x = start_x;
	wall.start_y = start_y;
	return (wall);
}

void	ft_texture_wall2(t_mlx *mlx, t_norm norm, t_wall_data wall, int half)
{
	while (wall.y + wall.len_y <= wall.size + wall.start_y)
	{
		wall.x = wall.start_x;
		if (half % 2 == 1)
		{
			norm = ft_set_norm_value(wall.x, wall.y, wall.len_x / 2,
					wall.len_y);
			ft_rectangle(mlx, norm, BRICK);
			wall.x += (wall.len_x / 2) + 2;
		}
		while (wall.x + wall.len_x <= wall.size + wall.start_x)
		{
			norm = ft_set_norm_value(wall.x, wall.y, wall.len_x, wall.len_y);
			ft_rectangle(mlx, norm, BRICK);
			wall.x += wall.len_x + 2;
		}
		if (half % 2 == 1)
		{
			norm = ft_set_norm_value(wall.x, wall.y, wall.len_x / 2 + 1,
					wall.len_y);
			ft_rectangle(mlx, norm, BRICK);
		}
		wall.y += wall.len_y + 2;
		half++;
	}
}

void	ft_texture_wall(t_mlx *mlx, int start_x, int start_y, int half)
{
	t_wall_data	wall;
	t_norm		norm;

	wall = ft_init_wall_data(start_x, start_y);
	wall.y = wall.start_y;
	norm = ft_set_norm_value(wall.start_x, wall.start_y, wall.size, wall.size);
	ft_rectangle(mlx, norm, WHITE);
	ft_texture_wall2(mlx, norm, wall, half);
}
