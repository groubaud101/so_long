/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:26:42 by groubaud          #+#    #+#             */
/*   Updated: 2021/10/26 16:58:07 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_so_long(t_so_long *ptr)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;

	ft_puttab(ptr->map, "\n");
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_PTR));

	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test");	
	if (win_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_WIN));

	img.img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	if (img.img_ptr == NULL)
		return (ft_map_err_msg(FAIL_MLX_IMG));

	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);


	ft_foreground_layer(10, 10, ptr, &img);

	// ft_player_layer
	// est ce que je créé une seconde image ?
	//   mais je crains que ca ecrase celle du dessous (fond noir ?)

	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx_ptr);

	return (CHECK_OK);
}
