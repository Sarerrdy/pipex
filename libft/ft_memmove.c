/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:50:31 by eina              #+#    #+#             */
/*   Updated: 2025/10/07 15:50:35 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (!dest && !src)
		return (NULL);
	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	if (dptr < sptr)
	{
		while (n--)
			*dptr++ = *sptr++;
	}
	else if (dptr > sptr)
	{
		while (n > 0)
		{
			n--;
			dptr[n] = sptr[n];
		}
	}
	return (dest);
}
