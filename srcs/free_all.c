/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:04:33 by clementngoi       #+#    #+#             */
/*   Updated: 2026/05/18 19:38:30 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	y;

	if (!game->map)
		return ;
	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_map_pathfinding(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
}

void	destroy_images(t_game *game)
{
	if (game->tex_wall)
		mlx_destroy_image(game->mlx, game->tex_wall);
	if (game->tex_floor)
		mlx_destroy_image(game->mlx, game->tex_floor);
	if (game->tex_player_front)
		mlx_destroy_image(game->mlx, game->tex_player_front);
	if (game->tex_player_back)
		mlx_destroy_image(game->mlx, game->tex_player_back);
	if (game->tex_player_left)
		mlx_destroy_image(game->mlx, game->tex_player_left);
	if (game->tex_player_right)
		mlx_destroy_image(game->mlx, game->tex_player_right);
	if (game->tex_collect)
		mlx_destroy_image(game->mlx, game->tex_collect);
	if (game->tex_exit)
		mlx_destroy_image(game->mlx, game->tex_exit);
}

void	free_struct(t_game *game)
{
	destroy_images(game);
	free_map(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	free_textures(t_game *g)
{
	void	*tex[8];
	int		i;

	tex[0] = g->tex_wall;
	tex[1] = g->tex_floor;
	tex[2] = g->tex_player_front;
	tex[3] = g->tex_player_back;
	tex[4] = g->tex_player_left;
	tex[5] = g->tex_player_right;
	tex[6] = g->tex_collect;
	tex[7] = g->tex_exit;
	i = 0;
	while (i < 8)
	{
		if (tex[i])
			mlx_destroy_image(g->mlx, tex[i]);
		i++;
	}
}
