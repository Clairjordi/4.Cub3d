/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:14 by mcloarec          #+#    #+#             */
/*   Updated: 2022/12/16 16:23:01 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (i == 0 && str[i + 1] != '.')
		return (FALSE);
	if (!(ft_strnstr(str, ".cub", ft_strlen(str))))
		return (FALSE);
	else
		return (TRUE);
}
