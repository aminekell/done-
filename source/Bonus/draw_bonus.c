/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/25 01:00:04 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;
	int			x;
	int			y;

	fractal = (t_fractal *)fractal_void;
	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return (NULL);
	x = 0;
	while (x < 700)
	{
		y = 0;
		while (y < 700)
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
	return (NULL);
}

void	draw_julia(t_fractal *fractal)
{
	int	x;
	int	y;

	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	x = 0;
	while (x < 700)
	{
		y = 0;
		while (y < 700)
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

void	draw_tricorn(t_fractal *fractal)
{
	int	x;
	int	y;

	if (!fractal || !fractal->mlx || !fractal->window || !fractal->image)
		return ;
	x = 0;
	while (x < 700)
	{
		y = 0;
		while (y < 700)
		{
			fractal->x = x;
			fractal->y = y;
			calculate_tricorn(fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}
