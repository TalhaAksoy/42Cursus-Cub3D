#include "cub3d.h"



void init_var(t_data *data){

	data->player.px = PX;
	data->player.py = PY;
	data->player.pov = 30;
	data->player.viewAngle = 90;
	data->mlx = mlx_init();
	data->m_data.map_height = mapHeight;
	data->m_data.map_width = mapWidth;
	data->width = 	data->m_data.map_width * 64;
	data->height = 	data->m_data.map_height * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "UwU");
	data->win2 = mlx_new_window(data->mlx, 600, 600, "Lil Dicks");
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->img2.img = mlx_new_image(data->mlx, 600, 600);
	data->img2.addr = mlx_get_data_addr(data->img2.img, &data->img2.bpp, &data->img2.line_len, &data->img2.endian);
}

int main()
{
	t_data data;

	printf("%d\n", ft_abs(-1));
	init_var(&data);
	draw_outlines(&data);
	draw_player();
	mlx_hook(data.win, 2, 1, keyPressFunc, &data);
	mlx_hook(data.win2, 2, 1, keyPressFunc, &data);
	mlx_loop(data.mlx);
}
