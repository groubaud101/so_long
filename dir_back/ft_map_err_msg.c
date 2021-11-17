/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_err_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:16:16 by groubaud          #+#    #+#             */
/*   Updated: 2021/11/17 12:40:00 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "libft.h"

static void	ft_format_map_msg(int num_err)
{
	if (num_err == LINE_NOT_ONLY_WALL)
		ft_putstr("The first and/or the last line is not only made of walls\n");
	else if (num_err == NOT_START_WALL)
		ft_putstr("A line doesn't start by a wall\n");
	else if (num_err == NOT_END_WALL)
		ft_putstr("A line doesn't end by a wall\n");
	else if (num_err == WRONG_CHR)
		ft_putstr("There is wrong character in this map\n");
	else if (num_err == MISSING_PEC)
		ft_putstr("The map must have at least one player/exit/collectible\n");
	else if (num_err == NOT_RECTANGULAR)
		ft_putstr("The map is not rectangular\n");
	else if (num_err == EMPTY_LINE)
		ft_putstr("There is an empty line in the file of the map\n");
}

static void	ft_error_mlx_msg(int num_err)
{
	if (num_err == FAIL_MLX_PTR)
		ft_putstr("Fail mlx init\n");
	else if (num_err == FAIL_MLX_WIN)
		ft_putstr("Failure to create the window with mlx\n");
	else if (num_err == FAIL_MLX_IMG)
		ft_putstr("Failure to create the image with mlx\n");
}

int	ft_map_err_msg(int num_err)
{
	ft_putstr("Error\n");
	ft_format_map_msg(num_err);
	ft_error_mlx_msg(num_err);
	if (num_err == MAP_NOT_FOUND)
		ft_putstr("Map not found\n");
	else if (num_err == NOT_BER)
		ft_putstr("The map's name doesn't end by a .ber\n");
	else if (num_err == NO_MAP)
		ft_putstr("There is nothing in this file\n");
	else if (num_err == FAIL_OPEN)
		ft_putstr("Couldn't open the file with the good right\n");
	else if (num_err == ERR_MALLOC)
		ft_putstr("Malloc or read fail\n");
	return (CHECK_ERR);
}
