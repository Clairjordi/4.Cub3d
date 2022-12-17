/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:27:04 by mcloarec          #+#    #+#             */
/*   Updated: 2022/12/17 11:05:11 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	ft_init_identifier(t_data *data)
{
	data->id.no = NULL;
	data->id.so = NULL;
	data->id.we = NULL;
	data->id.ea = NULL;
	data->id.f = NULL;
	data->id.c = NULL;
}

static void	ft_init_map(t_data *data)
{
	data->map.matrix = NULL;
	data->map.start = 0;
}

static void	ft_init_data(t_data *data)
{
	data->file_split = NULL;
}

void	ft_init_struct(t_data *data)
{
	ft_init_data(data);
	ft_init_map(data);
	ft_init_identifier(data);
}
