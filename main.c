/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lil_Dicks <.>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:01:42 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/01/25 09:52:57 by Lil_Dicks        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_set_map_in(t_data *data, int i, int j)
{
	while (i <= data->map_data.map_end - data->map_data.map_start)
	{
		data->map_data.int_map[i] = (int *)ft_calloc(longest_line(data),
				sizeof(int));
		while (j < longest_line(data) && data->map_data.map[i][j])
		{
			if (data->map_data.map[i][j] == '\n')
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
/*String Gelen Mapi Inte Donusturur*/
int	ft_set_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;̦
	data->map_data.int_map = (int **)ft_calloc(array_len(data->map_data.map),
			sizeof(int *));
	return (ft_set_map_in(data, i, j));
}

int	ft_exit(t_data *data)
{
	free_func(data, map | xpm);
	mlx_destroy_image(data->mlx, data->img4.img);
	mlx_destroy_window(data->mlx, data->win4);
	exit(0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 2)
	{
		init_var(&data);
		if (error_check(&data, av[1]) == -1)
		{
			return (1);
		}
		init_xpm(&data);
		init_color(&data);
		render_window(&data);
		mlx_hook(data.win, 2, 1, key_press_func, &data);
		mlx_hook(data.win2, 2, 1, key_press_func, &data);
		mlx_hook(data.win3, 2, 1, key_press_func, &data);
		mlx_hook(data.win4, 2, 1, key_press_func, &data);
		mlx_hook(data.win4, 17, 0, ft_exit, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
