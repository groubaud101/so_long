/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_norm_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:46:44 by groubaud          #+#    #+#             */
/*   Updated: 2021/12/05 15:06:57 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_norm	ft_set_norm_value(int start_x, int start_y, int len_x, int len_y)
{
	t_norm	norm;

	norm.start_x = start_x;
	norm.start_y = start_y;
	norm.len_x = len_x;
	norm.len_y = len_y;
	return (norm);
}
