/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:04:52 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/12 12:51:21 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->tex_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &w,
			&h);
	game->tex_floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&w, &h);
	game->tex_player_front = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_up.xpm", &w, &h);
	game->tex_player_back = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_back.xpm", &w, &h);
	game->tex_player_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_left.xpm", &w, &h);
	game->tex_player_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_right.xpm", &w, &h);
	game->tex_collect = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm", &w, &h);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &w,
			&h);
	game->tile_size = w;
}

void	render_tile(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * game->tile_size;
	py = y * game->tile_size;
	mlx_put_image_to_window(game->mlx, game->win, game->tex_floor, px, py);
	if (game->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, px, py);
	else if (game->map[y][x] == PLAYER)
	{
		game->player_x = x;
		game->player_y = y;
		mlx_put_image_to_window(game->mlx, game->win, game->tex_player_front,
			px, py);
	}
	else if (game->map[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_collect, px,
			py);
	else if (game->map[y][x] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_exit, px, py);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
