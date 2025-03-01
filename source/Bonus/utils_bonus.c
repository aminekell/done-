/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:49 by akella            #+#    #+#             */
/*   Updated: 2025/02/24 16:44:59 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	if (!fractal)
		return ;
	buffer = (int *)fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	if (!fractal)
		return (1);
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	exit(1);
}

static int	skip_whitespace_and_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	i = 0;
	sign = skip_whitespace_and_sign(str, &i);
	result = 0.0;
	fraction = 0.1;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			result += (str[i] - '0') * fraction;
			fraction /= 10.0;
			i++;
		}
	}
	return (result * sign);
}
