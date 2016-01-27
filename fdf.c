#include "fdf.h"

int main(int argc, char **argv)
{ 
  char *line;
  int i;
  t_struct *mystruct;
  char ***coord;
  char **tab;

  i = 0;
  if(error(argc) == 0)
    return (0);
  mystruct = give(mystruct);
  legend(mystruct->mlx, mystruct->win);  
  tab = create_tab(argv[1], tab);
  while(tab[i])
    i++;
  coord = create_coord_tab(tab, coord, i);
  mystruct = give2(mystruct, i, tab, coord);
  mystruct->img = give_img(mystruct->mlx);
  mystruct->event = give_myevent();;
  mlx_key_hook(mystruct->win, event_mlx, mystruct);
  mlx_loop(mystruct->mlx);
  return(0);
}
