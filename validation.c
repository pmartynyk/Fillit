/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:45:17 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/12 19:45:18 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_fig(char **fig)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(fig[i]);
		i++;
	}
	free(fig);
}

int		cnt_neighbors(char **fig, int i, int j)
{
	if ((i == 0 && j == 0) || (i == 3 && j == 0))
		return (check_1(fig, i, j));
	else if ((i == 0 && j == 3) || (i == 3 && j == 3))
		return (check_2(fig, i, j));
	else if ((i == 0 && (j >= 1 && j <= 2))
		|| (i == 3 && (j >= 1 && j <= 2)))
		return (check_3(fig, i, j));
	else if (((i >= 1 && i <= 2) && j == 0)
		|| ((i >= 1 && i <= 2) && j == 3))
		return (check_4(fig, i, j));
	else
		return (check_5(fig, i, j));
	return (0);
}

int		check_fig(char **fig)
{
	int	i;
	int j;
	int neighbors;

	i = 0;
	neighbors = 0;
	while (i < 4)
	{
		j = 0;
		while (fig[i][j] != '\0')
		{
			if (fig[i][j] == '#')
				neighbors += cnt_neighbors(fig, i, j);
			j++;
		}
		i++;
	}
	if ((neighbors == 6 || neighbors == 8) && g_num_list < 26)
		fill_map_list(fig);
	else
		return (0);
	free_fig(fig);
	return (1);
}

int		check_s_s(char *line)
{
	g_step = 0;
	if (line[g_step] == '\0')
		return (0);
	if (ft_strlen(line) != 4)
		return (0);
	while (line[g_step])
	{
		if (line[g_step] != '#' && line[g_step] != '.')
			return (0);
		if (line[g_step] == '#')
			g_count_s++;
		g_step++;
	}
	g_fig[g_num] = ft_strsub(line, 0, 4);
	g_num++;
	return (1);
}

int		checking(char *line)
{
	if (g_num == 0)
		MALLF(g_fig);
	g_count_n++;
	if (g_count_n % 5 != 0)
	{
		if (check_s_s(line) == 0)
			return (0);
		if (g_num == 4)
		{
			if (check_fig(g_fig) == 0 || g_count_s != 4)
				return (0);
		}
	}
	else if (g_count_n % 5 == 0)
	{
		g_num = 0;
		if (line[0] != '\0')
		{
			g_count_s = 0;
			return (0);
		}
		g_count_s = 0;
	}
	return (1);
}
