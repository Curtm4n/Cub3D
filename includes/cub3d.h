/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:31:50 by curtman           #+#    #+#             */
/*   Updated: 2021/10/01 00:15:14 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 128
# define WIDTH 800
# define HEIGHT 600

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <math.h>
# include <X11/Xlib.h>

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
}				t_rect;

typedef struct s_texture
{
	int		width;
	int		height;
	void	*texture;
	char	*data;
}				t_texture;

typedef struct s_info
{
	void			*mlx_ptr;
	void			*window_ptr;
	void			*image;
	char			*data;
	unsigned short	map_start;
	t_texture		*no_texture;
	t_texture		*so_texture;
	t_texture		*we_texture;
	t_texture		*ea_texture;
	unsigned char	ceil[4];
	unsigned char	floor[4];
	t_list			*map_ptr;
	char			orientation;
}				t_info;

t_info			*ft_parsing(char *map);
int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
int				check_line(char *str);
int				ft_is_good_mapchar(char *str);
int				find_pos(char *str, t_info *info, int ret);
int				correct_char(char c);
char			change_char(char c);
char			*ft_substr_free(char *s, int start, int len, int set);
char			*ft_strjoin_free(char *s1, char *s2, int free);
void			parsing_error(char *line, t_info *info);
void			free_info(t_info *info);
void			handle_map_line(char *line, t_info *info);
void			handle_info_line(char *line, t_info *info);
void			parsing_text(char *line, t_info *info);
void			parsing_color(char *line, t_info *info);
void			free_texture(void *mlx_ptr, t_texture *texture);
void			check_parsing(t_info *info);
void			check_map(t_info *info);
void			ff_check(t_info *info, int x, int y);
void			check_borders(t_info *info, char **map, int x, int y);
void			correct_map_char(char **map);
void			ft_launch_game(t_info *info);
t_texture		*get_texture(char *file, t_info *info);
int				my_key_hook(int key, void *param);
int				close_game(void *info);
void			quit_game(t_info *info);
int				loop_hook(void *info);
int				minimize_window(void *info);
void			display_background(t_info *info);
void			update(t_info *info);
void			set_color(unsigned char color[4], unsigned char r, \
					unsigned char g, unsigned char b);
void			rect(t_info *info, int x, int y);
void			draw_rect(t_info *info, t_rect rect, unsigned char color[4]);
void			clear_image(t_info *info);

#endif
