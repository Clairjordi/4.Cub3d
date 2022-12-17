/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:44:24 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/17 18:52:07 by clorcery         ###   ########.fr       */
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
// 1 fct pour appeler toutes les initialisation de struct, a voir ensuite
	ft_init_struct(&data);
	/*initialize_map(&data, argv[1]);*/
// recuperer le fichier en entier dans un tableau pour verifier 
// et mettre ensuite
// dans chaque structure correspondante : map ou id
//
	ft_recup_tab_file(&data, argv[1]);
	ft_recup_identifier(&data);
	ft_free(&data);
	return (0);
}
