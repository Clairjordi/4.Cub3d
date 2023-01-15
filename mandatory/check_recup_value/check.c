/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:14 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/15 10:12:30 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_valid_char(t_data *data, char c, int y, int x)
{
	if (c != ' ' && c != '0' && c != '1' && c != 'W'
		&& c != 'N' && c != 'S' && c != 'E')
		ft_error_free(data, "Map can only contain 1, 0, N, S, E, W");
	else if (c == 'W' || c == 'N' || c == 'S' || c == 'E')
	{
		if (data->player.start != 'O')
			ft_error_free(data, "Only one start possible");
		else
		{
			data->player.start = c;
			data->player.px = x + 0.5;
			data->player.py = y + 0.5;
		}
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
			check_valid_char(data, data->file_split[i][j], i, j);
			j++;
		}
		if (col < j)
			col = j;
		i++;
	}
	data->map.columns = col;
	data->map.lines = i - 6;
}

int	check_file_name(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '.')
		i++;
	if (i == 0 && str[i + 1] != '.')
		return (FALSE);
	else if (!ft_isalnum(str[i - 1]) && str[i + 1] != '.')
		return (FALSE);
	len = 0;
	while (str[i])
	{
		len++;
		i++;
	}
	if (!(ft_strnstr(str, ".cub", ft_strlen(str))))
		return (FALSE);
	else if (len < 4)
		return (FALSE);
	else if (str[i - 1] != 'b')
		return (FALSE);
	else
		return (TRUE);
}
