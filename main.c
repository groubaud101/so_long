/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:24:09 by user42            #+#    #+#             */
/*   Updated: 2021/10/19 18:02:20 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "ft_printf.h"
#include <stddef.h>

//mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title)
//mlx_clear_window  (void *mlx_ptr, void *win_ptr)
//mlx_destroy_window  (void *mlx_ptr, void *win_ptr)


int main(int ac, char **av)
{
	//void		*mlx_ptr;
	//void		*win_ptr;
	t_so_long	ptr;

	if (ac < 2)
	{
		ft_putstr("Error\nWhere is the map ?\n");
		return (1);
	}
	ptr.map = ft_init_map(av[1]);	
	if (ptr.map == NULL)
		return (1);
	ft_puttab(ptr.map, "\n");
/*
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (ft_printf_fd(2, "mlx_init fails to connect\n"));

	win_ptr = mlx_new_window(mlx_ptr, 100, 100, "test");	
	if (win_ptr == NULL)
		return (ft_printf_fd(2, "mlx_new_win fails to connect\n"));
	mlx_loop(mlx_ptr);
*/
	ft_printf("OK map\n");
	return (0);
}
