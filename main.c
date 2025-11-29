/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:11:53 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 12:16:51 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!f->win)
	{
		free(f->mlx);
		exit(1);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0, close_window, f);
}

void	show_help(void)
{
	write(2, "Usage:\n", 7);
	write(2, "  ./fractol M           - Mandelbrot\n", 36);
	write(2, "  ./fractol J -0.7 0.27 - Julia with custom parameters\n", 53);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2)
		return (show_help(), 1);
	if (argv[1][0] == 'M')
		f.type = 1;
	else if (argv[1][0] == 'J' && argc == 4)
	{
		f.type = 2;
		f.julia_c.re = ft_atof(argv[2]);
		f.julia_c.im = ft_atof(argv[3]);
	}
	else
		return (show_help(), 1);
	fractal_init(&f);
	render_fractal(&f);
	mlx_loop(f.mlx);
	return (0);
}

int	close_window(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}
