/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:47:32 by eina              #+#    #+#             */
/*   Updated: 2025/10/11 11:38:16 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checktotalstrlen(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	else
		s2_len = 0;
	return (s1_len + s2_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	newstr = malloc(sizeof(char) * (checktotalstrlen(s1, s2) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
