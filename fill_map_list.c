/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:56:55 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/15 10:57:00 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_map(char **fig, int *cord)
{
	int i;
	int j;
	int x;
	int	cnt;

	x = 0;
	cnt = 0;
	i = find_x(fig);
	j = find_y(fig);
	if (g_map_list == NULL)
		g_map_list = (char***)malloc(sizeof(char**) * 26);
	if (g_map_list[g_num_list] == NULL)
		g_map_list[g_num_list] = (char**)malloc(sizeof(char*) * cord[0] + 1);
	while (cnt < cord[0])
	{
		g_map_list[g_num_list][x] = ft_strsub(fig[i], j, cord[1]);
		i++;
		x++;
		cnt++;
	}
	g_map_list[g_num_list][x] = NULL;
	g_num_list++;
}

void	fill_map_list(char **fig)
{
	int			i;
	int			j;
	int			*cord;

	cord = (int *)malloc(sizeof(int) * 2);
	cord[0] = find_height(fig);
	cord[1] = find_width(fig, 0, 0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (fig[i][j])
		{
			if (fig[i][j] == '#')
				fig[i][j] = g_alph;
			j++;
		}
		i++;
	}
	fill_map(fig, cord);
	free(cord);
	g_alph++;
}
