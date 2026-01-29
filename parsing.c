/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:47:30 by clementngoi       #+#    #+#             */
/*   Updated: 2026/01/28 23:01:03 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int load_map(const char *file, t_game *game)
{
    int fd;
    char    *line;
    int i;
    int height;

    height = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (EXIT_FAILURE);
    while ((line = get_next_line(fd)))
    {
        free(line);
        height++;
    }
    close(fd);
    
    if (height == 0)
        return(EXIT_FAILURE);
    game->map.height = height;
    game->map.grid = malloc(sizeof(char *) * height);
    if (!game->map.grid)
        return (EXIT_FAILURE);
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        free(game->map.grid);
        return(EXIT_FAILURE);
    }
    i = 0;
    while (i < game->map.height)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        game->map.grid[i] = ft_strtrim(line, "\n");
        free(line);
        i++;
    }
    close (fd);
    
    game->map.width = ft_strlen(game->map.grid[0]);
    return (0);
}

int parse_map(const char *file, t_game *game)
{
    int len;

    if (!file || !game)
        return(EXIT_FAILURE);
    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
        return(1);
    if (load_map(file, game))
        return (1);
    if (check_rectangular(game))
        return (1);
    if (check_walls(game))
        return (1);
    if (find_entities(game))
        return (1);
    if (flood_fill(game)) 
        return (1);
    return (0);
    
    
}