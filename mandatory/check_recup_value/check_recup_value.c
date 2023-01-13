/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_recup_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:08:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 18:56:38 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*calcul du nombre de ligne pour le malloc char* de la map*/
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

/*recuperation de la map seule dans data->map.matrix*/
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

int	create_rgb(int r, int g, int b)
{
	int	tmp;

	tmp = (r << 16 | g << 8 | b);
	return (tmp);
}

/*recuperation de la couleur du sol et du plafond*/
void	ft_recup_color_f_c(t_data *data)
{
	data->id.floor = create_rgb(data->id.f[0], data->id.f[1], data->id.f[2]);
	data->id.ceiling = create_rgb(data->id.c[0], data->id.c[1], data->id.c[2]);
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
}
