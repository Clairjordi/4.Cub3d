/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:52:58 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/15 17:20:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_error_free_close(t_data *data, char *str)
{
	mlx_clear_window(data->mlx, data->win);
	ft_destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_error_free(t_data *data, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	ft_free(data);
	exit(EXIT_FAILURE);
}
