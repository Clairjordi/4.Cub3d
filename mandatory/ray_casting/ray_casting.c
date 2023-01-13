/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/13 19:31:22 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	color_walls(t_data *data, int x)
{
	int start;
	int end;
	int	color;

	start = data->render.drawstart;
	end = data->render.drawend;
	color = 0X08A56EF;
	if (data->ray.side == 0) //WE
	{
		if (data->ray.raydirx > 0) //E
			color = 0x0C91787; //rose
		else if (data->ray.raydirx < 0) // W
			color = 0x055BE11; //vert
	}
	else if (data->ray.side == 1) //NS
	{
		if (data->ray.raydiry < 0) //N
			color = 0x01218DE; //bleu
		else if (data->ray.raydiry > 0) 
			color = 0x0F27F0D; //orange
	}
	while (start <= end)
	{
		my_mlx_pixel_put(&data->display, x, start, color);
		start ++;
	}
}

void	ft_pos_player(t_data *data)
{
	int i;
	int	j;

	i = 0;
	while (data->map.matrix[i])
	{
		j = 0;
		while (data->map.matrix[i][j])
		{
			if (data->map.matrix[i][j] == 'N' || data->map.matrix[i][j] == 'S'
					||data->map.matrix[i][j] == 'E' || data->map.matrix[i][j] == 'W')
			{
				data->player.px = j + 0.5;
				data->player.py = i + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	angle_from_position(t_data *data)
{
	if (data->player.start == 'N')
	{
		data->view.angle = 90;
		data->view.diry = -1;
		data->view.planex = 0.66;
	}
	else if (data->player.start == 'S')
	{
		data->view.angle = 270;
		data->view.diry = 1;
		data->view.planex = -0.66;
	}
	else if (data->player.start == 'E')
	{
		data->view.angle = 0;
		data->view.dirx = 1;
		data->view.planey = 0.66;
	}
	else if (data->player.start == 'W')
	{
		data->view.angle = 180;
		data->view.dirx = -1;
		data->view.planey = -0.66;
	}
}

void	ft_sidedist(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->player.px - (double)data->ray.mapx) * data->ray.deltax;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = ((double)data->ray.mapx + 1 - data->player.px) * data->ray.deltax;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->player.py - (double)data->ray.mapy) * data->ray.deltay;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = ((double)data->ray.mapy + 1 - data->player.py) * data->ray.deltay;
	}
}

void	ft_dda(t_data *data)
{	
	data->ray.hit = 0;
	data->ray.side = -1;
	data->ray.mapx = (int)data->player.px;
	data->ray.mapy = (int)data->player.py;
	if (data->ray.raydirx == 0)
		data->ray.deltax = exp(30);
	else
		data->ray.deltax = fabs(1 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.deltay = exp(30);
	else
		data->ray.deltay = fabs(1 / data->ray.raydiry);
	ft_sidedist(data);
	while (data->ray.hit != 1)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltax;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0; // WE
		}
		else
		{
			data->ray.sidedisty += data->ray.deltay;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1; // NS
		}
		if (data->map.matrix[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpwalldist = data->ray.sidedistx - data->ray.deltax;
	else
		data->ray.perpwalldist = data->ray.sidedisty - data->ray.deltay;
}

void	ft_get_texture_x(t_data *data)
{
   	if (data->ray.side == 0) // tape sur un mur vertical
		data->render.wallx = data->player.py + data->ray.perpwalldist * data->ray.raydiry;
    else // tape sur un mur horizontal
		data->render.wallx = data->player.px + data->ray.perpwalldist * data->ray.raydirx;
    
	//calcule la distance dans le petit carre
	//exemple : wallx = 2.4
	//soit 2.4 - 2 = 0.4
	data->render.wallx -= floor(data->render.wallx); 
	// floor : calculent l'arrondi entier inférieur
	
	//calcul le x dans la texture
	data->render.texx = (int)(data->render.wallx * (double)TEX_WIDTH);
   //permet de faire les calculs en partant du bord gauche - on ne sait pas encore pourquoi 
	if((data->ray.side == 0 && data->ray.raydirx > 0)
		|| (data->ray.side == 1 && data->ray.raydiry < 0))
		data->render.texx = TEX_WIDTH - data->render.texx - 1;
}

void	*ft_choose_texture(t_data *data)
{
	void *tmp;

	tmp = NULL;
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		tmp = data->imgs.ea;
	if (data->ray.side == 0 && data->ray.raydirx < 0)
		tmp = data->imgs.we;
	// peut etre devoir inverse le nord et le sud car diry dans angle_for_position est inverse
	if (data->ray.side == 1 && data->ray.raydiry > 0)
		tmp = data->imgs.no;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		tmp = data->imgs.so;

	return (tmp);
}

int	ft_recup_rgb_pixel(t_data *data, void *texture, int texy)
{
	int	b;
	int	g;
	int	r;
	int	color;
	t_display	*d;

	d = data->render.display;
	d->addr = mlx_get_data_addr(texture, &d->bpp,
			&d->l_length, &d->endian);
	/* double	pix =  (data->render.texx * 4) + (TEX_HEIGHT * 4 * texy); */
	/* if (pix < 0) */
	/* { */
	/* 	color = data->id.ceiling; */
	/* 	return (color); */
	/* } */

	b = d->addr[(data->render.texx * 4) + (TEX_HEIGHT * 4 * texy)];
	g = d->addr[(data->render.texx * 4) + (TEX_HEIGHT * 4 * texy + 1)];
	r = d->addr[(data->render.texx * 4) + (TEX_HEIGHT * 4 * texy + 2)];
	color = create_rgb(r, g, b);

	printf("b = %d g = %d r = %d / texx = %d texy = %d\n",
			b, g, r,data->render.texx, texy);
	return (color);
}

void	ft_draw_line(t_data *data, void *texture, int x)
{
	//possibilite d'enlever le texy de la structure
	int	i;
	double step;
	int color_pixel;
	

	i = data->render.drawstart;
	step = (double)TEX_HEIGHT / data->render.line_height;
	//calculer la position du y dans la texture - coordonnee du y
	data->render.texy = (data->render.drawstart - SCREEN_HEIGHT * 0.5
			+ data->render.line_height * 0.5) * step;
	while (i < data->render.drawend)
	{
		//printf("texy = %f\n", data->render.texy);
		color_pixel = ft_recup_rgb_pixel(data, texture, (int)data->render.texy);
		my_mlx_pixel_put(data->render.display, x, i, color_pixel);
		data->render.texy += step;
		i++;
	}
}

void	ft_walls(t_data *data, int x) // changer pour noter ft_each_lines_walls
{
	void	*texture;

	data->render.line_height = (int)(SCREEN_HEIGHT / data->ray.perpwalldist);
	data->render.drawstart = SCREEN_HEIGHT * 0.5 - data->render.line_height * 0.5;
	if (data->render.drawstart < 0)
		data->render.drawstart = 0;
	data->render.drawend = SCREEN_HEIGHT * 0.5 + data->render.line_height * 0.5;
	if (data->render.drawend >= SCREEN_HEIGHT)
		data->render.drawend = SCREEN_HEIGHT - 1;
	ft_get_texture_x(data);
	texture = ft_choose_texture(data);
	ft_draw_line(data, texture, x); 
	//color_walls(data, x);
}

void	castrays(t_data *data)
{
	int x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		data->view.camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		if (SCREEN_WIDTH - 1 == x)
			data->view.camerax = 1;
		data->ray.raydirx = data->view.dirx + data->view.planex * data->view.camerax;
		data->ray.raydiry = data->view.diry + data->view.planey * data->view.camerax;
		ft_dda(data);
		ft_walls(data, x);
		x++;
	}
}

void	init_images(t_data *data)
{
	int	width;
	int	height;

	data->imgs.no = mlx_xpm_file_to_image(data->mlx, data->id.no, &width, &height);
	if (!data->imgs.no)
		ft_error_free(data, "Malloc");
	data->imgs.so = mlx_xpm_file_to_image(data->mlx, data->id.so, &width, &height);
	data->imgs.we = mlx_xpm_file_to_image(data->mlx, data->id.we, &width, &height);
	data->imgs.ea = mlx_xpm_file_to_image(data->mlx, data->id.ea, &width, &height);
	//checker la taille des images, si != TEX_WIDTH et TEX_HEIGHT alors erreurs	
}

void	ft_ray_casting(t_data *data)
{
	ft_pos_player(data);
	angle_from_position(data);
	init_images(data);
	castrays(data);
}
