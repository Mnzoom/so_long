/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:56:36 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/02 15:56:39 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	check_valid_map_again(t_game *game)
{
	int		i;
	int		j;
	char	m;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j + 1])
		{
			m = game->map[i][j];
			if (m != WALL && m != FLOOR && m != EXIT && m != COLLECTIBLE
				&& m != PLAYER)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static t_game	*init_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	ft_bzero(game, sizeof(t_game));
	get_map_info(game, argv[1]);
	get_map_size(game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error\nThe program need a map in argument\n"), 1);
	game = init_game(argv);
	if (check_valid_map_again(game))
		return (ft_printf("Error\nInvalid map\n"), free_struct(game), 1);
	if (map_verificator(game))
		return (free_struct(game), EXIT_FAILURE);
	if (!pathfinder(copy_map(game), &(t_pathfinder){0, 0, 0, 0}))
		return (free_struct(game), ft_printf("Error\nNo valid path\n"), 1);
	game->mlx = mlx_init();
	mlx_do_key_autorepeaton(game->mlx);
	init_textures(game);
	game->win = mlx_new_window(game->mlx, game->width * game->tile_size,
			game->height * game->tile_size, "so_long");
	render_game(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
