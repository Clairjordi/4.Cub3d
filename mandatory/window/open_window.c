/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:21:06 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 14:23:12 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_display *display, int x, int y, int color)
{
	char	*dst;

	dst = display->addr + (y * display->l_length + x * (display->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	color_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (SCREEN_HEIGHT / 2))
	{
		x = 0;
		while (x <= SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&data->display, x, y, data->id.ceiling);
			x++;
		}
		y++;
	}
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x <= SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&data->display, x, y, data->id.floor);
			x++;
		}
		y++;
	}
}

void	ft_open_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	data->display.img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.l_length, &data->display.endian);
	color_background(data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
}
