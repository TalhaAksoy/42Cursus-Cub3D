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

int mapVar[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

typedef enum keys{
  Key_W = 13,
  Key_A = 0,
  Key_S = 1,
  Key_D = 2,
  Key_ESC = 53
  key_up=126,
  key_dn=125,
  key_lt =123,
  key_rt =124
} keys;

https://www.youtube.com/watch?v=gYRrGTC7GtA
https://eastmanreference.com/complete-list-of-applescript-key-codes
https://github.com/Saxsori/ray-cast

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
        t_player player;
}	t_data;
#endif