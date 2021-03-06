/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:24:09 by user42            #+#    #+#             */
/*   Updated: 2021/12/05 14:39:55 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

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
