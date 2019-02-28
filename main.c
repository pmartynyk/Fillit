/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:49:59 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/12 19:41:40 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		reading(char *str)
{
	int		fd;
	int		res;
	char	*line;

	fd = open(str, O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (checking(line) == 0)
		{
			ft_putendl("error");
			close(fd);
			return (0);
		}
		free(line);
	}
	if (g_num != 4)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

void	start_algo(void)
{
	while (1)
	{
		if (algorithm(0))
			break ;
		my_realloc();
	}
}

int		main(int argc, char **argv)
{
	g_num_list = 0;
	g_num = 0;
	g_alph = 'A';
	g_count_n = 0;
	g_count_s = 0;
	g_map_rowe = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	if (reading(argv[1]) == 0)
		return (0);
	start_algo();
	print_map();
	return (0);
}
