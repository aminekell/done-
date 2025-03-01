/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:53:00 by akella            #+#    #+#             */
/*   Updated: 2025/03/01 00:21:33 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_tricorn(t_fractal *f)
{
	int		i;
	double	tmp;

	f->name = "tricorn";
	f->cx = f->x / f->zoom + f->offset_x;
	f->cy = f->y / f->zoom + f->offset_y;
	f->zx = 0.0;
	f->zy = 0.0;
	i = 0;
	while (i < f->max_iterations && hypot(f->zx, f->zy) < 2.0)
	{
		tmp = f->zx;
		f->zx = (f->zx * f->zx) - (f->zy * f->zy) + f->cx;
		f->zy = -2.0 * tmp * f->zy + f->cy;
		i++;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
