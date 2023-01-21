#ifndef CUBD3D_H
# define CUBD3D_H

# include <stdio.h>
# include "mlx/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "mathlib/mathlib.h"


# define PX 7.12
# define PY 6.32

# define mapWidth 10
# define mapHeight 10
# define CELLSIZE 64
# define GAMEWIDTH 600
# define T_SKY 0x123456
# define T_floor 0x654321
# ifdef __APPLE__

typedef enum keys{
  Key_W = 13,
  Key_A = 0,
  Key_S = 1,
  Key_D = 2,
  Key_ESC = 53,
  key_up = 126,
  key_dn = 125,
  key_lt =123,
  key_rt =124
} keys;

# else

typedef enum keys{
  Key_W = 119,
  Key_A = 97,
  Key_S = 115,
  Key_D = 100,
  Key_ESC = 65307,
  key_up = 65362,
  key_dn = 65364,
  key_lt = 65361,
  key_rt = 65363
} keys;

# endif

//https://www.youtube.com/watch?v=gYRrGTC7GtA
//https://eastmanreference.com/complete-list-of-applescript-key-codes
//https://github.com/Saxsori/ray-cast



typedef struct s_vector2
{
  double x;
  double y;
} t_vector2;

typedef struct s_llocation
{
  int x;
  int y;
} t_llocation;

typedef struct s_ray_data
{
  t_vector2   ray_location;
  t_llocation last_location;
  t_llocation wall_location;
  t_vector2   for_wall;

} t_ray_data;

typedef struct s_xpm{
  void* img;
  char* img_ptr;
  int bpp;
  int line_len;
  int endian;
  int width;
  int height;
} t_xpm;

typedef struct s_imgdata
{
  void		*img;
  char		*addr;
  int			bpp;
  int			line_len;
  int			endian;
}				t_imgdata;

typedef struct s_player{
  t_vector2 pos;
  double direction;
  double fov;
} t_player;

typedef struct s_mapdata{
  int		map_height;
  int		map_width;
} t_mapdata;

typedef struct s_data{
	void*	mlx;
	void*	win;
	void*	win2;
	void*	win3;
  void* win4;
  t_imgdata img; 
  t_imgdata img2;
  t_imgdata img3;
  t_imgdata img4;
  t_player  player;
  t_xpm     xpm[4];
	t_mapdata m_data;
	int width;
	int height;
}	t_data;

int keyPressFunc(int keycode, t_data *data);
void clear_img(t_data *data);
t_ray_data draw_ray(t_data *data, double angle);
// void draw_player(t_data *data);
void draw_player(void);
void draw_outlines(t_data *data);
void draw_square(int x, int y, t_data *data);
void ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color);
unsigned int	ft_my_get_pixel(t_data *data, int x, int y, int i);
#endif
