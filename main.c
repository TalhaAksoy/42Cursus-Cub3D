#include "cub3d.h"
void draw_square(int x, int y, t_data * data)
{

  int start_x, start_y;
  start_x = x * (WIDTH / 10);
  start_y = y * (HEIGHT / 10);
  printf("x = %d, y = %d\n", x, y);
  x = 0;
  y = 0;
  while (x < 190)
  {
    while (y < 107)
    {
      mlx_pixel_put(data->mlx,data->win,x + start_x, y + start_y, 0xff0000);
      y++;
    }
    y=0;
    x++;
  }
}

void draw_outlines(t_data * data)
{
  int i;
  int j;
  int k;
  i = 0;
  j = 0;
  k = 0;

while (i < 10) {
  while (j < 10) {
      if (mapVar[i][j] == 1)
        draw_square(i, j, data);
     j++;
  }

  j = 0 ;
  i++;

}

}

void draw_player(t_data * data)
{
int start_x, start_y, i, j;
start_x = data->player.px * (WIDTH / 10);
start_y = data->player.py * (HEIGHT / 10);
i = 0;
j=0;
while (i < 5)
{
  while (j < 5)
  {
     mlx_pixel_put(data->mlx, data->win, start_x + i, start_y + j, 0x00ff00);
    ++j;
  }
  j = 0;
  i++;
}
}

void draw_ray(t_data * data){
int start_x, start_y;
start_x = data->player.px * (WIDTH / 10);
start_y = data->player.py * (HEIGHT / 10);
int i = 0;
int oX = 0, oY = 0;
double rayY ,  rayX;
double line;
line = data->player.py;
line  = round(line)+ start_y;
++line;
while(i < 1000){
  mlx_pixel_put(data->mlx, data->win, (start_x + (i * cos(data->player.viewAngle))),(start_y + (i * sin(data->player.viewAngle))), 0xffffff);
  i++;
  rayY = data->player.py + (line - data->player.py);
  rayX = (data->player.py - rayY) / -tan(data->player.viewAngle) + data->player.px;
  oX = 1;
  oY = oX * tan(data->player.viewAngle);

  mlx_pixel_put(data->mlx, data->win, rayX+i, rayY, 0xffffff);


}

}

int keyPressFunc(int keycode , t_data * data){
  if (keycode == Key_W)
    data->player.py -= 0.05;
  if (keycode == Key_S)
    data->player.py -= 0.05;
  if (keycode == Key_A)
    data->player.px -= 0.05;
  if (keycode == Key_D)
    data->player.px += 0.05;
  mlx_clear_window(data->mlx, data->win);
  draw_outlines(data);
  draw_player(data);
  draw_ray(data);
  return (INT32_MAX - INT32_MAX);
}

int main(){
  t_data data;
  data.player.px = PX;
  data.player.py = PY;
  data.player.pov = 30;
  data.player.viewAngle = M_PI / 3;

  data.mlx = mlx_init();
  data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "UwU");
  draw_outlines(&data);
  draw_player(&data);
  draw_ray(&data);
  mlx_key_hook(data.win, keyPressFunc, &data);


  mlx_loop(data.mlx);
}