/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:51:21 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/18 03:15:04 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		list_have_new_line(t_list *list)
{
	size_t	i;

	if (!list)
		return (0);
	while(list)
	{
		i = -1;
		while (++i < list->end)
		{
			if ('\n' == (list->content)[i++])
				return (1);
		}
		list = list->next;
	}
	return (0);
}

char	*get_line(t_list *list, int fd)
{
	t_list	*tmp;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	if (!list)
		list = malloc(sizeof(t_list));
	if (!list)
		return(0);
	tmp = list;
	bytes_read = 1;
	while (!list_have_new_line(list) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		tmp->content = ft_strdup(buffer);
		tmp->end = bytes_read;
		tmp->next = malloc(sizeof(t_list));
		tmp = tmp->next;
		tmp->next = 0;
	}
	return (make_line(list));
}

char	*get_next_line(int fd)
{
	static t_list *list;
	char			line;

	if (read(fd, line, 0) == -1)
		return (0);
	line = get_line(list, fd);
	return (line);
}
