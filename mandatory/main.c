/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:44:24 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/16 21:58:25 by clorcery         ###   ########.fr       */
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
// dans chaque structure correspondante : map ou ident(ifier)[trouver un autre nom plus court ...]
//
	ft_recup_tab_file(&data, argv[1]);
//print le file_split
	int i = 0;
	while (data.file_split[i])
		ft_printf("%s\n", data.file_split[i++]);
	ft_free(&data);
	return (0);
}
