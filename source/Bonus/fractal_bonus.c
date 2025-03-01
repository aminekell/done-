/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:44:29 by akella            #+#    #+#             */
/*   Updated: 2025/02/25 01:24:16 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (!fractal || !query)
		return (1);
	if (ft_strcmp(query, "mandelbrot") == 0)
		draw_mandelbrot(fractal);
	else if (ft_strcmp(query, "julia") == 0)
		draw_julia(fractal);
	else if (ft_strcmp(query, "tricorn") == 0)
		draw_tricorn(fractal);
	else
	{
		write(2, "\nAvailable fractals: [mandelbrot] && [julia]\n", 46);
		write(2, "&& [tricorn]\n", 14);
		exit_fractal(fractal);
	}
	if (fractal->mlx && fractal->window && fractal->image)
		mlx_put_image_to_window(fractal->mlx, fractal->window,
			fractal->image, 0, 0);
	return (0);
}
