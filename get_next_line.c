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

char	*ft_principal(char *guardar, int fd)
{
	int		numBytes;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	numBytes = 1;
	while(numBytes && !ft_strchr(guardar, '\n'))
	{
		numBytes = read(fd, buffer, BUFFER_SIZE);
		if (numBytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		
	}

}



char	*get_next_line(int fd)
{
	char	*linia;
	char	*guardar;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);

	guardar = ft_principal(guardar, fd);
}
