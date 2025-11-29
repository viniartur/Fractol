/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:11:42 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 11:36:13 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifdef __linux__
#  include "minilibx-linux/mlx.h"
# else
#  include <mlx.h>
# endif

# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_complex	julia_c;
}	t_fractal;

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
double		complex_abs(t_complex a);

void		render_fractal(t_fractal *f);
void		my_mlx_pixel_put(t_fractal *f, int x, int y, int color);

int			calculate_mandelbrot(t_complex c);
int			calculate_julia(t_complex z, t_complex c);

int			key_hook(int keycode, t_fractal *f);
int			mouse_hook(int button, int x, int y, t_fractal *f);
int			close_window(t_fractal *f);

void		show_help(void);
int			create_trgb(int t, int r, int g, int b);
double		ft_atof(const char *str);

#endif