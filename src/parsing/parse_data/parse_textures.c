/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:08:51 by mwubneh           #+#    #+#             */
/*   Updated: 2023/11/01 09:09:36 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_textures(char **to_put, char *to_get)
{
	size_t	i;

	i = 0;
	while (to_get[i] && ft_isspace(to_get[i]))
		i++;
	if (!ft_strncmp(&to_get[i], "./", 2))
		*to_put = ft_strjoin(*to_put, trim_end(&to_get[i]));
}

void	is_valid_path(char **path)
{
	size_t	i;

	i = 0;
	while ((*path)[i] && ft_isspace((*path)[i]))
		i++;
	if (!ft_strncmp(path[i], "./", 2))
		i += 2;
	while ((*path)[i])
	{
		if (ft_isspace((*path)[i]) &&
			((*path)[i - 1] != '\\' || ft_isspace((*path)[i - 1])))
			errno = 4;
		i++;
	}
}