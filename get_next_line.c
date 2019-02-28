/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:28:46 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/12 15:20:57 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_restrjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;
	char	*res;

	if (s1 != NULL || s2 != NULL)
	{
		i = 0;
		j = 0;
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (res == 0)
			return (0);
		while (s1[i])
			res[j++] = s1[i++];
		i = 0;
		while (s2[i])
			res[j++] = s2[i++];
		res[j] = '\0';
		free(s1);
		return (res);
	}
	return (0);
}

char	*ft_restrchr(char *src, int to_find)
{
	int		i;
	char	*temp;

	i = 0;
	if (to_find == '\0')
		return (src + ft_strlen(src));
	while (src[i])
	{
		if (src[i] == to_find)
		{
			if (ft_strlen(&src[i + 1]) != 0)
			{
				temp = ft_memalloc(1);
				temp = ft_restrjoin(temp, &src[i + 1]);
				return (temp);
			}
			else
				return (NULL);
		}
		i++;
	}
	return (NULL);
}

size_t	line_length(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	fd_read(int fd, char *buf, char **temp)
{
	int rd;

	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		*temp = ft_restrjoin(*temp, buf);
		if (ft_strchr(*temp, '\n'))
			break ;
	}
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	static char *temp[10240];
	char		*del;

	buf = (char *)malloc(sizeof(char));
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	free(buf);
	if (temp[fd] == NULL)
		temp[fd] = ft_memalloc(1);
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	fd_read(fd, buf, &temp[fd]);
	free(buf);
	*line = ft_strsub(temp[fd], 0, line_length(temp[fd]));
	if (ft_strlen(temp[fd]) == 0)
		return (0);
	del = temp[fd];
	temp[fd] = ft_restrchr(temp[fd], '\n');
	free(del);
	return (1);
}
