/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:35:45 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/09 18:18:06 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

// 111111
// 3     2
// 3     2
// 344444
// 3
// 3
// 3
// 3

void	ft_texture_player(t_mlx *mlx, int start_x, int start_y)
{
	// 1
	ft_rectangle(mlx, start_x + 10, start_y + 5, 20, 5, RED);

	// 2
	ft_rectangle(mlx, start_x + 30, start_y + 10, 5, 10, RED);

	// 3
	ft_rectangle(mlx, start_x + 10, start_y + 5, 5, 35, RED);

	// 4
	ft_rectangle(mlx, start_x + 10, start_y + 20, 20, 5, RED);
}