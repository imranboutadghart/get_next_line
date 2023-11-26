/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:12:54 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/26 19:18:10 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int add_line(t_list **list, char *buffer, int bytes_read)
{
	t_list	*new_node;
	char	*str;

	if (!buffer || !bytes_read)
		return (1);
	new_node = (t_list *)malloc(sizeof(t_list));
	str = (char *)malloc(sizeof(char) * (bytes_read + 1));
	if (!new_node || !str)
		return (free(new_node), 0);
	str = ft_strncpy(str, buffer, bytes_read + 1);
	new_node->content = str;
	new_node->size = bytes_read;
	new_node->next = 0;
	ft_lst_add_back(list, new_node);
	return (1);
}

size_t	get_line_len(t_list *line, int eof)
{
	size_t	len;
	size_t	i;
	t_list	*tmp;

	tmp = line;
	len = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == '\n')
				return (len + 1);
			len++;
			i++;
		}
		tmp = tmp->next;
	}
	if (eof)
		return (len);
	return (0);
}

static char	*copy_line(char *ret_line, t_list *line, size_t size)
{
	size_t	i;
	size_t	j;
	t_list	*tmp;

	if (!ret_line || !line)
		return (0);
	i = 0;
	tmp = line;
	while (tmp && i < size)
	{
		j = 0;
		while (tmp->content[j])
		{
			ret_line[i++] = tmp->content[j];
			if (tmp->content[j++] == '\n')
				break ;
		}
		tmp = tmp->next;
	}
	ret_line[i] = '\0';
	return (ret_line);
}

char	*get_line(t_list **list, int eof)
{
	char	*result;
	size_t	size;

	if (!list || !*list || !((*list)->content))
		return (0);
	size = get_line_len(*list, eof);
	if (!size)
		return (0);
	result = (char *)malloc(sizeof(char ) * (size + 1));
	if (!result)
		return (0);
	result = copy_line(result, *list, size);
	*list = free_line_from_list(list);
	return (result);
}

char    *get_next_line(int fd)
{
    static t_list	*list_arr[OPEN_MAX];
	t_list			**list;
    char			*buffer;
    char			*result;
	int				bytes_read;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	list = &list_arr[fd];
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_lstclear(list), NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || !add_line(list, buffer, bytes_read))
			return (ft_lstclear(list), free(buffer), NULL);
		result = get_line(list, (bytes_read == 0));
		if (result)
			return (free(buffer), result);
	}
	return (ft_lstclear(list), free(buffer), NULL);
}