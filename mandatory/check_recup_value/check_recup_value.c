/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_recup_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:08:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 10:54:00 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*calcul du nombre de ligne pour le malloc char* de la map*/
int	ft_size_map(char **map)
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
}
