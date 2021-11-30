/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:28:07 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/30 16:10:26 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static int		ft_recreate_img(t_mlx *mlx, t_mlx *mlx_player, t_so_long *ptr)
{
	int	x;
	int	y;

	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx_player->img_ptr);

	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, ptr->x_map, ptr->y_map);
	if (mlx->img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));

	mlx_player->img_ptr = mlx_png_file_to_image(mlx->mlx_ptr, ptr->player.path_img_player, &x, &y);
	if (mlx_player->img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));

	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	mlx_player->addr = mlx_get_data_addr(mlx_player->img_ptr, &mlx_player->bits_per_pixel, &mlx_player->line_length, &mlx_player->endian);

	ft_foreground_layer(0, 0, ptr, mlx);
	mlx_put_image_to_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr, ptr->mlx.img_ptr, 0, 0);
	mlx_put_image_to_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr, ptr->player.mlx_player.img_ptr,
		ptr->player.x_player * 42 + 15, ptr->player.y_player * 42 + 13);
	return (CHECK_OK);
}

int	ft_movement_player(int keycode, t_so_long *ptr)
{
	int		origin;

	origin = ptr->player.y_player + ptr->player.x_player;

	ptr->map[ptr->player.y_player][ptr->player.x_player] = FLOOR;

	if (keycode == W)
		ft_move_up(ptr);
	else if (keycode == A)
		ft_move_left(ptr);
	else if (keycode == S)
		ft_move_down(ptr);
	else if (keycode == D)
		ft_move_right(ptr);

	ptr->map[ptr->player.y_player][ptr->player.x_player] = PLAYER;

	if (ft_recreate_img(&ptr->mlx, &ptr->player.mlx_player, ptr) == CHECK_ERR)
		exit (0); // a changer, faut free et tout

	if (origin != ptr->player.y_player + ptr->player.x_player)
		ft_printf("You have made %i moves\n", ++ptr->nb_moves);
	return (1);
}