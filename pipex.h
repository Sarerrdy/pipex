/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:44:33 by eina              #+#    #+#             */
/*   Updated: 2026/02/03 09:49:41 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**envp;

}			t_pipex;

char		*resolved_path(char *cmd, char **envp);
int			open_outfile(char *filename);
int			open_infile(char *filename);
void		pipex(t_pipex *px, char **argv, char **envp);
void		error_exit(char *msg);
void		free_split(char **arr);
#endif