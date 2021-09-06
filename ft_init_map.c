/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:03:35 by user42            #+#    #+#             */
/*   Updated: 2021/09/06 19:06:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_so_long.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_aff_list(t_map *ptr)
{
	int	i = 1;

	if (!ptr)
		ft_printf("ptr NULL\n");
	while (ptr)
	{
		ft_printf("line : %i |%s|\n", i++, ptr->line);
		ptr = ptr->next;
	}
}

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
	int		nb_line;
	t_map	*map;
	char	**tab;

	nb_line = 0;
	if (ft_check_path(path) == CHECK_ERR)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);

	ft_printf("LST map :\n");
	map = ft_create_lstmap(fd, &nb_line);
	ft_aff_list(map);
	if (!map || nb_line == 0)
	{
		close (fd);
		return (ft_free_list_map(&map));
	}
	ft_printf("TAB map :\n");
	tab = ft_tab_map(map, nb_line);
	if (!tab)
		return (ft_free_list_map(&map));
	ft_free_list_map(&map);
	return (tab);
}