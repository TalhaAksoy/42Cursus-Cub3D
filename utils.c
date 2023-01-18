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

double deg2rad(int deg)
{
	return(deg * (M_PI / 180));
}

int draw_wall_n(int angle, double distance, t_data *data, t_ray_data *ray_data)
{
		(void)ray_data; 
	distance = distance * cos(deg2rad((((double)angle * 0.1) -(data->player.fov / 2))));
	int height = (int)(50000 / distance);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;

	while (i < start)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0xff0000); // kirmizi
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	return(321);
};
int draw_wall_e(int angle, double distance, t_data *data, t_ray_data *ray_data){
	(void)ray_data; 
	distance = distance * cos(deg2rad((((double)angle * 0.1) -(data->player.fov / 2))));
	int height = (int)(50000 / distance);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;

	while (i < start)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x00ff00); // yesil
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	return(44242);
};
int draw_wall_w(int angle, double distance, t_data *data, t_ray_data *ray_data){
	(void)ray_data; 
	distance = distance * cos(deg2rad((((double)angle * 0.1) -(data->player.fov / 2))));
	int height = (int)(50000 / distance);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;

	while (i < start)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x0000ff); // mavi
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	return (443323);
};
int draw_wall_s(int angle, double distance, t_data *data, t_ray_data *ray_data){
	(void)ray_data; 
	distance = distance * cos(deg2rad((((double)angle * 0.1) -(data->player.fov / 2))));
	int height = (int)(50000 / distance);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;

	while (i < start)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x151515); // acik gri
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0x000000);
		i++;
	}
	return (123);
};

int draw_wall(int angle, double distance, t_data *data, t_ray_data *ray_data)
{
	(void)ray_data; 
	distance = distance * cos(deg2rad((((double)angle * 0.1) -(data->player.fov / 2))));
	int height = (int)(50000 / distance);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;
	while (i < start)
	{
		if (i > 600)
			break;
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
		if (i > 600)
			break;
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

int draw_screen3(t_data *data, t_ray_data *ray_data)
{
	int i = 0;
	printf("%d = lx, %d = ly\n%d = rx, %d = ry\n", ray_data[i].last_location.x, ray_data[i].last_location.y, ray_data[i].wall_location.x, ray_data[i].wall_location.y);
	while (i < 600)
	{
		if (ray_data[i].last_location.x == ray_data[i].wall_location.x + 1 && ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_e(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win3, data->img3.img, 0, 0);
	return (0); 
}

int keyPressFunc(int keycode, t_data *data)
{
	double angle;
	t_ray_data *ray;
	int i = data->width;
	t_vector2 w_check;

	angle = data->player.fov;
	ray = (t_ray_data *)malloc(sizeof(t_ray_data) * data->width); // leak
	if (keycode == Key_W)
	{
		w_check.y = data->player.pos.y - 0.1 * sin(deg2rad(-data->player.direction));
		w_check.x = data->player.pos.x + 0.1 * cos(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return (1);
		data->player.pos.y -= 0.05 * sin(deg2rad(-data->player.direction));
		data->player.pos.x += 0.05 * cos(deg2rad(data->player.direction));

	}
	if (keycode == Key_S)
	{
		w_check.y = data->player.pos.y + 0.1 * sin(deg2rad(-data->player.direction));
		w_check.x = data->player.pos.x - 0.1 * cos(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return (1);
		data->player.pos.y += 0.05 * sin(deg2rad(-data->player.direction));
		data->player.pos.x -= 0.05 * cos(deg2rad(data->player.direction));
	}
	if (keycode == Key_A)
	{
		w_check.y = data->player.pos.y - 0.1 * cos(deg2rad(data->player.direction));
		w_check.x = data->player.pos.x + 0.1 * sin(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return (1);
		data->player.pos.y -= 0.05 * cos(deg2rad(data->player.direction));
		data->player.pos.x += 0.05 * sin(deg2rad(data->player.direction));
	}
	if (keycode == Key_D)
	{
		w_check.y = data->player.pos.y + 0.1 * cos(deg2rad(data->player.direction));
		w_check.x = data->player.pos.x - 0.1 * sin(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return (1);
		data->player.pos.y += 0.05 * cos(deg2rad(data->player.direction));
		data->player.pos.x -= 0.05 * sin(deg2rad(data->player.direction));
	}
	if (keycode == key_rt)
		data->player.direction += 1;
	if (keycode == key_lt)
		data->player.direction -= 1;
	if (data->player.direction >= 360)
		data->player.direction = ft_abs((int)data->player.direction % 360);
	if (data->player.direction < 0)
		data->player.direction = 359;
	if (keycode == Key_ESC)
		exit(1);
	mlx_clear_window(data->mlx, data->win);
	clear_img(data);
	draw_outlines(data);
	draw_player();
	while (i--)
	{
		ray[i] = draw_ray(data, angle);
		angle -= data->player.fov / data->width;
	}
	draw_screen2(data, ray);
	draw_screen3(data, ray);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	return (0);
}
