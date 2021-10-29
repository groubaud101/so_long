/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:35:45 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/29 15:50:24 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_floor_data	ft_init_floor_data(void)
{
	t_floor_data	floor;

	floor.len = 6;
	floor.size = 42;
	floor.i = 0;
	floor.j = 0;
	floor.color1 = GREEN;
	floor.color2 = BLUE;
	// floor.design[][] = {
	// 	{0, 0, 0, 1, 0, 0, 0},
	// 	{0, 0, 1, 0, 1, 0, 0},
	// 	{0, 1, 0, 1, 0, 1, 0},
	// 	{1, 0, 1, 0, 1, 0, 1},
	// 	{0, 1, 0, 1, 0, 1, 0},
	// 	{0, 0, 1, 0, 1, 0, 0},
	// 	{0, 0, 0, 1, 0, 0, 0}
	// 	};
	return (floor);
}

void	ft_texture_floor(t_mlx *mlx, int start_x, int start_y)
{
	t_floor_data	floor;
	static int		design[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
		};
	int				x;
	int				y;
	int				color;

	y = start_y;
	floor = ft_init_floor_data();

	while (floor.i < 7)
	{
		x = start_x;
		floor.j = 0;
		while (floor.j < 7)
		{
			color = floor.color1;
			if (design[floor.i][floor.j] == 1)
				color = floor.color2;
			ft_rectangle(mlx, x, y, floor.len, floor.len, color);
			x += floor.len;
			floor.j++;
		}
		floor.i++;
		y += floor.len;
	}




	// while (y + floor.len <= floor.size + start_y)
	// {
	// 	x = start_x;
	// 	floor.j = 0;
	// 	while (x + floor.len <= floor.size + start_x)
	// 	{
	// 		color = GREEN;
	// 		if (floor.design[floor.i][floor.j] == 0)
	// 			color = BLUE;
	// 		ft_rectangle(img, x, y, floor.len, floor.len, color);
	// 		x += floor.len;
	// 		floor.j++;
	// 	}
	// 	floor.i++;
	// 	y += floor.len;
	// }
}