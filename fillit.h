/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:00:02 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/15 17:19:29 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# define MALLF(x) x = (char**)malloc(sizeof(char*) * 5);

int			g_count_n;
int			g_count_s;
int			g_num;
char		**g_fig;
char		***g_map_list;
int			g_step;
int			g_alph;
int			g_num_list;
char		**g_fin_map;
int			g_map_rowe;
int			check_fig(char **fig);
int			check_s_s(char *line);
int			checking(char *line);
int			check_1(char **fig, int i, int j);
int			check_2(char **fig, int i, int j);
int			check_3(char **fig, int i, int j);
int			check_4(char **fig, int i, int j);
int			check_5(char **fig, int i, int j);
void		free_fig(char **fig);
int			cnt_neighbors(char **fig, int i, int j);
void		fill_map_list(char **fig);
void		print_map(void);
int			ft_sqrt(int nb);
void		dot_alloc(char ****fin_map, size_t size);
void		create_fin_map(void);
int			algorithm(int num_map);
int			find_width(char **fig, int width, int j);
int			find_height(char **fig);
void		fill_map(char **fig, int *cord);
int			find_x(char **fig);
int			find_y(char **fig);
void		my_realloc(void);
int			fill_fin_map(int num_map, int x, int y);

#endif
