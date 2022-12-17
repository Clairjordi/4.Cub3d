/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:52:58 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/17 15:36:10 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_free_identifier(t_data *data)
{
	if (data->id.no != NULL)
		free(data->id.no);
	if (data->id.so != NULL)
		free(data->id.so);
	if (data->id.we != NULL)
		free(data->id.we);
	if (data->id.ea != NULL)
		free(data->id.ea);
	if (data->id.f != NULL)
		free(data->id.f);
	if (data->id.c != NULL)
		free(data->id.c);
}

void	ft_free_data(t_data *data)
{
	if (data->file_split != NULL)
		ft_free_tab_char(data->file_split);
}

void	ft_free_map(t_data *data)
{
	if (data->map.matrix != NULL)
		ft_free_tab_char(data->map.matrix);
}

void	ft_free(t_data *data)
{
	ft_free_map(data);
	ft_free_identifier(data);
	ft_free_data(data);
}

void	ft_error_free(t_data *data, char *str)
{
	ft_free(data);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
