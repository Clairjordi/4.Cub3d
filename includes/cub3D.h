/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/15 18:49:47 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TRUE 0
# define FALSE 1
# define ERROR -1
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/all_h.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

typedef struct s_map
{
	char	**matrix;
	int		columns;
	int		lines;
}	t_map;

typedef struct s_player
{
	char	start;
	double	px;
	double	py;
}	t_player;

typedef struct s_view
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
}	t_view;

typedef struct s_ray
{
	double	sidedistx;
	double	sidedisty;
	double	deltax;
	double	deltay;
	double	raydirx;
	double	raydiry;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		side;
	int		hit;
	double	perpwalldist;
}	t_ray;

typedef struct s_identifier
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	int		floor;
	int		ceiling;
}	t_id;

typedef struct s_imgs
{
	void	*img;
	int		w;
	int		h;
}	t_imgs;

typedef struct s_display
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}	t_display;

typedef struct s_renders
{
	t_display	*display;
	int			drawend;
	int			drawstart;
	int			line_height;
	double		wallx;
	int			texx;
	double		texy;
}	t_render;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**file_split;
	t_imgs		tex;
	t_imgs		imgs[4];
	t_id		id;
	t_map		map;
	t_player	player;
	t_view		view;
	t_ray		ray;
	t_render	render;
	t_display	display;
}	t_data;

/*Init*/
void		ft_init_struct(t_data *data);
void		ft_init_display(t_display *display);
void		ft_init_view(t_data *data);

//CHECK_RECUP_VALUE
/*Check*/
void		check_valid_char(t_data *data, char c, int y, int x);
void		check_map(t_data *data);
int			check_file_name(char *str);
/*Check_recup_value*/
void		ft_recup_map(t_data *data);
void		ft_recup_color_f_c(t_data *data);
void		ft_pos_player(t_data *data);
void		ft_check_recup_value(t_data *data, char *av);
/*Check Walls*/
void		check_non_even_walls(t_data *data, int i);
void		check_up_down_walls(t_data *data, char **s, int *j);
void		check_side_walls(t_data *data, char **s, int *j);
void		check_walls(t_data *data);
/*Recup_identifier*/
void		ft_check_first_letter(t_data *data, char c);
void		ft_check_name_id(t_data *data, char *s);
void		ft_check_id_bottom_file(t_data *data);
void		ft_recup_identifier(t_data *data);
/*Recup_identifier_bis*/
void		ft_verif_ext_file_path(t_data *data, char c);
void		ft_add_path_id(t_data *data, char *id, char c);
void		ft_check_value_id_and_add(t_data *data, char *s, char c);
/*Recup_identifier_add_value*/
void		ft_add_id(t_data *data, char *id, char c);
/*Recup_file*/
int			check_file(t_data *data, char *s);
void		ft_recup_tab_file(t_data *data, char *arg);
/*Utils_id*/
char		*ft_charjoin(t_data *data, char *s1, char c);
/*Utils_id_bis*/
char		*ft_strdup_cub(t_data *data, char *s);
long long	ft_atoll_cub(t_data *data, char *nptr);

//RAY_CASTING
/*Init_ray*/
void		angle_from_position(t_data *data);
void		ft_sidedist(t_data *data);
/*Ray_casting*/
void		ft_dda(t_data *data);
void		ft_dda_bis(t_data *data);
void		castrays(t_data *data);
void		ft_create_walls(t_data *data, int x);
void		ft_ray_casting(t_data *data);
/*Texture*/
void		init_images(t_data *data);
void		ft_get_texture_x(t_data *data);
void		*ft_choose_texture(t_data *data);
int			ft_recup_rgb_pixel(t_data *data, void *texture, int texy);
void		ft_draw_line(t_data *data, void *texture, int x);

//WINDOW
/*Open_window*/
void		my_mlx_pixel_put(t_display *display, int x, int y, int color);
void		color_background(t_data *data);
void		ft_open_window(t_data *data);
/*Close_window*/
void		ft_destroy_images(t_data *data);
int			ft_close(t_data *data);
void		ft_close_window(t_data *data);
/*Key_hook*/
void		plane_move(t_data *data, char c, double rot);
void		player_move_up_down(t_data *data, char c, double rot);
void		player_move_left_right(t_data *data, char c, double rot);
int			key_hook(int keycode, t_data *data);
/*Utils*/
int			create_rgb(int r, int g, int b);
int			ft_isspace(char c);

//FREE
/*Free*/
void		ft_free_identifier(t_data *data);
void		ft_free_data(t_data *data);
void		ft_free_map(t_data *data);
void		ft_free(t_data *data);
/*Exit*/
void		ft_error_free_close(t_data *data, char *str);
void		ft_error_free(t_data *data, char *str);

#endif
