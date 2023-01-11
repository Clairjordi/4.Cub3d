/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/11 09:32:19 by mcloarec         ###   ########.fr       */
=======
/*   Updated: 2023/01/09 19:07:42 by clorcery         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TRUE 0
# define FALSE 1
# define ERROR -1
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define RAD M_PI / 180

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
	bool		*wall;
	t_player	begin;
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
	double	raydirx;
	double	raydiry;
	double	fov;
} t_view;

typedef struct s_identifier
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}	t_id;

// typedef struct s_imgs
// {
// 	void		*img;
// 	int		*data;
// 	int		pp;
// 	int		l_length;
// 	int		endian;
// 	int		buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
// }	t_imgs;

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
	t_id		id;
	t_map		map;
	t_player	player;
	t_view		view;
}	t_data;


/*Init*/
void		ft_init_struct(t_data *data);

//CHECK_RECUP_VALUE
/*Check_recup_value*/
void	ft_check_recup_value(t_data *data, char *av);
void	ft_recup_map(t_data *data);
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

//WINDOW
/*open_window*/
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_open_window(t_data *data);
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
