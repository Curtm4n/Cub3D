/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:31:50 by curtman           #+#    #+#             */
/*   Updated: 2021/08/05 16:45:51 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 128
# define WIDTH_MAX 1920
# define HEIGHT_MAX 1080

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <math.h>

typedef struct s_texture
{
	int		width;
	int		height;
	void	*texture;
	char	*data;
}				t_texture;

typedef struct s_info
{
	void			*mlx_tmp_ptr;
	void			*window_ptr;
	unsigned short	map_start;
	t_texture		*no_texture;
	t_texture		*so_texture;
	t_texture		*we_texture;
	t_texture		*ea_texture;
	t_texture		*sprite_texture;
	int				width;
	int				height;
	unsigned char	ceil[3];
	unsigned char	floor[3];
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
void			parsing_res(char *line, t_info *info);
void			parsing_text(char *line, t_info *info);
void			parsing_color(char *line, t_info *info);
void			free_texture(void *mlx_ptr, t_texture *texture);
void			check_parsing(t_info *info);
void			check_map(t_info *info);
void			ff_check(t_info *info, int x, int y);
void			check_borders(t_info *info, char **map, int x, int y);
void			correct_map_char(char **map);
void			ft_display(t_info *info);
t_texture		*get_texture(char *file, t_info *info);

#endif
