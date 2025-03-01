/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:38:48 by akella            #+#    #+#             */
/*   Updated: 2025/03/01 00:22:12 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}	t_fractal;

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int		exit_fractal(t_fractal *fractal);
double	ft_atof(const char *str);
int		is_valid_float(const char *str);
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
void	calculate_mandelbrot(t_fractal *fractal);
void	calculate_julia(t_fractal *fractal);
void	calculate_tricorn(t_fractal *fractal);
void	*draw_mandelbrot(void *fractal_void);
void	draw_julia(t_fractal *fractal);
void	draw_tricorn(t_fractal *fractal);
int		draw_fractal(t_fractal *fractal, char *query);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif