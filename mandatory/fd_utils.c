/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:46:33 by eina              #+#    #+#             */
/*   Updated: 2026/02/03 11:17:59 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *filename)
{
	int	infile;

	infile = open(filename, O_RDONLY);
	if (infile == -1)
	{
		perror(filename);
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
		perror(filename);
		return (-1);
	}
	return (outfile);
}
