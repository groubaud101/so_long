/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:36:42 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 14:49:40 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

// 3111
// 3     
// 344
// 3
// 3222

void	ft_texture_exit(t_mlx *mlx, int start_x, int start_y)
{
	t_norm	norm;

	norm = ft_set_norm_value(start_x + 15, start_y + 5, 15, 5);
	ft_rectangle(mlx, norm, RED);
	norm = ft_set_norm_value(start_x + 15, start_y + 30, 15, 5);
	ft_rectangle(mlx, norm, RED);
	norm = ft_set_norm_value(start_x + 10, start_y + 5, 5, 30);
	ft_rectangle(mlx, norm, RED);
	norm = ft_set_norm_value(start_x + 15, start_y + 18, 10, 5);
	ft_rectangle(mlx, norm, RED);
}
