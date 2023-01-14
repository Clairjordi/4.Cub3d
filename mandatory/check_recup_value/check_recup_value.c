/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_recup_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:08:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 18:31:47 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	ft_size_map(char **map)
{
	int	i;
	int	size;

	i = 6;
	size = 0;
	while (map[i] != NULL)
	{
		size++;
		i++;
	}
	return (size);
}

void	ft_recup_map(t_data *data)
{
	int	i;
	int	j;
	int	size;

	i = 6;
	j = 0;
	size = ft_size_map(data->file_split);
	data->map.matrix = malloc(sizeof(char *) * (size + 1));
	while (data->file_split[i])
	{
		data->map.matrix[j] = ft_strdup(data->file_split[i]);
		i++;
		j++;
	}
	data->map.matrix[j] = NULL;
}

void	ft_recup_color_f_c(t_data *data)
{
	data->id.floor = create_rgb(data->id.f[0], data->id.f[1], data->id.f[2]);
	data->id.ceiling = create_rgb(data->id.c[0], data->id.c[1], data->id.c[2]);
}

void	ft_pos_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.matrix[i])
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (data->map.matrix[i][j] == 'N' || data->map.matrix[i][j] == 'S'
				||data->map.matrix[i][j] == 'E'
				|| data->map.matrix[i][j] == 'W')
			{
				data->player.px = j + 0.5;
				data->player.py = i + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_recup_value(t_data *data, char *av)
{
	ft_recup_tab_file(data, av);
	ft_recup_identifier(data);
	check_map(data);
	check_walls(data);
	if (data->player.start != 'W' && data->player.start != 'E'
		&& data->player.start != 'N' && data->player.start != 'S')
		ft_error_free(data, "Possible start only from N, S, W, E");
	ft_recup_map(data);
	ft_recup_color_f_c(data);
	ft_pos_player(data);
}
