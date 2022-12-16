/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcloarec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:30:17 by mcloarec          #+#    #+#             */
/*   Updated: 2022/12/16 19:03:36 by mcloarec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	get_columns(int fd)
{
	int		col;
	int		i;
	char	*cur;

	cur = get_next_line(fd);
	col = 0;
	while (cur)
	{
		i = 0;
		while (cur[i] != '\n' && cur[i] != '\0')
			i++;
		free(cur);
		cur = get_next_line(fd);
		if (i > col)
			col = i;
	}
	free(cur);
	return (i);
}

int	get_lines(int fd)
{
	int		i;
	char	*cur;

	i = 0;
	cur = get_next_line(fd);
	while (cur)
	{
		free(cur);
		cur = get_next_line(fd);
		i++;
	}
	free(cur);
	return (i);
}

void	initialize_map(t_data *data, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot read file");
	data->map.lines = get_lines(fd);
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot read file");
	data->map.columns = get_columns(fd);
	close(fd);
}