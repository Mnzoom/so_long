/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:56:55 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/02 16:07:15 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, int new_y, int new_x, void *texture)
{
	if (game->map[new_y][new_x] == WALL || (game->map[new_y][new_x] == EXIT
			&& game->collected < game->collectibles))
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->tex_floor,
		game->player_x * game->tile_size, game->player_y * game->tile_size);
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %i\n", game->moves);
	check_events(game);
	mlx_put_image_to_window(game->mlx, game->win, texture, game->player_x
		* game->tile_size, game->player_y * game->tile_size);
}

void	move_up(t_game *game)
{
	move_player(game, game->player_y - 1, game->player_x,
		game->tex_player_back);
}

void	move_left(t_game *game)
{
	move_player(game, game->player_y, game->player_x - 1,
		game->tex_player_left);
}

void	move_down(t_game *game)
{
	move_player(game, game->player_y + 1, game->player_x,
		game->tex_player_right);
}

void	move_right(t_game *game)
{
	move_player(game, game->player_y, game->player_x + 1,
		game->tex_player_front);
}
