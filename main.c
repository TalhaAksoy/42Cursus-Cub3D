#include "cub3d.h"

void init_var(t_data *data)
{

	data->player.pos.x = 0;
	data->player.pos.y = 0;
	data->player.fov = 60;
	data->player.direction = 60;
	data->mlx = mlx_init();
	data->width = MAPWIDTH * 64;
	data->height = MAPHEIGHT * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "UwU");
	data->win2 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT, "Lil Dicks");
	data->win3 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT, "Real Lil Dicks");
	data->win4 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT, "Real super Lil Dicks");
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	data->img2.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img2.addr = mlx_get_data_addr(data->img2.img, &data->img2.bpp, &data->img2.line_len, &data->img2.endian);
	data->img3.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img3.addr = mlx_get_data_addr(data->img3.img, &data->img3.bpp, &data->img3.line_len, &data->img3.endian);
	data->img4.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img4.addr = mlx_get_data_addr(data->img4.img, &data->img4.bpp, &data->img4.line_len, &data->img4.endian);
	ft_bzero(data->xpm, sizeof(t_xpm) * 4);
	ft_bzero(&data->map_data, sizeof(t_mapdata));
	data->ceiling_color = data->map_data.colors[flooor][0] * 0x010000 + data->map_data.colors[flooor][1] * 0x0100 + data->map_data.colors[flooor][2] * 0x01;
	data->floor_color = data->map_data.colors[ceiling][0] * 0x010000 + data->map_data.colors[ceiling][1] * 0x0100 + data->map_data.colors[ceiling][2] * 0x01;
}

void init_xpm(t_data *data)
{
	data->xpm[north].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[north], &data->xpm[north].width, &data->xpm[north].height);
	data->xpm[north].img_ptr = mlx_get_data_addr(data->xpm[north].img, &data->xpm[north].bpp, &data->xpm[north].line_len, &data->xpm[north].endian);
	data->xpm[east].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[east], &data->xpm[east].width, &data->xpm[east].height);
	data->xpm[east].img_ptr = mlx_get_data_addr(data->xpm[east].img, &data->xpm[east].bpp, &data->xpm[east].line_len, &data->xpm[east].endian);
	data->xpm[west].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[west], &data->xpm[west].width, &data->xpm[west].height);
	data->xpm[west].img_ptr = mlx_get_data_addr(data->xpm[west].img, &data->xpm[west].bpp, &data->xpm[west].line_len, &data->xpm[west].endian);
	data->xpm[south].img = mlx_xpm_file_to_image(data->mlx, data->map_data.xpm_dir[south], &data->xpm[south].width, &data->xpm[south].height);
	data->xpm[south].img_ptr = mlx_get_data_addr(data->xpm[south].img, &data->xpm[south].bpp, &data->xpm[south].line_len, &data->xpm[south].endian);
}

int array_len(char **str)
{
	int i;

	i = 0;
	printf("%s %s %s\n", str[0],str[1],str[2]);
	while (str[i] != NULL)
	{
		printf("%d\n", i);
		i++;
	}
	printf("zamazingo\n");
	return (i);
}

int init_direction(t_data *data, int i, int j)
{
	static int flags;

	if (data->map_data.map[i][j] == 'N')
		data->player.direction = 270;
	else if (data->map_data.map[i][j] == 'W')
		data->player.direction = 180;
	else if (data->map_data.map[i][j] == 'E')
		data->player.direction = 0;
	else if (data->map_data.map[i][j] == 'S')
		data->player.direction = 90;
	else if ((data->map_data.map[i][j] != '0' && data->map_data.map[i][j] != '1' && data->map_data.map[i][j] != 0) && ft_isascii(data->map_data.map[i][j]))
		return (-1);
	if (data->map_data.map[i][j] == 'N' || data->map_data.map[i][j] == 'W' 
	|| data->map_data.map[i][j] == 'E' ||data->map_data.map[i][j] == 'S')
	{
		flags += 1;
		data->player.pos.x = (double)j + .5;
		data->player.pos.y = (double)i + .5;
		data->map_data.map[i][j] = '0';
	}
	if (flags > 1)
		return (-1);
	return (0);
}

int ft_set_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->map_data.int_map = (int **)ft_calloc(array_len(data->map_data.map), sizeof(int *));
	while (i <= data->map_data.map_end - data->map_data.map_start)
	{
		data->map_data.int_map[i] = (int *)ft_calloc(longest_line(data), sizeof(int));
		while (j < longest_line(data) && data->map_data.map[i][j])
		{
			if(data->map_data.map[i][j] == '\n')
				break ;
			if (data->map_data.map[i][j] == 32)
				data->map_data.map[i][j] = '1';
			if (init_direction(data, i, j) == -1)
				return (map | int_map);
			data->map_data.int_map[i][j] = data->map_data.map[i][j] - 48;
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int check_wall_xpm(t_data *data)
{
	int i;
	int fd;

	i = 0;
	fd = 0;
	while (i < 4)
	{
		fd = open(data->map_data.xpm_dir[i], O_RDONLY);
		if (fd == -1)
		{
			return (xpm);
		}
		close(fd);
		i++;
	}
	return (0);
}

int extension_check(char *path)
{
	if (ft_strlen(path) > 4 
	&& path[ft_strlen(path) - 1] == 'b' 
	&& path[ft_strlen(path) - 2] == 'u' 
	&& path[ft_strlen(path) - 3] == 'c' 
	&& path[ft_strlen(path) - 4] == '.')
		return (0);
	return (-1);
}

t_control ft_recontrol(t_control control)
{
	t_control ret;

	ret = (t_control){
		.read_file = control.read_file * (control.read_file != -1),
		.check_wall =  control.check_wall * (control.check_wall != -1),
		.get_map = control.get_map * (control.get_map != -1),
		.set_map = control.set_map * (control.set_map != -1),
		.player_pos = control.player_pos
	};
	return (ret);
}

void ft_xpm_cleaner(t_data *data)
{
	if (data->map_data.xpm_dir[0])
		free(data->map_data.xpm_dir[0]);
	if (data->map_data.xpm_dir[1])
		free(data->map_data.xpm_dir[1]);
	if (data->map_data.xpm_dir[2])
		free(data->map_data.xpm_dir[2]);
	if (data->map_data.xpm_dir[3])
		free(data->map_data.xpm_dir[3]);
}

void	free_func(t_data *data,int control_data)
{
	if (control_data & xpm)
		ft_xpm_cleaner(data);
	if (control_data & int_map)
		array_cleaner((void **)data->map_data.int_map);
	if (control_data & map)
		array_cleaner((void **)data->map_data.map);
}

int error_check(t_data *data, char *path)
{
	int fd;
	t_control control;

	fd = open(path, O_RDONLY);
	if (fd < 0 || extension_check(path) == -1)
	{
		printf("Error\n");
		return (-8);
	}
	control = (t_control){read_file(data, fd), check_wall_xpm(data),
		ft_get_map(data, path), ft_set_map(data),
		.player_pos = (data->player.pos.x == 0 && data->player.pos.y == 0) * (xpm | map | int_map)};
	if (control.read_file != 0 || control.check_wall 
	!= 0 ||  control.get_map != 0 || control.set_map
	!= 0 || control.player_pos != 0)
	{
		control = ft_recontrol(control);
		free_func(data, control.check_wall | control.get_map | control.player_pos | control.read_file  | control.set_map);
		printf("Error\n");
		return (-1);
	}
	return (0);
}

void	ft_exit(t_data *data)
{
	free_func(data, map | xpm);
	mlx_destroy_image(data->mlx, data->img4.img);
	mlx_destroy_window(data->mlx, data->win4);
	system("leaks Cub3D");
	exit(1);
}

int main(int ac, char *av[])
{
	t_data data;

	if (ac == 2)
	{
		init_var(&data);
		if (error_check(&data, av[1]) == -1)
		{
			return (1);
		}
		init_xpm(&data);
		data.floor_color = data.map_data.colors[flooor][0] * 0x010000 + data.map_data.colors[flooor][1] * 0x0100 + data.map_data.colors[flooor][2] * 0x01;
		data.ceiling_color = data.map_data.colors[ceiling][0] * 0x010000 + data.map_data.colors[ceiling][1] * 0x0100 + data.map_data.colors[ceiling][2] * 0x01;
		// initBisiler
		// initBaskaBisilerFalan
		render_window(&data);
		mlx_hook(data.win, 2, 1, key_press_func, &data);
		mlx_hook(data.win2, 2, 1, key_press_func, &data);
		mlx_hook(data.win3, 2, 1, key_press_func, &data);
		mlx_hook(data.win4, 2, 1, key_press_func, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
