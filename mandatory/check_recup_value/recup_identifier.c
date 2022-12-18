/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:02:52 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/18 17:28:29 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
	//utiliser isspace
	if (s[0] == 'F' && s[1] != ' ')
		ft_error_free(data, "Invalid name identifier");
	//utiliser isspace
	if (s[0] == 'C' && s[1] != ' ')
		ft_error_free(data, "Invalid name identifier");
}

void	ft_check_id_bottom_file(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->file_split[i + 1])
		i++;
	//utiliser isspace
	if (data->file_split[i][0] != ' ' && data->file_split[i][0] != '1')
		ft_error_free(data, "Map Invalid");
	if (data->file_split[i][0] == ' ')
	{
		while (data->file_split[i][j])
		{
			//utiliser isspace
			if (data->file_split[i][j] != ' ' && data->file_split[i][j] != '1')
				ft_error_free(data, "Map Invalid");
			j++;
		}
	}
}

void	ft_recup_identifier(t_data *data)
{
	int	i;

	i = 0;
	ft_check_id_bottom_file(data);
	while (i < 6)
	{
		ft_check_first_letter(data, data->file_split[i][0]);
		ft_check_name_id(data, data->file_split[i]);
		ft_check_value_id_and_add(data, data->file_split[i],
			data->file_split[i][0]);
		i++;
	}
}

//verifier si 1ere lettre ok
//		AVANT de mettre dans id : 
//			ok - path/color = pas de txt en fin de fichier ex : "    NO[...]" ou "fanfan[..]"
//			ok - path/color = verifier que id bien ecris
//			ok - path/color = pas d'espace avant identifier
//			ok - path/color = value id vide
//			ok - path = verifier si path bien ecris
//			ok - color = verifier si c'est un chiffre
//			ok - color = pas plusieurs virgule
//			ok - color = pas de virgule au debut ou a la fin
//			ok - color = possible espace avant apres au milieu (avec chiffre RGB valide)
//			ok - color = espace a la place d'une valeur RGB ou entre chiffre
//			
//
//
//		AU MOMENT DE METTRE DANS ID:
//			ok - color = verifier si c'est bien un chiffre entre 0 et 255
//			ok - color = trop ou pas assez de valeur
//			ok - color = verification des doublons
//			
//			ok - path = ext path_file doit etre en xpm
//			ok - path = verification des doublons
//
//     ok - verifier que tous les identifiers sont remplis
