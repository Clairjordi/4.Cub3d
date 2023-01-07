/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:21:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/07 14:29:21 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
				data->player.px = j;
				data->player.py = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_test(t_data *data)
{
	int dist_x;
	int	dist_y;
	int	distance;

	dist_x = data->player.px;
	dist_y = data->player.py;
	

	while (data->map.matrix[dist_y] != NULL)
	{
		
		if (data->map.matrix[dist_y][dist_x] == '1')
		{
			distance = dist_x - data->player.px; 
			printf("I found wall - distance = %d\n", distance);
			break ;
		}
		dist_x += 1;
	}
	/* int	nx; */
	/* int	ny; */
    /*  */
	/* nx = data->player.px + cos(45) - d; */

}

void	ft_ray_casting(t_data *data)
{
	ft_pos_player(data);
	ft_test(data);
}
