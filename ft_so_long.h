/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:11:37 by user42            #+#    #+#             */
/*   Updated: 2021/09/06 19:16:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <mlx.h>
# include <stddef.h>

# define CHECK_ERR 0
# define CHECK_OK 1

# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define PLAYER 'P'

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

int		ft_window(void);
void	*ft_free_list_map(t_map **start);
char	**ft_init_map(char *path);

int	ft_check_path(char *path);
int	ft_check_first_and_last_line(char *line);
int	ft_check_correct_line(char *set, char *line);

#endif