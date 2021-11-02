/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curtman <cdapurif@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:31:50 by curtman           #+#    #+#             */
/*   Updated: 2021/11/02 14:04:25 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 128
# define WIDTH 1280
# define HEIGHT 720
# define PI 3.14159265
# define TWO_PI 6.28318530
# define MINIMAP_SCALE_FACTOR 0.2

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <stdbool.h>
# include <math.h>
# include <float.h>
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

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;

typedef struct s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	bool	was_hit_vertical;
	bool	facing_up;
	bool	facing_down;
	bool	facing_left;
	bool	facing_right;
	char	hit_content;
	bool	found_horz_wall_hit;
	float	horz_hit_x;
	float	horz_hit_y;
	char	horz_wall_content;
	bool	found_vert_wall_hit;
	float	vert_hit_x;
	float	vert_hit_y;
	char	vert_wall_content;
}				t_ray;

struct s_helper
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	x_check;
	float	y_check;
};

struct s_text_info
{
	int			top_pixel;
	int			bottom_pixel;
	int			text_offset_x;
	int			text_offset_y;
	t_texture	*text;
};

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
	char			**map;
	unsigned short	tile_size;
	int				map_num_rows;
	int				map_num_cols;
	float			fov;
	int				num_rays;
	int				width;
	int				height;
	int				x_limit;
	int				y_limit;
	float			dist_proj_plane;
	char			orientation;
	int				px;
	int				py;
	t_player		*player;
	t_ray			*rays;
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
void			parsing_error(char *line, t_info *info, char *error);
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
int				key_pressed(int key, void *param);
int				key_released(int key, void *param);
int				close_game(void *info);
void			quit_game(t_info *info);
int				loop_hook(void *info);
int				minimize_window(void *param);
void			display_background(t_info *info);
void			update(t_info *info);
void			render(t_info *info);
void			set_color(unsigned char color[4], unsigned char r, \
					unsigned char g, unsigned char b);
void			rect(t_info *info, int x, int y);
void			draw_rect(t_info *info, t_rect rect, unsigned char color[4]);
void			clear_image(t_info *info);
char			**create_strs_tab(t_info *info);
void			render_map(t_info *info);
void			render_rays(t_info *info);
void			render_player(t_info *info);
void			move_player(t_info *info);
t_ray			*init_rays(t_info *info);
void			cast_all_rays(t_info *info);
void			normalize_angle(float *angle);
float			find_horz_yintercept(t_info *info, int ray_id);
float			find_horz_xintercept(t_info *info, float angle, \
					float yintercept);
float			find_horz_ystep(t_info *info, int ray_id);
float			find_horz_xstep(t_info *info, int ray_id, float angle);
bool			is_wall(t_info *info, float x, float y);
char			map_content_at(t_info *info, float x, float y);
float			find_vert_xintercept(t_info *info, int ray_id);
float			find_vert_yintercept(t_info *info, float angle, \
					float xintercept);
float			find_vert_xstep(t_info *info, int ray_id);
float			find_vert_ystep(t_info *info, int ray_id, float angle);
float			distance_between_points(float x1, float y1, float x2, float y2);
void			set_ray_data(t_info *info, int id, float dist, int vertical);
int				find_max(t_info *info);
char			**create_map_matrix(t_info *info);
void			free_map(char **map);
void			generate_3d_proj(t_info *info);
int				find_wall_height(t_info *info, int x);
int				find_top_pixel(t_info *info, int wall_height);
int				find_bottom_pixel(t_info *info, int wall_height);
int				find_text_offset_x(t_info *info, t_texture *text, int x);
void			place_texture(t_info *info, struct s_text_info data, \
					int wall_height, int x);
t_texture		*find_good_texture(t_info *info, int x);
bool			is_inside_map(t_info *info, float x, float y);
void			draw_line(t_info *info, int i, float x0, float y0);
void			check_limits(t_info *info, char **map, int x, int y);
unsigned char	get_color(char *line, t_info *info, int i);

#endif
