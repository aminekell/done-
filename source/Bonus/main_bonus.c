/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/21 02:45:34 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
		write(2, "Usage: ./fractol_bonus [mandelbrot],[julia <cx> <cy>]", 54);
		write(2, ",[tricorn]\n ", 13);
		write(2, "\nAvailable fractals: [mandelbrot] && [julia] ", 46);
		write(2, "&& [tricorn]\n", 14);
		exit(1);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "tricorn") != 0)
	{
		write(2, "\nError: Invalid fractal type.\n", 31);
		write(2, "Usage: ./fractol [mandelbrot] || [julia <cx> <cy>]\n", 52);
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
		validate_julia_args(argc, argv);
}

static void	setup_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
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
	setup_hooks(fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
