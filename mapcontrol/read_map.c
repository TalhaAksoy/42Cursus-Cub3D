# include "../cub3d.h"

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

char *ft_clearline(char *line)
{
    char *ret;

    ret = ft_clearline(line);
    free(line);
    return (ret);
}

int ft_count_line(char *path)
{
    int     fd;
    char    *line;
    int     line_count;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return(-1);
    line = get_next_line(fd);
    while(line)
    {    
        ++line_count;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    if (!line_count)
        return (-1);
    return (line_count);
}

char **get_lines(char *path, int total_line)
{
    char    *line;
    int     fd;
    char    **ret;
    int     i;

    i = 0;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    ret = ft_calloc(total_line + 1, sizeof(char *));
    line = get_next_line(fd);
    while(line)
    {
        ret[i] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    close(fd);
    return (ret);
}

int control(char *tmp, int flags, t_data *data, int i)
{
    if (flags == 0 || flags == 2)
    {
        if (*tmp != '0' && *tmp != '1')
            return (flags);
        else if (flags == 0)
            data->map_data.map_start = i + 1; 
    }
    if (flags == 1)
    {
        if (*tmp == '0' || *tmp == '1')
            return (flags);
        else
            data->map_data.map_end = i - 1;
    }
    printf("%d => start | %d => end | burada2\n", data->map_data.map_start, data->map_data.map_end);
    return (flags + 1);
}

int ft_multi_map(t_data *data, int total_line, char **lines)
{
    int flag;
    int i;
    char *tmp;

    i = 0;
    flag = 0;

    while (lines[i])
    {
        tmp = ft_strdup(ft_is_space(lines[i]));
        flag = control(tmp, flag, data, i);
        if (flag == 3)
            return (-1);
        free(tmp);
        i++;
    }
    if (flag == 1)
        data->map_data.map_end = i;
    return (0);
}

int put_map(t_data *data, char **lines)
{
    int i;
    
    i = 0;
    printf("%d => start | %d => end | burada\n", data->map_data.map_start, data->map_data.map_end);
    while(data->map_data.map_start + i <= data->map_data.map_end)
    {
        data->map_data.map[i] = ft_strdup(lines[data->map_data.map_start + i - 1]);
        printf("%s map data\n", data->map_data.map[i]);
        i++;
    }
    return (0);
}

int ft_get_map(t_data *data, char *path)
{
    int     total_line;
    char    **lines;
    
    total_line = ft_count_line(path);
    if (total_line == -1)
        return (-1);
    data->map_data.map = ft_calloc(total_line, sizeof(char *));
    lines = get_lines(path, total_line);
    if (!lines)
        return (-1);
    if (ft_multi_map(data, total_line, lines) == -1)
        return (-1);
    for (int i = 0; i < total_line; i++)
    {
        printf("%s => line\n", lines[i]);
    }
    if (put_map(data, lines) == -1)
        return (-1);
    return (0);
}


int get_map_height(t_data *data, char *path)
{
    char *line;
    char *tmp;
    int fd;
    int ret;

    fd = open(path, O_RDONLY);
    ret = 0;
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while(line)
    {
        tmp = ft_is_space(line);
        if (*tmp == '0' || *tmp == '1')
            ret++;
    }
    return (ret);
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
        || ft_check_rgb(line, (char*[]){"F","C"}, 2, data) == -1)
        {
            free(line);
            return (-1);
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    if (check_null(data) == -1)
        return (-1);
    return (0);
}