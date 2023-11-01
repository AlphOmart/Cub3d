/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:56:38 by mwubneh           #+#    #+#             */
/*   Updated: 2023/11/01 08:29:41 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	element_init(void *element[6], t_data *data);

void	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	while (i++ < 3)
	{
		data->f[i] = -1;
		data->c[i] = -1;
	}
	element_init(data->element, data);
}

static void	element_init(void *element[6], t_data *data)
{
	(element)[0] = &data->no;
	(element)[1] = &data->so;
	(element)[2] = &data->we;
	(element)[3] = &data->ea;
	(element)[4] = &data->f;
	(element)[5] = &data->c;
}
