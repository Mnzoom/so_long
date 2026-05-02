/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:57:02 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/02 15:57:04 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*copy_map(t_game *game)
{
	t_map	*map_copied;
	int		i;

	map_copied = malloc(sizeof(t_map));
	if (!map_copied)
		return (NULL);
	map_copied->map_height = game->height;
	map_copied->map_width = game->width;
	map_copied->map = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copied->map)
		return (free(map_copied), NULL);
	i = 0;
	while (i < game->height)
	{
		map_copied->map[i] = ft_strdup(game->map[i]);
		if (!map_copied->map[i])
			return (free_map_pathfinding(map_copied), free(map_copied), NULL);
		i++;
	}
	map_copied->map[i] = NULL;
	return (map_copied);
}

void	count_nb_components(t_map *map, t_pathfinder *finder)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_height)
	{
		j = -1;
		while (++j < map->map_width)
			if (map->map[i][j] == COLLECTIBLE ||
				map->map[i][j] == EXIT)
				finder->nb_comp_total++;
	}
}

void	set_finder_xy(t_map *map, t_pathfinder *finder)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map[i][j] == PLAYER)
			{
				finder->y = i;
				finder->x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	browse_map(t_map *map, t_pathfinder *f, int nx, int ny)
{
	if (map->map[ny][nx] == EXIT ||
		map->map[ny][nx] == COLLECTIBLE)
		f->nb_comp_get++;
	if (map->map[ny][nx] == VISITED ||
		map->map[ny][nx] == WALL)
		return ;
	if (map->map[ny][nx] == EXIT)
	{
		map->map[ny][nx] = VISITED;
		return ;
	}
	map->map[ny][nx] = VISITED;
	browse_map(map, f, nx + 1, ny);
	browse_map(map, f, nx - 1, ny);
	browse_map(map, f, nx, ny + 1);
	browse_map(map, f, nx, ny - 1);
}

bool	pathfinder(t_map *map_copy, t_pathfinder *finder)
{
	count_nb_components(map_copy, finder);
	set_finder_xy(map_copy, finder);
	browse_map(map_copy, finder, finder->x, finder->y);
	free_map_pathfinding(map_copy);
	free(map_copy);
	return (finder->nb_comp_get == finder->nb_comp_total);
}
