/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:44:24 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 18:48:34 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error(".cub file not found");
	if (check_file_name(argv[1]) == FALSE)
		ft_error("Wrong format");
	ft_init_struct(&data);
	ft_check_recup_value(&data, argv[1]);
	data.mlx = mlx_init();
	ft_open_window(&data);
	ft_ray_casting(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.display.img, 0, 0);
	ft_close_window(&data);
	mlx_loop(data.mlx);
	ft_free(&data);
	return (0);
}
