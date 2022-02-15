/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:57:12 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/11 17:57:15 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_principal(char *guardar, int fd)
{
	int		numBytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	numBytes = 1;
	while(numBytes != 0 && !ft_strchr(guardar, '\n'))
	{
		numBytes = read(fd, buffer, BUFFER_SIZE);
		if (numBytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[numBytes] = '\0';
		guardar = ft_strjoin(guardar, buffer);
		
	}
	free(buffer);
	return(guardar);
}

char	*ft_linia(char *guardar)
{
	int  i;
	char *str;

	i = 0;
	while (guardar[i] != 0 && guardar[i] != '\n')
		i++;

	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (0);
	
	while (guardar[i] != 0 && guardar[i] != '\n')
	{
		str[i] = guardar[i];
		i++;
	}

	if (guardar[i] == '\n')
	{
		str[i] = guardar[i];
		i++;
	}

	str[i] = '\0';
	return (str);
}

char	*ft_static(char *guardar)
{
	int i;
	int len;
	char *str2;

	i = 0;

	while(guardar[i] != 0 && guardar[i] != '\n')
		i++;
	len =  (ft_strlen(guardar) - i);
	str2 = malloc((len + 1) * sizeof(char));
	return (str2);
}

char	*get_next_line(int fd)
{
	char	*linia;
	static char	*guardar;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);

	guardar = ft_principal(guardar, fd);
	if (!guardar)
		return (0);
	linia = ft_linia(guardar);
	//guardar = ft_static(guardar);
	return(linia);
}

int	main(void)
{

	int		fd;

	fd = open("/Users/tmerida-/Desktop/42CURSUS/get_next_line/text.txt", O_RDONLY);
	while (fd)
	{
		printf("prueba: %s", get_next_line(fd));
		if (!get_next_line(fd))
			return (0);
	}
	free (get_next_line(fd));
	close(fd);
	return (0);
}