#ifndef CUBD3D_H
# define CUBD3D_H

# include <stdio.h>
# include "./mlx/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080
# define PX 7.12
# define PY 6.32


typedef enum keys{
  Key_W = 13,
  Key_A = 0,
  Key_S = 1,
  Key_D = 2,
  Key_ESC = 53,
  key_up=126,
  key_dn=125,
  key_lt =123,
  key_rt =124
} keys;

//https://www.youtube.com/watch?v=gYRrGTC7GtA
//https://eastmanreference.com/complete-list-of-applescript-key-codes
//https://github.com/Saxsori/ray-cast

typedef struct s_imgdata
{
  void		*img;
  char		*addr;
  int			bpp;
  int			line_len;
  int			endian;
}				t_imgdata;

typedef struct s_player{
  double px;
  double pdx;
  double py;
  double pdy;
  double viewAngle;
  double pov;
} t_player;

typedef struct s_data{
	void*	mlx;
	void*	win;
        t_imgdata img;
        t_player player;
}	t_data;

int keyPressFunc(int keycode, t_data *data);
void clear_img(t_data *data);
void draw_ray(t_data *data, double angle);
void draw_player(t_data *data);
void draw_outlines(t_data *data);
void draw_square(int x, int y, t_data *data);
void ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color);
#endif