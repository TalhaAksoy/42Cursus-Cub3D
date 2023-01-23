# include "../cub3d.h"

char *ft_is_space(char *s)
{
    while(*s == ' ' || (*s >= 9 && *s <= 13))
    {
        s++;
    }
    return (s);
}

int ft_check_xpm(char *s, char **find, int size, t_data *data)
{
    int fd;
    char *tmp;
    int i;


    fd = 0;
    i = 0;
    s = ft_is_space(s);
    while(i < 4)
    {
        if (!ft_strncmp(s, find[i], 2))
        {
            s = s + 2;
            s = ft_is_space(s);
            if (data->map_data.xpm_dir[i])
                return (-1);
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

int check_null(t_data *data)
{
    int i;

    i = 0;
    while(i < 4)
    {
        if (data->map_data.xpm_dir[i] == NULL)
            return (-1);
        i++;
    }
    return (0);
}

int read_file(t_data *data , char *path)
{
    char    *line;
    int     fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        exit(1);
    line = get_next_line(fd);

    while(line)
    {
        if (ft_check_xpm(line, (char*[]){"NO", "EA", "WE", "SO"}, 4,data) == -1
        && ft_check_rgb(line, (char*[]){"F","C"}, 2, data))
        {
            free(line);
            return (-1);
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    if (check_null(data) == -1)
        return (-1);
    return (0);
}