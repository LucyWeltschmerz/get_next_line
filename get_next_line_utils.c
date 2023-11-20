/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:02:45 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/06 16:02:50 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sjoin;
	int		i;
	int		j;

	if (!(sjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	if (s1)
		while (s1[i] != '\0')
		{
			sjoin[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (s2[j] != '\0')
			sjoin[i++] = s2[j++];
	sjoin[i] = '\0';
	free(s1);
	return (sjoin);
}

int		ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
