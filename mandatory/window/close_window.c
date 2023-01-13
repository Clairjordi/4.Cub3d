/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:48:31 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 19:25:29 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_destroy_images(t_data *data)
{
	int i = 0;
	mlx_destroy_image(data->mlx, data->display.img);
	while (data->render.display[i].img != NULL)
	{
		mlx_destroy_image(data->mlx, data->render.display->img);
		i++;
	}
	mlx_destroy_image(data->mlx, data->imgs.no);
	mlx_destroy_image(data->mlx, data->imgs.so);
	mlx_destroy_image(data->mlx, data->imgs.we);
	mlx_destroy_image(data->mlx, data->imgs.ea);
}

int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_destroy_images(data);
	//detruire les images
	//utiliser mlx_destroy_image(data->mlx, [image]);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data);
	exit(0);
}

void	ft_close_window(t_data *data)
{
	mlx_hook(data->win, 17, 0, ft_close, data);
}
