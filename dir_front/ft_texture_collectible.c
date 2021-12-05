/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_collectible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:29:23 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 14:55:58 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_texture_collectible(t_mlx *mlx, int start_x, int start_y)
{
	t_norm	norm;

	norm = ft_set_norm_value(start_x + 11, start_y + 11, 20, 0);
	ft_diamond(mlx, norm, BLACK);
}
