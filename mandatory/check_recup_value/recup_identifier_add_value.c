/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_identifier_add_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:40 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/18 16:10:09 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	ft_add_id_c_f_ter(t_data *data, int *tmp, int j, char *val)
{
	if (j != 2)
	{
		free(val);
		ft_error_free(data, "RGB : to few value");
	}
	tmp[j] = ft_atoll_cub(data, val);
	free(val);
}

static void	ft_add_id_c_f_bis(int *j, int *i, char **val)
{
	free (*val);
	*val = NULL;
	(*j)++;
	(*i)++;
}

static void	ft_add_id_c_f(t_data *data, char *id, int *tmp)
{
	int		i;
	int		j;
	char	*val;

	i = 0;
	j = 0;
	val = NULL;
	while (id[i])
	{
		if (j > 2)
		{
			free(val);
			ft_error_free(data, "RGB : too many value");
		}
		val = ft_charjoin(data, val, id[i]);
		if (id[i + 1] == ',')
		{
			tmp[j] = ft_atoll_cub(data, val);
			ft_add_id_c_f_bis(&j, &i, &val);
		}
		if (id[i + 1] == '\0')
			ft_add_id_c_f_ter(data, tmp, j, val);
		i++;
	}
}

void	ft_add_id(t_data *data, char *id, char c)
{
	ft_add_path_id(data, id, c);
	if (c == 'F')
	{
		if (data->id.f != NULL)
			ft_error_free(data, "Double identifier detected");
		data->id.f = malloc(sizeof(int) * 3);
		if (!data->id.f)
			ft_error_free(data, "Malloc failed");
		ft_add_id_c_f(data, id, data->id.f);
	}
	if (c == 'C')
	{
		if (data->id.c != NULL)
			ft_error_free(data, "Double identifier detected");
		data->id.c = malloc(sizeof(int) * 3);
		if (!data->id.c)
			ft_error_free(data, "Malloc failed");
		ft_add_id_c_f(data, id, data->id.c);
	}
}
