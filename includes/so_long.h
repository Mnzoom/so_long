/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:58:55 by cn-goie           #+#    #+#             */
/*   Updated: 2026/05/02 16:06:28 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define VISITED 'V'
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UARROW_KEY 65362
# define LARROW_KEY 65361
# define DARROW_KEY 65364
# define RARROW_KEY 65363
# define ECHAP_KEY 0xFF1B

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;

	void	*tex_player_front;
	void	*tex_player_right;
	void	*tex_player_back;
	void	*tex_player_left;
	void	*tex_collect;
	void	*tex_floor;
	void	*tex_wall;
	void	*tex_exit;

	int		tile_size;
	int		height;
	char	**map;
	int		width;

	int		player_x;
	int		player_y;

	int		player_count;
	int		collectibles;
	int		exit_count;
	int		collected;
	int		moves;
}			t_game;

typedef struct s_pathfinder
{
	int		x;
	int		y;
	int		nb_comp_get;
	int		nb_comp_total;
}			t_pathfinder;

typedef struct s_map
{
	int		tile_size;
	int		map_height;
	int		map_width;
	char	**map;
}			t_map;

void		move_player(t_game *game, int new_y, int new_x, void *texture);
char		**expand_map(char **old_map, int old_size, char *new_line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		browse_map(t_map *map, t_pathfinder *f, int nx, int ny);
void		count_nb_components(t_map *map, t_pathfinder *finder);
bool		pathfinder(t_map *map_copy, t_pathfinder *finder);
void		set_finder_xy(t_map *map, t_pathfinder *finder);
void		count_components(const char *s, t_game *game);
char		*ft_strjoin(char const *s1, char const *s2);
void		get_map_info(t_game *game, char *map_path);
void		render_tile(t_game *game, int x, int y);
int			check_map_walls_inline(t_game *game);
int			check_map_rectangular(t_game *game);
int			check_map_components(t_game *game);
char		*ft_strchr(const char *s, int i);
void		free_map_pathfinding(t_map *map);
int			map_verificator(t_game *game);
int			check_map_walls(t_game *game);
int			map_verificator(t_game *game);
void		init_textures(t_game *game);
int			press_key(int key, void *p);
void		get_map_size(t_game *game);
void		check_events(t_game *game);
void		render_game(t_game *game);
char		*ft_strdup(const char *s);
void		free_struct(t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_down(t_game *game);
t_map		*copy_map(t_game *game);
void		free_map(t_game *game);
char		*get_next_line(int fd);
void		move_up(t_game *game);
int			close_window(void *p);

#endif
