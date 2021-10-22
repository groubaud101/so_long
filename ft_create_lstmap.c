/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lstmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:04:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/22 13:35:49 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "get_next_line.h"
#include "libft.h"


static int	ft_mapnew(int fd, t_map **tmp)
{
	t_map	*ptr;
	int		ret;

	ptr = (t_map *)malloc(sizeof(*ptr));
	if (!ptr)
		return (-1);
	ptr->line = NULL;
	ptr->next = NULL;
	ret = get_next_line(fd, &(ptr->line));
	if (ret == -1)
	{
		free(ptr);
		return (-1);
	}
	*tmp = ptr;
	return (ret);
}

static void	ft_lstadd_map(t_map **alst, t_map *new)
{
	t_map	*lst;

	if (!alst)
		return ;
	if (*alst)
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

t_map	*ft_create_lstmap(int fd)
{
	t_map	*new_list;
	t_map	*tmp;
	int		ret;
	int		len;
	int		prev_len;

	ret = ft_mapnew(fd, &new_list);
	if (ret == -1)
		return (NULL);
	if (ft_check_first_and_last_line(new_list->line) == CHECK_ERR)
		return (ft_free_list_map(&new_list, -1));

	prev_len = ft_strlen(new_list->line);
	tmp = new_list;
	while (ret > 0)
	{
		ret = ft_mapnew(fd, &tmp);
		if (ret == -1)
			return (ft_free_list_map(&new_list, ERR_MALLOC));

		ft_lstadd_map(&new_list, tmp);

		len = ft_strlen(tmp->line);
		if (len == 0)
			return (ft_free_list_map(&new_list, EMPTY_LINE));
		if (prev_len != len)
			return (ft_free_list_map(&new_list, NOT_RECTANGULAR));
		
		if (ft_check_correct_line(SET_CHAR, tmp->line) == CHECK_ERR)
			return (ft_free_list_map(&new_list, -1));
		prev_len = len;
	}
	tmp = new_list;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_check_first_and_last_line(tmp->line) == CHECK_ERR)
		return (ft_free_list_map(&new_list, -1));

	return (new_list);
}
