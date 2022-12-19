/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:44:24 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/19 15:48:32 by mcloarec         ###   ########.fr       */
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
	ft_init_struct(&data);
	initialize_map(&data, argv[1]);
	ft_recup_tab_file(&data, argv[1]);
	//ft_recup_identifier(&data);
	check_map(&data);
	check_walls(&data);
	ft_open_window(&data);
	ft_close_window(&data);
	mlx_loop(data.mlx);
	ft_free(&data);
	return (0);
}
