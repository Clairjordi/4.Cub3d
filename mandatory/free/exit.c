/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:52:58 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 15:32:45 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_error_free(t_data *data, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	ft_free(data);
	exit(EXIT_FAILURE);
}
