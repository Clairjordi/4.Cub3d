/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:52:58 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/15 17:00:32 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_error_free_close(t_data *data, char *str)
{
	ft_close_window(data);
	ft_error_free(data, str);
	
}

void	ft_error_free(t_data *data, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	ft_free(data);
	exit(EXIT_FAILURE);
}
