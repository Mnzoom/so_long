/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:09:40 by clementngoi       #+#    #+#             */
/*   Updated: 2026/01/28 14:21:45 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int find_entities(t_game *game)
{
    int x;
    int y;
    int player_count;
    int enemies_count;
    int collectibles;
    int exit_count;

    y = 0;
    player_count = 0;
    enemies_count = 0;
    collectibles = 0;
    exit_count = 0;

    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.grid[y][x] == 'P')
            {
                game->player.x = x;
                game->player.y = y;
                game->player.type = 0;
                player_count++;
            }
            else if (game->map.grid[y][x] == 'E')
            {
                game->map.exit_x = x;
                game->map.exit_y = y;
                exit_count++;
            }
            else if (game->map.grid[y][x] == 'C')
                collectibles++;
            else if (game->map.grid[y][x] == 'N')
                enemies_count++;
            else if ( game->map.grid[y][x] == '1' 
                || game->map.grid[y][x] == '0')
            ;
            else
                return (EXIT_FAILURE);
            x++;
        }
        y++;
    }
    game->map.collectibles = collectibles;
    game->nb_enemies = enemies_count;
    if (player_count != 1 || exit_count != 1 || collectibles < 1)
        return (EXIT_FAILURE);
    return (0);
}

int check_rectangular(t_game *game)
{
    int i;
    int width;

    i = 0;
    width = game->map.width;
    while (i < game->map.height)
    {
        if ((int)ft_strlen(game->map.grid[i]) != width)
            return (EXIT_FAILURE);
        i++;
    }
    return (0);
}

int check_walls(t_game *game)
{
    int x;
    int y;
    
    x = 0;
    while (x < game->map.width)
    {
        if (game->map.grid[0][x] != '1')
            return(EXIT_FAILURE);
        x++;
    }
    x = 0;
    while (x < game->map.width)
    {
        if (game->map.grid[game->map.height - 1][x] != '1')
            return (EXIT_FAILURE);
        x++;
    }
    y = 0;
    while (y < game->map.height)
    {
        if (game->map.grid[y][0] != '1'
        || game->map.grid[y][game->map.width - 1] != '1')
            return (EXIT_FAILURE);
        y++;
    }
    return (EXIT_SUCCESS);
}
