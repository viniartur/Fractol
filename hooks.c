/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:11:47 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 11:23:59 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		close_window(f);
	else if (keycode == 65362)
		f->offset_y -= 0.1 / f->zoom;
	else if (keycode == 65364)
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == 65361)
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == 65363)
		f->offset_x += 0.1 / f->zoom;
	render_fractal(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom /= 1.1;
	render_fractal(f);
	return (0);
}
