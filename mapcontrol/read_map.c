# include "../cub3d.h"

int ft_check_xpm(char *s, char **find, t_data *data)
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
                return (-(xpm));
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

int ft_count_line(char *path)
{
    int     fd;
    char    *line;
    int     line_count;

    line_count = 0;
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
    return (flags + 1);
}

int ft_multi_map(t_data *data, char **lines)
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

int check_all_way(t_data *data, int i, int j)
{
    if (data->map_data.map[i - 1][j] == 32 || (data->map_data.map[i - 1][j] >= 9 && data->map_data.map[i - 1][j] <= 13))
        return (-1);
    if (data->map_data.map[i + 1][j] == 32 || (data->map_data.map[i + 1][j] >= 9 && data->map_data.map[i + 1][j] <= 13))
        return (-1);
    if (data->map_data.map[i][j - 1] == 32 || (data->map_data.map[i][j - 1] >= 9 && data->map_data.map[i][j - 1] <= 13))
        return (-1);
    if (data->map_data.map[i][j + 1] == 32 || (data->map_data.map[i][j + 1] >= 9 && data->map_data.map[i][j + 1] <= 13))
        return (-1);
    if (data->map_data.map[i+1][j+1] == 32 || (data->map_data.map[i+1][j+1] >= 9 && data->map_data.map[i+1][j+1] <= 13))
        return (-1);
    if (data->map_data.map[i-1][j-1] == 32 || (data->map_data.map[i-1][j-1] >= 9 && data->map_data.map[i-1][j-1] <= 13))
        return (-1);
    if (data->map_data.map[i-1][j+1] == 32 || (data->map_data.map[i-1][j+1] >= 9 && data->map_data.map[i-1][j+1] <= 13))
        return (-1);
    if (data->map_data.map[i+1][j-1] == 32 || (data->map_data.map[i+1][j-1] >= 9 && data->map_data.map[i+1][j-1] <= 13))
        return (-1);
    return (0);
}

int check_wall(t_data *data)
{
    int i;
    int j;

    i= 1;
    j = 1;
    if (left_wall(data) == -1 || top_wall(data) == -1 || bottom_wall(data) == -1)
        return (-(map));
    while (data->map_data.map[i])
    {
        while(data->map_data.map[i][j])
        {
            if (data->map_data.map[i][j] == '0' || data->map_data.map[i][j] == 'N' 
            || data->map_data.map[i][j] == 'S' || data->map_data.map[i][j] == 'E' 
            || data->map_data.map[i][j] == 'W')
            {
                if (check_all_way(data, i, j) == -1)
                    return (-1);
            }
            j++;
        }
        i++;
        j=1;
    }
    return (0);
}

int put_map(t_data *data, char **lines)
{
    int i;
    
    i = 0;
    while(data->map_data.map_start + i <= data->map_data.map_end)
    {
        data->map_data.map[i] = ft_strdup(lines[data->map_data.map_start + i - 1]);
        i++;
    }
    array_cleaner((void **)lines);
    if (check_wall(data) == -1)
        return (-1);
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
    if (ft_multi_map(data, lines) == -1)
    {
        array_cleaner((void **)lines);
        return (-1);
    }
    if (put_map(data, lines) == -1)
        return (map);
    return (0);
}


int get_map_height(char *path)
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

int read_file(t_data *data , int fd)
{
    char    *line;

    line = get_next_line(fd);
    while(line)
    {
        if (ft_check_xpm(line, (char*[]){"NO", "EA", "WE", "SO"}, data) == -1
        || ft_check_rgb(line, (char*[]){"F","C"}, 2, data) == -1)
        {
            free(line);
            return (xpm);
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    if (check_null(data) == -1)
        return (xpm);
    return (0);
}