/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:02:46 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/11 16:07:05 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_move_up(t_so_long *ptr)
{
	ptr->player.img_player = PLAYER_UP;
	if (ptr->map[ptr->player.y_player - 1][ptr->player.x_player] == WALL)
		return ;
	ptr->player.y_player--;
}

void	ft_move_down(t_so_long *ptr)
{
	ptr->player.img_player = PLAYER_DOWN;
	if (ptr->map[ptr->player.y_player + 1][ptr->player.x_player] == WALL)
		return ;
	ptr->player.y_player++;
}

void	ft_move_left(t_so_long *ptr)
{
	ptr->player.img_player = PLAYER_LEFT;
	if (ptr->map[ptr->player.y_player][ptr->player.x_player - 1] == WALL)
		return ;
	ptr->player.x_player--;
}

void	ft_move_right(t_so_long *ptr)
{
	ptr->player.img_player = PLAYER_RIGHT;
	if (ptr->map[ptr->player.y_player][ptr->player.x_player + 1] == WALL)
		return ;
	ptr->player.x_player++;
}
