/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:21:06 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/19 11:09:00 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//determiner *combien pour les sprites - 32 mis en attendant
void	ft_open_window(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->file_split[0][x])
		x++;
	while(data->file_split[y] != NULL)
		y++;
	data->win = mlx_new_window(data->mlx, (x * 32), (y * 32), "Cub3D");
	//init des images ici ? - pixel put dans une image puis afficher l'image car utilisation de
	//la fonction pixel put obligatoire
	 mlx_hook(data->win, 2, 1L << 0, key_hook, data);
}
