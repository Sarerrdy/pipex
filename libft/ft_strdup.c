/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:36:43 by eina              #+#    #+#             */
/*   Updated: 2025/10/11 11:36:48 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	char	*dup;

	newstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	dup = newstr;
	if (!newstr)
		return (NULL);
	while (*s)
	{
		*newstr++ = *s++;
	}
	*newstr = '\0';
	return (dup);
}
