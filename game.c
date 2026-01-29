#include "so_long.h" 

static void flood(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    map[y][x] = 'V';

    flood(map, x + 1, y);
    flood(map, x -1, y);
    flood(map, x, y + 1);
    flood(map, x, y - 1);
}

static char **copy_map(t_game *game)
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

static int  check_acces(char **map)
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