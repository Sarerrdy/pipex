/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:44:33 by eina              #+#    #+#             */
/*   Updated: 2026/02/05 17:07:49 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>

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
char		**parse_cmd(char *arg);
#endif