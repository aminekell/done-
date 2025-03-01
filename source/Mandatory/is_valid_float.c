/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:43:21 by akella            #+#    #+#             */
/*   Updated: 2025/02/28 23:31:43 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_first_char(const char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (str[*i] == '.')
		return (0);
	if (!str[*i] || !ft_isdigit(str[*i]))
		return (0);
	return (1);
}

static int	process_digits(const char *str, int *i, int *has_dot,
int *has_digit)
{
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (*has_dot || !ft_isdigit(str[*i + 1]))
				return (0);
			*has_dot = 1;
		}
		else if (!ft_isdigit(str[*i]))
			return (0);
		else
			*has_digit = 1;
		(*i)++;
	}
	return (1);
}

int	is_valid_float(const char *str)
{
	int	i;
	int	has_dot;
	int	has_digit;

	i = 0;
	has_dot = 0;
	has_digit = 0;
	if (!check_first_char(str, &i))
		return (0);
	if (!process_digits(str, &i, &has_dot, &has_digit))
		return (0);
	return (has_digit);
}
