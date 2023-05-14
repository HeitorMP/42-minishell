/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaciel- <hmaciel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:34:12 by hmaciel-          #+#    #+#             */
/*   Updated: 2023/04/06 15:26:34 by hmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	1 - Resets the display state to a clean state
	2 - Resets the terminal to the state before readline() was called
	3 - Clears the current prompt
	4 - Moves the cursor to the next line
	5 - redisplay prompt
*/
void	redisplay_prompt(void)
{
	write(1, "\n", STDOUT);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
