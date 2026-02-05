/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:38:23 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/05 12:34:34 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  load_sprite(t_game *game, t_img *sprite, char *path)
{
    sprite->img_ptr = mlx_png_file_to_image(game->mlx, path, 
        &sprite->width, &sprite->height);
    if (!sprite->img_ptr)
        return(EXIT_FAILURE);
    return(EXIT_SUCCESS);
}

int load_textures(t_game *game)
{
    if (load_sprite(game, &game->wall, "textures/wall.xpm")
    || load_sprite(game, &game->floor, "textures/floor.xpm")
    ||load_sprite(game, &game->player.sprite, "textures/player.xpm")
    ||load_sprite(game, &game->collectibles, "textures/item.xpm")
    || load_sprite(game, &game->exit, "textures/exit.view.xpm"))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void    put_sprite(t_game *game, void *img_ptr, int x, int y)
{
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
            put_sprite(game, game->floor.img_ptr, x, y);
            
            if (game->map.grid[y][x] == '1')
                put_sprite(game, game->wall.img_ptr, x, y);
            else if (game->map.grid[y][x] == 'P')
                put_sprite(game, game->player.sprite.img_ptr, y, x);
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
    int i;

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
    i = 0;
    while (i < game->map.height)
        free(game->map.grid[i++]);
    free(game->map.grid);
    ft_printf("Fermeture du jeu... A bientot !\n");
    exit(0);
    return(EXIT_SUCCESS);
}