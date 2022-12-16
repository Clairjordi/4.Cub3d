/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:46:50 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/16 17:29:57 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TRUE 0
# define FALSE 1
# define ERROR -1

# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<stdio.h>
# include "../libft/all_h.h"

typedef struct s_map
{
	char	**matrix;
	int		start;
	int		columns;
	int		lines;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_data;

/*Init*/
void	init_map(t_data *data);

/*Check*/
int		check_file_name(char *str);

/*Map*/
void	initialize_map(t_data *data, char *str);

/*Utils*/
void	putstr_error(char *s);

#endif
