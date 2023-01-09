/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:30:25 by mcloarec          #+#    #+#             */
/*   Updated: 2022/12/21 15:55:07 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	check_non_even_walls_bis(t_data *data, int i, int j)
{
	if ((i != 0 || i != data->map.lines + 5) && j > 0
		&& data->file_split[i][j] == '0'
		&& (data->file_split[i][j + 1] == '1'
				|| data->file_split[i][j - 1] == '1'))
	{
		if (ft_isspace(data->file_split[i + 1][j - 1]) == 0
				|| ft_isspace(data->file_split[i - 1][j - 1]) == 0)
			ft_error_free(data, "Map is not surrounded by walls");
		if ((ft_isspace(data->file_split[i + 1][j + 1]) == 0
			|| data->file_split[i + 1][j + 1] == '\0')
			|| ft_isspace(data->file_split[i - 1][j + 1]) == 0 ||
			data->file_split[i - 1][j + 1] == '\0')
			ft_error_free(data, "Map is not surrounded by walls");
	}
}

void	check_non_even_walls(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->file_split[i][j])
	{
		check_non_even_walls_bis(data, i, j);
		if ((i != 0 || i != data->map.lines + 5)
			&& data->file_split[i][j] == '0'
			&& data->file_split[i - 1][j] == 32)
			ft_error_free(data, "Map is not surrounded by walls");
		else if ((i != 0 || i != data->map.lines + 5)
			&& data->file_split[i][j] == '0'
			&& data->file_split[i + 1][j] == 32)
			ft_error_free(data, "Map is not surrounded by walls");
		else if (i == 0 || i == data->map.lines + 5)
			break ;
		j++;
	}
}

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
	if ((*s)[*j - 1] != '1' && (*s)[*j] == '\0')
		ft_error_free(data, "Map is not surrounded by walls");
}

void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 6;
	while (data->file_split[i])
	{
		j = 0;
		while (data->file_split[i][j])
		{
			check_non_even_walls(data, i);
			if (i == 6)
				check_up_down_walls(data, &data->file_split[i], &j);
			else if (i != 0 && i != (data->map.lines + 5))
				check_side_walls(data, &data->file_split[i], &j);
			else if (i == (data->map.lines + 5))
				check_up_down_walls(data, &data->file_split[i], &j);
			if (data->file_split[i][j] != '\0')
				j++;
		}
		i++;
	}
}
