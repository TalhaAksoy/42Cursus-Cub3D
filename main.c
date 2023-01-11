#include "cub3d.h"

void ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color) // image adresine pixel basmak icin
{
	char *dst;

	dst = img_data->addr + (y * img_data->line_len + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_square(int x, int y, t_data *data) // kirmizi kutular icin
{

	int start_x, start_y;
	start_x = x * (WIDTH / 10);
	start_y = y * (HEIGHT / 10);
	printf("x = %d, y = %d\n", x, y);
	x = 0;
	y = 0;
	while (x < 190)
	{
		while (y < 107)
		{
			ft_my_put_pixel(&data->img, x + start_x, y + start_y, 0xff0000);
			y++;
		}
		y = 0;
		x++;
	}
}

void draw_outlines(t_data *data) // kirmizi kutularin tamami icin
{
	int i;
	int j;
	int k;
	i = 0;
	j = 0;
	k = 0;

	while (i < 10)
	{
		while (j < 10)
		{
			if (mapVar[i][j] == 1)
				draw_square(i, j, data);
			j++;
		}

		j = 0;
		i++;
	}
}

void draw_player(t_data *data) // playeri ciziyor
{
	int start_x, start_y, i, j;
	start_x = data->player.px * (WIDTH / 10);
	start_y = data->player.py * (HEIGHT / 10);
	i = 0;
	j = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			++j;
		}
		j = 0;
		i++;
	}
}

void draw_ray(t_data *data, double angle)
{ // isinlar icin
	int start_x, start_y;
	start_x = data->player.px * (WIDTH / 10);
	start_y = data->player.py * (HEIGHT / 10);
	int i = 0;

	int mapX = (int)start_x;
	int mapY = (int)start_y;
	int stepX = 0;
	int stepY = 0;
	double rayY, rayX;
	double deltaDistX = 0;
	double deltaDistY = 0;
	double sideDistX = 0;
	double sideDistY = 0;
	rayY = (start_y) + (i * sin((angle + data->player.viewAngle - 180) * (M_PI / 180)));
	rayX = (start_x) + (i * cos((angle + data->player.viewAngle - 180) * (M_PI / 180)));
	while (!mapVar[(int)rayX / (WIDTH / 10)][(int)rayY / (HEIGHT / 10)])
	{
		deltaDistX = (rayX == 0) ? 1e30 : fabs(1 / rayX);
		deltaDistY = (rayY == 0) ? 1e30 : fabs(1 / rayY);
		rayY = (start_y) + (i * sin((angle + data->player.viewAngle - 180) * (M_PI / 180)));
		rayX = (start_x) + (i * cos((angle + data->player.viewAngle - 180) * (M_PI / 180)));
		if (rayX < 0)
		{
			stepX = -1;
			sideDistX = (start_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - start_x) * deltaDistX;
		}
		if (rayY < 0)
		{
			stepY = -1;
			sideDistY = (start_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - start_y) * deltaDistY;
		}
		// printf("%lf = ry, %lf = rx, %f =ddx\n", rayY, rayX, sqrt(1 + (rayY * rayY) / (rayX * rayX)));
		if (angle == 180)
			ft_my_put_pixel(&data->img, rayX, rayY, 0xfff);
		else
			ft_my_put_pixel(&data->img, rayX, rayY, 0xffffff);
		i++;
	}
	printf("%lf => deltaDistX |  %lf => deltaDistY\n", sideDistX, sideDistY);
	// printf("ray_len = %f\n", sqrt(1 + (rayY * rayY) / (rayX * rayX)));
	// printf("%f angle\n", data->player.viewAngle);
}

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
	draw_player(data);
	while (angle--)
		draw_ray(data, angle);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);

	return (INT32_MAX - INT32_MAX);
}

int main()
{
	t_data data;
	data.player.px = PX;
	data.player.py = PY;
	data.player.pov = 30;
	data.player.viewAngle = 360;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "UwU");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	draw_outlines(&data);
	draw_player(&data);
	mlx_hook(data.win, 2, 0, keyPressFunc, &data);
	mlx_loop(data.mlx);
}