/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:27:49 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 14:40:57 by groubaud         ###   ########.fr       */
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
	mlx_destroy_image(ptr->mlx.mlx_ptr, ptr->player.mlx_player.img_ptr);
	mlx_destroy_window(ptr->mlx.mlx_ptr, ptr->mlx.win_ptr);
	ft_printf("End of the game\n");
	exit(0);
}
