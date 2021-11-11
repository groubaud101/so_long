/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:24:09 by user42            #+#    #+#             */
/*   Updated: 2021/11/11 17:33:13 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
//#include <stddef.h>

//mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title)
//mlx_clear_window  (void *mlx_ptr, void *win_ptr)
//mlx_destroy_window  (void *mlx_ptr, void *win_ptr)

void	ft_define_size_and_coord_player(t_so_long *ptr)
{
	int	x;
	int	y;
	int	yet_player;

	y = -1;
	yet_player = 0;
	while (ptr->map[++y])
	{
		x = -1;
		while (ptr->map[y][++x])
		{
			if (ptr->map[y][x] == PLAYER)
			{
				if (yet_player == 0)
					yet_player = 1;
				else
					ptr->map[y][x] = FLOOR;
			}
		}
	}
	ptr->x_map = x * 42;
	ptr->y_map = y * 42;
}

int main(int ac, char **av)
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

	ft_define_size_and_coord_player(&ptr);
	ft_printf("x_map : %i, y_map : %i\n", ptr.x_map, ptr.y_map);
	ft_so_long(&ptr);
	// free ptr.map
	ft_printf("OK map\n");
	return (0);
}
