/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:16:12 by user42            #+#    #+#             */
/*   Updated: 2021/10/22 13:37:55 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdlib.h>

static void	ft_lstdelone(t_map *lst)
{
	if (!lst)
		return ;
	free(lst->line);
	free(lst);
}

void	*ft_free_list_map(t_map **start, int num_err)
{
	t_map	*tmp;

	if (num_err >= 0)
		ft_map_err_msg(num_err);
	if (!start || !(*start))
		return (NULL);
	tmp = (*start)->next;
	while (tmp)
	{
		ft_lstdelone(*start);
		*start = tmp;
		tmp = tmp->next;
	}
	ft_lstdelone(*start);
	*start = NULL;
	return (NULL);
}