/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:46:33 by eina              #+#    #+#             */
/*   Updated: 2026/02/05 19:05:00 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *filename)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile == -1)
	{
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		return (-1);
	}
	return (infile);
}

int	open_outfile(char *filename)
{
	int	outfile;

	outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		return (-1);
	}
	return (outfile);
}
