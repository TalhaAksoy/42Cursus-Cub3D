#include "cub3d.h"

void init_var(t_data *data){
	data->player.px = PX;
	data->player.py = PY;
	data->player.pov = 30;
	data->player.viewAngle = 360;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "UwU");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
}

int main()
{
	t_data data;

	init_var(&data);
	draw_outlines(&data);
	draw_player(&data);
	mlx_hook(data.win, 2, 0, keyPressFunc, &data);
	mlx_loop(data.mlx);
}