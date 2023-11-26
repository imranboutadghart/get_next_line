/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:13:24 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/26 19:19:07 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, size_t dsize)
{
	size_t	i;

	if (!dest || !src)
		return (dest);
	i = 0;
	while (i < dsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_lst_add_back(t_list **line, t_list *node)
{
	t_list	*tmp;

	if (!line || !node)
		return ;
	tmp = *line;
	if (!tmp || !tmp->content)
	{
		*line = node;
		return ;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return ;
}

void	ft_lstclear(t_list **line)
{
	t_list	*tmp;
	t_list	*next;

	if (!line || !*line)
		return ;
	tmp = *line;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*line = NULL;
	return ;
}

t_list	*ft_handle_and_free_node(t_list **line, t_list *node, size_t i)
{
	char	*new_block;

	new_block = (char *)malloc(sizeof(char) * (node->size - i));
	if (!new_block)
		return (NULL);
	new_block = ft_strncpy(new_block, node->content + i + 1, node->size - i);
	i = 0;
	while (new_block[i])
		i++;
	node->size = i;
	return (free(node->content), node->content = new_block, *line = node, node);
}

t_list	*free_line_from_list(t_list **line)
{
	t_list	*tmp;
	t_list	*next;
	size_t	i;

	tmp = *line;
	while (tmp)
	{
		next = tmp->next;
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
			i++;
		if (!tmp->content[i])
		{
			free(tmp->content);
			free(tmp);
		}
		else if (tmp->content[i] == '\n')
			return (ft_handle_and_free_node(line, tmp, i));
		tmp = next;
	}
	*line = 0;
	return (0);
}
