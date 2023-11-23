/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:51:23 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/23 19:34:59 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t  size;
	size_t  i;
	char    *dst;

	size = 0;
	while (str[size] && size < BUFFER_SIZE)
		size++;
	dst = malloc ((size + 1) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	while (++i <= size)
		dst[i] = str[i];
	return (dst);
}


char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        size_t                  slen;
        char                    *dst;
        unsigned int    i;

        if (!s)
                return (0);
        slen = 0;
		while (s[slen])
			slen++;
        if (start > slen || !len)
                return (ft_strdup(""));
		if (slen - start > len)
        	dst = (char *)malloc((len + 1) * sizeof(char));
        else
        	dst = (char *)malloc((slen - start + 1) * sizeof(char));
		if (!dst)
                return (0);
        i = 0;
        while (s[start] && i < len)
                dst[i++] = s[start++];
        dst[i] = '\0';
        return (dst);
}