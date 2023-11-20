/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:02:19 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/06 16:02:27 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nwline(char *tmp)
{
	char		*ptr;
	int			i;

	i = 0;
	while (tmp && tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (!(ptr = malloc((i + 1))))
		return (NULL);
	i = 0;
	while (tmp && tmp[i] != '\0' && tmp[i] != '\n')
	{
		ptr[i] = tmp[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_free(char *temp)
{
	char	*new_temp;
	int		len;
	int		i;
	int		j;

	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (0);
	}
	len = ft_strlen(temp) - i;
	if (!(new_temp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i++;
	j = 0;
	while (temp[i] != '\0')
		new_temp[j++] = temp[i++];
	new_temp[j] = '\0';
	free(temp);
	return (new_temp);
}

int		get_next_line(int fd, char **line)
{
	int				r;
	char			*buffer;
	static char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	r = 1;
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_strchr(buffer, '\n') || ft_strchr(buffer, '\0'))
			break ;
	}
	free(buffer);
	if (r < 0)
		return (-1);
	*line = ft_nwline(tmp);
	tmp = ft_free(tmp);
	if (r == 0 && !tmp)
		return (0);
	return (1);
}
