/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:46:05 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 18:07:21 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	plane_move(t_data *data, char c, double rot)
{
	double	old_dirx;
	double	old_planex;

	old_planex = data->view.planex;
	old_dirx = data->view.dirx;
	if (c == 'r')
	{
		data->view.dirx = old_dirx * cos(rot) - data->view.diry * sin(rot);
		data->view.diry = old_dirx * sin(rot) + data->view.diry * cos(rot);
		data->view.planex = old_planex * cos(rot)
			- data->view.planey * sin(rot);
		data->view.planey = old_planex * sin(rot)
			+ data->view.planey * cos(rot);
	}
	else if (c == 'l')
	{
		data->view.dirx = old_dirx * cos(-rot) - data->view.diry * sin(-rot);
		data->view.diry = old_dirx * sin(-rot) + data->view.diry * cos(-rot);
		data->view.planex = data->view.planex * cos(-rot)
			- data->view.planey * sin(-rot);
		data->view.planey = old_planex * sin(-rot)
			+ data->view.planey * cos(-rot);
	}
}

void	player_move_up_down(t_data *data, char c, double rot)
{
	/* (void)rot; */
	/* if (c =='s' && data->view.diry < 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py] */
	/* 			[(int)data->player.px + 1] == '0') */
	/* 		data->player.py += 1; */
	/* } */
	/* else if ((c =='w' && data->view.diry < 0)) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py] */
	/* 			[(int)data->player.px] == '0') */
	/* 		data->player.py -= 1; */
	/* } */
	/* else if (c =='s' && data->view.diry > 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py] */
	/* 			[(int)data->player.px + 1] == '0') */
	/* 		data->player.py += 1; */
	/* } */
	/* else if (c =='w' && data->view.diry > 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py] */
	/* 			[(int)data->player.px - 1] == '0') */
	/* 		data->player.py -= 1; */
	/* } */
	if (c =='w')
	{
		if (data->map.matrix[(int)data->player.py]
				[(int)(data->player.px + data->view.dirx * rot)] == '0')
			data->player.px += data->view.dirx * rot;
		if (data->map.matrix[(int)(data->player.py + data->view.diry * rot)]
				[(int)data->player.px] == '0')
			data->player.py += data->view.diry * rot;
	}
	else if (c =='s')
	{
		if (data->map.matrix[(int)data->player.py]
				[(int)(data->player.px - data->view.dirx * rot)] == '0')
			data->player.px -= data->view.dirx * rot;
		if (data->map.matrix[(int)(data->player.py - data->view.diry * rot)]
				[(int)data->player.px] == '0')
			data->player.py -= data->view.diry * rot;
	}
}

void	player_move_left_right(t_data *data, char c, double rot)
{
	/* (void) rot; */
	/* if (c =='d' && data->view.diry < 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py + 1] */
	/* 			[(int)data->player.px] == '0') */
	/* 		data->player.px += 1; */
	/* } */
	/* else if (c =='a' && data->view.diry < 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py - 1] */
	/* 			[(int)data->player.px] == '0') */
	/* 		data->player.px -= 1; */
	/* } */
	/* else if (c =='a' && data->view.diry > 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py + 1] */
	/* 			[(int)data->player.px] == '0') */
	/* 		data->player.px += 1; */
	/* } */
	/* else if (c =='d' && data->view.diry > 0) */
	/* { */
	/* 	if (data->map.matrix[(int)data->player.py - 1] */
	/* 			[(int)data->player.px] == '0') */
	/* 		data->player.px -= 1; */
	/* } */
    /*  */
	if (c =='d')
	{
		if (data->map.matrix[(int)data->player.py]
				[(int)(data->player.px + data->view.planex * rot)] == '0')
			data->player.px += data->view.planex * rot;
		if (data->map.matrix[(int)(data->player.py + data->view.planey * rot)]
				[(int)data->player.px] == '0')
			data->player.py += data->view.planey * rot;
	}
	else if (c =='a')
	{
		if (data->map.matrix[(int)data->player.py]
				[(int)(data->player.px - data->view.planex * rot)] == '0')
			data->player.px -= data->view.planex * rot;
		if (data->map.matrix[(int)(data->player.py - data->view.planey * rot)]
				[(int)data->player.px] == '0')
			data->player.py -= data->view.planey * rot;
	}
}

int	key_hook(int keycode, t_data *data)
{
	double	rot;

	rot = 30 * (M_PI / 180);

	if (data->map.matrix[(int)data->player.py][(int)data->player.px] == data->player.start)
		data->map.matrix[(int)data->player.py][(int)data->player.px] = '0';
	//rotation camera seulement avec arrow right and left
	if (keycode == XK_Left)
		plane_move(data, 'l', rot);
	else if (keycode == XK_Right)
		plane_move(data, 'r', rot);
	//Mouvement du player seulement avec W,A,S,D
	else if (keycode == XK_a )
		player_move_left_right(data, 'a', rot);
	else if (keycode == XK_d )
		player_move_left_right(data, 'd', rot);
	else if (keycode == XK_w)
		player_move_up_down(data, 'w', rot);
	else if (keycode == XK_s)
		player_move_up_down(data, 's', rot);
	else if (keycode == XK_Escape)
		ft_close(data);
	color_background(data);
	castrays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->display.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->render.display->img, 0, 0);
	return (0);
}
