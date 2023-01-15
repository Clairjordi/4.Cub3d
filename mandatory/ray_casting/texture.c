/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:38:51 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/15 18:48:03 by mcloarec         ###   ########.fr       */
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
	data->render.texx = (int)(data->render.wallx * (double)data->tex.w);
	if ((data->ray.side == 0 && data->ray.raydirx > 0)
		|| (data->ray.side == 1 && data->ray.raydiry < 0))
		data->render.texx = data->tex.w - data->render.texx - 1;
}

void	*ft_choose_texture(t_data *data)
{
	void	*tmp;

	tmp = NULL;
	if (data->ray.side == 0 && data->ray.raydirx > 0)
	{
		tmp = data->imgs[3].img;
		data->tex = data->imgs[3];
	}
	if (data->ray.side == 0 && data->ray.raydirx < 0)
	{
		tmp = data->imgs[2].img;
		data->tex = data->imgs[2];
	}
	if (data->ray.side == 1 && data->ray.raydiry < 0)
	{
		tmp = data->imgs[0].img;
		data->tex = data->imgs[0];
	}
	if (data->ray.side == 1 && data->ray.raydiry > 0)
	{
		tmp = data->imgs[1].img;
		data->tex = data->imgs[1];
	}
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
	color = (data->render.texx * 4) + (data->tex.h * 4 * texy);
	if (color < 0)
	{
		color = data->id.ceiling;
		return (color);
	}
	color = 0;
	b = d->addr[(data->render.texx * 4) + (data->tex.h * 4 * texy)];
	g = d->addr[(data->render.texx * 4) + (data->tex.h * 4 * texy + 1)];
	r = d->addr[(data->render.texx * 4) + (data->tex.h * 4 * texy + 2)];
	color = create_rgb(r, g, b);
	return (color);
}

void	ft_draw_line(t_data *data, void *texture, int x)
{
	int		i;
	double	step;
	int		color_pixel;

	i = data->render.drawstart;
	step = (double)data->tex.h / data->render.line_height;
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
	t_imgs	*d;

	d = data->imgs;
	d[0].img = mlx_xpm_file_to_image(data->mlx, data->id.no, &d[0].w, &d[0].h);
	if (!d[0].img)
		ft_error_free_close(data, "Failed init image");
	d[1].img = mlx_xpm_file_to_image(data->mlx, data->id.so, &d[1].w, &d[1].h);
	if (!d[1].img)
		ft_error_free_close(data, "Failed init image");
	d[2].img = mlx_xpm_file_to_image(data->mlx, data->id.we, &d[2].w, &d[2].h);
	if (!d[2].img)
		ft_error_free_close(data, "Failed init image");
	d[3].img = mlx_xpm_file_to_image(data->mlx, data->id.ea, &d[3].w, &d[3].h);
	if (!d[3].img)
		ft_error_free_close(data, "Failed init image");
}
