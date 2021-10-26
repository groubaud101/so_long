/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:35:45 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/26 17:10:12 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static t_floor_data	ft_init_floor_data(void)
{
	t_floor_data	floor;

	floor.len = 7;
	floor.size = 42;
	return (floor);
}

static int	the_other_one(int color, int color1, int color2)
{
	if (color == color1)
		color = color2;
	else
		color = color1;
	return (color);
}

void	ft_texture_floor(t_data *img, int start_x, int start_y, int half)
{
	t_floor_data	floor;
	int				x;
	int				y;
	int				color;

	y = start_y;
	floor = ft_init_floor_data();
	color = BLUE;
	while (y + floor.len <= floor.size + start_y)
	{
		x = start_x;
		color = the_other_one(color, BLUE, GREEN);
		while (x + floor.len <= floor.size + start_x)
		{
			color = the_other_one(color, BLUE, GREEN);
			ft_rectangle(img, x, y, floor.len, floor.len, color);
			x += floor.len;
		}
		y += floor.len;
		half++;
	}
}