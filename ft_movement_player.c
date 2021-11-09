/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:28:07 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/09 19:07:44 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_movement(int keycode, t_so_long *ptr)
{
	t_mlx	*mlx;

	mlx = &ptr->mlx;
	ptr->map[ptr->y_player][ptr->x_player] = '0';
	if (keycode == W)
	{
		if (ptr->map[ptr->y_player - 1][ptr->x_player] != '1')
			ptr->y_player--;

		//mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		// mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
		// if (mlx->img_ptr == NULL)
		// 	return (ft_map_err_msg(FAIL_MLX_IMG));
		//mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);

	}
	else if (keycode == A)
	{
		if (ptr->map[ptr->y_player][ptr->x_player - 1] != '1')
			ptr->x_player--;
	}
	else if (keycode == S)
	{
		if (ptr->map[ptr->y_player + 1][ptr->x_player] != '1')
			ptr->y_player++;
	}
	else if (keycode == D)
	{
		if (ptr->map[ptr->y_player][ptr->x_player + 1] != '1')
			ptr->x_player++;
	}

	ptr->map[ptr->y_player][ptr->x_player] = 'P';

	ft_foreground_layer(10, 10, ptr, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (1);
}

void	ft_movement_player(t_so_long *ptr)
{
	mlx_hook(ptr->mlx.win_ptr, 2, 1L<<0, ft_movement, ptr);

}