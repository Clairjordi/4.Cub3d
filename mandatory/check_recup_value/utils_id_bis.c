/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_id_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:19:07 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/18 17:28:57 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_strdup_cub(t_data *data, char *s)
{
	char	*dest;
	int		len;

	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		ft_error_free(data, "Malloc failed");
	ft_strlcpy(dest, s, (len + 1));
	return (dest);
}

static void	ft_atoll_cub_bis(t_data *data, char *nptr, char c)
{
	if (c != '\0')
	{
		free(nptr);
		ft_error_free(data, "Invalid RGB form");
	}
}

long long	ft_atoll_cub(t_data *data, char *nptr)
{
	long long	i;
	long int	reponse;

	i = 0;
	reponse = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '\0')
	{
		free(nptr);
		ft_error_free(data, "Missing value RGB");
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		reponse = reponse * 10;
		reponse = reponse + nptr[i] - '0';
		if (reponse > 255)
		{
			free(nptr);
			ft_error_free(data, "Invalid RGB form");
		}
		i++;
	}
	ft_atoll_cub_bis(data, nptr, nptr[i]);
	return (reponse);
}
