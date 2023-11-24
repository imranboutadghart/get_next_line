/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:51:26 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/24 16:21:54 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif //BUFFER_SIZE

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_strdup(const char *str);
char    *ft_substr(const char *s, unsigned int start, size_t len);

typedef struct s_list {
	char			*content;
	struct s_list	*next;
} t_list;

#endif //GET_NEXT_LINE_H