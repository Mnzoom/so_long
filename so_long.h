#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "mlx.h"
#include "ft_printf/inc/ft_printf.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define BUFFER_SIZE 1024
typedef struct s_map
{
	char **grid; 
	int width;
	int height;
	int collectibles;
	int exit_x;
	int exit_y;
}   t_map;
typedef struct s_img
{
	void    *img_ptr;
	int width;
	int height;
}   t_img;
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

int check_walls(t_game *game);
int check_rectangular(t_game *game);
int find_entities(t_game *game);
int load_map(const char *file, t_game *game);
void flood(char **map, int x, int y, t_game *game);
char **copy_map(t_game *game);
int  check_acces(char **map);
int flood_fill(t_game *game);
int parse_map(const char *file, t_game *game);
int init_game(t_game *game);
int keypress(int keycode, t_game *game);
void    move_player(t_game *game, int dx, int dy);
int  load_sprite(t_game *game, t_img *sprite, char *path);
int load_textures(t_game *game);
void    put_sprite(t_game *game, void *img_ptr, int x, int y);
int render_map(t_game *game);
int close_window(t_game *game);
char	*read_doc(int fd, char *buf, char *backup);
char	*set_line(char *line_buffer);
char	*get_next_line(int fd);

#endif