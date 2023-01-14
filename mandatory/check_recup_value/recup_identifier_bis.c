/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_identifier_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:03:35 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/14 18:44:24 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_verif_ext_file_path(t_data *data, char c)
{
	char	*tmp;

	tmp = NULL;
	if (c == 'N')
		tmp = data->id.no;
	else if (c == 'S')
		tmp = data->id.so;
	else if (c == 'W')
		tmp = data->id.we;
	else if (c == 'E')
		tmp = data->id.ea;
	tmp = ft_strrchr(tmp, '.');
	if (ft_strcmp(tmp, ".xpm") != 0)
		ft_error_free(data, "Extension file incorrect");
}

static void	ft_add_path_id_bis(t_data *data, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		ft_verif_ext_file_path(data, c);
}

void	ft_add_path_id(t_data *data, char *id, char c)
{
	if (c == 'N')
	{
		if (data->id.no != NULL)
			ft_error_free(data, "Double identifier detected");
		data->id.no = ft_strdup_cub(data, id);
	}
	else if (c == 'S')
	{
		if (data->id.so != NULL)
			ft_error_free(data, "Double identifier detected");
		data->id.so = ft_strdup_cub(data, id);
	}
	else if (c == 'W')
	{
		if (data->id.we != NULL)
			ft_error_free(data, "Double identifier detected");
		data->id.we = ft_strdup_cub(data, id);
	}
	else if (c == 'E')
	{
		if (data->id.ea != NULL)
			ft_error_free(data, "Double identifier detected");
		data->id.ea = ft_strdup_cub(data, id);
	}
	ft_add_path_id_bis(data, c);
}

static void	ft_check_value_c_f(t_data *data, char *s)
{
	int	i;

	i = 2;
	if (s[2] == '\0')
		ft_error_free(data, "Missing value RGB");
	while (s[i])
	{
		if (s[2] == '\0')
			ft_error_free(data, "Missing value RGB");
		if (s[2] == ',')
			ft_error_free(data, "Invalid RGB form");
		if ((s[i] != ',' && ft_isspace(s[i]) != 0) && ft_isdigit(s[i]) == 0)
			ft_error_free(data, "Invalid RGB form");
		if (s[i] == ',' && (s[i + 1] == ',' || s[i + 1] == '\0'))
			ft_error_free(data, "Invalid RGB form");
		i++;
	}
}

void	ft_check_value_id_and_add(t_data *data, char *s, char c)
{
	char	*value;
	int		fd;
	char	n;

	value = NULL;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (s[3] != '.')
			ft_error_free(data, "Invalid file path texture");
		value = ft_strchr(s, '.');
		fd = open(value, O_RDONLY);
		if (fd < 0)
			ft_error_free(data, "Invalid file path texture");
		close (fd);
	}
	else if (c == 'F' || c == 'C')
	{
		ft_check_value_c_f(data, s);
		n = s[2];
		value = ft_strchr(s, n);
	}
	ft_add_id(data, value, c);
}
