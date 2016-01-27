#include "fdf.h"

t_event *give_myevent()
{
  t_event *myevent;

  myevent = (t_event *)malloc(sizeof(t_event) * 4);
  myevent->xd = 300;
  myevent->yd = 60;
  return (myevent);
}

int error(int argc)
{
  if(argc != 2)
    {
      printf("Bug arg");
      return (0);
    }
  return (1);
}
