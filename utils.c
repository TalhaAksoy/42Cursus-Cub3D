#include "cub3d.h"

int mapVar2[mapHeight][mapWidth] = {
    {1,1,1,1,1,1,1,1,1,1},
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
	// i = 0;
	// j = 0;
	// while (i < 600)
	// {
	// 	while (j < 600)
	// 	{
	// 		ft_my_put_pixel(&data->img2, j, i, 0x0);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// }
	// i = 0;
	// j = 0;
	// while (i < 600)
	// {
	// 	while (j < 600)
	// 	{
	// 		ft_my_put_pixel(&data->img3, j, i, 0x0);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// }
i = 0;
	j = 0;
	while (i < 600)
	{
		while (j < 600)
		{
			ft_my_put_pixel(&data->img4, j, i, 0x0);
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
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
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
		ft_my_put_pixel(&data->img3, angle, i, T_floor);
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
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
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
		ft_my_put_pixel(&data->img3, angle, i, T_floor);
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
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
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
		ft_my_put_pixel(&data->img3, angle, i, T_floor);
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
		ft_my_put_pixel(&data->img3, angle, i, T_SKY);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, 0xaaaaaa); // acik gri
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img3, angle, i, T_floor);
		i++;
	}
	return (123);
};
int draw_wall_n_img(int angle, double distance, t_data *data, t_ray_data ray_data)
{
	distance = distance * cos(deg2rad((((double)angle * 0.1) -(data->player.fov / 2))));
	int height = (int)(50000 / distance);
	// printf("height: %d\n", height);
	int start = (600 - height) / 2;
	int end = (600 + height) / 2;
	int i = 0;

	data->xpm.img = mlx_xpm_file_to_image(data->mlx, "textures/wall1.xpm", &data->xpm.width, &data->xpm.height);
	data->xpm.img_ptr = mlx_get_data_addr(data->xpm.img, &data->xpm.bpp, &data->xpm.line_len, &data->xpm.endian);
	while (i < start)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img4, angle, i, T_SKY);
		i++;
	}
	while (i < end)
	{
		if (i > 600)
			break;
		unsigned clr = ft_my_get_pixel(data, ((ray_data.for_wall.x - floor(ray_data.for_wall.x))* 64) , ((i - start) * 64) / height);
		ft_my_put_pixel(&data->img4, angle, i, clr); // kirmizi
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img4, angle, i, T_floor);
		i++;
	}
	return(321);
};
int draw_wall_e_img(int angle, double distance, t_data *data, t_ray_data ray_data){
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
		ft_my_put_pixel(&data->img4, angle, i, T_SKY);
		i++;
	}
	data->xpm.img = mlx_xpm_file_to_image(data->mlx, "textures/wall2.xpm", &data->xpm.width, &data->xpm.height);
	data->xpm.img_ptr = mlx_get_data_addr(data->xpm.img, &data->xpm.bpp, &data->xpm.line_len, &data->xpm.endian);
	while (i < end)
	{
		if (i > 600)
			break;
		unsigned clr = ft_my_get_pixel(data, ((ray_data.for_wall.y - floor(ray_data.for_wall.y))* 64) , ((i - start) * 64) / height);
		ft_my_put_pixel(&data->img4, angle, i, clr); // yesil
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img4, angle, i, T_floor);
		i++;
	}
	return(44242);
};
int draw_wall_w_img(int angle, double distance, t_data *data, t_ray_data ray_data){
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
		ft_my_put_pixel(&data->img4, angle, i, T_SKY);
		i++;
	}
	data->xpm.img = mlx_xpm_file_to_image(data->mlx, "textures/wall3.xpm", &data->xpm.width, &data->xpm.height);
	data->xpm.img_ptr = mlx_get_data_addr(data->xpm.img, &data->xpm.bpp, &data->xpm.line_len, &data->xpm.endian);
	while (i < end)
	{
		if (i > 600)
			break;
		unsigned clr = ft_my_get_pixel(data, ((ray_data.for_wall.y - floor(ray_data.for_wall.y))* 64) , ((i - start) * 64) / height);
		ft_my_put_pixel(&data->img4, angle, i, clr); // mavi
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img4, angle, i, T_floor);
		i++;
	}
	return (443323);
};
int draw_wall_s_img(int angle, double distance, t_data *data, t_ray_data ray_data){
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
		ft_my_put_pixel(&data->img4, angle, i, T_SKY);
		i++;B
		unsigned clr = ft_my_get_pixel(data, ((ray_data.for_wall.x - floor(ray_data.for_wall.x))* 64) , ((i - start) * 64) / height);
		ft_my_put_pixel(&data->img4, angle, i, clr); // acik gri
		i++;
	}
	while (i < data->height)
	{
		if (i > 600)
			break;
		ft_my_put_pixel(&data->img4, angle, i, T_floor);
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
	//printf("%d = lx, %d = ly\n%d = rx, %d = ry\n", ray_data[i].last_location.x, ray_data[i].last_location.y, ray_data[i].wall_location.x, ray_data[i].wall_location.y);
	while (i < 600)
	{
		if (ray_data[i].last_location.x == ray_data[i].wall_location.x + 1 && ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_e(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data);
		else if (ray_data[i].last_location.x == ray_data[i].wall_location.x && ray_data[i].last_location.y + 1 == ray_data[i].wall_location.y)
			draw_wall_n(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data);
		if (ray_data[i].last_location.x +1 == ray_data[i].wall_location.x && ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_w(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data);
		else if (ray_data[i].last_location.x == ray_data[i].wall_location.x && ray_data[i].last_location.y == ray_data[i].wall_location.y + 1)
			draw_wall_s(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win3, data->img3.img, 0, 0);
	return (0); 
}

int draw_screen4(t_data *data, t_ray_data *ray_data)
{
	int i = 0;
	
	while (i < 600)
	{
		if (ray_data[i].last_location.x == ray_data[i].wall_location.x + 1 && ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_e_img(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data[i]);
		else if (ray_data[i].last_location.x == ray_data[i].wall_location.x && ray_data[i].last_location.y + 1 == ray_data[i].wall_location.y)
			draw_wall_n_img(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data[i]);
		else if (ray_data[i].last_location.x +1 == ray_data[i].wall_location.x && ray_data[i].last_location.y == ray_data[i].wall_location.y)
			draw_wall_w_img(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data[i]);
		else if (ray_data[i].last_location.x == ray_data[i].wall_location.x && ray_data[i].last_location.y == ray_data[i].wall_location.y + 1)
			draw_wall_s_img(i, ft_sqrt(ft_pow(ray_data[i].ray_location.x, 2) + ft_pow(ray_data[i].ray_location.y, 2)) ,data, ray_data[i]);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win4, data->img4.img, 0, 0);
	return (0);
}

void	ft_left_right(int keycode, t_data *data)
{
	t_vector2 w_check;

	if (keycode == Key_A)
	{
		w_check.y = data->player.pos.y - 0.1 * cos(deg2rad(data->player.direction));
		w_check.x = data->player.pos.x + 0.1 * sin(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return ;
		data->player.pos.y -= 0.05 * cos(deg2rad(data->player.direction));
		data->player.pos.x += 0.05 * sin(deg2rad(data->player.direction));
	}
	if (keycode == Key_D)
	{
		w_check.y = data->player.pos.y + 0.1 * cos(deg2rad(data->player.direction));
		w_check.x = data->player.pos.x - 0.1 * sin(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return ;
		data->player.pos.y += 0.05 * cos(deg2rad(data->player.direction));
		data->player.pos.x -= 0.05 * sin(deg2rad(data->player.direction));
	}

}

void	ft_forward_backward(int keycode, t_data *data)
{
	t_vector2 w_check;

	if (keycode == Key_W)
	{
		w_check.y = data->player.pos.y - 0.1 * sin(deg2rad(-data->player.direction));
		w_check.x = data->player.pos.x + 0.1 * cos(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return ;
		data->player.pos.y -= 0.05 * sin(deg2rad(-data->player.direction));
		data->player.pos.x += 0.05 * cos(deg2rad(data->player.direction));
	}
	if (keycode == Key_S)
	{
		w_check.y = data->player.pos.y + 0.1 * sin(deg2rad(-data->player.direction));
		w_check.x = data->player.pos.x - 0.1 * cos(deg2rad(data->player.direction));
		if (mapVar2[(int)w_check.x][(int)w_check.y] == 1)
			return ;
		data->player.pos.y += 0.05 * sin(deg2rad(-data->player.direction));
		data->player.pos.x -= 0.05 * cos(deg2rad(data->player.direction));
	}
}

void	ft_move(int keycode, t_data *data)
{
	
	if (keycode == Key_W || keycode == Key_S)
		ft_forward_backward(keycode, data);
	else if (keycode == Key_A || keycode == Key_D)
		ft_left_right(keycode, data);
}


int keyPressFunc(int keycode, t_data *data)
{
	double angle;
	t_ray_data *ray;
	int i = GAMEWIDTH;

	angle = data->player.fov;
	ray = (t_ray_data *)malloc(sizeof(t_ray_data) * GAMEWIDTH); // leak

	if (keycode == Key_W || keycode == Key_A || keycode == Key_S || keycode == Key_D)
		ft_move(keycode, data);
	if (keycode == key_rt)
		data->player.direction += 6;
	if (keycode == key_lt)
		data->player.direction -= 6;
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
		angle -= data->player.fov / GAMEWIDTH;
	}
	//draw_screen2(data, ray);
	draw_screen3(data, ray);
	draw_screen4(data, ray);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
