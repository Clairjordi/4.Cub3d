/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:27:04 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/09 14:50:30 by mcloarec         ###   ########.fr       */
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

static void	ft_init_player(t_data *data)
{
	data->player.start = 'O';
	data->player.px = 0;
	data->player.py = 0;
	//data->fov = 0;
}

static void	ft_init_map(t_data *data)
{
	data->map.matrix = NULL;
	data->map.columns = -1;
	data->map.lines = -1;
	//data->map.vx = 0;
	//data->map.vy = 0;
}

static void	ft_init_data(t_data *data)
{
	data->file_split = NULL;
	data->addr = NULL;
	data->bpp = 0;
	data->l_length = 0;
	data->endian = 0;
}

void	ft_init_struct(t_data *data)
{
	ft_init_data(data);
	ft_init_map(data);
	ft_init_identifier(data);
	ft_init_player(data);
}
