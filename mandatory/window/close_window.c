/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:48:31 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/20 18:02:02 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	//detruire les images
	//utiliser mlx_destroy_image(data->mlx, [image]);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data);
	exit(0);
}

void	ft_close_window(t_data *data)
{
	mlx_hook(data->win, 17, 0, ft_close, data);
}
