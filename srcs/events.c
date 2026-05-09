/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:04:17 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/09 16:04:18 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

int	close_window(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	free_struct(game);
	exit(EXIT_SUCCESS);
}

int	press_key(int key, void *p)
{
	if (key == ECHAP_KEY)
		close_window((t_game *)p);
	if (key == W_KEY || key == UARROW_KEY)
		move_up((t_game *)p);
	if (key == A_KEY || key == LARROW_KEY)
		move_left((t_game *)p);
	if (key == S_KEY || key == DARROW_KEY)
		move_down((t_game *)p);
	if (key == D_KEY || key == RARROW_KEY)
		move_right((t_game *)p);
	return (EXIT_SUCCESS);
}

void	check_events(t_game *game)
{
	char	cell;

	cell = game->map[game->player_y][game->player_x];
	if (cell == COLLECTIBLE)
	{
		game->collected += 1;
		game->map[game->player_y][game->player_x] = '0';
	}
	else if (cell == EXIT)
		close_window(game);
}
