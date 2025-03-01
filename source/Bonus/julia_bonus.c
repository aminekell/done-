/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/24 16:44:45 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_julia(t_fractal *f)
{
	int		i;
	double	tmp;

	f->name = "julia";
	f->zx = f->x / f->zoom + f->offset_x;
	f->zy = f->y / f->zoom + f->offset_y;
	i = 0;
	while (++i < f->max_iterations && hypot(f->zx, f->zy) < 2.0)
	{
		tmp = f->zx;
		f->zx = fma(f->zx, f->zx, -f->zy * f->zy) + f->cx;
		f->zy = fma(2.0 * tmp, f->zy, f->cy);
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
