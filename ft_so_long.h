/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:11:37 by user42            #+#    #+#             */
/*   Updated: 2021/10/19 18:00:52 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <mlx.h>
# include <stddef.h>

# define LINE_NOT_ONLY_WALL 0
# define MAP_NOT_FOUND 1
# define NOT_BER 2
# define NO_MAP 3
# define NOT_START_WALL 4
# define NOT_END_WALL 5
# define WRONG_CHR 6
# define MISSING_PEC 7
# define FAIL_OPEN 8

# define CHECK_ERR 0
# define CHECK_OK 1

# define SET_CHAR "01EPC"
# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define PLAYER 'P'
# define COLECT 'C'

typedef struct	s_map
{
	char			*line;
	struct s_map	*next;
}t_map;

typedef struct	s_so_long
{
	int		x_win;
	int		y_win;
	int		x_pic;
	int		y_pic;
	int		x_map;
	int		y_map;
	char	**map;

}t_so_long;

t_map	*ft_free_list_map(t_map **start);
char	**ft_init_map(char *path);

t_map	*ft_create_lstmap(int fd);

int	ft_check_path(char *path);
int	ft_check_first_and_last_line(char *line);
int	ft_check_correct_line(char *set, char *line);
int	ft_check_enough_object(t_map *ptr, int *nb_line);
int	ft_map_err_msg(int num_err);

#endif