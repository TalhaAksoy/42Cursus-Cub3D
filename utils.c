#include "cub3d.h"

int mapVar2[mapHeight][mapWidth] = {
    {1,1,1,1,1,0,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};


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
	i = 0;
	j = 0;
	while (i < 600)
	{
		while (j < 600)
		{
			ft_my_put_pixel(&data->img2, j, i, 0x0);
			j++;
		}
		j = 0;
		i++;
	}

}

int draw_wall_n();
int draw_wall_e();
int draw_wall_w();
int draw_wall_s();

int draw_wall(int angle, double distance, t_data *data, t_ray_data *ray_data)
{
	(void)ray_data;
	int height = (int)((60 / distance) * 600);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;
	printf("%d s, %d e\n", start, end);
	while (i < start)
	{
		ft_my_put_pixel(&data->img2, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
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

int draw_screen2(t_data *data, t_ray_data *ray_data)
{
	int i = 0;
	while (i < 600)
	{
		draw_wall(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win2, data->img2.img, 0, 0);
	return (0); 
}

int keyPressFunc(int keycode, t_data *data)
{
	double angle = 60;
	t_ray_data ray[600];
	int i = 599;
	double tmp, tmp2;
	printf("keycode: %d, key_w: %d, key_s: %d, key_a: %d, key_d: %d, key_lt: %d, key_rt: %d\n", keycode, Key_W, Key_S, Key_A, Key_D, key_lt, key_rt);
	if (keycode == Key_W)
	{
		tmp = data->player.pos.y - 0.1 * sin((-data->player.direction) * (M_PI / 180));
		tmp2 = data->player.pos.x + 0.1 * cos((data->player.direction) * (M_PI / 180));
		if (mapVar2[(int)tmp2][(int)tmp] == 1)
			return (0);
		data->player.pos.y -= 0.05 * sin((-data->player.direction) * (M_PI / 180));
		data->player.pos.x += 0.05 * cos((data->player.direction) * (M_PI / 180));

	}
	if (keycode == Key_S)
	{
		tmp = data->player.pos.y + 0.1 * sin((-data->player.direction) * (M_PI / 180));
		tmp2 = data->player.pos.x - 0.1 * cos((data->player.direction) * (M_PI / 180));
		if (mapVar2[(int)tmp2][(int)tmp] == 1)
			return (0);
		data->player.pos.y += 0.05 * sin((-data->player.direction) * (M_PI / 180));
		data->player.pos.x -= 0.05 * cos((data->player.direction) * (M_PI / 180));
	}
	if (keycode == Key_A)
	{
		tmp = data->player.pos.y - 0.1 * cos((data->player.direction) * (M_PI / 180));
		tmp2 = data->player.pos.x + 0.1 * sin((data->player.direction) * (M_PI / 180));
		if (mapVar2[(int)tmp2][(int)tmp] == 1)
			return (0);
		data->player.pos.y -= 0.05 * cos((data->player.direction) * (M_PI / 180));
		data->player.pos.x += 0.05 * sin((data->player.direction) * (M_PI / 180));
	}
	if (keycode == Key_D)
	{
		tmp = data->player.pos.y + 0.1 * cos((data->player.direction) * (M_PI / 180));
		tmp2 = data->player.pos.x - 0.1 * sin((data->player.direction) * (M_PI / 180));
		if (mapVar2[(int)tmp2][(int)tmp] == 1)
			return (0);
		data->player.pos.y += 0.05 * cos((data->player.direction) * (M_PI / 180));
		data->player.pos.x -= 0.05 * sin((data->player.direction) * (M_PI / 180));
	}
	if (keycode == key_rt)
		data->player.direction += 1;
	if (keycode == key_lt)
		data->player.direction -= 1;
	if (data->player.direction >= 360)
		data->player.direction = abs((int)data->player.direction % 360);
	if (data->player.direction < 0)
		data->player.direction = 359;
	if (keycode == Key_ESC)
		exit(1);
	mlx_clear_window(data->mlx, data->win);
	clear_img(data);
	draw_outlines(data);
	draw_player();
	while (angle >= 0)
	{
		ray[i] = draw_ray(data, angle);
		angle -= .1;
		i--;
	}
	draw_screen2(data, ray);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	return (0);
}
