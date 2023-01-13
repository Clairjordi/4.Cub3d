/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 14:01:34 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TRUE 0
# define FALSE 1
# define ERROR -1
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TEXTURE "../sprites_solong/item1.xpm"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
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
	double	angle;
	double	dirx;//représente la direction du joueur
	double	diry;
	double	planex;//représente le plan de la camera du joueur
	double	planey;
	double	camerax;
} t_view;

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
} t_ray;

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

typedef struct s_imgs //struct pour le tableau de textures
{
	void	*img; // chaque image
	int		width; // largeur utilise pour mlx_xpm_file_to_image
	int		height; // hauteur utilise pour mlx_xpm_file_to_image
/*variable a modifier*/	
	int		texdir; //direction NO, S, EA, WE de la texture
	double	wallx; //valeur où mur a été touché: coord y si side == 0, coord x si side == 1
	int		texx; // coordonnée x de la texture
	int		texy; // coordonée y de la texture
	double	step; // indique de combien augmenter les coord de la texture pour chaque pixel
	double	texpos; // coordonnée de départ
	// variables pour mlx_get_data_addr
	int		*addr; 
	int		bpp;
	int		l_length;
	int		endian;
	//
}	t_imgs;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			l_length;
	int			endian;
	char		*addr;
	char		**file_split;
	t_imgs		texture[4]; //tableau avec les 4 textures
	t_id		id;
	t_map		map;
	t_player	player;
	t_view		view;
	t_ray		ray;
}	t_data;


/*Init*/
void		ft_init_struct(t_data *data);

//CHECK_RECUP_VALUE
/*Check_recup_value*/
void		ft_check_recup_value(t_data *data, char *av);
void		ft_recup_map(t_data *data);
/*Check*/
int			check_file_name(char *str);
void		check_map(t_data *data);
void		check_valid_char(t_data *data, char c, int y, int x);
/*Check Walls*/
void		check_non_even_walls(t_data *data, int i);
void		check_up_down_walls(t_data *data, char **s, int *j);
void		check_side_walls(t_data *data, char **s, int *j);
void		check_walls(t_data *data);
/*recup_identifier*/
void		ft_check_first_letter(t_data *data, char c);
void		ft_check_name_id(t_data *data, char *s);
void		ft_check_id_bottom_file(t_data *data);
void		ft_recup_identifier(t_data *data);
/*recup_identifier_bis*/
void		ft_verif_ext_file_path(t_data *data, char c);
void		ft_add_path_id(t_data *data, char *id, char c);
void		ft_check_value_id_and_add(t_data *data, char *s, char c);
/*recup_identifier_add_value*/
void		ft_add_id(t_data *data, char *id, char c);
/*Utils_id*/
char		*ft_charjoin(t_data *data, char *s1, char c);
/*Utils_id_bis*/
char		*ft_strdup_cub(t_data *data, char *s);
long long	ft_atoll_cub(t_data *data, char *nptr);
/*recup_file*/
void		ft_recup_tab_file(t_data *data, char *arg);

//RAY_CASTING
/*ray_casting*/
void		ft_ray_casting(t_data *data);
void	castrays(t_data *data);

//WINDOW
/*open_window*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_open_window(t_data *data);
void    color_background(t_data *data);
/*close_window*/
int			ft_close(t_data *data);
void		ft_close_window(t_data *data);
/*key_hook*/
int			key_hook(int keycode, t_data *data);
/*Utils*/
int			ft_isspace(char c);

//FREE
/*free*/
void		ft_free_identifier(t_data *data);
void		ft_free_data(t_data *data);
void		ft_free_map(t_data *data);
void		ft_free(t_data *data);
/*exit*/
void		ft_error_free(t_data *data, char *str);

#endif
