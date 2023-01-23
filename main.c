#include "cub3d.h"



void init_var(t_data *data){

	data->player.pos.x = PX;
	data->player.pos.y = PY;
	data->player.fov = 60;
	data->player.direction = 60;
	data->mlx = mlx_init();
	data->width = MAPWIDTH * 64;
	data->height = MAPHEIGHT * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "UwU");
	data->win2 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT, "Lil Dicks");
	data->win3 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT, "Real Lil Dicks");
	data->win4 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT, "Real super Lil Dicks");
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->img2.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img2.addr = mlx_get_data_addr(data->img2.img, &data->img2.bpp, &data->img2.line_len, &data->img2.endian);
	data->img3.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img3.addr = mlx_get_data_addr(data->img3.img, &data->img3.bpp, &data->img3.line_len, &data->img3.endian);
	data->img4.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img4.addr = mlx_get_data_addr(data->img4.img, &data->img4.bpp, &data->img4.line_len, &data->img4.endian);
	ft_bzero(data->xpm, sizeof(t_xpm) * 4);
	ft_bzero(&data->map_data, sizeof(t_mapdata));
	data->ceiling_color = T_SKY;
	data->floor_color = T_FLOOR;
}

void init_xpm(t_data *data)
{
	data->xpm[north].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[north], &data->xpm[north].width, &data->xpm[north].height);
	data->xpm[north].img_ptr = mlx_get_data_addr(data->xpm[north].img, &data->xpm[north].bpp, &data->xpm[north].line_len, &data->xpm[north].endian);
	data->xpm[east].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[east], &data->xpm[east].width, &data->xpm[east].height);
	data->xpm[east].img_ptr = mlx_get_data_addr(data->xpm[east].img, &data->xpm[east].bpp, &data->xpm[east].line_len, &data->xpm[east].endian);
	data->xpm[west].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[west], &data->xpm[west].width, &data->xpm[west].height);
	data->xpm[west].img_ptr = mlx_get_data_addr(data->xpm[west].img, &data->xpm[west].bpp, &data->xpm[west].line_len, &data->xpm[west].endian);
	data->xpm[south].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[south], &data->xpm[south].width, &data->xpm[south].height);
	data->xpm[south].img_ptr = mlx_get_data_addr(data->xpm[south].img, &data->xpm[south].bpp, &data->xpm[south].line_len, &data->xpm[south].endian);
}

void init_color(t_data *data)
{
	data->map_data.colors[0][0] = 256;
	data->map_data.colors[0][1] = 256;
	data->map_data.colors[0][2] = 256;
	data->map_data.colors[1][0] = 256;
	data->map_data.colors[1][1] = 256;
	data->map_data.colors[1][2] = 256;
}

int check_wall_xpm(t_data *data)
{
	int i;
	int fd;

	i = 0;
	fd = 0;
	while(data->map_data.xpm_dir[i])
	{
		fd = open(data->map_data.xpm_dir[i], O_RDONLY);
		if (fd == -1)
			return (-1);
		close(fd);
		i++;
	}
	return (0);
}

int main()
{
	t_data data;

	init_var(&data);
	if (read_file(&data, "./map.cub") == -1)
		return (1);
	if (check_wall_xpm(&data) == -1)
		return (1);
	init_xpm(&data);
	init_color(&data);
	// initBisiler
	// initBaskaBisilerFalan
	draw_outlines(&data);
	render_window(&data);
	mlx_hook(data.win, 2, 1, key_press_func, &data);
	mlx_hook(data.win2, 2, 1, key_press_func, &data);
	mlx_hook(data.win3, 2, 1, key_press_func, &data);
	mlx_hook(data.win4, 2, 1, key_press_func, &data);
	mlx_loop(data.mlx);
}
