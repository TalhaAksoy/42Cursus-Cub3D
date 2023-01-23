# include "../cub3d.h"

char *ft_is_space(char *s)
{
    while(*s == ' ' || (*s >= 9 && *s <= 13))
    {
        s++;
    }
    return (s);
}

int ft_check_value(char *s, char **find, int size, t_data *data)
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
            printf("%s tmp\n", tmp);
            data->map_data.xpm_dir[i] = ft_strdup(tmp);
            printf("%s\n", data->map_data.xpm_dir[i]);
            free(tmp);
            break ;
        }
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
        if (ft_check_value(line, (char*[]){"NO", "EA", "WE", "SO"}, 4,data) == -1)
        {
            free(line);
            return (-1);
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    if (data->map_data.xpm_dir[0] == NULL)
        return (-1);
    return (0);
}