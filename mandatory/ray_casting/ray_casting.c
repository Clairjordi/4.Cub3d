/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/11 12:01:53 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_pos_player(t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (data->map.matrix[i])
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (data->map.matrix[i][j] == 'N' || data->map.matrix[i][j] == 'S'
					||data->map.matrix[i][j] == 'E' || data->map.matrix[i][j] == 'W')
			{
				data->player.px = j;
				data->player.py = i;
				printf("px = %f py = %f\n", data->player.px, data->player.py);
				break ;
			}
			j++;
		}
		i++;
	}
}

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

void	ft_test(t_data *data)
{
	int dist_x;
	int	dist_y;
	int	distance;

	dist_x = data->player.px;
	dist_y = data->player.py;
	

	while (data->map.matrix[dist_y] != NULL)
	{
		
		if (data->map.matrix[dist_y][dist_x] == '1')
		{
			distance = dist_x - data->player.px; 
			printf("I found wall - distance = %d\n", distance);
			break ;
		}
		dist_x += 1;
	}
	/* int	nx; */
	/* int	ny; */
    /*  */
	/* nx = data->player.px + cos(45) - d; */

}

void	ft_ray_casting(t_data *data)
{
	ft_pos_player(data);
	angle_from_position(data);
	start_direction(data);
	set_fov(data);
}
