/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/15 18:34:49 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_dda_bis(t_data *data)
{
	while (data->ray.hit != 1)
	{
		if (data->map.matrix[data->ray.mapy][data->ray.mapx] == '1')
		{
			data->ray.hit = 1;
			break ;
		}
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltax;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltay;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map.matrix[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
}

void	ft_dda(t_data *data)
{	
	data->ray.hit = 0;
	data->ray.side = -1;
	data->ray.mapx = (int)data->player.px;
	data->ray.mapy = (int)data->player.py;
	if (data->ray.raydirx == 0)
		data->ray.deltax = exp(30);
	else
		data->ray.deltax = fabs(1 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.deltay = exp(30);
	else
		data->ray.deltay = fabs(1 / data->ray.raydiry);
	ft_sidedist(data);
	ft_dda_bis(data);
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltax;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltay;
}

void	castrays(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		data->view.camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		if (SCREEN_WIDTH - 1 == x)
			data->view.camerax = 1;
		data->ray.raydirx = data->view.dirx + data->view.planex
			* data->view.camerax;
		data->ray.raydiry = data->view.diry + data->view.planey
			* data->view.camerax;
		ft_dda(data);
		ft_create_walls(data, x);
		x++;
	}
}

void	ft_create_walls(t_data *data, int x)
{
	void	*texture;

	data->render.line_height = SCREEN_HEIGHT / data->ray.perpwalldist;
	data->render.drawstart = SCREEN_HEIGHT * 0.5
		- data->render.line_height * 0.5;
	if (data->render.drawstart < 0)
		data->render.drawstart = 0;
	data->render.drawend = SCREEN_HEIGHT * 0.5 + data->render.line_height * 0.5;
	if (data->render.drawend >= SCREEN_HEIGHT)
		data->render.drawend = SCREEN_HEIGHT - 1;
	texture = ft_choose_texture(data);
	ft_get_texture_x(data);
	ft_draw_line(data, texture, x);
}

void	ft_ray_casting(t_data *data)
{
	angle_from_position(data);
	init_images(data);
	castrays(data);
}
