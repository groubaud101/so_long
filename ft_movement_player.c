/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:28:07 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/10 20:38:47 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int		ft_recreate_img(t_mlx *mlx, t_so_long *ptr)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000);
	if (mlx->img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));
	//mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);

	ft_foreground_layer(10, 10, ptr, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (CHECK_OK);
}

int	ft_movement_player(int keycode, t_so_long *ptr)
{
	int		origin;

	origin = ptr->y_player + ptr->x_player;

	ptr->map[ptr->y_player][ptr->x_player] = FLOOR;

	if (keycode == W && ptr->map[ptr->y_player - 1][ptr->x_player] != WALL)
			ptr->y_player--;
	else if (keycode == A
		&& ptr->map[ptr->y_player][ptr->x_player - 1] != WALL)
			ptr->x_player--;
	else if (keycode == S
		&& ptr->map[ptr->y_player + 1][ptr->x_player] != WALL)
			ptr->y_player++;
	else if (keycode == D
		&& ptr->map[ptr->y_player][ptr->x_player + 1] != WALL)
			ptr->x_player++;

	ptr->map[ptr->y_player][ptr->x_player] = PLAYER;

	if (ft_recreate_img(&ptr->mlx, ptr) == CHECK_ERR)
		exit (0); // a changer, faut free et tout

	if (origin != ptr->y_player + ptr->x_player)
		ft_printf("You have made %i moves\n", ++ptr->nb_moves);
	return (1);
}