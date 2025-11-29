/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:03 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 11:26:30 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	handle_pixel(t_fractal *f, int x, int y)
{
	t_complex	c;
	int			iter;
	int			color;

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
}

void	render_fractal(t_fractal *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(f, x, y);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
