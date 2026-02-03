/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:07:33 by eina              #+#    #+#             */
/*   Updated: 2026/02/03 14:43:24 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_cmd(char *arg)
{
	char	**tokens;
	int		i;
	int		j;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '\0')
		{
			j = i;
			while (tokens[j])
			{
				tokens[j] = tokens[j + 1];
				j++;
			}
		}
		else
			i++;
	}
	return (tokens);
}

static void	child1(t_pipex *px, int fd[2], char **argv, char **envp)
{
	char	*full;
	char	**tokens;

	tokens = parse_cmd(argv[2]);
	if (!tokens || !tokens[0])
		exit(EXIT_FAILURE);
	full = resolved_path(tokens[0], envp);
	if (!full)
	{
		write(2, tokens[0], ft_strlen(tokens[0]));
		write(2, ": command not found\n", 20);
		free_split(tokens);
		exit(127);
	}
	dup2(px->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(px->infile);
	close(px->outfile);
	execve(full, tokens, envp);
	perror("execve");
	free(full);
	free_split(tokens);
	exit(EXIT_FAILURE);
}

static void	child2(t_pipex *px, int fd[2], char **argv, char **envp)
{
	char	*full;
	char	**tokens;

	tokens = parse_cmd(argv[3]);
	if (!tokens || !tokens[0])
		exit(EXIT_FAILURE);
	full = resolved_path(tokens[0], envp);
	if (!full)
	{
		write(2, tokens[0], ft_strlen(tokens[0]));
		write(2, ": command not found\n", 20);
		free_split(tokens);
		exit(127);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(px->outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(px->infile);
	close(px->outfile);
	execve(full, tokens, envp);
	perror("execve");
	free(full);
	free_split(tokens);
	exit(EXIT_FAILURE);
}

void	pipex(t_pipex *px, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork");
	if (pid1 == 0)
		child1(px, fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork");
	if (pid2 == 0)
		child2(px, fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
