#include "cub3d.h"
/*
void    ft_routine(t_data *data, t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3_D");
    data->screen->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);//burda!
    data->screen->heigth = WIN_HEIGHT;
    data->screen->width = WIN_WIDTH;
    data->screen->addr = mlx_get_data_addr(data->screen->img, &data->screen->bbp, &data->screen->line_len, &data->screen->endian);
    
    mlx_loop(map->mlx);
}
*/
int main(int ac, char **av)
{
    t_data      *data;
    //t_map       *map;
    //t_screen    *screen;

    data = ft_calloc(sizeof(t_data),1);
    //map = malloc(sizeof(t_map));
    //screen = malloc(sizeof(t_screen));
    if (ac == 2)
    {
        data = ft_calloc(sizeof(t_data),1);
        ft_all_check_and_read_map(data, av[1]);
        //if (map == NULL)
            //return(1);
        printf("Okey\n");
        //ft_routine(data, map);
    }
    else
    {
        return (1);
        printf("Wrong Arg!\n");
    }
    //system("leaks Cub3D");
    return (0);
}