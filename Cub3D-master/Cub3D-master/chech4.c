#include "cub3d.h"

void    ft_find(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (data->map[++i])
    {
        j = 0;
        while (data->map[i][j])
        {  
            if (data->map[i][j] == 'N' || data->map[i][j] == 'W' || data->map[i][j] == 'E' || data->map[i][j] == 'S')
                break ;
            if (data->map[i][j] == 'F' || data->map[i][j] == 'C' || data->map[i][j] == '\n')
                break ;
            if (data->map[i][j] == ' ' || data->map[i][j] == '1' || data->map[i][j] == '0')
            {
                while ((data->map[i][j] != '1' || data->map[i][j] != '0') && data->map[i][j])
                {
                    if (data->map[i][j] == '1' || data->map[i][j] == '0')
                    {
                        data->first_line = i;
                        return ;
                    }
                    j++;
                }
            }
        }
    }
}   

char    **ft_rebuild(t_data *data)
{
    int i;
    int j;
    int k;
    char    **s;
    i = data->first_line - 1;
    k = 0;
    while (data->map[++i])
    {
        j = 0;
        while (data->map[i][j])
            j++;
        if (k < j)
            k = j;
    }
    j = data->first_line - 1;
    s = (char **)malloc(sizeof(i - data->first_line + 1));
    i = 0;
    while (data->map[++j])
        s[i++] = (char *)malloc(sizeof(k + 1));
    return (s);
}

char    **ft_rebuild2(t_data *data, char **s)
{
    int i;
    int j;
    int k;

    k = 0;
    i = data->first_line - 1;
    j = 0;
    while (data->map[++i])
    {
        j = 0;
        while (data->map[i][j])
            j++;
        if (k < j)
            k = j;
    }
    while (data->map[++i])
    {
        j = 0;
        while (j <= k)
        {
            s[k++][j] = data->map[i][j];
            j++;
        }
    }
    return (s);
}

void    ft_check_zero(t_data *data)
{
    int i;
    int j;
    char    **s;

    s = ft_rebuild(data);
    s = ft_rebuild2(data, s);
    i = data->first_line;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')
            {
                if (data->map[i][j + 1] == '\0'  || data->map[i - 1] || \
                data->map[i][j - 1] == '\0' || data->map[i + 1][j] == 0)
                {
                    printf("Map Error!\n");
                    ft_clear(data);
                    exit(1);
                }
            }
            j++;
        }
        i++;
    }
    free(s);
}