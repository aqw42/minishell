/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:28:05 by conoel            #+#    #+#             */
/*   Updated: 2019/04/26 15:36:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv)
{
	t_token *instruction;

	if (argc != 2)
		return (0);
	instruction = lexer(argv[1]);
	while (instruction->next)
	{
		ft_printf("<%s [%d]> ", instruction->next->content, instruction->next->type);
		instruction = instruction->next;
	}
}