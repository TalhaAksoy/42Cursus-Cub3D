# include "../cub3d.h"

char    *last_trim(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
    while(str[i])
    {
        if (ft_isprint(str[i]) == 1 && str[i] != 32)
        {
            break;
        }
        str[i] = 0;
        i--;
    }
    return (str);
}

int ft_check_rgb(char *s, char **find, int size, t_data *data)
{
    int fd;
    char *tmp;
    int i;
    int j;


    fd = 0;
    i = 0;
    j = 0;
    s = ft_is_space(s);
    while(i < 4)
    {
        if (!ft_strncmp(s, find[i], 1))
        {
            s = s + 1;
            s = ft_is_space(s);
            while (data->map_data.colors[i])
            {
                while(data->map_data.colors[i][j])
                {
                    if (data->map_data.colors[i][j] > 256 && data->map_data.colors[i][j] < 0)
                        return (-1);
                    j++;
                }
                i++;
            }
            tmp = ft_substr(s, 0, ft_strlen(s) - 1);
            data->map_data.xpm_dir[i] = ft_strdup(tmp);
            data->map_data.xpm_dir[i] = last_trim(data->map_data.xpm_dir[i]);
            free(tmp);
            break ;
        }
        i++;
    }
    return (0);
}
