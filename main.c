/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:11:09 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/05 12:24:45 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_game  game;
    if (ac != 2)
    {
        ft_printf("Error\n Usage: ./so_long maps/map.ber\n");
        return (EXIT_FAILURE);
    }
    ft_memset(&game, 0, sizeof(t_game));

    if (parse_map(av[1], &game) == EXIT_FAILURE)
        return (1);
    if (flood_fill(&game) == EXIT_FAILURE)
    {
        // maybe free aussi ici //
        return (1);
    }
    if (init_game(&game) == EXIT_FAILURE)
        return (close_window(&game));
    render_map(&game);
    mlx_key_hook(game.win, keypress, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    mlx_loop(game.mlx);
    return (0);
}