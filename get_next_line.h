/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:51:26 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/24 23:05:11 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list {
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_head {
	char	buffer[BUFFER_SIZE];
	t_list	*next;
}	t_head;

char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*get_line(t_list **list, int fd);
char	*make_line(t_head *list, int fd);
size_t	line_len_from_list(t_list *list, int get_len);
void	construct_line(t_list **list, char *line);
char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_H