#ifndef CUB3D_H
# define CUB3D_H

//# define WIN_WIDTH 1920
//# define WIN_HEIGHT 1080

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "./libft/libft.h"
#include "./mlx/mlx.h"
/*
typedef struct s_screen
{
    int         width;
    int         heigth;
    void        *img;
    char        *addr;
    int		    bbp;
    int		    line_len;
    int		    endian;
}
               t_screen;
typedef struct s_map
{
    void    *mlx;
    void    *mlx_win;
    char    *no;
    char    *we;
    char    *ea;
    char    *so;
}           t_map;*/

typedef struct s_data
{
    char        **map;
    int         first_line;
    int         last_line;
    //t_screen    screen[4];
    //t_map       s_map;
}               t_data;


int     ft_check_cub(char *s);
void    ft_clear(t_data *data);
void    ft_check_map(t_data *data);
void    ft_check_wall(t_data *data);
void    ft_all_check_and_read_map(t_data *data, char *map);
void    ft_check_for_long(t_data *data);
void    ft_check_once_to_map(t_data *data);
void    ft_addjust2(t_data *data);
void    ft_check_file(t_data *data);
void    ft_find(t_data *data);

#endif