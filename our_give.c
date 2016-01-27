#include "fdf.h"

t_struct *give(t_struct *mystruct)
{
  mystruct = (t_struct *)malloc(sizeof(t_struct) * 20);
  mystruct->mlx = mlx_init();
  mystruct->win = mlx_new_window(mystruct->mlx, WIDTH, HEIGTH, "42");
  mystruct->zoom = 20;
  return (mystruct);
}

int give_maxline(char **tab)
{
  int maxline;
  int index;

  maxline = 0;
  index = 0;
  while(tab[index][0] != '\n')
    {
      if(tab[index][0] != ' ')
        maxline++;
      index++;
    }
  return (maxline);
}

t_struct *give2(t_struct *mystruct, int i, char **tab, char ***coord)
{
  mystruct->i = i;
  mystruct->maxline = give_maxline(tab);;
  mystruct->coord = coord;
  return (mystruct);
}

t_img *give_img(void *mlx)
{
  t_img *myimg;

  myimg = (t_img *)malloc(sizeof(t_img) * 10);
  myimg->img_ptr = mlx_new_image(mlx, WIDTH, HEIGTH);
  myimg->mlx_ptr = mlx;
  return (myimg);
}

void legend(void *mlx, void *win)
{
  int sizeH;
  int sizeW;

  sizeH = HEIGTH /3;
  sizeW = WIDTH / 3;
  mlx_string_put(mlx, win, sizeH, sizeW, 0x00FFFF, "HOW TO USE ?");
  mlx_string_put(mlx, win, sizeH, sizeW + 40, 0x00FFFF, "Q : ZOOM + | ZOOM - : E");
  mlx_string_put(mlx, win, sizeH, sizeW + 80, 0x00FFFF, "A : MOVE LEFT | MOVE RIGHT : D");
  mlx_string_put(mlx, win, sizeH, sizeW + 120, 0x00FFFF, "W : MOVE UP | MOVE DOWN : S");
  mlx_string_put(mlx, win, sizeH, sizeW + 160, 0x00FFFF, "T : SMALL SCALE");
  mlx_string_put(mlx, win, sizeH, sizeW + 210, 0x00FFFF, "PRESS RETURN FOR START");
}
