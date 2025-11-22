#include "fractol.h"

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == 65307) // ESC
		close_window(f);
	else if (keycode == 65362) // Up arrow
		f->offset_y -= 0.1 / f->zoom;
	else if (keycode == 65364) // Down arrow
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == 65361) // Left arrow
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == 65363) // Right arrow
		f->offset_x += 0.1 / f->zoom;
	render_fractal(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	(void)x;
	(void)y;
	if (button == 4) // Scroll up
		f->zoom *= 1.1;
	else if (button == 5) // Scroll down
		f->zoom /= 1.1;
	render_fractal(f);
	return (0);
}