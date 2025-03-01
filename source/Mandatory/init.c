/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/26 13:19:44 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	if (!fractal)
	{
		write(2, "Error: Fractal structure is NULL.\n", 35);
		exit(1);
	}
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0x19071A;
	fractal->zoom = 200.0;
	fractal->offset_x = -1.70;
	fractal->offset_y = -1.40;
	fractal->max_iterations = 50;
	fractal->cx = 0.0;
	fractal->cy = 0.0;
}

static void	init_mlx_fail_cleanup(t_fractal *fractal, int step)
{
	if (step >= 3 && fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (step >= 2 && fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (step >= 1 && fractal->mlx)
		free(fractal->mlx);
	write(2, "Error: MiniLibX initialization failed.\n", 40);
	exit(1);
}

void	init_mlx(t_fractal *fractal)
{
	if (!fractal)
	{
		write(2, "Error: Fractal structure is NULL.\n", 35);
		exit(1);
	}
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		init_mlx_fail_cleanup(fractal, 1);
	fractal->window = mlx_new_window(fractal->mlx, 600, 600, "Fract-ol");
	if (!fractal->window)
		init_mlx_fail_cleanup(fractal, 2);
	fractal->image = mlx_new_image(fractal->mlx, 600, 600);
	if (!fractal->image)
		init_mlx_fail_cleanup(fractal, 3);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (!fractal->pointer_to_image)
		init_mlx_fail_cleanup(fractal, 3);
}
