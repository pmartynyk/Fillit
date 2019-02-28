/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkneighbors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:38:42 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/14 10:38:44 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_1(char **fig, int i, int j)
{
	int res;

	res = 0;
	if (i == 0 && j == 0)
	{
		if (fig[i + 1][j] == '#')
			res++;
		if (fig[i][j + 1] == '#')
			res++;
	}
	else if (i == 3 && j == 0)
	{
		if (fig[i - 1][j] == '#')
			res++;
		if (fig[i][j + 1] == '#')
			res++;
	}
	return (res);
}

int	check_2(char **fig, int i, int j)
{
	int res;

	res = 0;
	if (i == 0 && j == 3)
	{
		if (fig[i][j - 1] == '#')
			res++;
		if (fig[i + 1][j] == '#')
			res++;
	}
	else if (i == 3 && j == 3)
	{
		if (fig[i][j - 1] == '#')
			res++;
		if (fig[i - 1][j] == '#')
			res++;
	}
	return (res);
}

int	check_3(char **fig, int i, int j)
{
	int res;

	res = 0;
	if (i == 0 && (j >= 1 && j <= 2))
	{
		if (fig[i][j - 1] == '#')
			res++;
		if (fig[i][j + 1] == '#')
			res++;
		if (fig[i + 1][j] == '#')
			res++;
	}
	else if (i == 3 && (j >= 1 && j <= 2))
	{
		if (fig[i][j - 1] == '#')
			res++;
		if (fig[i][j + 1] == '#')
			res++;
		if (fig[i - 1][j] == '#')
			res++;
	}
	return (res);
}

int	check_4(char **fig, int i, int j)
{
	int res;

	res = 0;
	if ((i >= 1 && i <= 2) && j == 0)
	{
		if (fig[i - 1][j] == '#')
			res++;
		if (fig[i + 1][j] == '#')
			res++;
		if (fig[i][j + 1] == '#')
			res++;
	}
	else if ((i >= 1 && i <= 2) && j == 3)
	{
		if (fig[i - 1][j] == '#')
			res++;
		if (fig[i + 1][j] == '#')
			res++;
		if (fig[i][j - 1] == '#')
			res++;
	}
	return (res);
}

int	check_5(char **fig, int i, int j)
{
	int res;

	res = 0;
	if (fig[i][j - 1] == '#')
		res++;
	if (fig[i][j + 1] == '#')
		res++;
	if (fig[i - 1][j] == '#')
		res++;
	if (fig[i + 1][j] == '#')
		res++;
	return (res);
}
