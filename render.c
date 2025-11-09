#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calculate_mandelbrot(t_complex c)
{
	t_complex	z;
	int			iter;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		z = complex_add(complex_square(z), c);
		if (complex_abs(z) > 2.0)
			break ;
		iter++;
	}
	return (iter);
}

int	calculate_julia(t_complex z, t_complex c)
{
	int	iter;

	iter = 0;
	while (iter < MAX_ITER)
	{
		z = complex_add(complex_square(z), c);
		if (complex_abs(z) > 2.0)
			break ;
		iter++;
	}
	return (iter);
}

void	render_fractal(t_fractal *f)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) / (0.5 * WIDTH * f->zoom) + f->offset_x;
			c.im = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * f->zoom) + f->offset_y;
			if (f->type == 1)
				iter = calculate_mandelbrot(c);
			else
				iter = calculate_julia(c, f->julia_c);
			color = create_trgb(0, (iter * 8) % 255,
					(iter * 4) % 255, (iter * 2) % 255);
			if (iter == MAX_ITER)
				color = 0;
			my_mlx_pixel_put(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}