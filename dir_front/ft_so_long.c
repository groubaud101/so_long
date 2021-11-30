/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:26:42 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/30 16:11:01 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_close(t_so_long *ptr)
{
	int	y;

	y = 0;
	while (ptr->map[y])
		free(ptr->map[y++]);
	free(ptr->map);
	mlx_destroy_image(ptr->mlx.mlx_ptr, ptr->mlx.img_ptr);
	mlx_destroy_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr);
	ft_printf("End of the game\n");
	exit(0);
}


int	ft_escape_hook(int keycode, t_so_long *ptr)
{
	if (keycode == 53)
		ft_close(ptr);
	return (1);
}

// temp, I use it to know the keycode
int	key_hook(int keycode, void *win_ptr)
{
	(void)win_ptr;
	
	ft_printf("keycode : %i\n", keycode);
	if (keycode == 53)
		exit(0);
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

	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	return (CHECK_OK);
}

int	ft_init_img_sprite(t_mlx *mlx, t_mlx *mlx_player, int x, int y)
{
	mlx_player->img_ptr = mlx_png_file_to_image(mlx->mlx_ptr, PLAYER_UP, &x, &y);
	if (mlx_player->img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));

	mlx_player->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
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
	ft_puttab(ptr->map, "\n");
	if (ft_init_mlx(&ptr->mlx, ptr->x_map, ptr->y_map) == CHECK_ERR)
		return (CHECK_ERR);
	int	x = 0;
	int	y = 0;

	if (ft_init_img_sprite(&ptr->mlx, &ptr->player.mlx_player, x, y) == CHECK_ERR)
		return (CHECK_ERR);

	ft_foreground_layer(0, 0, ptr, &ptr->mlx);

	mlx_put_image_to_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr, ptr->mlx.img_ptr, 0, 0);
	mlx_put_image_to_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr, ptr->player.mlx_player.img_ptr,
		ptr->player.x_player * 42 + 15, ptr->player.y_player * 42 + 13);

	//mlx_key_hook(mlx.win_ptr, key_hook, &mlx); // connaitre la touche
	mlx_hook(ptr->mlx.win_ptr, 2, 1L<<0, ft_key_hook, ptr);
	mlx_hook(ptr->mlx.win_ptr, 17, 1L<<17, ft_close, ptr);

	mlx_loop(ptr->mlx.mlx_ptr);

	return (CHECK_OK);
}
