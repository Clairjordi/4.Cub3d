/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:37:54 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/20 16:03:44 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// open le fichier est recupere la taille pour le malloc de char *map 
int	check_file(t_data *data, char *s)
{
	int		fd;
	int		size;
	int		rd;
	char	*buf;

	size = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		ft_error_free(data, "Open failed");
	buf = malloc(sizeof(char));
	if (!buf)
		ft_error_free(data, "Malloc failed");
	rd = 1;
	while (rd > 0)
	{	
		rd = read(fd, buf, 1);
		if (rd < 0)
			break ;
		size++;
	}
	free(buf);
	if (rd < 0)
		ft_error_free(data, "Read failed");
	close(fd);
	return (size);
}

//recupere le fichier .cub dans une string, ici : *
static char	*ft_recup_file(t_data *data, char *arg)
{
	int		fd;
	int		len;
	char	*file;
	int		rd;

	len = check_file(data, arg);
	file = malloc(sizeof(char) * len);
	if (!file)
		ft_error_free(data, "Malloc failed");
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		ft_error_free(data, "Open failed");
	rd = read(fd, file, len);
	if (rd < 0)
		ft_error_free(data, "Read failed");
	if (rd == 0)
	{
		free(file);
		ft_error_free(data, "File void");
	}
		file[len - 1] = '\0';
	close(fd);
	return (file);
}

void	ft_recup_tab_file(t_data *data, char *arg)
{
	char	*file;

	file = ft_recup_file(data, arg);
	data->file_split = ft_split(file, '\n');
	if (data->file_split == NULL)
		ft_error_free(data, "The map is not usable");
	free (file);
}
