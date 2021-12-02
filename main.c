/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:24:09 by user42            #+#    #+#             */
/*   Updated: 2021/12/02 20:19:28 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_set_player(int x, int y, t_so_long *ptr, int *yet_player)
{
	if (*yet_player == 0)
	{
		*yet_player = 1;
		ptr->player.x_player = x;
		ptr->player.y_player = y;
	}
	else
		ptr->map[y][x] = FLOOR;
}

void	ft_define_data_ptr(t_so_long *ptr)
{
	int	x;
	int	y;
	int	yet_player;

	y = -1;
	yet_player = 0;
	ptr->collectible = 0;
	while (ptr->map[++y])
	{
		x = -1;
		while (ptr->map[y][++x])
		{
			if (ptr->map[y][x] == COLLECT)
				ptr->collectible++;
			else if (ptr->map[y][x] == PLAYER)
				ft_set_player(x, y, ptr, &yet_player);
		}
	}
	ptr->x_map = x * 42;
	ptr->y_map = y * 42;
}

int	main(int ac, char **av)
{
	t_so_long	ptr;

	if (ac < 2)
	{
		ft_putstr("Error\nWhere is the map ?\n");
		return (1);
	}
	ptr.map = ft_init_map(av[1]);
	if (ptr.map == NULL)
		return (1);
	ft_define_data_ptr(&ptr);
	ft_so_long(&ptr);
	return (0);
}
