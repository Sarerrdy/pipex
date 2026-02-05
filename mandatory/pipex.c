/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 03:07:33 by eina              #+#    #+#             */
/*   Updated: 2026/02/05 19:04:50 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_and_free(t_pipex *px, int fd[2], char **tokens, char *msg)
{
	if (fd)
	{
		if (fd[0] >= 0)
			close(fd[0]);
		if (fd[1] >= 0)
			close(fd[1]);
	}
	if (tokens)
		free_split(tokens);
	if (px)
		free(px);
	if (msg)
		error_exit(msg);
}

static void	handle_infile(t_pipex *px)
{
	int	devnull;

	if (px->infile >= 0)
	{
		dup2(px->infile, STDIN_FILENO);
		return ;
	}
	devnull = open("/dev/null", O_RDONLY);
	if (devnull >= 0)
	{
		dup2(devnull, STDIN_FILENO);
		close(devnull);
	}
}

static void	child1(t_pipex *px, int fd[2], char **argv, char **envp)
{
	char	*full;
	char	**tokens;

	tokens = parse_cmd(argv[2]);
	if (!tokens || !tokens[0])
		close_and_free(px, fd, tokens, " ");
	full = resolved_path(tokens[0], envp);
	if (!full)
	{
		write(2, tokens[0], ft_strlen(tokens[0]));
		write(2, ": command not found\n", 20);
		close_and_free(px, fd, tokens, NULL);
		exit(127);
	}
	handle_infile(px);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	free(px);
	execve(full, tokens, envp);
	perror(tokens[0]);
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
		close_and_free(px, fd, tokens, " ");
	full = resolved_path(tokens[0], envp);
	if (!full)
	{
		write(2, tokens[0], ft_strlen(tokens[0]));
		write(2, ": command not found\n", 20);
		close_and_free(px, fd, tokens, NULL);
		exit(127);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(px->outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	free(px);
	execve(full, tokens, envp);
	perror(tokens[0]);
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
		close_and_free(px, fd, NULL, "fork");
	if (pid1 == 0)
		child1(px, fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		close_and_free(px, fd, NULL, "fork");
	if (pid2 == 0)
		child2(px, fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
