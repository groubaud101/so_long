/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:26:42 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/02 20:30:08 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_escape_hook(int keycode, t_so_long *ptr)
{
	if (keycode == 53)
		ft_close(ptr);
	return (1);
}

int	ft_init_mlx(t_mlx *mlx, int x, int y)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_PTR));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, x, y, "so_long");
	if (mlx->win_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_WIN));
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, x, y);
	if (mlx->img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	return (CHECK_OK);
}

int	ft_init_sprite(t_mlx *mlx, t_mlx *mlx_player, t_so_long *ptr)
{
	mlx_player->img_ptr = mlx_png_file_to_image(mlx->mlx_ptr, PLAYER_DOWN,
			&ptr->player.x, &ptr->player.y);
	if (mlx_player->img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));
	mlx_player->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	return (CHECK_OK);
}

int	ft_key_hook(int keycode, t_so_long *ptr)
{
	if (keycode == 53)
		ft_close(ptr);
	else
		ft_movement_player(keycode, ptr);
	return (1);
}

int	ft_so_long(t_so_long *ptr)
{
	ptr->nb_moves = 0;
	if (ft_init_mlx(&ptr->mlx, ptr->x_map, ptr->y_map) == CHECK_ERR)
		ft_close(ptr);
	if (ft_init_sprite(&ptr->mlx, &ptr->player.mlx_player, ptr) == CHECK_ERR)
		ft_close(ptr);
	ft_foreground_layer(0, 0, ptr, &ptr->mlx);
	mlx_put_image_to_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr,
		ptr->player.mlx_player.img_ptr, ptr->player.x_player * 42 + 15,
		ptr->player.y_player * 42 + 13);
	mlx_hook(ptr->mlx.win_ptr, 2, 1L << 0, ft_key_hook, ptr);
	mlx_hook(ptr->mlx.win_ptr, 17, 1L << 17, ft_close, ptr);
	mlx_loop(ptr->mlx.mlx_ptr);
	return (CHECK_OK);
}
