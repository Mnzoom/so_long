/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:38:23 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/11 15:24:40 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  load_sprite(t_game *game, t_img *sprite, char *path)
{
    sprite->img_ptr = mlx_xpm_file_to_image(game->mlx, path, 
        &sprite->width, &sprite->height);
    if (!sprite->img_ptr)
        return(EXIT_FAILURE);
    return(EXIT_SUCCESS);
}

int load_textures(t_game *game)
{
    printf("Début du chargement...\n");
    
    if (load_sprite(game, &game->wall, "textures/wall.xpm"))
        return (printf("Erreur: Impossible de charger textures/wall.xpm\n"), 1);
    printf("Wall OK\n");

    if (load_sprite(game, &game->floor, "textures/floor.xpm"))
        return (printf("Erreur: Impossible de charger textures/floor.xpm\n"), 1);
    printf("Floor OK\n");

    if (load_sprite(game, &game->player.sprite, "textures/player.xpm"))
        return (printf("Erreur: Impossible de charger textures/player.xpm\n"), 1);
    printf("Player OK\n");

    if (load_sprite(game, &game->collectibles, "textures/item.xpm"))
        return (printf("Erreur: Impossible de charger textures/item.xpm\n"), 1);
    printf("Item OK\n");

    if (load_sprite(game, &game->exit, "textures/exit.xpm"))
        return (printf("Erreur: Impossible de charger textures/exit.xpm\n"), 1);
    printf("Exit OK\n");

    return (0);
}

void    put_sprite(t_game *game, void *img_ptr, int x, int y)
{
    if(!img_ptr)
        return;
    mlx_put_image_to_window(game->mlx, game->win, img_ptr, x * 64, y * 64);
}
int render_map(t_game *game)
{
    int x;
    int y;
    
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (!game->map.grid[y]) 
                break;
            put_sprite(game, game->floor.img_ptr, x, y);
            if (game->map.grid[y][x] == '1')
                put_sprite(game, game->wall.img_ptr, x, y);
            else if (game->map.grid[y][x] == 'P')
                put_sprite(game, game->player.sprite.img_ptr, x, y); 
            else if (game->map.grid[y][x] == 'C')
                put_sprite(game, game->collectibles.img_ptr, x, y);
            else if (game->map.grid[y][x] == 'E')
                put_sprite(game, game->exit.img_ptr, x, y);
            x++;
        }
        y++;
    }
    return (0);
}

int close_window(t_game *game)
{
    if (game->wall.img_ptr)
        mlx_destroy_image(game->mlx, game->wall.img_ptr);
    if (game->floor.img_ptr)
        mlx_destroy_image(game->mlx, game->floor.img_ptr);
    if (game->player.sprite.img_ptr)
        mlx_destroy_image(game->mlx, game->player.sprite.img_ptr);
    if (game->player.sprite.img_ptr)
        mlx_destroy_image(game->mlx, game->collectibles.img_ptr);
    if (game->exit.img_ptr)
        mlx_destroy_image(game->mlx, game->exit.img_ptr);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->map.grid)
        free_grid(game->map.grid, game->map.height);
    ft_printf("Fermeture du jeu ... A bientot !\n");
    exit(EXIT_SUCCESS);
    return(EXIT_SUCCESS);
}