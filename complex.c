/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:11:35 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 11:45:05 by vvieira          ###   ########.fr       */
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

	result.re = a.re * a.re - a.im * a.im;
	result.im = 2 * a.re * a.im;
	return (result);
}

double	complex_abs(t_complex a)
{
	return (sqrt(a.re * a.re + a.im * a.im));
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
