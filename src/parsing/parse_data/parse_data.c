/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:59:43 by mwubneh           #+#    #+#             */
/*   Updated: 2023/11/04 15:01:55 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_info(char *str, t_data *data);
void	get_colors(int colors[3], char *to_get);

//TODO Normer cette fontion.
void	parse_data(char ***file, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*file)[i] != NULL && errno != 4)
	{
		j = 0;
		while ((*file)[i][j] != '\0')
		{
			while (ft_isspace((*file)[i][j]))
				j++;
			if ((*file)[i][j])
			{
				get_info(&(*file)[i][j], data);
				break ;
			}
		}
		i++;
	}
	if (errno == 4 || (*file)[i] != NULL)
	{
		i = -1;
		while ((*file)[++i] != NULL)
		{
			if (data->element[i] != NULL && i < 4)
				free(*(char **) data->element[i]);
			free((*file)[i]);
		}
		free(*file);
		ft_error("ERROR file parse", errno);
	}
}

//TODO	verifier que les elements on été parse
void	get_info(char *str, t_data *data)
{
	const char	*info[7] = {"NO ", "SO ", "WE ", "EA ", "F", "C", NULL};
	size_t		i;

	i = -1;
	while (info[++i] != NULL && errno != 4)
	{
		if (i < 4 && !ft_strncmp(str, info[i], 2))
			return (parse_textures(data->element[i],
								&str[2]), is_valid_path(data->element[i]));
		else if (4 <= i && !ft_strncmp(str, info[i], 1))
			return (get_colors(data->element[i], trim_end(&str[1])));
	}
}

size_t get_split_size(char **temp)
{
	size_t	i;

	i = 0;
	while (temp[i])
	{
		i++;
	}
	return (i);
}

void	get_colors(int colors[3], char *to_get)
{
	char	**temp;
	size_t	i;

	i = 0;
	while (to_get[i] && ft_isspace(to_get[i]))
		i++;
	temp = ft_split(&to_get[i], ',');
	if (get_split_size(temp) != 3)
	{
		errno = 4;
		return ;
	}
	i = 0;
	while (temp[i])
	{
		colors[i] = ft_atoi(temp[i]);
		i++;
	}
	i = 0;
	while (temp[i] != NULL)
		free(temp[i++]);
	free(temp);
}

char	*trim_end(char *string)
{
	size_t	i;

	i = ft_strlen(string);
	while (i > 0 && !ft_isspace(string[i]))
		i--;
	string[i] = '\0';
	return (string);
}
