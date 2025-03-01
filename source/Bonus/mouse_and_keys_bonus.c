/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/24 20:06:04 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom(t_fractal *fractal, int x, int y, double direction)
{
	double	zoom_level;

	if (!fractal || fractal->zoom <= 0)
		return ;
	zoom_level = exp(direction * 0.20);
	fractal->offset_x += (x / fractal->zoom - x / (fractal->zoom * zoom_level));
	fractal->offset_y += (y / fractal->zoom - y / (fractal->zoom * zoom_level));
	fractal->zoom *= zoom_level;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (!fractal)
		return (0);
	if (key_code == 53)
		exit(0);
	else if (key_code == 123)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == 124)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == 126)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == 125)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == 8)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == 24)
		fractal->max_iterations += 20;
	else if (key_code == 27)
	{
		if (fractal->max_iterations > 50)
			fractal->max_iterations -= 20;
	}
	if (fractal->name)
		draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (!fractal)
		return (0);
	if (mouse_code == 4)
		zoom(fractal, x, y, 1);
	else if (mouse_code == 5)
		zoom(fractal, x, y, -1);
	if (fractal->name)
		draw_fractal(fractal, fractal->name);
	return (0);
}
