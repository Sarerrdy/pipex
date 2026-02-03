/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:27:16 by eina              #+#    #+#             */
/*   Updated: 2025/10/11 11:27:20 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	if (n > 0)
		len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbrstr;
	int		len;
	long	num;

	num = n;
	len = ft_int_len(n);
	nbrstr = malloc(sizeof(char) * (len + 1));
	if (!nbrstr)
		return (NULL);
	nbrstr[len] = '\0';
	if (num == 0)
		nbrstr[0] = '0';
	if (num < 0)
	{
		nbrstr[0] = '-';
		num = -num;
	}
	while (num)
	{
		nbrstr[--len] = num % 10 + '0';
		num = num / 10;
	}
	return (nbrstr);
}
