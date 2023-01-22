#include "cub3d.h"

int ft_check_last(t_data *data, char *s, int j)
{
    int i;
    int k;

    i = 0;
    k = 0;
    if (data->map[j + 1] == 0)
        return (0);
    while (s[i])
        i++;
    while (data->map[j + 1][k])
        k++;
    if (i != k)
        return (1);
    return (0);
}

void    ft_control_last_lines(t_data *data, char *s, int j)
{
    int i;
    int k;

    i = ft_strlen(s);
    k = ft_strlen(data->map[j + 1]);
    if (i > k)
    {
        while (i != k)
        {
            if (s[k] != '1' && s[k] != '\n')
            {
                printf("Error!\n");
                ft_clear(data);
                exit(0);
            }
            k++;
        }
    }
    else
    {
        while (k != i)
        {
            if (data->map[j + 1][i] != '1' && data->map[j + 1][i] != '\n')
            {
                printf("%i\n",data->map[j + 1][i]);
                printf("Error!\n");
                ft_clear(data);
                exit(0);
            }
            i++;
        }
    }
}

void    ft_check_for_long(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = data->first_line;
    while (data->map[j] && data->map[j][0] != '\n')
    {
        if (ft_check_last(data, data->map[j], j))
            ft_control_last_lines(data, data->map[j], j);
        j++;
    }
}