/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/07 11:47:07 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_valid_char(t_data *data, char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != 'W'
		&& c != 'N' && c != 'S' && c != 'E')
		ft_error_free(data, "Map can only contain 1, 0, N, S, E, W");
	else if (c == 'W' || c == 'N' || c == 'S' || c == 'E')
	{
		if (data->player.start != 'O')
			ft_error_free(data, "Only one start possible");
		else
			data->player.start = c;
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	col;

	i = 6;
	col = 0;
	while (data->file_split[i])
	{
		j = 0;
		while (data->file_split[i][j])
		{
			while (ft_isspace(data->file_split[i][j]) == 0)
				j++;
			check_valid_char(data, data->file_split[i][j]);
			j++;
		}
		if (col < j)
			col = j;
		i++;
	}
	data->map.columns = col;
	data->map.lines = i - 6;
	/* if (i != data->map.lines || j != data->map.columns) */
	/* 	ft_error_free(data, "Wrong map configuration"); */
}

int	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (i == 0 && str[i + 1] != '.')
		return (FALSE);
	if (!(ft_strnstr(str, ".cub", ft_strlen(str))))
		return (FALSE);
	else
		return (TRUE);
}
