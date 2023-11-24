/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:51:21 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/24 16:18:42 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	construct_line(t_list **list, char *line)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;
	char	*tmpline;

	if (!(*list) || !(*list)->content)
		return ;
	j = 0;
	while((*list) && (*list)->content)
	{
		i = -1;
		while (((*list)->content)[++i])
		{
			line[j] = ((*list)->content)[i];
			j++;
			if ('\n' == ((*list)->content)[i])
			{
				line[j] = '\0';
				tmpline = ft_substr((*list)->content, i + 1, BUFFER_SIZE);
				free((*list)->content);
				(*list)->content = tmpline;
				(*list)->next = 0;
				return ;
			}
		}
		line[j] = '\0';
		tmp = (*list);
		(*list) = (*list)->next;
		free(tmp->content);
		free(tmp);
	}
	return ;
}

size_t	line_len_from_list(t_list *list)
{
	size_t	i;
	size_t	j;

	if (!list || !list->content)
		return (0);
	j = 0;
	while(list && list->content)
	{
		i = -1;
		while ((list->content)[++i])
		{
			j++;
			if ('\n' == (list->content)[i])
				return (j);
		}
		list = list->next;
	}
	return (j);
}

int		list_have_new_line(t_list *list)
{
	size_t	i;

	if (!list || !list->content)
		return (0);
	while(list && list->content)
	{
		i = -1;
		while ((list->content)[++i])
		{
			if ('\n' == (list->content)[i])
				return (1);
		}
		list = list->next;
	}
	return (0);
}

char	*make_line(t_list **list)
{
	char		*line;
	size_t		len;

	if (!list_have_new_line(*list))
		return (0);
	len = line_len_from_list(*list);
	line = malloc(sizeof(char ) * (len + 1));
	construct_line(list, line);
	return (line);
}

char	*get_line(t_list **list, int fd)
{
	t_list	*tmp;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	tmp = (*list);
	bytes_read = 1;
	while (!list_have_new_line(*list) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		tmp->next = malloc(sizeof(t_list));
		tmp = tmp->next;
		tmp->content = ft_strdup(buffer);
		tmp->next = 0;
	}
	return (make_line(list));
}

char	*get_next_line(int fd)
{
	static t_list *list = 0;
	char	buffer[BUFFER_SIZE + 1];
	char			*line;

	if (read(fd, line, 0) == -1)
		return (0);
	if (!list)
	{
		list = malloc (sizeof(t_list));
		buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
		list->content = ft_strdup(buffer);
	}
	line = get_line(&list, fd);
	return (line);
}

#include <stdio.h>
int main(void)
{
	int		fd = open("get_next_line.h", O_RDONLY);
	char	*line;
	while(line = get_next_line(fd))
		printf("%s", line);
	return (0);
}
