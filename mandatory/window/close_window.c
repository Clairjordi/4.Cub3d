/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:48:31 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 14:21:39 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->display.img);
	mlx_destroy_image(data->mlx, data->imgs.no);
	mlx_destroy_image(data->mlx, data->imgs.so);
	mlx_destroy_image(data->mlx, data->imgs.we);
	mlx_destroy_image(data->mlx, data->imgs.ea);
}

int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data);
	exit(0);
}

void	ft_close_window(t_data *data)
{
	mlx_hook(data->win, 17, 0, ft_close, data);
}
