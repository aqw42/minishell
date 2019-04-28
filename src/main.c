/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:28:05 by conoel            #+#    #+#             */
/*   Updated: 2019/04/28 21:07:50 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(void)
{
	char	*line;
	t_token *command;

	if (signal(SIGINT, sigint_catch) == SIG_ERR)
		ft_putstr_fd("minishell: Cannot handle SIGINT...\n", 2);
	if (!get_env("PWD=") || !get_env("USER=") || !get_env("PATH="))
		ft_putstr_fd("minishell: Path / User / Pwd env unavailable\n\
Please define them with `setenv name [value]`\n", 2);
	while (1)
	{
		print_prompt();
		line = get_the_file(0);
		if (ft_strlen(line) == 0)
			break;
		command = lexer(line);
		exec_command(command->next);
		release_tokens(command);
	}
	return (1);
}
