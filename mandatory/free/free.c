/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:25:19 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 15:32:13 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	if (data->mlx != NULL)
		free(data->mlx);
}

void	ft_free_display(t_data *data)
{
	if (data->render.display != NULL)
		free(data->render.display);
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
	ft_free_display(data);
	ft_free_data(data);
}
