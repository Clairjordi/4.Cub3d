/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:21:06 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 14:12:12 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	color_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;

	while (y <= (SCREEN_HEIGHT / 2))
	{
		x = 0;
		while (x <= SCREEN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, data->id.ceiling); // rose : 0x00D995A0
			x++;
		}
		y++;
	}
	while (y <= SCREEN_HEIGHT)
	{
		x = 0;
		while (x <= SCREEN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, data->id.floor);// jaune : 0x00FFF973
			x++;
		}
		y++;
	}

}

void	ft_open_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH,
		SCREEN_HEIGHT, "Cub3D");
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
		&data->l_length, &data->endian);
	color_background(data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
}
