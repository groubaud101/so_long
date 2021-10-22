/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:03:35 by user42            #+#    #+#             */
/*   Updated: 2021/10/22 14:18:02 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

static char	**ft_tab_map(t_map *ptr, int nb_line)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(*tab) * (nb_line + 1));
	if (!tab)
		return (NULL);
	while (ptr)
	{
		tab[i] = ft_strdup(ptr->line);
		if (!tab[i])
			return (NULL);
		i++;
		ptr = ptr->next;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_init_map(char *path)
{
	int		fd;
	t_map	*map;
	char	**tab;
	int		nb_line;

	nb_line = 0;
	if (ft_check_path(path) == CHECK_ERR)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_map_err_msg(FAIL_OPEN);
		return (NULL);
	}
	map = ft_create_lstmap(fd);
	close (fd);
	if (!map)
		return (NULL);
	if (ft_check_enough_object(map, &nb_line) == CHECK_ERR)
		return (ft_free_list_map(&map, -1));
	tab = ft_tab_map(map, nb_line);
	ft_free_list_map(&map, -1);
	return (tab);
}
