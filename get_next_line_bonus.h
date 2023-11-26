/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:13:05 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/26 19:12:12 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_list {
	char			*content;
	size_t			size;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif /* BUFFER_SIZE */

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif /* OPEN_MAX */

char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, size_t dsize);
void	ft_lst_add_back(t_list **list, t_list *node);
void	ft_lstclear(t_list **list);
t_list	*ft_handle_and_free_node(t_list **list, t_list *node, size_t i);
t_list	*free_line_from_list(t_list **list);

#endif /* GET_NEXT_LINE_BONUS_H */
