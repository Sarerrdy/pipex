/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:30:10 by eina              #+#    #+#             */
/*   Updated: 2025/10/11 11:31:16 by eina             ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	int		len;
	char	nstr[12];

	len = ft_int_len(n);
	ln = n;
	nstr[len] = '\0';
	if (ln == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (ln < 0)
	{
		nstr[0] = '-';
		ln = -ln;
	}
	while (ln)
	{
		nstr[--len] = ln % 10 + '0';
		ln = ln / 10;
	}
	ft_putstr_fd(nstr, fd);
}
