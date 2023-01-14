/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:43:51 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/14 14:44:19 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	angle_from_position(t_data *data)
{
	if (data->player.start == 'N')
	{
		data->view.diry = -1;
		data->view.planex = 0.66;
	}
	else if (data->player.start == 'S')
	{
		data->view.diry = 1;
		data->view.planex = -0.66;
	}
	else if (data->player.start == 'E')
	{
		data->view.dirx = 1;
		data->view.planey = 0.66;
	}
	else if (data->player.start == 'W')
	{
		data->view.dirx = -1;
		data->view.planey = -0.66;
	}
}

void	ft_sidedist(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.px - (double)data->ray.mapx)
			* data->ray.deltax;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = ((double)data->ray.mapx + 1 - data->player.px)
			* data->ray.deltax;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.py - (double)data->ray.mapy)
			* data->ray.deltay;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = ((double)data->ray.mapy + 1 - data->player.py)
			* data->ray.deltay;
	}
}
