/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:02:46 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/30 19:16:06 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_move_up(t_so_long *ptr)
{
	ptr->player.path_img_player = PLAYER_UP;
	if (ptr->map[ptr->player.y_player - 1][ptr->player.x_player] == WALL)
		return (0);
	ptr->player.y_player--;
	return (1);
}

int	ft_move_down(t_so_long *ptr)
{
	ptr->player.path_img_player = PLAYER_DOWN;
	if (ptr->map[ptr->player.y_player + 1][ptr->player.x_player] == WALL)
		return (0);
	ptr->player.y_player++;
	return (1);
}

int	ft_move_left(t_so_long *ptr)
{
	ptr->player.path_img_player = PLAYER_LEFT;
	if (ptr->map[ptr->player.y_player][ptr->player.x_player - 1] == WALL)
		return (0);
	ptr->player.x_player--;
	return (1);
}

int	ft_move_right(t_so_long *ptr)
{
	ptr->player.path_img_player = PLAYER_RIGHT;
	if (ptr->map[ptr->player.y_player][ptr->player.x_player + 1] == WALL)
		return (0);
	ptr->player.x_player++;
	return (1);
}
