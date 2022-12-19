/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:46:05 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/19 10:48:07 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close(data);

	//initialiser les deplacements
	/* if (keycode == XK_a || keycode == XK_Left) */
	/* 	move_player(data, 'x', -1, 'l'); */
	/* if (keycode == XK_d || keycode == XK_Right) */
	/* 	move_player(data, 'x', 1, 'r'); */
	/* if (keycode == XK_w || keycode == XK_Up) */
	/* 	move_player(data, 'y', -1, 'r'); */
	/* if (keycode == XK_s || keycode == XK_Down) */
	/* 	move_player(data, 'y', 1, 'r'); */
	return (0);
}
