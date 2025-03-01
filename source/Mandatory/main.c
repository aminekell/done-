/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/26 06:16:31 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (!fractal || !query)
		return (1);
	if (ft_strcmp(query, "mandelbrot") == 0)
		draw_mandelbrot(fractal);
	else if (ft_strcmp(query, "julia") == 0)
		draw_julia(fractal);
	else
	{
		write(2, "\nAvailable fractals: [mandelbrot] && [julia]\n", 46);
		exit_fractal(fractal);
	}
	if (fractal->mlx && fractal->window && fractal->image)
		mlx_put_image_to_window(
			fractal->mlx,
			fractal->window,
			fractal->image,
			0,
			0);
	return (0);
}

static void	validate_julia_args(int argc, char **argv)
{
	double	cx;
	double	cy;

	if (argc != 4)
	{
		write(2, "\nError: Julia requires two float parameters ", 44);
		write(2, "(cx, cy).\n", 11);
		exit(1);
	}
	cx = ft_atof(argv[2]);
	cy = ft_atof(argv[3]);
	if (cx < -2 || cx > 2 || cy < -2 || cy > 2)
	{
		write(2, "Error: Julia constants must be between -2 and 2.\n", 50);
		exit(1);
	}
	if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
	{
		write(2, "\nError: Julia parameters must be ", 34);
		write(2, "valid float numbers.\n", 22);
		exit(1);
	}
}

static void	check_args(int argc, char **argv)
{
	if (argc == 1 || (ft_strcmp(argv[1], "mandelbrot") == 0 && argc > 2))
	{
		write(2, "Usage: ./fractol [mandelbrot] || [julia <cx> <cy>]\n", 52);
		write(2, "\nAvailable fractals: [mandelbrot] && [julia]\n", 46);
		exit(1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0)
	{
		write(2, "\nError: Invalid fractal type.\n", 31);
		write(2, "Usage: ./fractol [mandelbrot] || [julia <cx> <cy>]\n", 52);
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
		validate_julia_args(argc, argv);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	check_args(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
	{
		write(2, "Error: Memory allocation failed.\n", 34);
		return (1);
	}
	init_fractal(fractal);
	init_mlx(fractal);
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
