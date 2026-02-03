/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:46:16 by eina              #+#    #+#             */
/*   Updated: 2026/02/03 09:43:12 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*px;

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	px = malloc(sizeof(t_pipex));
	if (!px)
		error_exit("malloc");
	px->envp = envp;
	px->infile = open_infile(argv[1]);
	if (px->infile < 0)
		return (free(px), EXIT_FAILURE);
	px->outfile = open_outfile(argv[4]);
	if (px->outfile < 0)
	{
		close(px->infile);
		free(px);
		exit(EXIT_FAILURE);
	}
	pipex(px, argv, envp);
	close(px->infile);
	close(px->outfile);
	free(px);
	return (0);
}
