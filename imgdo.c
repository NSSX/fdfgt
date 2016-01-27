#include "fdf.h"

void place_img(t_struct *param, float xd, float yd)
{
  mlx_destroy_image(param->mlx, param->img->img_ptr);
  param->img->img_ptr = mlx_new_image(param->mlx, WIDTH, HEIGTH);
  set_coordq(param, xd, yd, 0);
  draw_with_tab_on_img(param->coord, param->i, param->maxline, param);
  mlx_put_image_to_window(param->mlx, param->win, param->img->img_ptr, 0, 0);
}

void img_move(int keycode, t_struct *param)
{
  if(keycode == 2)
    {
      param->event->xd += 40;
      place_img(param, param->event->xd, param->event->yd);
    }
  if(keycode == 1)
    {
      param->event->yd += 40;
      place_img(param, param->event->xd, param->event->yd);
    }
  if(keycode == 13)
    {
      param->event->yd -= 40;
      place_img(param, param->event->xd, param->event->yd);
    }
  if(keycode == 0)
    {
      param->event->xd -= 40;
      place_img(param, param->event->xd, param->event->yd);
    }
}

void img_zoom(int keycode, t_struct *param)
{
  if(keycode == 12)
    {
      if(param->zoom < 5)
        {
          param->zoom += 1;
        }
      else
        param->zoom += 5;
      place_img(param, param->event->xd, param->event->yd);
    }
  if(keycode == 14)
    {
      if(param->zoom >= 10)
        param->zoom -= 5;
      else
        param->zoom -= 0.5;
      place_img(param, param->event->xd, param->event->yd);
    }
}

void img_other_view(int keycode, t_struct *param)
{
  if(keycode == 124)
    {
      mlx_destroy_image(param->mlx, param->img->img_ptr);
      param->img->img_ptr = mlx_new_image(param->mlx, WIDTH, HEIGTH);
      set_coordp(param, 10, 10, 0);
      draw_with_tab_on_img(param->coord, param->i, param->maxline, param);
      mlx_put_image_to_window(param->mlx, param->win, param->img->img_ptr, 0, 0);
    }
  if(keycode == 123)
    {
      mlx_destroy_image(param->mlx, param->img->img_ptr);
      param->img->img_ptr = mlx_new_image(param->mlx, WIDTH, HEIGTH);
      set_coordp(param, param->event->xd, param->event->yd, 0);
      draw_with_tab_on_img(param->coord, param->i, param->maxline, param);
      mlx_put_image_to_window(param->mlx, param->win, param->img->img_ptr, 0, 0);
    }
}

void img_other(int keycode, t_struct *param)
{
  if(keycode == 17)
    {
      mlx_destroy_image(param->mlx, param->img->img_ptr);
      param->img->img_ptr = mlx_new_image(param->mlx, WIDTH, HEIGTH);
      set_coordx(param, param->event->xd, param->event->yd, 0);
      draw_with_tab_on_img(param->coord, param->i, param->maxline, param);
      mlx_put_image_to_window(param->mlx, param->win, param->img->img_ptr, 0, 0);
    }
  if(keycode == 36)
    {
      place_img(param, param->event->xd, param->event->yd);
    }
}
