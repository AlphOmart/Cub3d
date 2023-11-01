/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:35:29 by mwubneh           #+#    #+#             */
/*   Updated: 2023/11/01 08:18:58 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, int err)
{
	errno = err;
	perror(str);
	exit(err);
}


int	main(int argc, char **argv)
{
	t_data	data;
	char	**file;
	size_t	i;

	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5))
		ft_error(RED ERROR YELLOW USAGE NC, 2);

	get_file(argv[1], &file);
	data_init(&data);
	parse_data(&file, &data);
	printf("%s\n", data.no);
	printf("%s\n", data.so);
	printf("%s\n", data.we);
	if (data.ea)
		printf("%s\n", data.ea);



	free(data.no);
	free(data.so);
	free(data.we);
	free(data.ea);
	i = -1;
	while (file[++i] != NULL)
		free(file[i]);
	free(file);
	return (0);
}