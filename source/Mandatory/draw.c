/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/28 23:30:02 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	int			x;
	int			y;

	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 600)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_mandelbrot(fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 600)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_julia(fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}
//why 0 in mlx put image?