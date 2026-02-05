/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:16:29 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/03 15:39:40 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keypress(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        close_window(game);
    if (keycode == KEY_W)
        move_player(game, 0, -1);
    if (keycode == KEY_S)
        move_player(game, 0, 1);
    if (keycode == KEY_A)
        move_player(game, -1, 0);
    if (keycode == KEY_D)
        move_player(game, 1, 0);
    return (EXIT_SUCCESS);
}

void    move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->player.x + dx;
    new_y = game->player.y + dy;
    
    if (game->map.grid[new_y][new_x] == '1')
        return ;
    if (game->map.grid[new_y][new_x] == 'C')
        game->map.collectibles--;
    if (game->map.grid[new_y][new_x] == 'E')
    {
        if (game->map.collectibles == 0)
        {
            ft_printf("Bravo ! Vous avez gagne en %d mouvements !\n", game->player.moves + 1);
            close_window(game);
            return ;
        }
    }
    if (game->player.x == game->map.exit_x && game->player.y == game->map.exit_y)
        game->map.grid[game->player.y][game->player.x] = 'E';
    else
        game->map.grid[game->player.y][game->player.x] = '0';
    game->player.x = new_x;
    game->player.y = new_y;

    if (!(new_x == game->map.exit_x && new_y == game->map.exit_y))
        game->map.grid[new_y][new_x] = 'P';
    game->player.moves++;
    ft_printf("Mouvements: %d\n", game->player.moves);
    render_map(game); //Fonctin que t'as toujours pas fait avec close et open window //
}