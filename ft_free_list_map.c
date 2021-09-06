/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:16:12 by user42            #+#    #+#             */
/*   Updated: 2021/09/06 19:19:13 by user42           ###   ########.fr       */
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

t_map	*ft_free_list_map(t_map **start)
{
	t_map	*tmp;

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