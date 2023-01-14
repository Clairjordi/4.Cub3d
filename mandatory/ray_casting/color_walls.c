/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:27:26 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/14 14:27:46 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	color_walls(t_data *data, int x)
{
	int	start;
	int	end;
	int	color;

	start = data->render.drawstart;
	end = data->render.drawend;
	if (data->ray.side == 0)
	{
		if (data->ray.raydirx > 0)
			color = 0x0C91787;
		else if (data->ray.raydirx < 0)
			color = 0x055BE11;
	}
	else if (data->ray.side == 1)
	{
		if (data->ray.raydiry < 0)
			color = 0x01218DE;
		else if (data->ray.raydiry > 0)
			color = 0x0F27F0D;
	}
	while (start <= end)
	{
		my_mlx_pixel_put(&data->display, x, start, color);
		start ++;
	}
}
