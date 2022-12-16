/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:27:04 by mcloarec          #+#    #+#             */
/*   Updated: 2022/12/16 21:49:27 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	ft_init_identifier(t_data *data)
{
	data->ident.no = NULL;
	data->ident.so = NULL;
	data->ident.we = NULL;
	data->ident.ea = NULL;
	data->ident.floor = NULL;
	data->ident.ceiling = NULL;
}

static void	ft_init_map(t_data *data)
{
	data->map.matrix = NULL;
	data->map.start = 0;
}

static void	ft_init_data(t_data *data)
{
	data->file_split = NULL;
}

void	ft_init_struct(t_data *data)
{
	ft_init_data(data);
	ft_init_map(data);
	ft_init_identifier(data);
}
