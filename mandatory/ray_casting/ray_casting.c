/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/12 10:59:52 by clorcery         ###   ########.fr       */
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
				data->player.px = j + 0.5;
				data->player.py = i + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
}

/* double	degree_to_radian(t_data *data) */
/* { */
/* 	double	radian; */
/*  */
/* 	radian = data->view.angle * RAD; */
/* 	return (radian); */
/* } */
/*  */
/* void	start_direction(t_data *data) */
/* { */
/*  	data->view.dirx = cos(degree_to_radian(data)); */
/*  	data->view.diry = sin(degree_to_radian(data)); */
/* 	data->view.planex = cos(((data->view.angle - 90) * RAD) * 0.66); */
/*  	data->view.planey = sin(((data->view.angle - 90) * RAD) * 0.66); */
/* } */


void	angle_from_position(t_data *data)
{
	if (data->player.start == 'N')
	{
		data->view.angle = 90;
		//start_direction(data);
		data->view.diry = -1;
		data->view.planex = 0.66;
	}
	else if (data->player.start == 'S')
	{
		data->view.angle = 270;
		//start_direction(data);
		data->view.diry = 1;
		data->view.planex = -0.66;
	}
	else if (data->player.start == 'E')
	{
		data->view.angle = 0;
		//start_direction(data);
		data->view.dirx = 1;
		data->view.planey = 0.66;
	}
	else if (data->player.start == 'W')
	{
		data->view.angle = 180;
		//start_direction(data);
		data->view.dirx = -1;
		data->view.planey = -0.66;
	}
}

/* void	set_fov(t_data *data) */
/* { */
/* 	int	pixel; */
/*  */
/* 	pixel = SCREEN_WIDTH; */
/* 	data->view.planex = cos(((data->view.angle - 90) * RAD) * 0.66); */
/* 	data->view.planey = sin(((data->view.angle - 90) * RAD) * 0.66); */
/*  */
/* 	while (pixel > 0) */
/* 	{ */
/* 		data->view.camerax = ((2 * pixel) / SCREEN_WIDTH) - 1; */
/* 		data->view.raydirx = data->view.dirx + data->view.planex * data->view.camerax; */
/* 		data->view.raydiry = data->view.diry + data->view.planey * data->view.camerax; */
/* 		pixel--; */
/* 	} */
/* 	printf("x = %f - y = %f\n", data->view.raydirx, data->view.raydiry ); */
/* 	//my_mlx_pixel_put(data, (int)data->player.raydirx, (int)data->player.raydiry, 0X00005EF7); */
/* } */

void	ft_sidedist(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.px - (double)data->ray.mapx) * data->ray.deltax;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = ((double)data->ray.mapx + 1 - data->player.px) * data->ray.deltax;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.py - (double)data->ray.mapy) * data->ray.deltay;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = ((double)data->ray.mapy + 1 - data->player.py) * data->ray.deltay;
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
	while (data->ray.hit != 1)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltax;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0; // WE
		}
		else
		{
			data->ray.sidedisty += data->ray.deltay;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1; // NS
		}
		if (data->map.matrix[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltax;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltay;
}

void	color_walls(t_data *data, int start, int end, int x)
{
	int	color;

	if (data->ray.side == 0) //WE
	{
		if (data->view.dirx == 1) //E
			color = 0x0C91787; //rose
		else
			color = 0x055BE11; //vert
	}
	else if (data->ray.side == 1) //NS
	{
		if (data->view.diry == -1) //N
			color = 0x01218DE; //bleu
		else
			color = 0x0F27F0D; //orange
	}
	while (start <= end)
	{
		my_mlx_pixel_put(data, x, start, color);
		start ++;
	}
}

void	ft_walls(t_data *data, int x)
{
	int	line_height;
	int	drawstart;
	int	drawend;
	
	line_height = (int)(SCREEN_HEIGHT / data->ray.perpwalldist);
	drawstart = SCREEN_HEIGHT * 0.5 - line_height * 0.5;
	if (drawstart < 0)
		drawstart = 0;
	drawend = SCREEN_HEIGHT * 0.5 + line_height * 0.5;
	if (drawend >= SCREEN_HEIGHT)
		drawend = SCREEN_HEIGHT - 1;
	color_walls(data, drawstart, drawend, x);
}

void	castrays(t_data *data)
{
	int x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		data->view.camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		if (SCREEN_WIDTH - 1 == x)
			data->view.camerax = 1;
		data->ray.raydirx = data->view.dirx + data->view.planex * data->view.camerax;
		data->ray.raydiry = data->view.diry + data->view.planey * data->view.camerax;
		ft_dda(data);
		ft_walls(data, x);
		x++;
	}
}

void	ft_ray_casting(t_data *data)
{
	ft_pos_player(data);
	angle_from_position(data);
	castrays(data);
	//start_direction(data);
	//set_fov(data);
}
