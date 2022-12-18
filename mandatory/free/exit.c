/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:52:58 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/18 16:25:45 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_error_free(t_data *data, char *str)
{
	ft_free(data);
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
