/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:13:30 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/15 17:13:33 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	dell_map(int num_map)
{
	int i;
	int j;

	i = 0;
	while (g_fin_map[i] != NULL)
	{
		j = 0;
		while (g_fin_map[i][j])
		{
			if (g_fin_map[i][j] == 'A' + num_map)
				g_fin_map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		fill_fin_map(int num_map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (g_map_list[num_map][i] != NULL)
	{
		j = 0;
		if (g_fin_map[x + i] == NULL)
			return (0);
		while (g_map_list[num_map][i][j])
		{
			if (g_fin_map[x + i][y + j] == '\0' ||
				(g_map_list[num_map][i][j] != '.'
					&& g_fin_map[x + i][y + j] != '.'))
				return (0);
			if (g_fin_map[x + i][y + j] != '.'
				&& g_map_list[num_map][i][j++] == '.')
				continue ;
			if (g_map_list[num_map][i][j] != '.')
				g_fin_map[x + i][y + j] = g_map_list[num_map][i][j];
			j++;
		}
		i++;
	}
	return (1);
}

int		algorithm(int num_map)
{
	int x;
	int y;

	x = 0;
	if (g_fin_map == NULL)
		create_fin_map();
	if (g_map_list[num_map] == NULL)
		return (1);
	while (g_fin_map[x] != NULL)
	{
		y = 0;
		while (g_fin_map[x][y] != '\0')
		{
			if (fill_fin_map(num_map, x, y))
			{
				if (algorithm(num_map + 1))
					return (1);
			}
			dell_map(num_map);
			y++;
		}
		x++;
	}
	return (0);
}
