/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric_figure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:31:38 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/29 15:51:25 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_rectangle(t_mlx *mlx, int start_x, int start_y,
					int len_x, int len_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + len_y)
	{
		x = start_x;
		while (x < start_x + len_x)
			ft_mlx_pixel_put(mlx, x++, y, color);
		y++;
	}
}