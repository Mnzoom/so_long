/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:27:03 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/05 12:34:07 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void flood(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    map[y][x] = 'V';

    flood(map, x + 1, y);
    flood(map, x -1, y);
    flood(map, x, y + 1);
    flood(map, x, y - 1);
}

char **copy_map(t_game *game)
{
    char **copy;
    int i;

    copy = malloc(sizeof(char *) * game->map.height);
    if (!copy)
        return (NULL);

    i = 0;
    while (i < game->map.height)
    {
        copy[i] = ft_strdup(game->map.grid[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    return (copy);
}

int  check_acces(char **map)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C' || map[y][x] == 'E')
                return (EXIT_FAILURE);
            x++;
        }
        y++;
    }
    return (0);
}

int flood_fill(t_game *game)
{
    char **map_copy;
    int result;

    map_copy = copy_map(game);
    if (!map_copy)
        return (EXIT_FAILURE);
    flood(map_copy, game->player.x, game->player.y);
    result = check_acces(map_copy);

    int i = 0;
    while (i < game->map.height)
        free(map_copy[i++]);
    free(map_copy);

    return(result);
}