/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:35:29 by mwubneh           #+#    #+#             */
/*   Updated: 2023/10/20 14:57:03 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "cub3d.h"

void	ft_error(char *str, int err)
{
	errno = err;
	perror(str);
	exit(err);
}

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

int	main(int argc, char **argv)
{
	char	**file;

	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5))
		ft_error(RED ERROR YELLOW USAGE NC, 2);
	get_file(argv[1], &file);
	int i = 0;
	while (42)
	{
		printf("%s", file[i++]);
		if (file[i] == NULL)
		{
			printf("%s", file[i]);
			printf("\n");
			break ;
		}
	}
	i = -1;
	while (file[++i] != NULL)
		free(file[i]);
	free(file);
	return (0);
}
