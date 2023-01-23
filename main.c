#include "cub3d.h"



void init_var(t_data *data){

	data->player.pos.x = PX;
	data->player.pos.y = PY;
	data->player.fov = 60;
	data->player.direction = 60;
	data->mlx = mlx_init();
	data->m_data.map_height = mapHeight;
	data->m_data.map_width = mapWidth;
	data->width = data->m_data.map_width * 64;
	data->height = data->m_data.map_height * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "UwU");
	data->win2 = mlx_new_window(data->mlx, 600, 600, "Lil Dicks");
	data->win3 = mlx_new_window(data->mlx, 600, 600, "Real Lil Dicks");
	data->win4 = mlx_new_window(data->mlx, 600, 600, "Real super Lil Dicks");
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->img2.img = mlx_new_image(data->mlx, 600, 600);
	data->img2.addr = mlx_get_data_addr(data->img2.img, &data->img2.bpp, &data->img2.line_len, &data->img2.endian);
	data->img3.img = mlx_new_image(data->mlx, 600, 600);
	data->img3.addr = mlx_get_data_addr(data->img3.img, &data->img3.bpp, &data->img3.line_len, &data->img3.endian);
	data->img4.img = mlx_new_image(data->mlx, 600, 600);
	data->img4.addr = mlx_get_data_addr(data->img4.img, &data->img4.bpp, &data->img4.line_len, &data->img4.endian);
	data->xpm[0].img = mlx_xpm_file_to_image(data->mlx, "textures/wall1.xpm", &data->xpm[0].width, &data->xpm[0].height);
	data->xpm[0].img_ptr = mlx_get_data_addr(data->xpm[0].img, &data->xpm[0].bpp, &data->xpm[0].line_len, &data->xpm[0].endian);
	data->xpm[1].img = mlx_xpm_file_to_image(data->mlx, "textures/wall2.xpm", &data->xpm[1].width, &data->xpm[1].height);
	data->xpm[1].img_ptr = mlx_get_data_addr(data->xpm[1].img, &data->xpm[1].bpp, &data->xpm[1].line_len, &data->xpm[1].endian);
	data->xpm[2].img = mlx_xpm_file_to_image(data->mlx, "textures/wall3.xpm", &data->xpm[2].width, &data->xpm[2].height);
	data->xpm[2].img_ptr = mlx_get_data_addr(data->xpm[2].img, &data->xpm[2].bpp, &data->xpm[2].line_len, &data->xpm[2].endian);
	data->xpm[3].img = mlx_xpm_file_to_image(data->mlx, "textures/wall4.xpm", &data->xpm[3].width, &data->xpm[3].height);
	data->xpm[3].img_ptr = mlx_get_data_addr(data->xpm[3].img, &data->xpm[3].bpp, &data->xpm[3].line_len, &data->xpm[3].endian);
	data->ceiling_color = T_SKY;
	data->floor_color = T_floor;
}

int main()
{
	t_data data;

	init_var(&data);
	// initBisiler
	// initBaskaBisilerFalan
	// draw_outlines(&data);
	// draw_player();
	render_window(&data);
	mlx_hook(data.win, 2, 1, key_press_func, &data);
	mlx_hook(data.win2, 2, 1, key_press_func, &data);
	mlx_hook(data.win3, 2, 1, key_press_func, &data);
	mlx_hook(data.win4, 2, 1, key_press_func, &data);
	mlx_loop(data.mlx);
}
