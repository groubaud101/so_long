/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:03:35 by user42            #+#    #+#             */
/*   Updated: 2021/10/22 09:12:42 by groubaud         ###   ########.fr       */
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

	ft_printf("LST map :\n");
	map = ft_create_lstmap(fd);
	close (fd);
	if (!map)
		return (NULL);
	if (ft_check_enough_object(map, &nb_line) == CHECK_ERR)
	{
		ft_free_list_map(&map);
		return (NULL);
	}

	ft_aff_list(map);

	if (!map)
		return (NULL);
	ft_printf("TAB map :\n");
	tab = ft_tab_map(map, nb_line); // pas besoin de verifier car pas utilisé av ret
	ft_free_list_map(&map);
	return (tab);
}