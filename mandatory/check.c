/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:14 by mcloarec          #+#    #+#             */
/*   Updated: 2022/12/17 19:14:56 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_up_down_walls(t_data *data, char **s, int *j)
{
	while (ft_isspace((*s)[*j]) == 0)
		(*j)++;
	if ((*s)[*j] != '1')
		ft_error_free(data, "Map is not surrounded by walls");
	while ((*s)[*j])
	{
		while ((*s)[*j] == '1')
		{
			if (ft_isspace((*s)[*j]) != 0 && (*s)[*j] != '1')
				ft_error_free(data, "Map is not surrounded by walls");
			(*j)++;
		}
		if ((*s)[*j] != '\0' && (*s)[*j] != '0')
			(*j)++;
		else if ((*s)[*j] == '0')
			ft_error_free(data, "Map is not surrounded by walls");
	}
	if ((*s)[*j] != '\0')
		ft_error_free(data, "Map is not surrounded by walls");
}

void	check_side_walls(t_data *data, char **s, int *j)
{
	while (ft_isspace((*s)[*j]) == 0)
		(*j)++;
	if ((*s)[*j] != '1')
		ft_error_free(data, "Map is not surrounded by walls");
	(*j)++;
	while ((*s)[*j])
	{
		while ((*s)[*j] == '0' || (*s)[*j] == '1')
		{
			if ((*s)[*j] != '1' && (*s)[*j] != '0')
				ft_error_free(data, "Map is not surrounded by walls");
			else if ((*s)[*j] == '1' && (*s)[*j + 1] == '\0')
				break ;
			(*j)++;
		}
		if ((*s)[*j] != '\0')
			(*j)++;
	}
	if ((*s)[*j - 1] != '1' && (*s)[*j] != '\0')
		ft_error_free(data, "Map is not surrounded by walls");
}

/*ca marche pas sur la derniere ligne de la map test2*/

void	check_walls(t_data *data)
{
    int    i;
    int    j;

    i = 0;
    while (data->file_split[i])
    {
        j = 0;
        while (data->file_split[i][j])
        {
			if (i == 0)
				check_up_down_walls(data, &data->file_split[i], &j);
			else if (i != 0 && i != data->map.lines)
				check_side_walls(data, &data->file_split[i], &j);
			else if (i == data->map.lines)
				check_up_down_walls(data, &data->file_split[i], &j);
            j++;
        }
        i++;
    }
}

void check_valid_char(t_data *data, char c)
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

	/* if (data->id.no == NULL || data->id.so == NULL || data->id.we == NULL */
	/* 	|| data->id.ea == NULL || data->id.f == -1 || data->id.c == -1) */
	/* 	ft_error_free(data, "File content is wrong"); */
	i = 0;
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
	if (i != data->map.lines || j != data->map.columns)
		ft_error_free(data, "Wrong map configuration");
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
