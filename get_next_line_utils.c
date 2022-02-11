/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:39:52 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/11 18:39:55 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	c1;

	s1 = (char *)s;
	c1 = (char)c;
	while (*s1)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	if (*s1 == c1)
		return (s1);
	return (NULL);
}