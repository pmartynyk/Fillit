/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fin_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:30:40 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/16 16:30:41 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_copy_map(char ***copy_map)
{
	int step;

	step = 0;
	while (copy_map[step])
	{
		free(copy_map[step]);
		step++;
	}
	free(copy_map);
}

void	my_realloc(void)
{
	g_map_rowe++;
	create_fin_map();
}

void	create_fin_map(void)
{
	int		map_size;
	int		j;
	int		k;

	j = 0;
	map_size = ft_sqrt(g_num_list) + g_map_rowe;
	g_fin_map = (char**)malloc(sizeof(char*) * map_size + 1);
	while (j < map_size)
	{
		k = 0;
		g_fin_map[j] = ft_memalloc(map_size + 1);
		while (k < map_size)
		{
			g_fin_map[j][k] = '.';
			k++;
		}
		j++;
	}
	g_fin_map[j] = NULL;
}

int		ft_sqrt(int nb)
{
	int eps;
	int i;

	i = 1;
	eps = 1;
	nb *= 4;
	while (i * i < nb)
		i++;
	return (i);
}
