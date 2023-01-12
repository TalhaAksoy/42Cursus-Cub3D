#include "cub3d.h"

void clear_img(t_data *data) // ekrani temizlemek icin
{
	int i = 0, j = 0;

	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			ft_my_put_pixel(&data->img, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
}

int keyPressFunc(int keycode, t_data *data)
{
	if (keycode == Key_W)
	{
		data->player.py -= 0.05 * sin((-data->player.viewAngle) * (M_PI / 180));
		data->player.px += 0.05 * cos((data->player.viewAngle) * (M_PI / 180));
	}
	if (keycode == Key_S)
	{
		data->player.py += 0.05 * sin((-data->player.viewAngle) * (M_PI / 180));
		data->player.px -= 0.05 * cos((data->player.viewAngle) * (M_PI / 180));
	}
	if (keycode == Key_A)
	{
		data->player.py -= 0.05 * cos((data->player.viewAngle) * (M_PI / 180));
		data->player.px += 0.05 * sin((data->player.viewAngle) * (M_PI / 180));
	}
	if (keycode == Key_D)
	{
		data->player.py += 0.05 * cos((data->player.viewAngle) * (M_PI / 180));
		data->player.px -= 0.05 * sin((data->player.viewAngle) * (M_PI / 180));
	}
	if (keycode == key_rt)
		data->player.viewAngle += 1;
	if (keycode == key_lt)
		data->player.viewAngle -= 1;
	if (data->player.viewAngle >= 360)
		data->player.viewAngle = abs((int)data->player.viewAngle % 360);
	if (data->player.viewAngle < 0)
		data->player.viewAngle = 359;
	if (keycode == Key_ESC)
		exit(1);
	double angle = 360;
	mlx_clear_window(data->mlx, data->win);
	clear_img(data);
	draw_outlines(data);
	draw_player();
	while (angle--)
		draw_ray(data, angle);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	return (0);
}
