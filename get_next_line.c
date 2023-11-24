/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:09:15 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/24 23:17:39 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	head_has_new_line(t_head head)
{
	size_t	i;
	size_t	j;
	t_list	*list;

	i = 0;
	while(head.buffer[i])
	{
		if ('\n' == head.buffer[i])
			return (i + 2);
		i++;
	}
	j = i;
	list = head.next;
	while (list)
	{
		i = (size_t)-1;
		while(list->content[++i])
		{
			if ('\n' == list->content[i])
				return (j);
			j++;
		}
	}
}

char	*make_line(t_head *head, int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	t_list	*tmp;
	int		bytes_read;

	if (head_has_new_line(*head))
		return (get_line_from_head(head));
	tmp = head->next;
	bytes_read = 1;
	while (!head_has_new_line(*head) && bytes_read > 0)
	{
		
	}
	
}

char	*get_next_line(int fd)
{
	static t_head	head;

	if (fd < 0 || read(fd, head.buffer, 0) < 0)
		return (0);
	make_line(&head, fd);
	return (0);
}

#include <stdio.h>
int main(void)
{
	int		fd;
	char	*line;

	fd = open("files/41_no_nl", O_RDONLY);
	line = (char *)1;
	line = get_next_line(fd);
	while (line)
	{
		printf(line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}