/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:34:07 by mwubneh           #+#    #+#             */
/*   Updated: 2023/10/20 17:30:04 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	valid_path(char *path, int *fd)
{
	*fd = open(path, O_DIRECTORY);
	if (*fd != -1)
		ft_error(RED ERROR YELLOW NOT_FILE NC, 2);
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		ft_error(RED ERROR YELLOW INV_PATH NC, 2);
}

void	get_file_size(size_t *file_size, char *path)
{
	char	*line;
	int		fd;

	valid_path(path, &fd);
	*file_size = 0;
	while (42)
	{
		++(*file_size);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
}

//TODO add while (42 || i++)
void	get_file(char *path, char ***file)
{
	size_t	file_size;
	size_t	i;
	int		fd;

	get_file_size(&file_size, path);
	valid_path(path, &fd);
	*file = malloc(sizeof(char *) * file_size);
	if (!(*file))
		ft_error("malloc failed\n", 4);
	i = 0;
	while (42)
	{
		(*file)[i] = get_next_line(fd);
		if ((*file)[i] == NULL)
			break ;
		i++;
	}
	if (i != file_size - 1)
		ft_error("weird things happen", 4);
}
