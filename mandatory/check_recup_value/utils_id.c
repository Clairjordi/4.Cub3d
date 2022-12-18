/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:27:48 by clorcery          #+#    #+#             */
/*   Updated: 2022/12/18 17:24:11 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	*ft_cdup(t_data *data, char c)
{
	char	*dest;

	dest = malloc(sizeof(char) * 2);
	if (!dest)
		ft_error_free(data, "Malloc failed");
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}

static char	*ft_charjoin_bis(char *s1, char c, char *result)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = c;
	i++;
	result[i] = '\0';
	return (result);
}

char	*ft_charjoin(t_data *data, char *s1, char c)
{
	char	*result;
	int		len;

	result = NULL;
	if (!s1 && !c)
		ft_error_free(data, "Function ft_charjoin failed");
	else if (!s1)
	{
		result = ft_cdup(data, c);
		if (result == NULL)
			ft_error_free(data, "Malloc failed");
		return (result);
	}
	len = ft_strlen(s1);
	result = malloc(sizeof(char) * len + 2);
	if (!result)
		ft_error_free(data, "Malloc failed");
	result = ft_charjoin_bis(s1, c, result);
	free(s1);
	return (result);
}
