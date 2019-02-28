/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:15:13 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/16 16:15:15 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_width(char **fig, int width, int j)
{
	int			i;
	int			start;
	int			finish;

	start = -1;
	finish = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (fig[i][j] == '#' && start == -1)
				start = j;
			if (fig[i][j] == '#' && j >= finish)
				finish = j;
			i++;
		}
		j++;
	}
	while (start <= finish)
	{
		width++;
		start++;
	}
	return (width);
}

int		find_height(char **fig)
{
	int			i;
	int			height;

	i = 0;
	height = 0;
	while (i < 4)
	{
		if (ft_strchr(fig[i], '#'))
			height++;
		i++;
	}
	return (height);
}

int		find_x(char **fig)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_strchr(fig[i], g_alph))
			return (i);
		i++;
	}
	return (0);
}

int		find_y(char **fig)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (fig[i][j] == g_alph)
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}
