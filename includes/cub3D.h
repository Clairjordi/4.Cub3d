/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/17 17:56:56 by mcloarec         ###   ########.fr       */
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

typedef struct s_map
{
	char	**matrix;
	int		start;
	int		columns;
	int		lines;
}	t_map;

typedef struct s_player
{
	char	start;
}	t_player;

typedef struct s_identifier
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_id;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**file_split;
	t_id		id;
	t_map		map;
	t_player	player;
}	t_data;

/*Init*/
void	ft_init_struct(t_data *data);

/*Check*/
int		check_file_name(char *str);
void	check_map(t_data *data);
void	check_walls(t_data *data);

/*Map*/
void	initialize_map(t_data *data, char *str);

/*Recup_map*/
void	ft_recup_tab_file(t_data *data, char *arg);

/*Utils*/
int		ft_isspace(char c);

/*Exit*/
void	ft_free_map(t_data *data);
void	ft_free(t_data *data);
void	ft_error_free(t_data *data, char *str);

#endif
