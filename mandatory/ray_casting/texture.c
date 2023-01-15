/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:38:51 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/15 17:41:53 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	int				color;
	t_display		*d;

	d = data->render.display;
	d->addr = mlx_get_data_addr(texture, &d->bpp,
			&d->l_length, &d->endian);
	color = (data->render.texx * 4) + (TEX_HEIGHT * 4 * texy);
	if (color < 0)
	{
		color = data->id.ceiling;
		return (color);
	}
	color = 0;
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

void	init_images(t_data *data)
{
	int	w;
	int	h;

	data->imgs.no = mlx_xpm_file_to_image(data->mlx, data->id.no, &w, &h);
	/* if (w != TEX_WIDTH || h != TEX_HEIGHT) */
	/* 	ft_error_free_close(data, "Wrong xpm size"); */
	data->imgs.so = mlx_xpm_file_to_image(data->mlx, data->id.so, &w, &h);
	/* if (w != TEX_WIDTH || h != TEX_HEIGHT) */
	/* 	ft_error_free_close(data, "Wrong xpm size"); */
	data->imgs.we = mlx_xpm_file_to_image(data->mlx, data->id.we, &w, &h);
	/* if (w != TEX_WIDTH || h != TEX_HEIGHT) */
	/* 	ft_error_free_close(data, "Wrong xpm size"); */
	data->imgs.ea = mlx_xpm_file_to_image(data->mlx, data->id.ea, &w, &h);
	/* if (w != TEX_WIDTH || h != TEX_HEIGHT) */
	/* 	ft_error_free_close(data, "Wrong xpm size"); */
}
