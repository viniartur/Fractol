/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:11:35 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 12:16:11 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	complex_square(t_complex a)
{
	t_complex	result;

	result.re = (a.re * a.re) - (a.im * a.im);
	result.im = 2 * a.re * a.im;
	return (result);
}

int	calculate_mandelbrot(t_complex c)
{
	t_complex	z;
	double		z_re2;
	double		z_im2;
	int			iter;

	z.re = 0;
	z.im = 0;
	z_re2 = 0;
	z_im2 = 0;
	iter = 0;
	while (iter < MAX_ITER && (z_re2 + z_im2) <= 4.0)
	{
		z.im = 2 * z.re * z.im + c.im;
		z.re = z_re2 - z_im2 + c.re;
		z_re2 = z.re * z.re;
		z_im2 = z.im * z.im;
		iter++;
	}
	return (iter);
}

int	calculate_julia(t_complex z, t_complex c)
{
	double	z_re2;
	double	z_im2;
	int		iter;

	iter = 0;
	z_re2 = z.re * z.re;
	z_im2 = z.im * z.im;
	while (iter < MAX_ITER && (z_re2 + z_im2) <= 4.0)
	{
		z.im = 2 * z.re * z.im + c.im;
		z.re = z_re2 - z_im2 + c.re;
		z_re2 = z.re * z.re;
		z_im2 = z.im * z.im;
		iter++;
	}
	return (iter);
}
