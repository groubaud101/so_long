/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:11:37 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 15:53:05 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "mlx.h"
# include <stddef.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_colors.h"

# define LINE_NOT_ONLY_WALL 0
# define MAP_NOT_FOUND 1
# define NOT_BER 2
# define NO_MAP 3
# define NOT_START_WALL 4
# define NOT_END_WALL 5
# define WRONG_CHR 6
# define MISSING_PEC 7
# define FAIL_OPEN 8
# define NOT_RECTANGULAR 9
# define EMPTY_LINE 10
# define ERR_MALLOC 11
# define FAIL_MLX_PTR 12
# define FAIL_MLX_WIN 13
# define FAIL_MLX_IMG 14

# define CHECK_ERR 0
# define CHECK_OK 1

# define SET_CHAR "01EPC"
# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define PLAYER 'P'
# define COLECT 'C'

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}t_map;

typedef struct s_wall_data
{
	int	len_x;
	int	len_y;
	int	size;
}
t_wall_data;

typedef struct s_floor_data
{
	int	len;
	int	size;
	int	i;
	int	j;
	int	color1;
	int	color2;
	int	design[7][7];
}
t_floor_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_mlx;

typedef struct s_so_long
{
	int		x_win;
	int		y_win;
	int		x_map;
	int		y_map;
	char	**map;
}t_so_long;

void	*ft_free_list_map(t_map **start, int num_err);
char	**ft_init_map(char *path);

t_map	*ft_create_lstmap(int fd);

int		ft_check_path(char *path);
int		ft_check_first_and_last_line(char *line);
int		ft_check_correct_line(char *set, char *line);
int		ft_check_enough_object(t_map *ptr, int *nb_line);
int		ft_map_err_msg(int num_err);

// ft_mlx_pixel_put.c
void	ft_mlx_pixel_put(t_mlx *data, int x, int y, int color);

// ft_geometric_figure.c
void	ft_rectangle(t_mlx *img, int start_x, int start_y,
					int len_x, int len_y, int color);

// ft_texture_wall.c
void	ft_texture_wall(t_mlx *img, int start_x, int start_y, int half);

// ft_texture_floor.c
void	ft_texture_floor(t_mlx *img, int start_x, int start_y);

// ft_foreground_layer.c
void	ft_foreground_layer(int wall_start_x, int wall_start_y,
							t_so_long *ptr, t_mlx *img);

// ft_so_long.c
int		ft_so_long(t_so_long *ptr);



#endif