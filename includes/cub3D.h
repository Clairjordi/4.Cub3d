/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/17 19:11:35 by clorcery         ###   ########.fr       */
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
	t_id	id;
	t_map	map;
}	t_data;

/*Init*/
void	ft_init_struct(t_data *data);

/*Check*/
int		check_file_name(char *str);

/*Map*/
void	initialize_map(t_data *data, char *str);

/*recup_map*/
void	ft_recup_tab_file(t_data *data, char *arg);

/*recup_identifier*/
void	ft_recup_identifier(t_data *data);

/*recup_identifier_bis*/
void    ft_add_id(t_data *data, char *id, char c);

/*Utils*/
char    *ft_strdup_cub(t_data *data, char *s);
long long	ft_atoll_cub(t_data *data, char *nptr);
char		*ft_charjoin(t_data *data, char *s1, char c);

/*exit*/
void	ft_free_map(t_data *data);
void	ft_free(t_data *data);
void	ft_error_free(t_data *data, char *str);

#endif
