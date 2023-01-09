/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/09 19:08:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* void	ft_pos_player(t_data *data) */
/* { */
/* 	int i; */
/* 	int	j; */
/*  */
/* 	i = 0; */
/* 	while (data->map.matrix[i]) */
/* 	{ */
/* 		j = 0; */
/* 		while (data->map.matrix[i][j]) */
/* 		{ */
/* 			if (data->map.matrix[i][j] == 'N' || data->map.matrix[i][j] == 'S' */
/* 					||data->map.matrix[i][j] == 'E' || data->map.matrix[i][j] == 'W') */
/* 			{ */
/* 				data->player.px = j; */
/* 				data->player.py = i; */
/* 				break ; */
/* 			} */
/* 			j++; */
/* 		} */
/* 		i++; */
/* 	} */
/* } */

double	degree_to_radian(t_data *data)
{
	double	radian;

	radian = data->view.angle * RAD;
	return (radian);
}

void	angle_from_position(t_data *data)
{
	if (data->player.start == 'N')
	{
		data->view.angle = 90;
	}
	else if (data->player.start == 'S')
	{
		data->view.angle = 270;
	}
	else if (data->player.start == 'E')
	{
		data->view.angle = 0;
	}
	else if (data->player.start == 'W')
	{
		data->view.angle = 180;
	}
}

void	start_direction(t_data *data)
{
	data->view.dirx = cos(degree_to_radian(data));
	data->view.diry = sin(degree_to_radian(data));
}

void	set_fov(t_data *data)
{
	int	pixel;

	pixel = SCREEN_WIDTH;
	data->view.planex = cos(((data->view.angle - 90) * RAD) * 0.66);
	data->view.planey = sin(((data->view.angle - 90) * RAD) * 0.66);

	while (pixel > 0)
	{
		data->view.camerax = ((2 * pixel) / SCREEN_WIDTH) - 1;
		data->view.raydirx = data->view.dirx + data->view.planex * data->view.camerax;
		data->view.raydiry = data->view.diry + data->view.planey * data->view.camerax;
		pixel--;
	}
	printf("x = %f - y = %f\n", data->view.raydirx, data->view.raydiry );
	//my_mlx_pixel_put(data, (int)data->player.raydirx, (int)data->player.raydiry, 0X00005EF7);
}

void	ft_ray_casting(t_data *data)
{
	angle_from_position(data);
	start_direction(data);
	set_fov(data);
}
