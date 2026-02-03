/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:31:26 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/03 14:36:37 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (EXIT_FAILURE);
    game->win = mlx_new_window(game->mlx, game->map.width * 64, game->map.height * 64, "so_long");
    if (!game->win)
        return (EXIT_FAILURE);
    if (load_textures(game) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}