/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:35:45 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 15:12:30 by groubaud         ###   ########.fr       */
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
	ft_memcpy(floor.design, &(int [7][7]){
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 0, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0}
	}, 7 * 7 * sizeof(int));
	return (floor);
}

static int	ft_set_color_floor(t_floor_data floor)
{
	int	color;

	color = floor.color1;
	if (floor.design[floor.i][floor.j] == 1)
		color = floor.color2;
	return (color);
}

void	ft_texture_floor(t_mlx *mlx, int start_x, int start_y)
{
	t_floor_data	floor;
	t_norm			norm;
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
			color = ft_set_color_floor(floor);
			norm = ft_set_norm_value(x, y, floor.len, floor.len);
			ft_rectangle(mlx, norm, color);
			x += floor.len;
			floor.j++;
		}
		floor.i++;
		y += floor.len;
	}
}
