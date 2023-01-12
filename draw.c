#include "cub3d.h"


int mapVar[10][10] = {
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


/**
 * It draws a ray from the player's position to the wall
 * 
 * @param data the data structure that holds all the information about the game.
 * @param angle the angle of the ray in degrees
 */
void draw_ray(t_data *data, double angle)
{ // isinlar icin
	int start_x, start_y;
	start_x = data->player.px * (WIDTH / 10);
	start_y = data->player.py * (HEIGHT / 10);
	int i = 0;

	int mapX = (int)start_x;
	int mapY = (int)start_y;
	// int stepX = 0;
	// int stepY = 0;
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
			// stepX = -1;
			sideDistX = (start_x - mapX) * deltaDistX;
		}
		else
		{
			// stepX = 1;
			sideDistX = (mapX + 1.0 - start_x) * deltaDistX;
		}
		if (rayY < 0)
		{
			// stepY = -1;
			sideDistY = (start_y - mapY) * deltaDistY;
		}
		else
		{
			// stepY = 1;
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

/**
 * It draws the player
 * 
 * @param data This is the data structure that holds all the information about the game.
 */
// void draw_player(t_data *data) // playeri ciziyor
void draw_player(void) // playeri ciziyor
{
	//int start_x, start_y; 
	int i, j;
	//start_x = data->player.px * (WIDTH / 10);
	//start_y = data->player.py * (HEIGHT / 10);
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

void draw_outlines(t_data *data) // kirmizi kutularin tamami icin
{
	int i;
	int j;
	// int k;
	i = 0;
	j = 0;
	// k = 0;

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

void ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color) // image adresine pixel basmak icin
{
	char *dst;

	dst = img_data->addr + (y * img_data->line_len + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}
