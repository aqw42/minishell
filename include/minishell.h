/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:28:18 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 15:54:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include "lexer.h"

extern char		**environ;
t_token			*g_command;
pid_t			g_pid;

typedef struct	s_builtin
{
	t_token_type	type;
	int				(*function)(t_token *);
}				t_builtin;

/*
**	EXEC_COMMAND
*/
int				exec_command(t_token *command);

/*
**	BUILTIN
*/
int				pwd_handler(t_token *command);
int				cd_handler(t_token *command);
int				echo_handler(t_token *command);
int				env_handler(t_token *command);
int				setenv_handler(t_token *command);
int				unsetenv_handler(t_token *command);
int				exit_handler(t_token *command);
int				clear_handler(t_token *command);

/*
**	UTILS
*/
char			*get_env(char *var);
char			**get_env_addr(char *var);
void			set_env(char *var_name, char *new);
void			unset_env(char *var_name);
t_token			*check_semilicon(t_token *command);
char			**allocate_args(t_token *command);
char			**realloc_tab_remove_index(char **tab, size_t index);
char			**realloc_tab_add_var(char **tab, char *new);
char			**copy_tab(char **tab);

/*
**	DISPLAY
*/
void			unknown_command(t_token *command);
void			print_prompt(void);
void			sigint_catch(int signo);
void			quit(void);

#endif
