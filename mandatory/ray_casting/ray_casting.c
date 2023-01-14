/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 14:36:43 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_pos_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.matrix[i])
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (data->map.matrix[i][j] == 'N' || data->map.matrix[i][j] == 'S'
				||data->map.matrix[i][j] == 'E'
				|| data->map.matrix[i][j] == 'W')
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

void	ft_dda_bis(t_data *data)
{
	while (data->ray.hit != 1)
	{
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
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltax;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltay;
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
}

void	ft_get_texture_x(t_data *data)
{
	if (data->ray.side == 0)
		data->render.wallx = data->player.py + data->ray.perpwalldist
			* data->ray.raydiry;
	else
		data->render.wallx = data->player.px + data->ray.perpwalldist
			* data->ray.raydirx;
	data->render.wallx -= floor(data->render.wallx);
	data->render.texx = (int)(data->render.wallx * (double)TEX_WIDTH);
	if ((data->ray.side == 0 && data->ray.raydirx > 0)
		|| (data->ray.side == 1 && data->ray.raydiry < 0))
		data->render.texx = TEX_WIDTH - data->render.texx - 1;
}

void	*ft_choose_texture(t_data *data)
{
	void	*tmp;

	tmp = NULL;
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		tmp = data->imgs.ea;
	if (data->ray.side == 0 && data->ray.raydirx < 0)
		tmp = data->imgs.we;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		tmp = data->imgs.no;
	if (data->ray.side == 1 && data->ray.raydiry > 0)
		tmp = data->imgs.so;
	return (tmp);
}

int	ft_recup_rgb_pixel(t_data *data, void *texture, int texy)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned int	color;
	t_display		*d;

	d = data->render.display;
	d->addr = mlx_get_data_addr(texture, &d->bpp,
			&d->l_length, &d->endian);
	b = d->addr[(data->render.texx * 4) + (TEX_HEIGHT * 4 * texy)];
	g = d->addr[(data->render.texx * 4) + (TEX_HEIGHT * 4 * texy + 1)];
	r = d->addr[(data->render.texx * 4) + (TEX_HEIGHT * 4 * texy + 2)];
	color = create_rgb(r, g, b);
	return (color);
}

void	ft_draw_line(t_data *data, void *texture, int x)
{
	int		i;
	double	step;
	int		color_pixel;

	i = data->render.drawstart;
	step = (double)TEX_HEIGHT / data->render.line_height;
	data->render.texy = (data->render.drawstart - SCREEN_HEIGHT * 0.5
			+ data->render.line_height * 0.5) * step;
	while (i < data->render.drawend)
	{
		color_pixel = ft_recup_rgb_pixel(data, texture, (int)data->render.texy);
		my_mlx_pixel_put(&data->display, x, i, color_pixel);
		data->render.texy += step;
		i++;
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
	ft_get_texture_x(data);
	texture = ft_choose_texture(data);
	ft_draw_line(data, texture, x);
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

void	init_images(t_data *data)
{
	int	width;
	int	height;

	data->imgs.no = mlx_xpm_file_to_image(data->mlx, data->id.no, &width, &height);
	if (!data->imgs.no)
		ft_error_free(data, "Malloc");
	data->imgs.so = mlx_xpm_file_to_image(data->mlx, data->id.so, &width, &height);
	data->imgs.we = mlx_xpm_file_to_image(data->mlx, data->id.we, &width, &height);
	data->imgs.ea = mlx_xpm_file_to_image(data->mlx, data->id.ea, &width, &height);
}

void	ft_ray_casting(t_data *data)
{
	ft_pos_player(data);
	angle_from_position(data);
	init_images(data);
	castrays(data);
}
