#include "cub3d.h"

void clear_img(t_data *data) // ekrani temizlemek icin
{
	int i = 0, j = 0;

	while (i < data->height)
	{
		while (j < data->width)
		{
			ft_my_put_pixel(&data->img, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}
}

int draw_wall(int angle, double  distance, t_data *data)
{
	// draw wall
	int height = (int)((64 / distance) * data->height);
	int start = (data->height - height) / 2;
	int end = (data->height + height) / 2;
	int i = 0;
	while (i < start)
	{
		ft_my_put_pixel(&data->img2, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		ft_my_put_pixel(&data->img2, angle, i, 0x00ff00);
		i++;
	}
	while (i < data->height)
	{
		ft_my_put_pixel(&data->img2, angle, i, 0x000000);
		i++;
	}
	return (0);
}

int draw_screen2(t_data *data, t_vector2 *ray)
{
	int i = 0;
	while (i < 90)
	{
		draw_wall(i, ft_sqrt(ft_pow(ray[i].x, 2) + ft_pow(ray[i].y, 2)) , data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win2, data->img2.img, 0, 0);
	return (0);
}

int keyPressFunc(int keycode, t_data *data)
{
	int angle = 90;
	t_vector2 ray[(int) angle];
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
	mlx_clear_window(data->mlx, data->win);
	clear_img(data);
	draw_outlines(data);
	draw_player();
	while (angle--)
		ray[(int)angle] = draw_ray(data, angle);
	draw_screen2(data, ray);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	return (0);
}
