/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 04:13:43 by pcottet           #+#    #+#             */
/*   Updated: 2021/12/29 04:57:41 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_merge(char **line1, ssize_t *size1, char *line2, ssize_t size2)
{
	char	*tmp_line;

	tmp_line = merge_lines(*line1, *size1, line2, size2);
	free(*line1);
	*size1 = *size1 + size2;
	return (tmp_line);
}

int	ft_init(char *rest, ssize_t *rest_size, char **line, ssize_t *line_size)
{
	*line = NULL;
	*line_size = 0;
	if (*rest_size > 0)
	{
		*line = malloc(sizeof(char) * (*rest_size + 1));
		if (*line == NULL)
			return (0);
		ft_memcpy(*line, rest, *rest_size);
		(*line)[*rest_size] = '\0';
		*line_size = *rest_size;
		*rest_size = 0;
	}
	return (1);
}

char	*ft_newline(char *buffer, int fd, char *rest, ssize_t *rest_size)
{
	char			*line;
	ssize_t			nl_pos;
	ssize_t			line_size;
	ssize_t			read_size;

	if (!ft_init(rest, rest_size, &line, &line_size))
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		nl_pos = find_new_line(buffer, read_size);
		if (nl_pos == -1)
			line = ft_merge(&line, &line_size, buffer, read_size);
		else
		{
			line = ft_merge(&line, &line_size, buffer, nl_pos + 1);
			*rest_size = read_size - (nl_pos + 1);
			if (*rest_size)
				ft_memmove(rest, &buffer[nl_pos + 1], *rest_size);
			break ;
		}
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static char		rest[BUFFER_SIZE];
	static ssize_t	rest_size;
	ssize_t			nl_pos;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl_pos = find_new_line(rest, rest_size);
	if (nl_pos >= 0)
	{
		line = malloc(sizeof(char) * (nl_pos + 2));
		if (line == NULL)
			return (NULL);
		ft_memcpy(line, rest, nl_pos + 1);
		line[nl_pos + 1] = '\0';
		rest_size = rest_size - (nl_pos + 1);
		ft_memmove(rest, &rest[nl_pos + 1], rest_size);
		return (line);
	}
	return (ft_newline(buffer, fd, rest, &rest_size));
}
