#include "cub3d.h"


int			mapVar[mapHeight][mapWidth] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void	init_req(t_vector2 *start, t_data *data,
			t_vector2 *sin_cos, double angle)
{
	*start = (t_vector2){.x = data->player.pos.x * (data->width / mapWidth),
		data->player.pos.y * (data->height / mapHeight)};
	*sin_cos = (t_vector2){.x = cos((angle + data->player.direction \
	- (data->player.fov / 2)) * M_PI / 180), .y = sin((angle \
	+ data->player.direction - (data->player.fov / 2)) * M_PI / 180)};
}

void	draw_ray(t_ray_data *ray_data, t_vector2 *ray,
		t_data *data, t_vector2 sin_cos)
{
	int	wall;

	wall = 0;
	while (!wall)
	{
		(*ray_data).last_location = (*ray_data).wall_location;
		(*ray).y += sin_cos.y;
		(*ray).x += sin_cos.x;
		ft_my_put_pixel(&data->img, (*ray).x, (*ray).y, 0xffffff);
		(*ray_data).wall_location = (t_llocation){.x = (int)(*ray).x / \
		(data->width / mapWidth), .y = (int)(*ray).y / (data->height / \
		mapHeight)};
		(*ray_data).for_wall = (t_vector2){.x = (*ray).x / \
		(data->width / mapWidth), .y = (*ray).y / (data->width / mapWidth)};
		wall = mapVar[(int)floor((*ray_data).wall_location.x)] \
		[(int)floor((*ray_data).wall_location.y)];
	}
}

t_ray_data	calculate_ray(t_data *data, double angle)
{
	t_ray_data	ray_data;
	t_vector2	ray;
	t_vector2	start;
	t_vector2	sin_cos;

	init_req(&start, data, &sin_cos, angle);
	ray = (t_vector2){.y = start.y, .x = start.x};
	ray_data.wall_location = (t_llocation){.x = (int)ray.x / (data->width
			/ mapWidth), .y = (int)ray.y / (data->height / mapHeight)};
	draw_ray(&ray_data, &ray, data, sin_cos);
	ray_data.ray_location = (t_vector2){.x = ft_fabs(ray.x - start.x),
		.y = (ray.y - start.y)};
	return (ray_data);
}

void	draw_player(void)
{
	int	i;
	int	j;

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

void	draw_outlines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

void	draw_square(int x, int y, t_data *data)
{
	int	start_x;
	int	start_y;

	start_x = x * 64;
	start_y = y * 64;
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

void	ft_my_put_pixel(t_imgdata *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_len + x * (img_data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_my_get_pixel(t_data *data, int x, int y, int i)
{
	char	*dst;

	dst = data->xpm[i].img_ptr + (y * data->xpm[i].line_len + x
			* (data->xpm[i].bpp / 8));
	return (*(unsigned int *)dst);
}
