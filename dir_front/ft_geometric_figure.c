/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric_figure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:31:38 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 15:24:09 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_diamond(int x, int y, int size)
{
	int		half;

	half = size / 2;
	if (x != half && ((y < half && x > half - y && x < half + y)
			|| (y > half && x > y - (size / 2) && size + half - x > y)))
		return (CHECK_OK);
	return (CHECK_ERR);
}

void	ft_diamond(t_mlx *mlx, t_norm norm, int color)
{
	int	x;
	int	y;
	int	size;

	size = norm.len_x;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_check_diamond(x, y, size) == CHECK_OK)
				ft_mlx_pixel_put(mlx, x + norm.start_x, y + norm.start_y,
					color);
			x++;
		}
		y++;
	}
}

void	ft_rectangle(t_mlx *mlx, t_norm norm, int color)
{
	int	x;
	int	y;

	y = norm.start_y;
	while (y < norm.start_y + norm.len_y)
	{
		x = norm.start_x;
		while (x < norm.start_x + norm.len_x)
			ft_mlx_pixel_put(mlx, x++, y, color);
		y++;
	}
}
