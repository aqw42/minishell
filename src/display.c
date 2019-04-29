/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:55:42 by conoel            #+#    #+#             */
/*   Updated: 2019/04/29 05:46:34 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		unknown_command(t_token *command)
{
	ft_printf("minishell: Unknown command %s\n", command->content);
}

static void	printer_prompt(char *user, char *display)
{
	if (!get_env("PATH=") || get_env("PATH=")[0] == '\0')
		ft_printf("\033[31m\033[1m /!\\ No PATH /!\\ ");
	ft_printf("%s%s%s %s[%s] %s->%s ", BOLD, CYAN, user, BLUE, display, CYAN,
		DEF);
}

void		print_prompt(void)
{
	char *path;
	char *home;
	char *user;
	char *display;

	path = ft_strdup(get_env("PWD="));
	home = get_env("HOME=");
	user = get_env("USER=");
	if (home && path && home[0] && path[0]
		&& ft_strncmp(path, home, ft_strlen(home)) == 0)
	{
		path[ft_strlen(home) - 1] = '~';
		display = &path[ft_strlen(home) - 1];
	}
	else
		display = path;
	if (user == NULL || user[0] == '\0')
		user = ft_strdup("minishell");
	if (display == NULL || display[0] == '\0')
		display = ft_strdup("?");
	printer_prompt(user, display);
	free(path);
}

void		sigint_catch(int signo)
{
	signo = 0;
	ft_putstr_fd("\n", 1);
	print_prompt();
}
