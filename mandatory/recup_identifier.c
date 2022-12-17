/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:02:52 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/17 19:41:12 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_check_first_letter(t_data *data, char c)
{
	if (!(c == 'N' || c == 'S' || c == 'W' || c == 'E'
			|| c == 'F' || c == 'C'))
		ft_error_free(data, "Invalid Identifier");
}

void	ft_check_name_id(t_data *data, char *s)
{
	if (s[0] == 'N' && ft_strncmp("NO", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'S' && ft_strncmp("SO", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'W' && ft_strncmp("WE", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'E' && ft_strncmp("EA", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'S' && ft_strncmp("SO", s, 2) != 0)
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'F' && s[1] != ' ')
		ft_error_free(data, "Invalid name identifier");
	if (s[0] == 'C' && s[1] != ' ')
		ft_error_free(data, "Invalid name identifier");
}

static void	ft_check_value_c_f(t_data *data, char *s)
{
	int	i;

	i = 2;
	while (s[i])
	{
		if (s[2] == ',')
			ft_error_free(data, "Invalid RGB form");
		if (s[i] != ',' && ft_isdigit(s[i]) == 0)
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
		value = ft_strchr(s, '.');
		fd = open(value, O_RDONLY);
		if (fd < 0)
			ft_error_free(data, "File path texture invalid");
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

void	ft_recup_identifier(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_check_first_letter(data, data->file_split[i][0]);
		ft_check_name_id(data, data->file_split[i]);
		ft_check_value_id_and_add(data, data->file_split[i],
			data->file_split[i][0]);
		i++;
	}
	if (data->id.no == NULL || data->id.so == NULL || data->id.we == NULL
		|| data->id.ea == NULL || data->id.f == NULL || data->id.c == NULL)
		ft_error_free(data, "Invalid identifier");
}


//verifier si 1ere lettre ok
//		AVANT de mettre dans id : 
//			path/color = verifier que id bien ecris
//			path = verifier si path correct
//			color = verifier si c'est un chiffre
//			color = pas plusieurs virgule
//			color = pas de virgule au debut ou a la fin
//
//
//		AU MOMENT DE METTRE DANS ID:
//			color = verifier si c'est bien un chiffre entre 0 et 255
//			color = trop ou pas assez de valeur
//			color = verification des doublons
//			
//			path = verification des doublons
//
//verifier que tous les identifiers sont remplis
