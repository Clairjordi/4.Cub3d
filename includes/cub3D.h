/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/19 11:02:34 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TRUE 0
# define FALSE 1
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/all_h.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

typedef struct s_map
{
	char	**matrix;
	int		start;
	int		columns;
	int		lines;
}	t_map;

typedef struct s_identifier
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}	t_id;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**file_split;
	int		px;
	int		py;
	t_id	id;
	t_map	map;
}	t_data;

/*Init*/
void		ft_init_struct(t_data *data);

//CHECK_RECUP_VALUE
/*Check*/
int			check_file_name(char *str);
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

/*Map*/
void		initialize_map(t_data *data, char *str);

/*recup_map*/
void		ft_recup_tab_file(t_data *data, char *arg);

//WINDOW
/*open_window*/
void		ft_open_window(t_data *data);
/*close_window*/
int			ft_close(t_data *data);
void		ft_close_window(t_data *data);
/*key_hook*/
int			key_hook(int keycode, t_data *data);
/*Utils*/

//FREE
/*free*/
void		ft_free_identifier(t_data *data);
void		ft_free_data(t_data *data);
void		ft_free_map(t_data *data);
void		ft_free(t_data *data);
/*exit*/
void		ft_error_free(t_data *data, char *str);

#endif
