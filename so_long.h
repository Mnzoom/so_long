#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_map
{
	char **grid; 
	int width;
	int height;
	int collectibles;
	int exit_x;
	int exit_y;
}   t_map;

typedef struct s_entity
{
	int	x;
	int	y;
	t_img	sprite;
	int	type;
	int	moves;
	int health;
	int	last_move_time;
	
}	t_entity;

typedef struct s_img
{
	void    *img_ptr;
	int width;
	int height;
}   t_img;

typedef struct s_game
{
	void    *mlx;
	void    *win;
	t_map   map;
	t_entity    player;
	t_entity    *enemies;
	int	nb_enemies;
	t_img	wall;
	t_img	floor;
	t_img	exit;
	t_img	collectibles;
}	t_game;

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int check_walls(t_game *game);
int check_rectangular(t_game *game);
int find_entities(t_game *game);
int load_map(const char *file, t_game *game);
static void flood(char **map, int x, int y);
static char **copy_map(t_game *game);
static int  check_acces(char **map);
int flood_fill(t_game *game);
int parse_map(const char *file, t_game *game);


#endif