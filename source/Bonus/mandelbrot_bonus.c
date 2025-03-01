/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/24 16:44:48 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_mandelbrot(t_fractal *f)
{
	int		i;
	double	old_zx;
	int		color;

	f->name = "mandelbrot";
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (i < f->max_iterations && hypot(f->zx, f->zy) < 2.0)
	{
		old_zx = f->zx;
		f->zx = fma(f->zx, f->zx, -f->zy * f->zy) + f->cx;
		f->zy = fma(2.0 * old_zx, f->zy, f->cy);
		i++;
	}
	if (i == f->max_iterations)
		color = 0x000000;
	else
		color = f->color * i;
	put_color_to_pixel(f, f->x, f->y, color);
}
