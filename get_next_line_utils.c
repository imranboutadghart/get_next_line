/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <iboutadg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:51:23 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/17 01:50:27 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
        size_t  size;
        size_t  i;
        char    *dst;

        size = ft_strlen(str);
        dst = malloc ((size + 1) * sizeof(char));
        if (!dst)
                return (0);
        i = -1;
        while (++i <= size)
                dst[i] = str[i];
        return (dst);
}