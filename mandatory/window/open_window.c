/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:21:06 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/21 18:06:51 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_open_window(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->win = mlx_new_window(data->mlx, (data->map.columns * 64),
		(data->map.lines * 64), "Cub3D");
	data->img = mlx_new_image(data->mlx, (data->map.columns * 64),
		(data->map.lines * 64));
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
		&data->l_length, &data->endian);
	while (y <= (data->map.lines * 64 / 2))
	{
		x = 0;
		while (x <= data->map.columns * 64)
		{
			my_mlx_pixel_put(data, x, y, 0x00D995A0);
			x++;
		}
		y++;
	}
	while (y <= (data->map.lines * 64))
	{
		x = 0;
		while (x <= data->map.columns * 64)
		{
			my_mlx_pixel_put(data, x, y, 0x00FFF973);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	//init des images ici ? - pixel put dans une image puis afficher l'image car utilisation de
	//la fonction pixel put obligatoire
	 mlx_hook(data->win, 2, 1L << 0, key_hook, data);
}
