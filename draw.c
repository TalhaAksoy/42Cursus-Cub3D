#include "cub3d.h"

int mapVar[mapHeight][mapWidth] = {
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




/**
 * It draws a ray from the player's position to the wall
 * 
 * @param data the data structure that holds all the information about the game.
 * @param angle the angle of the ray in degrees
 */
t_ray_data draw_ray(t_data *data, double angle)
{ // isinlar icin
	int start_x, start_y;
	start_x = data->player.pos.x * (data->width / mapWidth);
	start_y = data->player.pos.y * (data->height / mapHeight);
	int i = 0;
	t_llocation last_location;

	// int mapX = (int)start_x;
	// int mapY = (int)start_y;
	// int stepX = 0;
	// int stepY = 0;
	double rayY, rayX;
	// double deltaDistX = 0;
	// double deltaDistY = 0;
	// double sideDistX = 0;
	// double sideDistY = 0;
	rayY = (start_y) + (i * sin((angle + data->player.direction - 30) * (M_PI / 180)));
	rayX = (start_x) + (i * cos((angle + data->player.direction - 30) * (M_PI / 180)));
	last_location = (t_llocation){.x = (int) rayX / (data->width / mapWidth), .y = (int) rayY / (data->height / mapHeight)};
	
	while (!mapVar[last_location.x][last_location.y])
	{
		rayY = (start_y) + (i * sin((angle + data->player.direction - 30) * (M_PI / 180)));
		rayX = (start_x) + (i * cos((angle + data->player.direction - 30) * (M_PI / 180)));
		// printf("%lf = ry, %lf = rx, %f =ddx\n", rayY, rayX, sqrt(1 + (rayY * rayY) / (rayX * rayX)));
		if (angle >= 29.5 && angle <=30.5)
			ft_my_put_pixel(&data->img, rayX, rayY, 0xfff);
		else
			ft_my_put_pixel(&data->img, rayX, rayY, 0xffffff);
		i++;
		last_location = (t_llocation){.x = (int) rayX / (data->width / mapWidth), .y = (int) rayY / (data->height / mapHeight)};
	}
	return ((t_ray_data){.last_location = last_location, .ray_location = (t_vector2){.x = ft_fabs(rayX - start_x), .y = (rayY - start_y)}});
	//	 printf("%lf => deltaDistX |  %lf => deltaDistY\n", sideDistX, sideDistY);
	// printf("ray_len = %f\n", sqrt(1 + (rayY * rayY) / (rayX * rayX)));
	// printf("%f angle\n", data->player.direction);
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
	//start_x = data->player.pos.x * (data->width / 10);
	//start_y = data->player.pos.y * (data->height / 10);
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

	while (i < mapHeight)
	{
		while (j < mapWidth)
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
	start_x = x * 64;
	start_y = y * 64;
	// printf("x = %d, y = %d\n", x, y);
	x = 0;
	y = 0;
	while (x < 64)
	{
		while (y < 64)
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
