/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:02:52 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 13:45:22 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_check_first_letter(t_data *data, char c)
{
	if (!(c == 'N' || c == 'S' || c == 'W' || c == 'E'
			|| c == 'F' || c == 'C'))
		ft_error_free(data, "Invalid Identifier");
}

void	ft_check_name_id(t_data *data, char *s)
{
	if (s[0] == 'N' && ft_strncmp("NO", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'S' && ft_strncmp("SO", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'W' && ft_strncmp("WE", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'E' && ft_strncmp("EA", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'S' && ft_strncmp("SO", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'F' && ft_isspace(s[1]) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'C' && ft_isspace(s[1]) != 0)
		ft_error_free(data, "Invalid name identifier");
}

void	ft_check_id_bottom_file(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->file_split[i + 1])
		i++;
	if (ft_isspace(data->file_split[i][0]) != 0
			&& data->file_split[i][0] != '1')
		ft_error_free(data, "Invalid map");
	if (data->file_split[i][0] == ' ')
	{
		while (data->file_split[i][j])
		{
			if (ft_isspace(data->file_split[i][j]) != 0
					&& data->file_split[i][j] != '1')
				ft_error_free(data, "Invalid map");
			j++;
		}
	}
}

void	ft_recup_identifier(t_data *data)
{
	int	i;

	i = 0;
	ft_check_id_bottom_file(data);
	while (i < 6)
	{
		ft_check_first_letter(data, data->file_split[i][0]);
		ft_check_name_id(data, data->file_split[i]);
		ft_check_value_id_and_add(data, data->file_split[i],
			data->file_split[i][0]);
		i++;
	}
}
