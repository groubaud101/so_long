/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreground_layer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:25:17 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/02 20:20:41 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_choose_texture(char c, int start_x, int start_y, t_mlx *mlx)
{
	if (c == WALL)
		ft_texture_wall(mlx, start_x, start_y, 0);
	else if (ft_isinstr(c, SET_CHAR) >= 0)
	{
		ft_texture_floor(mlx, start_x, start_y);
		if (c == EXIT)
			ft_texture_exit(mlx, start_x, start_y);
		else if (c == COLLECT)
			ft_texture_collectible(mlx, start_x, start_y);
	}
}

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
			ft_choose_texture(ptr->map[y][x], start_x, start_y, mlx);
			start_x += 42;
			x++;
		}
		start_y += 42;
		start_x = 0;
		y++;
	}
	mlx_put_image_to_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr,
		ptr->mlx.img_ptr, 0, 0);
}
