#include "fdf.h"

int		event_mlx(int keycode, t_struct *param)
{
	if (keycode == 53)
		exit(1);
	img_move(keycode, param);
	img_zoom(keycode, param);
	img_other_view(keycode, param);
	img_other(keycode, param);
	return (0);
}
