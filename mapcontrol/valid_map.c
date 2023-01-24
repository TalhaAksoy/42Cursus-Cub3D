# include "../cub3d.h"

int top_wall(t_data *data)
{
    int i;

    i = 0;
    while(data->map_data.map[0][i])
    {
        if (data->map_data.map[0][i] == '0')
            return (-1);
        i++;
    }
    return (0);
}

int bottom_wall(t_data *data)
{
    int i;

    i = 0;
    while (data->map_data.map[array_len(data->map_data.map) - 1][i])
    {
        if (data->map_data.map[array_len(data->map_data.map) - 1][i] == '0')
            return (-1);
        i++;
    }
    return (0);
}

int left_wall(t_data *data)
{
    int i;

    i = 0;
    while(data->map_data.map[i])
    {
        if (data->map_data.map[i][0] == '0')
            return (-1);
        i++;
    }
    return (0);
}