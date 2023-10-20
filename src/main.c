/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:35:29 by mwubneh           #+#    #+#             */
/*   Updated: 2023/10/20 18:53:02 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, int err)
{
	errno = err;
	perror(str);
	exit(err);
}

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	int		f[3];
	int		c[3];

	char	**map;
}		t_data;

void	get_texture_path(char **to_put, char *to_get)
{
	size_t	i;

	i = 0;
	while (to_get[i] && ft_isspace(to_get[i]))
		i++;
	if (!ft_strncmp(&to_get[i], "./", 2))
		perror();
}

void	get_info(char *str, t_data *data)
{
	const char	*info[7] = {"NO ", "SO ", "WE ", "EA ", "F", "C", NULL};
	void		*(data_element[11]);
	size_t		i;

	data_element[0] = &data->no;
	data_element[1] = &data->so;
	data_element[2] = &data->we;
	data_element[3] = &data->ea;
	data_element[4] = &data->f;
	data_element[5] = &data->c;
	i = 0;
	while (info[i++] != NULL)
	{
		if (i < 4 && ft_strncmp(str, info[i], 2))
			get_texture_path(data_element[i], &str[2]);
//		else if (4 <= i && i < 6 && ft_strncmp(str, info[i], 1))
//			get_color(data_element[i], str);
	}
}

void	parse_data(char ***file, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*file[i] != NULL)
	{
		j = 0;
		while ((*file)[i][j] != '\0')
		{
			if (!ft_isspace(*file[i][j]))
			{
				get_info(file[i][j], &data);
				break ;
			}
			j++;
		}
		i++;
	}

}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**file;
	size_t	i;

	(void)data;
	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5))
		ft_error(RED ERROR YELLOW USAGE NC, 2);
	get_file(argv[1], &file);
	parse_data(&file, &data);
	i = 0;
	while (file[++i] != NULL)
		free(file[i]);
	free(file);
	return (0);
}
