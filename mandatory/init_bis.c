/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:10:05 by mcloarec          #+#    #+#             */
/*   Updated: 2023/01/14 15:01:15 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_init_view(t_data *data)
{
	data->view.camerax = 0;
	data->view.dirx = 0;
	data->view.diry = 0;
	data->view.planex = 0;
	data->view.planey = 0;
}

void	ft_init_display(t_display *display)
{
	display->img = NULL;
	display->addr = NULL;
	display->bpp = 0;
	display->l_length = 0;
	display->endian = 0;
}
