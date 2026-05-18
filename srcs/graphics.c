/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:04:52 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/18 19:28:11 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_game_error(t_game *g)
{
	write(2, "Error\nTexture loading failed\n", 29);
	free_textures(g);
	if (g->map)
		free_map(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free(g);
	exit(1);
}

void	init_textures(t_game *g)
{
	int	w;

	g->tex_wall = mlx_xpm_file_to_image(g->mlx, "./textures/wall.xpm", &w, &w);
	g->tex_floor = mlx_xpm_file_to_image(g->mlx, "./textures/floor.xpm", &w,
			&w);
	g->tex_player_front = mlx_xpm_file_to_image(g->mlx,
			"./textures/player_up.xpm", &w, &w);
	g->tex_player_back = mlx_xpm_file_to_image(g->mlx,
			"./textures/player_back.xpm", &w, &w);
	g->tex_player_left = mlx_xpm_file_to_image(g->mlx,
			"./textures/player_left.xpm", &w, &w);
	g->tex_player_right = mlx_xpm_file_to_image(g->mlx,
			"./textures/player_right.xpm", &w, &w);
	g->tex_collect = mlx_xpm_file_to_image(g->mlx, "./textures/collect.xpm", &w,
			&w);
	g->tex_exit = mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm", &w, &w);
	if (!g->tex_wall || !g->tex_floor || !g->tex_player_front
		|| !g->tex_player_back || !g->tex_player_left || !g->tex_player_right
		|| !g->tex_collect || !g->tex_exit)
		close_game_error(g);
	g->tile_size = w;
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
