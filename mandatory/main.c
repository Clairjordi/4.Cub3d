/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:44:24 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/21 14:24:25 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error(".cub file not found");
	if (check_file_name(argv[1]) == FALSE)
		ft_error("wrong format");
	data.mlx = mlx_init();
	ft_init_struct(&data);
	//initialize_map(&data, argv[1]);
	ft_recup_tab_file(&data, argv[1]);
	ft_recup_identifier(&data);
	check_map(&data);
	check_walls(&data);
	ft_open_window(&data);
	//ft_raycasting(&data);
	ft_close_window(&data);
	mlx_loop(data.mlx);
	ft_free(&data);
	return (0);
}
